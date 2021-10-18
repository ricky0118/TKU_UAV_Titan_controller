/* Include files */

#include "px4demo_attitude_system20190504_gps_cgxe.h"
#include "m_t1kSfRT32OS29myErLpFTF.h"

unsigned int cgxe_px4demo_attitude_system20190504_gps_method_dispatcher
  (SimStruct* S, int_T method, void* data)
{
  if (ssGetChecksum0(S) == 384210959 &&
      ssGetChecksum1(S) == 2355883829 &&
      ssGetChecksum2(S) == 1036565233 &&
      ssGetChecksum3(S) == 1212432732) {
    method_dispatcher_t1kSfRT32OS29myErLpFTF(S, method, data);
    return 1;
  }

  return 0;
}
