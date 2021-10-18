/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: px4demo_attitude_control20190311gps_private.h
 *
 * Code generated for Simulink model 'px4demo_attitude_control20190311gps'.
 *
 * Model version                  : 1.392
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri May 31 02:06:21 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_px4demo_attitude_control20190311gps_private_h_
#define RTW_HEADER_px4demo_attitude_control20190311gps_private_h_
#include "rtwtypes.h"
#include "model_reference_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsSampleHit
# define rtmIsSampleHit(sti, tid)      (px4demo_attitude_con_TimingBrdg->taskCounter[px4demo_attitude_cont_GlobalTID[sti]] == 0)
#endif

/* Macros for accessing real-time model data structure */
#ifndef rtmGetClockTick0
# define rtmGetClockTick0()            ( *((px4demo_attitude_con_TimingBrdg->clockTick[px4demo_attitude_cont_GlobalTID[0]])) )
#endif

#ifndef rtmGetClockTick1
# define rtmGetClockTick1()            ( *((px4demo_attitude_con_TimingBrdg->clockTick[px4demo_attitude_cont_GlobalTID[1]])) )
#endif

#ifndef rtmGetClockTick2
# define rtmGetClockTick2()            ( *((px4demo_attitude_con_TimingBrdg->clockTick[px4demo_attitude_cont_GlobalTID[2]])) )
#endif

#ifndef rtmGetClockTickH0
# define rtmGetClockTickH0()           ( *(px4demo_attitude_con_TimingBrdg->clockTickH[px4demo_attitude_cont_GlobalTID[0]]) )
#endif

#ifndef rtmGetClockTickH1
# define rtmGetClockTickH1()           ( *(px4demo_attitude_con_TimingBrdg->clockTickH[px4demo_attitude_cont_GlobalTID[1]]) )
#endif

#ifndef rtmGetClockTickH2
# define rtmGetClockTickH2()           ( *(px4demo_attitude_con_TimingBrdg->clockTickH[px4demo_attitude_cont_GlobalTID[2]]) )
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
# define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
# define rtmGetT()                     (*(px4demo_attitude_con_TimingBrdg->taskTime[0]))
#endif

extern int_T px4demo_attitude_cont_GlobalTID[3];
extern const rtTimingBridge *px4demo_attitude_con_TimingBrdg;

#endif                                 /* RTW_HEADER_px4demo_attitude_control20190311gps_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
