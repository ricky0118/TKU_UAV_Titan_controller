/* Include files */

#include "px4demo_attitude_system20280822car_cgxe.h"
#include "m_phrcbHND41ENnIMDaFIa.h"
#include "m_uJANcDPJBJJGA9VfejisT.h"

unsigned int cgxe_px4demo_attitude_system20280822car_method_dispatcher(SimStruct*
  S, int_T method, void* data)
{
  if (ssGetChecksum0(S) == 1528777687 &&
      ssGetChecksum1(S) == 1394578831 &&
      ssGetChecksum2(S) == 727761111 &&
      ssGetChecksum3(S) == 3799567972) {
    method_dispatcher_phrcbHND41ENnIMDaFIa(S, method, data);
    return 1;
  }

  if (ssGetChecksum0(S) == 1804942976 &&
      ssGetChecksum1(S) == 1281187472 &&
      ssGetChecksum2(S) == 1934332342 &&
      ssGetChecksum3(S) == 2714205564) {
    method_dispatcher_uJANcDPJBJJGA9VfejisT(S, method, data);
    return 1;
  }

  return 0;
}
