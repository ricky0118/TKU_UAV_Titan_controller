#ifndef __phrcbHND41ENnIMDaFIa_h__
#define __phrcbHND41ENnIMDaFIa_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "slexec_vm_zc_functions.h"

/* Type Definitions */
#ifndef struct_tag_sAyLVJ6ilmkIN9Za5GPnbLG
#define struct_tag_sAyLVJ6ilmkIN9Za5GPnbLG

struct tag_sAyLVJ6ilmkIN9Za5GPnbLG
{
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
};

#endif                                 /*struct_tag_sAyLVJ6ilmkIN9Za5GPnbLG*/

#ifndef typedef_codertarget_pixhawk_blocks_SerialCOM
#define typedef_codertarget_pixhawk_blocks_SerialCOM

typedef struct tag_sAyLVJ6ilmkIN9Za5GPnbLG codertarget_pixhawk_blocks_SerialCOM;

#endif                                 /*typedef_codertarget_pixhawk_blocks_SerialCOM*/

#ifndef typedef_struct_T
#define typedef_struct_T

typedef struct {
  real_T f0[2];
} struct_T;

#endif                                 /*typedef_struct_T*/

#ifndef typedef_InstanceStruct_phrcbHND41ENnIMDaFIa
#define typedef_InstanceStruct_phrcbHND41ENnIMDaFIa

typedef struct {
  SimStruct *S;
  codertarget_pixhawk_blocks_SerialCOM sysobj;
  boolean_T sysobj_not_empty;
  void *emlrtRootTLSGlobal;
  covrtInstance *covInst;
  real_T *u0;
} InstanceStruct_phrcbHND41ENnIMDaFIa;

#endif                                 /*typedef_InstanceStruct_phrcbHND41ENnIMDaFIa*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
extern void method_dispatcher_phrcbHND41ENnIMDaFIa(SimStruct *S, int_T method,
  void* data);

#endif
