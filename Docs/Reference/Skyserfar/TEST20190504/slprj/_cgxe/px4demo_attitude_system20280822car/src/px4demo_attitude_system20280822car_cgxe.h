#ifndef __px4demo_attitude_system20280822car_cgxe_h__
#define __px4demo_attitude_system20280822car_cgxe_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "emlrt.h"
#include "covrt.h"
#include "cgxert.h"
#include <stdio.h>
#define rtInf                          (mxGetInf())
#define rtMinusInf                     (-(mxGetInf()))
#define rtNaN                          (mxGetNaN())
#define rtIsNaN(X)                     ((int)mxIsNaN(X))
#define rtIsInf(X)                     ((int)mxIsInf(X))

extern unsigned int cgxe_px4demo_attitude_system20280822car_method_dispatcher
  (SimStruct* S, int_T method, void* data);

#endif
