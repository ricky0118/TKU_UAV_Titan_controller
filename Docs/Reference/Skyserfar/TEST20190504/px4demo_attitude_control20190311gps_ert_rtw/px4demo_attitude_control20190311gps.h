/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: px4demo_attitude_control20190311gps.h
 *
 * Code generated for Simulink model 'px4demo_attitude_control20190311gps'.
 *
 * Model version                  : 1.388
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Sun May 12 00:42:13 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_px4demo_attitude_control20190311gps_h_
#define RTW_HEADER_px4demo_attitude_control20190311gps_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef px4demo_attitude_control20190311gps_COMMON_INCLUDES_
# define px4demo_attitude_control20190311gps_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* px4demo_attitude_control20190311gps_COMMON_INCLUDES_ */

#include "px4demo_attitude_control20190311gps_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#define px4demo_attitude_control20190311gps_M (px4demo_attitude_control2019_M)

/* Block signals for system '<S3>/MATLAB Function1' */
typedef struct {
  real32_T y;                          /* '<S3>/MATLAB Function1' */
} B_MATLABFunction1_px4demo_att_T;

/* Block signals for system '<S3>/MATLAB Function2' */
typedef struct {
  real32_T y;                          /* '<S3>/MATLAB Function2' */
} B_MATLABFunction2_px4demo_att_T;

/* Block signals for system '<Root>/pwm_out1' */
typedef struct {
  uint16_T M1;                         /* '<Root>/pwm_out1' */
  uint16_T M2;                         /* '<Root>/pwm_out1' */
  uint16_T M3;                         /* '<Root>/pwm_out1' */
  uint16_T M4;                         /* '<Root>/pwm_out1' */
} B_pwm_out1_px4demo_attitude_c_T;

/* Block signals (auto storage) */
typedef struct {
  real_T y_f;                          /* '<S3>/MATLAB Function5' */
  real_T Sum;                          /* '<S22>/Sum' */
  real_T Saturate;                     /* '<S22>/Saturate' */
  real_T Sum2;                         /* '<S3>/Sum2' */
  real_T Sum_j;                        /* '<S23>/Sum' */
  real_T Saturate_o;                   /* '<S23>/Saturate' */
  real_T Sum_e;                        /* '<S3>/Sum' */
  real_T Sum_m;                        /* '<S21>/Sum' */
  real_T Saturate_d;                   /* '<S21>/Saturate' */
  real_T Sum3;                         /* '<S3>/Sum3' */
  real_T Sum_f;                        /* '<S20>/Sum' */
  real_T Saturate_h;                   /* '<S20>/Saturate' */
  real_T y_n;                          /* '<S3>/MATLAB Function' */
  real_T y_h;                          /* '<S3>/MATLAB Function10' */
  real32_T Gain6;                      /* '<Root>/Gain6' */
  real32_T RateTransition;             /* '<S3>/Rate Transition' */
  real32_T RateTransition1;            /* '<S3>/Rate Transition1' */
  real32_T Gain5;                      /* '<Root>/Gain5' */
  real32_T Gain1;                      /* '<S3>/Gain1' */
  real32_T b_a;
  real32_T Gain3_m;                    /* '<S3>/Gain3' */
  real32_T DataTypeConversion17;       /* '<S3>/Data Type Conversion17' */
  real32_T DataTypeConversion18;       /* '<S3>/Data Type Conversion18' */
  int32_T q;
  int32_T q1;
  int32_T arrival;
  B_pwm_out1_px4demo_attitude_c_T sf_pwm_out2;/* '<Root>/pwm_out2' */
  B_pwm_out1_px4demo_attitude_c_T sf_pwm_out1;/* '<Root>/pwm_out1' */
  B_MATLABFunction2_px4demo_att_T sf_MATLABFunction6;/* '<S3>/MATLAB Function6' */
  B_MATLABFunction1_px4demo_att_T sf_MATLABFunction4;/* '<S3>/MATLAB Function4' */
  B_MATLABFunction2_px4demo_att_T sf_MATLABFunction3;/* '<S3>/MATLAB Function3' */
  B_MATLABFunction2_px4demo_att_T sf_MATLABFunction2;/* '<S3>/MATLAB Function2' */
  B_MATLABFunction1_px4demo_att_T sf_MATLABFunction1;/* '<S3>/MATLAB Function1' */
} B_px4demo_attitude_control201_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay2_DSTATE;            /* '<S3>/Unit Delay2' */
  real_T UnitDelay3_DSTATE;            /* '<S3>/Unit Delay3' */
  real_T Integrator_DSTATE;            /* '<S22>/Integrator' */
  real_T Integrator_DSTATE_g;          /* '<S23>/Integrator' */
  real_T Integrator_DSTATE_n;          /* '<S21>/Integrator' */
  real_T Integrator_DSTATE_k;          /* '<S20>/Integrator' */
  real_T UnitDelay4_DSTATE;            /* '<S3>/Unit Delay4' */
  real32_T Delay2_DSTATE;              /* '<Root>/Delay2' */
  real32_T Delay3_DSTATE;              /* '<Root>/Delay3' */
  boolean_T Delay1_DSTATE;             /* '<Root>/Delay1' */
  boolean_T Delay_DSTATE;              /* '<Root>/Delay' */
} DW_px4demo_attitude_control20_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real32_T phi;                        /* '<Root>/roll' */
  real32_T theta;                      /* '<Root>/pitch' */
  uint16_T ch1;                        /* '<Root>/ch1' */
  uint16_T ch2;                        /* '<Root>/ch2' */
  uint16_T ch3;                        /* '<Root>/ch3' */
  uint16_T ch4;                        /* '<Root>/ch4' */
  uint16_T ch5;                        /* '<Root>/ch5' */
  uint16_T ch6;                        /* '<Root>/ch6' */
  real32_T P;                          /* '<Root>/P' */
  real32_T Q;                          /* '<Root>/Q' */
  real32_T yaw;                        /* '<Root>/yaw' */
  real32_T lat;                        /* '<Root>/lat' */
  real32_T long_e;                     /* '<Root>/long' */
  real32_T attin1;                     /* '<Root>/attin1' */
} ExtU_px4demo_attitude_control_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  uint16_T PWM[4];                     /* '<Root>/PWM' */
  boolean_T ARM_Control;               /* '<Root>/ARM_Control' */
  real_T q1;                           /* '<Root>/q1' */
  real_T q;                            /* '<Root>/q' */
  real32_T y_out;                      /* '<Root>/y_out' */
  real32_T lat_out;                    /* '<Root>/lat_out' */
  real32_T long_out;                   /* '<Root>/long_out' */
  real32_T waypoint;                   /* '<Root>/waypoint' */
  real32_T distance;                   /* '<Root>/distance' */
  real32_T rollout;                    /* '<Root>/rollout' */
  real32_T pitchout;                   /* '<Root>/pitchout' */
  boolean_T mode;                      /* '<Root>/mode' */
} ExtY_px4demo_attitude_control_T;

