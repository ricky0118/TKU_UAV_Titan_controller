/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: model_reference_types.h
 *
 * Code generated for Simulink model 'px4demo_attitude_control20190311pitch'.
 *
 * Model version                  : 1.388
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Sat May 11 23:47:20 2019
 */

#ifndef MODEL_REFERENCE_TYPES_H
#define MODEL_REFERENCE_TYPES_H
#include "rtwtypes.h"
#ifndef MODEL_REFERENCE_TYPES
#define MODEL_REFERENCE_TYPES

/*===========================================================================*
 * Model reference type definitions                                          *
 *===========================================================================*/
/*
 * This structure is used by model reference to
 * communicate timing information through the hierarchy.
 */
typedef struct _rtTimingBridge_tag rtTimingBridge;
struct _rtTimingBridge_tag {
  uint32_T nTasks;
  uint32_T** clockTick;
  uint32_T** clockTickH;
  uint32_T* taskCounter;
  real_T** taskTime;
  boolean_T** rateTransition;
  boolean_T *firstInitCond;
};

#endif                                 /* MODEL_REFERENCE_TYPES */
#endif                                 /* MODEL_REFERENCE_TYPES_H */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
