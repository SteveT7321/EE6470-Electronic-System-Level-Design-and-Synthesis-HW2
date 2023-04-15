#ifndef MM_FILTER_H_
#define MM_FILTER_H_
#include <systemc>
using namespace sc_core;

// Note: To be the TLM - target
#include "tlm"
#include "tlm_utils/simple_target_socket.h"

#include "filter_def.h"

class MMFilter : public sc_module {
public:
  // Note: To be the TLM - target
  tlm_utils::simple_target_socket<MMFilter> t_skt;

  sc_fifo<unsigned char> i_r;
  sc_fifo<unsigned char> i_g;
  sc_fifo<unsigned char> i_b;
  sc_fifo<unsigned char> buf_fifo;
  sc_fifo<unsigned char> o_result_r;
  sc_fifo<unsigned char> o_result_g;
  sc_fifo<unsigned char> o_result_b;

  SC_HAS_PROCESS(MMFilter);
  MMFilter(sc_module_name n);
  ~MMFilter() = default;

private:
  void do_filter();
  int val[MASK_N];

  unsigned int base_offset;
  void blocking_transport(tlm::tlm_generic_payload &payload,
                          sc_core::sc_time &delay);
};
#endif