/* Real-time Model Data Structure */
struct tag_RTM_px4demo_attitude_cont_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[3];
    } TaskCounters;
  } Timing;
};

/* Block signals (auto storage) */
extern B_px4demo_attitude_control201_T px4demo_attitude_control20190_B;

/* Block states (auto storage) */
extern DW_px4demo_attitude_control20_T px4demo_attitude_control2019_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_px4demo_attitude_control_T px4demo_attitude_control20190_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_px4demo_attitude_control_T px4demo_attitude_control20190_Y;

/* Model entry point functions */
extern void px4demo_attitude_control20190311gps_initialize(void);
extern void px4demo_attitude_control20190311gps_step(void);
extern void px4demo_attitude_control20190311gps_terminate(void);

/* Real-time Model object */
extern RT_MODEL_px4demo_attitude_con_T *const px4demo_attitude_control2019_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'px4demo_attitude_control20190311gps'
 * '<S1>'   : 'px4demo_attitude_control20190311gps/ARMINGControl'
 * '<S2>'   : 'px4demo_attitude_control20190311gps/ARMINGControl1'
 * '<S3>'   : 'px4demo_attitude_control20190311gps/AttitudeControl'
 * '<S4>'   : 'px4demo_attitude_control20190311gps/InputConditioning'
 * '<S5>'   : 'px4demo_attitude_control20190311gps/pwm_out1'
 * '<S6>'   : 'px4demo_attitude_control20190311gps/pwm_out2'
 * '<S7>'   : 'px4demo_attitude_control20190311gps/ARMINGControl/Compare To Constant3'
 * '<S8>'   : 'px4demo_attitude_control20190311gps/ARMINGControl1/Compare To Constant3'
 * '<S9>'   : 'px4demo_attitude_control20190311gps/AttitudeControl/MATLAB Function'
 * '<S10>'  : 'px4demo_attitude_control20190311gps/AttitudeControl/MATLAB Function1'
 * '<S11>'  : 'px4demo_attitude_control20190311gps/AttitudeControl/MATLAB Function10'
 * '<S12>'  : 'px4demo_attitude_control20190311gps/AttitudeControl/MATLAB Function2'
 * '<S13>'  : 'px4demo_attitude_control20190311gps/AttitudeControl/MATLAB Function3'
 * '<S14>'  : 'px4demo_attitude_control20190311gps/AttitudeControl/MATLAB Function4'
 * '<S15>'  : 'px4demo_attitude_control20190311gps/AttitudeControl/MATLAB Function5'
 * '<S16>'  : 'px4demo_attitude_control20190311gps/AttitudeControl/MATLAB Function6'
 * '<S17>'  : 'px4demo_attitude_control20190311gps/AttitudeControl/MATLAB Function7'
 * '<S18>'  : 'px4demo_attitude_control20190311gps/AttitudeControl/MATLAB Function8'
 * '<S19>'  : 'px4demo_attitude_control20190311gps/AttitudeControl/MATLAB Function9'
 * '<S20>'  : 'px4demo_attitude_control20190311gps/AttitudeControl/PITCH'
 * '<S21>'  : 'px4demo_attitude_control20190311gps/AttitudeControl/pitch1'
 * '<S22>'  : 'px4demo_attitude_control20190311gps/AttitudeControl/roll'
 * '<S23>'  : 'px4demo_attitude_control20190311gps/AttitudeControl/roll1'
 */
#endif                                 /* RTW_HEADER_px4demo_attitude_control20190311gps_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
