#ifndef __c3_pixhawk_slib_misc_utils_h__
#define __c3_pixhawk_slib_misc_utils_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_pixhawk_slib_misc_utilsInstanceStruct
#define typedef_SFc3_pixhawk_slib_misc_utilsInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_pixhawk_slib_misc_utils;
  uint8_T c3_logname[15];
  boolean_T c3_cacheflag;
  uint32_T c3_numRecs;
  FILE* c3_fp;
  boolean_T c3_fp_not_empty;
  boolean_T c3_isflushed;
  boolean_T c3_isflushed_not_empty;
  boolean_T c3_isopen;
  boolean_T c3_isopen_not_empty;
  uint32_T c3_count;
  boolean_T c3_count_not_empty;
  real_T c3_lognumstr;
  boolean_T c3_lognumstr_not_empty;
  uint16_T c3_elem_size;
  boolean_T c3_elem_size_not_empty;
  uint8_T c3_vect_size;
  boolean_T c3_vect_size_not_empty;
  boolean_T *c3_en;
  real32_T (*c3_data)[6];
} SFc3_pixhawk_slib_misc_utilsInstanceStruct;

#endif                                 /*typedef_SFc3_pixhawk_slib_misc_utilsInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c3_pixhawk_slib_misc_utils_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_pixhawk_slib_misc_utils_get_check_sum(mxArray *plhs[]);
extern void c3_pixhawk_slib_misc_utils_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
