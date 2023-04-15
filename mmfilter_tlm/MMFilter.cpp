#include <cmath>
#include <iomanip>

#include "MMFilter.h"

MMFilter::MMFilter(sc_module_name n)
    : sc_module(n), t_skt("t_skt"), base_offset(0) {
  SC_THREAD(do_filter);

  t_skt.register_b_transport(this, &MMFilter::blocking_transport);
}

// sobel mask
const int mask[MASK_X][MASK_Y] = {{1, 1, 1}, {1, 2, 1}, {1, 1, 1}};
int pixel_r[3][3]={0};
int pixel_g[3][3]={0};
int pixel_b[3][3]={0};
int r_buffer[2][3]={0};
int g_buffer[2][3]={0};
int b_buffer[2][3]={0};

void MMFilter::do_filter() {
  while (true) {
    unsigned char buffer_used = buf_fifo.read();
    if(buffer_used){
      // Read in a 3x3 sliding window of pixels centered around the current pixel
      for (unsigned int v = 0; v < MASK_Y; ++v) {
        for (unsigned int u = 0; u < MASK_X; ++u) {
          pixel_r[u][v] = i_r.read();
          pixel_g[u][v] = i_g.read();
          pixel_b[u][v] = i_b.read();
        }
      }
      // To write the buffer
      for (unsigned int v = 0; v < MASK_Y; ++v){
        for (unsigned int u = 0; u < MASK_X-1; ++u){ 
        r_buffer[u][v] = pixel_r[u+1][v];
        g_buffer[u][v] = pixel_g[u+1][v]; 
        b_buffer[u][v] = pixel_b[u+1][v];
        }
      }
    }
    else{
      for (unsigned int v = 0; v < MASK_Y; ++v){
        for (unsigned int u = 0; u < MASK_X; ++u){
          if(u!=2){
          pixel_r[u][v] = r_buffer[u][v];
          pixel_g[u][v] = g_buffer[u][v];
          pixel_b[u][v] = b_buffer[u][v];
          }
          else{
          pixel_r[u][v] = i_r.read();
          pixel_g[u][v] = i_g.read();
          pixel_b[u][v] = i_b.read();
          }
        }
      }
      // To write the buffer
      for (unsigned int v = 0; v < MASK_Y; ++v){
        for (unsigned int u = 0; u < MASK_X-1; ++u){ 
        r_buffer[u][v] = pixel_r[u+1][v];
        g_buffer[u][v] = pixel_g[u+1][v]; 
        b_buffer[u][v] = pixel_b[u+1][v];
        }
      }
    }

    // 1. Applying "median filter" to each color channel
    // Flatten the 2D array into a 1D array
    int flattened_r[9],flattened_g[9],flattened_b[9];
    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            flattened_r[k] = pixel_r[i][j];
            flattened_g[k] = pixel_g[i][j];
            flattened_b[k] = pixel_b[i][j];
            k+=1;

        }
    }
    std::sort(flattened_r, flattened_r + 9);
    std::sort(flattened_g, flattened_g + 9);
    std::sort(flattened_b, flattened_b + 9);

    unsigned char filtered_r = flattened_r[4];
    unsigned char filtered_g = flattened_g[4];
    unsigned char filtered_b = flattened_b[4];

    // 2. Applying "mean filter" to each color channel
    int sum_r = 0, sum_g = 0, sum_b = 0;

    for (unsigned int v = 0; v < MASK_Y; ++v) {
      for (unsigned int u = 0; u < MASK_X; ++u) {
        sum_r += filtered_r * mask[u][v];
        sum_g += filtered_g * mask[u][v];
        sum_b += filtered_b * mask[u][v];
      }
    }

    filtered_r = sum_r / 10;
    filtered_g = sum_g / 10;
    filtered_b = sum_b / 10;

    // Write out the filtered pixel
    o_result_r.write(filtered_r);
    o_result_g.write(filtered_g);
    o_result_b.write(filtered_b);

    // wait(5); //emulate module delay
    wait(5 * CLOCK_PERIOD, SC_NS); //May cause system to hang
  }
}

void MMFilter::blocking_transport(tlm::tlm_generic_payload &payload,
                                     sc_core::sc_time &delay) {
  sc_dt::uint64 addr = payload.get_address();
  addr = addr - base_offset;
  unsigned char *mask_ptr = payload.get_byte_enable_ptr();
  unsigned char *data_ptr = payload.get_data_ptr();
  word buffer;
  switch (payload.get_command()) {
  case tlm::TLM_READ_COMMAND: //read the filtered reult
    switch (addr) {
    case MM_FILTER_RESULT_ADDR:
      buffer.uc[0] = o_result_r.read();
      buffer.uc[1] = o_result_g.read();
      buffer.uc[2] = o_result_b.read();
      buffer.uc[3] = 0;
      break;
    case MM_FILTER_CHECK_ADDR:
      buffer.uint = o_result_r.num_available();
      break;
    default:
      std::cerr << "Error! MMFilter::blocking_transport: address 0x"
                << std::setfill('0') << std::setw(8) << std::hex << addr
                << std::dec << " is not valid" << std::endl;
      break;
    }
    data_ptr[0] = buffer.uc[0];
    data_ptr[1] = buffer.uc[1];
    data_ptr[2] = buffer.uc[2];
    data_ptr[3] = buffer.uc[3];
    delay = sc_time(1, SC_NS);
    break;

  case tlm::TLM_WRITE_COMMAND: // write to the filter
    switch (addr) {
    case MM_FILTER_R_ADDR:
      if (mask_ptr[0] == 0xff) {
        i_r.write(data_ptr[0]);
      }
      if (mask_ptr[1] == 0xff) {
        i_g.write(data_ptr[1]);
      }
      if (mask_ptr[2] == 0xff) {
        i_b.write(data_ptr[2]);
      }
      if (mask_ptr[3] == 0xff) {
        buf_fifo.write(data_ptr[3]);
      }
      break;
    default:
      std::cerr << "Error! MMFilter::blocking_transport: address 0x"
                << std::setfill('0') << std::setw(8) << std::hex << addr
                << std::dec << " is not valid" << std::endl;
      break;
    }
    delay = sc_time(1, SC_NS);
    break;

  case tlm::TLM_IGNORE_COMMAND:
    payload.set_response_status(tlm::TLM_GENERIC_ERROR_RESPONSE);
    return;
  default:
    payload.set_response_status(tlm::TLM_GENERIC_ERROR_RESPONSE);
    return;
  }
  payload.set_response_status(tlm::TLM_OK_RESPONSE); // Always OK
}
