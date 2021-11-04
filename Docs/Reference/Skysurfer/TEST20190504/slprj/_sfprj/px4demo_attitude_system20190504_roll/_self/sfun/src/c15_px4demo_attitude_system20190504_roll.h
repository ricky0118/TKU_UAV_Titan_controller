#ifndef __c15_px4demo_attitude_system20190504_roll_h__
#define __c15_px4demo_attitude_system20190504_roll_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#include <stddef.h>
#ifndef typedef_SFc15_px4demo_attitude_system20190504_rollInstanceStruct
#define typedef_SFc15_px4demo_attitude_system20190504_rollInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c15_sfEvent;
  boolean_T c15_doneDoubleBufferReInit;
  uint8_T c15_is_active_c15_px4demo_attitude_system20190504_roll;
  real32_T (*c15_u)[4];
  real32_T *c15_y;
} SFc15_px4demo_attitude_system20190504_rollInstanceStruct;

#endif                                 /*typedef_SFc15_px4demo_attitude_system20190504_rollInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c15_px4demo_attitude_system20190504_roll_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c15_px4demo_attitude_system20190504_roll_get_check_sum(mxArray
  *plhs[]);
extern void c15_px4demo_attitude_system20190504_roll_method_dispatcher(SimStruct
  *S, int_T method, void *data);

#endif
