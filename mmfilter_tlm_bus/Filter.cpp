#include <cmath>
#include <iomanip>

#include "Filter.h"

Filter::Filter(sc_module_name n)
    : sc_module(n), t_skt("t_skt"), base_offset(0) {
  SC_THREAD(do_filter);

  t_skt.register_b_transport(this, &Filter::blocking_transport);
}

Filter::~Filter() = default;


void Filter::do_filter() {
  int pixel_r[3][3]={0};
  int pixel_g[3][3]={0};
  int pixel_b[3][3]={0};
  int r_buffer[2][3]={0};
  int g_buffer[2][3]={0};
  int b_buffer[2][3]={0};
  while (true) {
    unsigned char flag = buffer.read();

    if (flag == 1){
      for (int i = 0; i < 8; i ++){
        flag = buffer.read();
      }
    } else {
      for (int i = 0; i < 2; i ++){
        flag = buffer.read();
      }
    }

    if(flag){
      // Read in a 3x3 sliding window of pixels centered around the current pixel
      for (unsigned int v = 0; v < MASK_Y; ++v) {
        for (unsigned int u = 0; u < MASK_X; ++u) {
          pixel_r[u][v] = r.read();
          pixel_g[u][v] = g.read();
          pixel_b[u][v] = b.read();
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
          pixel_r[u][v] = r.read();
          pixel_g[u][v] = g.read();
          pixel_b[u][v] = b.read();
          
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
            k=k+1;
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
    result_r.write(filtered_r);
    result_g.write(filtered_g);
    result_b.write(filtered_b);
    wait(10 * CLOCK_PERIOD, SC_NS);
  }
}

void Filter::blocking_transport(tlm::tlm_generic_payload &payload,
                                     sc_core::sc_time &delay) {
  sc_dt::uint64 addr = payload.get_address();
  addr -= base_offset;
  unsigned char *mask_ptr = payload.get_byte_enable_ptr();
  unsigned char *data_ptr = payload.get_data_ptr();
  word temp;
  switch (payload.get_command()) {
  //if ((payload.get_command() == tlm::TLM_READ_COMMAND)) counter_read++;
  //if ((payload.get_command() == tlm::TLM_WRITE_COMMAND)) counter_write++;

  case tlm::TLM_READ_COMMAND:
    counter_read++;
    switch (addr) {
    case SOBEL_FILTER_RESULT_ADDR:
      temp.uc[0] = result_r.read();
      temp.uc[1] = result_g.read();
      temp.uc[2] = result_b.read();
      temp.uc[3] = 0;
      break;
    case SOBEL_FILTER_CHECK_ADDR:
      temp.uint = result_r.num_available();
    break;
    default:
      std::cerr << "Error! SobelFilter::blocking_transport: address 0x"
                << std::setfill('0') << std::setw(8) << std::hex << addr
                << std::dec << " is not valid" << std::endl;
    }
    data_ptr[0] = temp.uc[0];
    data_ptr[1] = temp.uc[1];
    data_ptr[2] = temp.uc[2];
    data_ptr[3] = temp.uc[3];
    delay=sc_time(5, SC_NS);
    break;

  case tlm::TLM_WRITE_COMMAND:
    counter_write++;
    switch (addr) {
    case SOBEL_FILTER_R_ADDR:
      if (mask_ptr[0] == 0xff) {
        r.write(data_ptr[0]);
      }
      if (mask_ptr[1] == 0xff) {
        g.write(data_ptr[1]);
      }
      if (mask_ptr[2] == 0xff) {
        b.write(data_ptr[2]);
      }
      if (mask_ptr[3] == 0xff) {
        buffer.write(data_ptr[3]);
      }
      break;
    default:
      std::cerr << "Error! SobelFilter::blocking_transport: address 0x"
                << std::setfill('0') << std::setw(8) << std::hex << addr
                << std::dec << " is not valid" << std::endl;
    }
    delay=sc_time(10, SC_NS);
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