/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: px4demo_attitude_control20180822car.c
 *
 * Code generated for Simulink model 'px4demo_attitude_control20180822car'.
 *
 * Model version                  : 1.380
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Tue Jul 30 10:34:50 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "px4demo_attitude_control20180822car.h"
#include "px4demo_attitude_control20180822car_private.h"

int_T px4demo_attitude_cont_GlobalTID[3];
const rtTimingBridge *px4demo_attitude_con_TimingBrdg;

/*
 * Output and update for atomic system:
 *    '<S3>/MATLAB Function1'
 *    '<S3>/MATLAB Function4'
 */
void px4demo_attitud_MATLABFunction1(real32_T rtu_u,
  B_MATLABFunction1_px4demo_att_T *localB)
{
  /* MATLAB Function 'AttitudeControl/MATLAB Function1': '<S10>:1' */
  /* '<S10>:1:3' */
  localB->y = rt_roundf_snf(rtu_u * 10.0F) / 10.0F;
}

/*
 * Output and update for atomic system:
 *    '<S3>/MATLAB Function2'
 *    '<S3>/MATLAB Function3'
 *    '<S3>/MATLAB Function6'
 */
void px4demo_attitud_MATLABFunction2(real32_T rtu_u,
  B_MATLABFunction2_px4demo_att_T *localB)
{
  /* MATLAB Function 'AttitudeControl/MATLAB Function2': '<S12>:1' */
  /* '<S12>:1:3' */
  localB->y = rt_roundf_snf(rtu_u * 100.0F) / 100.0F;
}

/*
 * Output and update for atomic system:
 *    '<Root>/pwm_out1'
 *    '<Root>/pwm_out2'
 */
void px4demo_attitude_contr_pwm_out1(real32_T rtu_Roll, real32_T rtu_Pitch,
  real32_T rtu_Yaw, real32_T rtu_Thrust, B_pwm_out1_px4demo_attitude_c_T *localB)
{
  real32_T tmp;

  /* MATLAB Function 'pwm_out1': '<S5>:1' */
  /* idle_PWM = uint16(1000); */
  /*  Quad X */
  /*  M1 = ((Roll + Pitch - Yaw) / 2 * Thrust + Thrust) * 1000 + idle_PWM; */
  /*  M2 = ((-Roll + Pitch + Yaw) / 2 * Thrust + Thrust) * 1000 + idle_PWM; */
  /*  M3 = ((-Roll - Pitch - Yaw) / 2 * Thrust + Thrust) * 1000 + idle_PWM; */
  /*  M4 = ((Roll - Pitch + Yaw) / 2 * Thrust + Thrust) * 1000 + idle_PWM; */
  /*  M5 = 1000; */
  /*  M6 = 1000; */
  /*  M7 = 1000; */
  /*  M8 = 1000; */
  /*  Quad + */
  /*  M1 = ((Pitch - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M2 = ((-Roll + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M3 = ((-Pitch - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M4 = ((Roll + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M5 = 1000; */
  /*  M6 = 1000; */
  /*  M7 = 1000; */
  /*  M8 = 1000; */
  /*  Hex X */
  /*  M1 = ((Pitch + Roll / 2 - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M2 = ((Pitch - Roll / 2 + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M3 = ((-Roll - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M4 = ((-Pitch - Roll / 2 + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M5 = ((-Pitch + Roll / 2 - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M6 = ((Roll + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M7 = 1000; */
  /*  M8 = 1000; */
  /*  Hex X (From Adam) */
  /* '<S5>:1:36' */
  tmp = rt_roundf_snf(rtu_Roll * 400.0F + 1500.0F);
  if (tmp < 65536.0F) {
    if (tmp >= 0.0F) {
      localB->M1 = (uint16_T)tmp;
    } else {
      localB->M1 = 0U;
    }
  } else {
    localB->M1 = MAX_uint16_T;
  }

  /* '<S5>:1:37' */
  tmp = rt_roundf_snf(rtu_Pitch * 400.0F + 1500.0F);
  if (tmp < 65536.0F) {
    if (tmp >= 0.0F) {
      localB->M2 = (uint16_T)tmp;
    } else {
      localB->M2 = 0U;
    }
  } else {
    localB->M2 = MAX_uint16_T;
  }

  /* '<S5>:1:38' */
  tmp = rt_roundf_snf(rtu_Thrust * 800.0F + 1100.0F);
  if (tmp < 65536.0F) {
    if (tmp >= 0.0F) {
      localB->M3 = (uint16_T)tmp;
    } else {
      localB->M3 = 0U;
    }
  } else {
    localB->M3 = MAX_uint16_T;
  }

  /* '<S5>:1:39' */
  tmp = rt_roundf_snf(rtu_Yaw * 400.0F + 1500.0F);
  if (tmp < 65536.0F) {
    if (tmp >= 0.0F) {
      localB->M4 = (uint16_T)tmp;
    } else {
      localB->M4 = 0U;
    }
  } else {
    localB->M4 = MAX_uint16_T;
  }

  /*  Hex X (Version 2) */
  /*  Roll/Yaw */
  /*  M1 = ((-Roll - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M2 = ((Roll + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  % + Pitch/Roll */
  /*  M6 = ((Pitch + Roll / 2 - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M4 = ((Pitch - Roll / 2 + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  % - Pitch/Roll */
  /*  M5 = ((-Pitch - Roll / 2 + Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
  /*  M3 = ((-Pitch + Roll / 2 - Yaw) * Thrust / 2 + Thrust) * 1000 + idle_PWM; */
}

/* System initialize for referenced model: 'px4demo_attitude_control20180822car' */
void px4demo_attitude_control20_Init(DW_px4demo_attitude_control_f_T *localDW)
{
  /* InitializeConditions for UnitDelay: '<S3>/Unit Delay2' */
  localDW->UnitDelay2_DSTATE = 1.0;
}

/* Output and update for referenced model: 'px4demo_attitude_control20180822car' */
void px4demo_attitude_control2018082(const real32_T *rtu_roll, const real32_T
  *rtu_pitch, const uint16_T *rtu_ch1, const uint16_T *rtu_ch2, const uint16_T
  *rtu_ch3, const uint16_T *rtu_ch4, const uint16_T *rtu_ch5, const uint16_T
  *rtu_ch6, const int32_T *rtu_lat, const int32_T *rtu_long, const real32_T
  *rtu_yaw, const real32_T *rtu_attin, uint16_T rty_PWM[4], boolean_T
  *rty_ARM_Control, real_T *rty_q1, real_T *rty_q, real32_T *rty_y_out, real32_T
  *rty_lat_out, real32_T *rty_long_out, real32_T *rty_waypoint, real32_T
  *rty_distance, real32_T *rty_rollout, real32_T *rty_pitchout, real32_T
  *rty_attout, B_px4demo_attitude_control2_c_T *localB,
  DW_px4demo_attitude_control_f_T *localDW)
{
  /* local block i/o variables */
  real32_T rtb_Saturation9;
  real32_T rtb_DataTypeConversion4_m;
  real32_T rtb_Saturation8;
  real32_T rtb_DataTypeConversion5;
  real32_T rtb_Gain3_a;
  real32_T rtb_Gain4_g;
  real32_T rtb_Saturation10;
  real32_T rtb_thera_new2;
  real32_T rtb_vector_a_y;
  real32_T rtb_vector_a_x;
  real32_T rtb_Saturation7;
  static const int32_T position[4] = { 251981990, 251989590, 1214213880,
    1214219020 };

  real32_T vector_a1_idx_1;
  real32_T vector_b1_idx_0;
  real32_T vector_b1_idx_1;
  real32_T u0;
  if (rtmIsSampleHit(1, 0)) {
    /* Fcn: '<S4>/Fcn7' incorporates:
     *  DataTypeConversion: '<S4>/Data Type Conversion4'
     */
    u0 = ((real32_T)*rtu_ch4 - 1500.0F) / 400.0F;

    /* Saturate: '<S4>/Saturation7' */
    if (u0 > 1.0F) {
      rtb_Saturation7 = 1.0F;
    } else if (u0 < (-1.0F)) {
      rtb_Saturation7 = (-1.0F);
    } else {
      rtb_Saturation7 = u0;
    }

    /* End of Saturate: '<S4>/Saturation7' */

    /* MATLAB Function: '<S3>/MATLAB Function6' */
    px4demo_attitud_MATLABFunction2(rtb_Saturation7, &localB->sf_MATLABFunction6);

    /* Gain: '<S3>/Gain1' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion9'
     */
    localB->Gain1 = 1.0F * localB->sf_MATLABFunction6.y;
  }

  /* Gain: '<S3>/Gain3' */
  localB->Gain3 = 57.2957802F * *rtu_yaw;

  /* MATLAB Function: '<S3>/MATLAB Function7' */
  /* MATLAB Function 'AttitudeControl/MATLAB Function7': '<S17>:1' */
  if (localB->Gain3 <= 0.0F) {
    /* '<S17>:1:2' */
    /* '<S17>:1:3' */
    localB->y_jg = 360.0F + localB->Gain3;
  } else {
    /* '<S17>:1:5' */
    localB->y_jg = localB->Gain3;
  }

  /* End of MATLAB Function: '<S3>/MATLAB Function7' */

  /* DataTypeConversion: '<S3>/Data Type Conversion15' */
  *rty_lat_out = (real32_T)*rtu_lat;

  /* DataTypeConversion: '<S3>/Data Type Conversion16' */
  *rty_long_out = (real32_T)*rtu_long;

  /* RateTransition: '<S3>/Rate Transition' */
  if (rtmIsSampleHit(2, 0)) {
    localB->RateTransition = *rty_lat_out;

    /* RateTransition: '<S3>/Rate Transition1' */
    localB->RateTransition1 = *rty_long_out;
  }

  /* End of RateTransition: '<S3>/Rate Transition' */
  if (rtmIsSampleHit(1, 0)) {
    /* UnitDelay: '<S3>/Unit Delay2' */
    localB->y_j = localDW->UnitDelay2_DSTATE;

    /* MATLAB Function: '<S3>/MATLAB Function5' incorporates:
     *  UnitDelay: '<S3>/Unit Delay2'
     *  UnitDelay: '<S3>/Unit Delay3'
     */
    /* MATLAB Function 'AttitudeControl/MATLAB Function5': '<S15>:1' */
    /* '<S15>:1:1' */
    if ((localDW->UnitDelay3_DSTATE == 1.0) && (localDW->UnitDelay2_DSTATE <=
         3.0)) {
      /* '<S15>:1:2' */
      /* '<S15>:1:3' */
      localB->y_j = localDW->UnitDelay2_DSTATE + 1.0;
    }

    if (localB->y_j == 3.0) {
      /* '<S15>:1:5' */
      /* '<S15>:1:6' */
      localB->y_j = 1.0;
    }

    /* End of MATLAB Function: '<S3>/MATLAB Function5' */

    /* DataTypeConversion: '<S3>/Data Type Conversion12' */
    *rty_waypoint = (real32_T)localB->y_j;
  }

  /* MATLAB Function: '<S3>/MATLAB Function' */
  /* MATLAB Function 'AttitudeControl/MATLAB Function': '<S9>:1' */
  /* '<S9>:1:2' */
  /* '<S9>:1:6' */
  localB->yaw_pwm = 0.0;

  /* '<S9>:1:7' */
  localB->thera_new = 0.0;

  /* '<S9>:1:8' */
  localB->vector_a[0] = (real32_T)position[(int32_T)*rty_waypoint - 1] -
    *rty_lat_out;
  localB->vector_a[1] = (real32_T)position[(int32_T)*rty_waypoint + 1] -
    *rty_long_out;

  /* '<S9>:1:9' */
  u0 = (real32_T)position[(int32_T)*rty_waypoint - 1] - *rty_lat_out;

  /* '<S9>:1:10' */
  localB->rtb_Switch1_idx_1 = (real32_T)position[(int32_T)*rty_waypoint + 1] -
    *rty_long_out;

  /* '<S9>:1:11' */
  localB->vector_b[0] = localB->RateTransition - *rty_lat_out;
  localB->vector_b[1] = localB->RateTransition1 - *rty_long_out;

  /* '<S9>:1:12' */
  localB->a = (real32_T)position[(int32_T)*rty_waypoint - 1] - *rty_lat_out;
  localB->b_a = (real32_T)position[(int32_T)*rty_waypoint + 1] - *rty_long_out;

  /* thera=acosd(dot(vector_a,vector_b)/(distance_a*distance_b)) */
  /* thera_new=acosd(dot(vector_a,vector_b)/(distance_a*distance_b)) */
  /* '<S9>:1:17' */
  localB->vector_a1_idx_0 = (real32_T)position[(int32_T)*rty_waypoint - 1] -
    *rty_lat_out;
  vector_a1_idx_1 = (real32_T)position[(int32_T)*rty_waypoint + 1] -
    *rty_long_out;

  /* '<S9>:1:18' */
  vector_b1_idx_0 = localB->RateTransition - *rty_lat_out;
  vector_b1_idx_1 = localB->RateTransition1 - *rty_long_out;

  /* '<S9>:1:20' */
  localB->a = (real32_T)sqrt(localB->a * localB->a + localB->b_a * localB->b_a) /
    1000.0F;

  /* vector_a_y=(position(x,1)-latitutde); */
  /* vector_a_x=(position(x,2)-longitude); */
  /* '<S9>:1:24' */
  localB->b_a = (real32_T)atan(localB->rtb_Switch1_idx_1 / u0) * 57.2957802F;
  if (((real_T)position[(int32_T)*rty_waypoint - 1] >= *rty_lat_out) && ((real_T)
       position[(int32_T)*rty_waypoint + 1] >= *rty_long_out)) {
    /* '<S9>:1:26' */
    /* '<S9>:1:27' */
    localB->b_a = (real32_T)fabs(localB->b_a);

    /* '<S9>:1:28' */
    localB->q = 1;
  } else if (((real_T)position[(int32_T)*rty_waypoint - 1] <= *rty_lat_out) &&
             ((real_T)position[(int32_T)*rty_waypoint + 1] >= *rty_long_out)) {
    /* '<S9>:1:29' */
    /* '<S9>:1:30' */
    localB->b_a = (localB->b_a + 90.0F) + 90.0F;

    /* '<S9>:1:31' */
    localB->q = 2;
  } else if (((real_T)position[(int32_T)*rty_waypoint - 1] <= *rty_lat_out) &&
             ((real_T)position[(int32_T)*rty_waypoint + 1] <= *rty_long_out)) {
    /* '<S9>:1:32' */
    /* '<S9>:1:33' */
    localB->b_a += 180.0F;

    /* '<S9>:1:34' */
    localB->q = 3;
  } else {
    /* '<S9>:1:36' */
    localB->b_a = (localB->b_a + 90.0F) + 270.0F;

    /* '<S9>:1:37' */
    localB->q = 4;
  }

  if ((localB->y_jg <= 90.0F) && (localB->y_jg > 0.0F)) {
    /* '<S9>:1:39' */
    /* '<S9>:1:40' */
    localB->q1 = 1;
  } else if ((localB->y_jg <= 180.0F) && (localB->y_jg > 90.0F)) {
    /* '<S9>:1:41' */
    /* '<S9>:1:42' */
    localB->q1 = 2;
  } else if ((localB->y_jg <= 270.0F) && (localB->y_jg > 180.0F)) {
    /* '<S9>:1:43' */
    /* '<S9>:1:44' */
    localB->q1 = 3;
  } else {
    /* '<S9>:1:46' */
    localB->q1 = 4;
  }

  /* '<S9>:1:48' */
  localB->dif_thera = localB->b_a - localB->y_jg;
  if ((localB->q == 4) && (localB->q1 == 1)) {
    /* '<S9>:1:49' */
    /* '<S9>:1:50' */
    localB->y_h = -0.4;

    /* '<S9>:1:51' */
    localB->y1 = 1;
  } else if ((localB->q == 4) && (localB->q1 == 2)) {
    /* '<S9>:1:52' */
    /* '<S9>:1:53' */
    localB->y_h = -1.0;

    /* '<S9>:1:54' */
    localB->y1 = 1;
  } else if ((localB->q == 4) && (localB->q1 == 3)) {
    /* '<S9>:1:55' */
    /* '<S9>:1:56' */
    localB->y_h = 0.4;

    /* '<S9>:1:57' */
    localB->y1 = 1;
  } else if ((localB->q == 3) && (localB->q1 == 4)) {
    /* '<S9>:1:59' */
    /*  */
    /* '<S9>:1:60' */
    localB->y_h = -0.4;

    /* '<S9>:1:61' */
    localB->y1 = 1;
  } else if ((localB->q == 3) && (localB->q1 == 1)) {
    /* '<S9>:1:62' */
    /* '<S9>:1:63' */
    localB->y_h = -1.0;

    /* '<S9>:1:64' */
    localB->y1 = 1;
  } else if ((localB->q == 3) && (localB->q1 == 2)) {
    /* '<S9>:1:65' */
    /* '<S9>:1:66' */
    localB->y_h = 0.4;

    /* '<S9>:1:67' */
    localB->y1 = 1;
  } else if ((localB->q == 2) && (localB->q1 == 4)) {
    /* '<S9>:1:69' */
    /*  */
    /* '<S9>:1:70' */
    localB->y_h = -1.0;

    /* '<S9>:1:71' */
    localB->y1 = 1;
  } else if ((localB->q == 2) && (localB->q1 == 1)) {
    /* '<S9>:1:72' */
    /* '<S9>:1:73' */
    localB->y_h = 0.4;

    /* '<S9>:1:74' */
    localB->y1 = 1;
  } else if ((localB->q == 2) && (localB->q1 == 3)) {
    /* '<S9>:1:75' */
    /* '<S9>:1:76' */
    localB->y_h = -0.4;

    /* '<S9>:1:77' */
    localB->y1 = 1;
  } else if ((localB->q == 1) && (localB->q1 == 4)) {
    /* '<S9>:1:79' */
    /*  */
    /* '<S9>:1:80' */
    localB->y_h = 0.4;

    /* '<S9>:1:81' */
    localB->y1 = 1;
  } else if ((localB->q == 1) && (localB->q1 == 2)) {
    /* '<S9>:1:82' */
    /* '<S9>:1:83' */
    localB->y_h = -0.4;

    /* '<S9>:1:84' */
    localB->y1 = 1;
  } else if ((localB->q == 1) && (localB->q1 == 3)) {
    /* '<S9>:1:85' */
    /* '<S9>:1:86' */
    localB->y_h = -1.0;

    /* '<S9>:1:87' */
    localB->y1 = 1;
  } else if (localB->q == localB->q1) {
    /* '<S9>:1:88' */
    /* '<S9>:1:89' */
    localB->y1 = 0;

    /* '<S9>:1:90' */
    localB->y_h = 0.0;
  } else if (localB->b_a == 90.0F) {
    /* '<S9>:1:92' */
    /* '<S9>:1:93' */
    localB->y_h = 0.0;

    /* '<S9>:1:94' */
    localB->y1 = 1;
  } else if (localB->b_a == 180.0F) {
    /* '<S9>:1:95' */
    /* '<S9>:1:96' */
    localB->y_h = 0.0;

    /* '<S9>:1:97' */
    localB->y1 = 1;
  } else if (localB->b_a == 270.0F) {
    /* '<S9>:1:98' */
    /* '<S9>:1:99' */
    localB->y_h = 0.0;

    /* '<S9>:1:100' */
    localB->y1 = 1;
  } else if (localB->b_a == 270.0F) {
    /* '<S9>:1:101' */
    /* '<S9>:1:102' */
    localB->y_h = 0.0;

    /* '<S9>:1:103' */
    localB->y1 = 1;

    /* elseif(q==q1 & dif_thera <79 & dif_thera>=69) */
    /*     y=0.8 */
    /* elseif(q==q1 & dif_thera <69 & dif_thera>=59) */
    /*     y=0.7 */
    /* elseif(q==q1 & dif_thera <59 & dif_thera>=49) */
    /*     y=0.6 */
    /* elseif(q==q1 & dif_thera <49 & dif_thera>=39) */
    /*     y=0.5 */
    /* elseif(q==q1 & dif_thera <39 & dif_thera>=29) */
    /*     y=0.4 */
    /* elseif(q==q1 & dif_thera <29 & dif_thera>=19) */
    /*     y=0.3 */
    /* elseif(q==q1 & dif_thera <19 & dif_thera>=9) */
    /*    y=0.2 */
    /* elseif(q==q1 & dif_thera <9 & dif_thera >=0) */
    /*    y=0 */
    /*  */
    /* elseif(q==q1 & dif_thera <-89 & dif_thera>=-79) */
    /*     y=-0.9 */
    /* elseif(q==q1 & dif_thera <-79 & dif_thera>=-69) */
    /*     y=-0.8 */
    /* elseif(q==q1 & dif_thera <-69 & dif_thera>=-59) */
    /*     y=-0.7 */
    /* elseif(q==q1 & dif_thera <-59 & dif_thera>=-49) */
    /*     y=-0.6 */
    /* elseif(q==q1 & dif_thera <-49 & dif_thera>=-39) */
    /*     y=-0.5 */
    /* elseif(q==q1 & dif_thera <-39 & dif_thera>=-29) */
    /*     y=-0.4 */
    /* elseif(q==q1 & dif_thera <-29 & dif_thera>=-19) */
    /*     y=-0.3 */
    /* elseif(q==q1 & dif_thera <-19 & dif_thera>=-9) */
    /*     y=-0.2 */
    /* elseif(q==q1 & dif_thera <-9 & dif_thera > 0) */
    /*     y=-0 */
  } else {
    /* '<S9>:1:140' */
    localB->y_h = 0.0;

    /* '<S9>:1:141' */
    localB->y1 = 1;
  }

  /* dif_thera=thera_new2-yaw; */
  /* if(vector_a_y>=0 && vector_a_x >=0) */
  /*     thera_new1=abs(thera_new1) */
  /* elseif(vector_a_y>=0 && vector_a_x <=0) */
  /*     thera_new1=thera_new1+90 */
  /*     elseif(vector_a_y<=0 && vector_a_x <=0) */
  /*     thera_new1=thera_new1+180 */
  /*     elseif(vector_a_y<=0 && vector_a_x >=0) */
  /*     thera_new1=thera_new1+270 */
  /* end */
  /* dif_thera=(thera_new1-yaw)+360 */
  /* if(dif_thera>=360) */
  /*     dif_thera=dif_thera-360 */
  /* end */
  /* '<S9>:1:166' */
  localB->pn[0] = vector_a1_idx_1 * 0.0F - 0.0F * vector_b1_idx_1;
  localB->pn[1] = 0.0F * vector_b1_idx_0 - localB->vector_a1_idx_0 * 0.0F;
  localB->pn[2] = localB->vector_a1_idx_0 * vector_b1_idx_1 - vector_a1_idx_1 *
    vector_b1_idx_0;

  /* '<S9>:1:168' */
  localB->positionx = position[(int32_T)*rty_waypoint - 1];

  /* '<S9>:1:169' */
  localB->positiony = position[(int32_T)*rty_waypoint + 1];

  /* if((latitutdeold-latitutde)==0 && (longitudeold-longitude)==0 ) */
  /* yaw_pwm=single(180) */
  /* elseif(pn(1,3)>0) */
  /*  yaw_pwm=-(single(thera)) */
  /* else */
  /* yaw_pwm=single(thera) */
  /* end */
  if (((real_T)position[(int32_T)*rty_waypoint - 1] > (real32_T)fabs
       (*rty_lat_out)) && ((real_T)position[(int32_T)*rty_waypoint + 1] <
       (real32_T)fabs(*rty_long_out))) {
    /* '<S9>:1:179' */
    /* '<S9>:1:180' */
    localB->Quadrant = 1.0;
  } else if (((real_T)position[(int32_T)*rty_waypoint - 1] > (real32_T)fabs
              (*rty_lat_out)) && ((real_T)position[(int32_T)*rty_waypoint + 1] >
              (real32_T)fabs(*rty_long_out))) {
    /* '<S9>:1:181' */
    /* '<S9>:1:182' */
    localB->Quadrant = 2.0;
  } else if (((real_T)position[(int32_T)*rty_waypoint - 1] < (real32_T)fabs
              (*rty_lat_out)) && ((real_T)position[(int32_T)*rty_waypoint + 1] >
              (real32_T)fabs(*rty_long_out))) {
    /* '<S9>:1:183' */
    /* '<S9>:1:184' */
    localB->Quadrant = 3.0;
  } else if (((real_T)position[(int32_T)*rty_waypoint - 1] < (real32_T)fabs
              (*rty_lat_out)) && ((real_T)position[(int32_T)*rty_waypoint + 1] <
              (real32_T)fabs(*rty_long_out))) {
    /* '<S9>:1:185' */
    /* '<S9>:1:186' */
    localB->Quadrant = 4.0;
  } else {
    /* '<S9>:1:188' */
    localB->Quadrant = 0.0;
  }

  if (localB->a < 2.0F) {
    /* '<S9>:1:190' */
    /* '<S9>:1:191' */
    localB->arrival = 1;
  } else {
    /* '<S9>:1:193' */
    localB->arrival = 0;
  }

  /* && distance_a > 0.002 */
  /* if(x == 3 && distance_a < 0.08)  */
  /*  reset=round(-3) */
  /* else */
  /*  reset=round(0) */
  /* end */
  rtb_thera_new2 = localB->b_a;
  *rty_q = localB->q;
  *rty_q1 = localB->q1;
  *rty_distance = localB->a;
  rtb_vector_a_y = u0;
  rtb_vector_a_x = localB->rtb_Switch1_idx_1;

  /* MATLAB Function: '<S3>/MATLAB Function10' */
  /* MATLAB Function 'AttitudeControl/MATLAB Function10': '<S11>:1' */
  if ((localB->dif_thera < 89.0F) && (localB->dif_thera >= 79.0F)) {
    /* '<S11>:1:3' */
    /* '<S11>:1:4' */
    localB->y_f = 0.9;
  } else if ((localB->dif_thera < 79.0F) && (localB->dif_thera >= 69.0F)) {
    /* '<S11>:1:5' */
    /* '<S11>:1:6' */
    localB->y_f = 0.8;
  } else if ((localB->dif_thera < 69.0F) && (localB->dif_thera >= 59.0F)) {
    /* '<S11>:1:7' */
    /* '<S11>:1:8' */
    localB->y_f = 0.7;
  } else if ((localB->dif_thera < 59.0F) && (localB->dif_thera >= 49.0F)) {
    /* '<S11>:1:9' */
    /* '<S11>:1:10' */
    localB->y_f = 0.6;
  } else if ((localB->dif_thera < 49.0F) && (localB->dif_thera >= 39.0F)) {
    /* '<S11>:1:11' */
    /* '<S11>:1:12' */
    localB->y_f = 0.5;
  } else if ((localB->dif_thera < 39.0F) && (localB->dif_thera >= 29.0F)) {
    /* '<S11>:1:13' */
    /* '<S11>:1:14' */
    localB->y_f = 0.4;
  } else if ((localB->dif_thera < 29.0F) && (localB->dif_thera >= 19.0F)) {
    /* '<S11>:1:15' */
    /* '<S11>:1:16' */
    localB->y_f = 0.3;
  } else if ((localB->dif_thera < 19.0F) && (localB->dif_thera >= 9.0F)) {
    /* '<S11>:1:17' */
    /* '<S11>:1:18' */
    localB->y_f = 0.2;
  } else if ((localB->dif_thera < 9.0F) && (localB->dif_thera >= 0.0F)) {
    /* '<S11>:1:19' */
    /* '<S11>:1:20' */
    localB->y_f = 0.0;
  } else if ((localB->dif_thera > -89.0F) && (localB->dif_thera <= -79.0F)) {
    /* '<S11>:1:22' */
    /*  */
    /* '<S11>:1:23' */
    localB->y_f = -0.9;
  } else if ((localB->dif_thera > -79.0F) && (localB->dif_thera <= -69.0F)) {
    /* '<S11>:1:24' */
    /* '<S11>:1:25' */
    localB->y_f = -0.8;
  } else if ((localB->dif_thera > -69.0F) && (localB->dif_thera <= -59.0F)) {
    /* '<S11>:1:26' */
    /* '<S11>:1:27' */
    localB->y_f = -0.7;
  } else if ((localB->dif_thera > -59.0F) && (localB->dif_thera <= -49.0F)) {
    /* '<S11>:1:28' */
    /* '<S11>:1:29' */
    localB->y_f = -0.6;
  } else if ((localB->dif_thera > -49.0F) && (localB->dif_thera <= -39.0F)) {
    /* '<S11>:1:30' */
    /* '<S11>:1:31' */
    localB->y_f = -0.5;
  } else if ((localB->dif_thera > -39.0F) && (localB->dif_thera <= -29.0F)) {
    /* '<S11>:1:32' */
    /* '<S11>:1:33' */
    localB->y_f = -0.4;
  } else if ((localB->dif_thera > -29.0F) && (localB->dif_thera <= -19.0F)) {
    /* '<S11>:1:34' */
    /* '<S11>:1:35' */
    localB->y_f = -0.3;
  } else if ((localB->dif_thera > -19.0F) && (localB->dif_thera <= -9.0F)) {
    /* '<S11>:1:36' */
    /* '<S11>:1:37' */
    localB->y_f = -0.2;
  } else if ((localB->dif_thera > -9.0F) && (localB->dif_thera < 0.0F)) {
    /* '<S11>:1:38' */
    /* '<S11>:1:39' */
    localB->y_f = -0.0;
  } else {
    /* '<S11>:1:41' */
    localB->y_f = 0.0;
  }

  /* End of MATLAB Function: '<S3>/MATLAB Function10' */

  /* Switch: '<S3>/Switch' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion13'
   *  DataTypeConversion: '<S3>/Data Type Conversion14'
   */
  if (localB->y1 > 0.0) {
    *rty_y_out = (real32_T)localB->y_h;
  } else {
    *rty_y_out = (real32_T)localB->y_f;
  }

  /* End of Switch: '<S3>/Switch' */
  if (rtmIsSampleHit(1, 0)) {
    /* DataTypeConversion: '<S3>/Data Type Conversion11' incorporates:
     *  UnitDelay: '<S3>/Unit Delay4'
     */
    localB->DataTypeConversion11 = (real32_T)localDW->UnitDelay4_DSTATE;
  }

  /* Fcn: '<S4>/Fcn2' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion2'
   */
  u0 = ((real32_T)*rtu_ch1 - 1500.0F) / 400.0F;

  /* Saturate: '<S4>/Saturation9' */
  if (u0 > 1.0F) {
    rtb_Saturation9 = 1.0F;
  } else if (u0 < (-1.0F)) {
    rtb_Saturation9 = (-1.0F);
  } else {
    rtb_Saturation9 = u0;
  }

  /* End of Saturate: '<S4>/Saturation9' */

  /* MATLAB Function: '<S3>/MATLAB Function3' */
  px4demo_attitud_MATLABFunction2(rtb_Saturation9, &localB->sf_MATLABFunction3);

  /* Switch: '<Root>/Switch1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Delay: '<Root>/Delay1'
   */
  if (localDW->Delay1_DSTATE) {
    /* DataTypeConversion: '<S3>/Data Type Conversion4' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    rtb_DataTypeConversion4_m = 0.0F;
    localB->rtb_Switch1_idx_1 = 0.0F;
  } else {
    /* DataTypeConversion: '<S3>/Data Type Conversion4' */
    rtb_DataTypeConversion4_m = *rtu_roll;
    localB->rtb_Switch1_idx_1 = *rtu_pitch;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* MATLAB Function: '<S3>/MATLAB Function4' */
  px4demo_attitud_MATLABFunction1(rtb_DataTypeConversion4_m,
    &localB->sf_MATLABFunction4);

  /* Sum: '<S3>/Sum1' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion2'
   *  Gain: '<S3>/Gain2'
   *  Gain: '<S3>/Gain4'
   */
  localB->Sum1 = (1.0F * localB->sf_MATLABFunction3.y -
                  localB->sf_MATLABFunction4.y) + 1.0F * *rty_y_out;
  if (rtmIsSampleHit(1, 0)) {
    /* UnitDelay: '<S3>/Unit Delay' */
    localB->UnitDelay = localDW->UnitDelay_DSTATE;

    /* Sum: '<S21>/Sum' incorporates:
     *  DiscreteIntegrator: '<S21>/Integrator'
     *  Gain: '<S21>/Proportional Gain'
     */
    localB->Sum = 1.0 * localB->UnitDelay + localDW->Integrator_DSTATE;

    /* Saturate: '<S21>/Saturate' */
    if (localB->Sum > 1.0) {
      localB->Saturate = 1.0;
    } else if (localB->Sum < (-1.0)) {
      localB->Saturate = (-1.0);
    } else {
      localB->Saturate = localB->Sum;
    }

    /* End of Saturate: '<S21>/Saturate' */

    /* DataTypeConversion: '<S3>/Data Type Conversion6' */
    *rty_rollout = (real32_T)localB->Saturate;

    /* Sum: '<S21>/SumI1' incorporates:
     *  Gain: '<S21>/Integral Gain'
     *  Gain: '<S21>/Kb'
     *  Sum: '<S21>/SumI2'
     */
    localB->SumI1 = (localB->Saturate - localB->Sum) * 1.0 + 0.05 *
      localB->UnitDelay;
  }

  /* Fcn: '<S4>/Fcn5' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion3'
   */
  u0 = ((real32_T)*rtu_ch2 - 1500.0F) / 400.0F;

  /* Saturate: '<S4>/Saturation8' */
  if (u0 > 1.0F) {
    rtb_Saturation8 = 1.0F;
  } else if (u0 < (-1.0F)) {
    rtb_Saturation8 = (-1.0F);
  } else {
    rtb_Saturation8 = u0;
  }

  /* End of Saturate: '<S4>/Saturation8' */

  /* MATLAB Function: '<S3>/MATLAB Function2' */
  px4demo_attitud_MATLABFunction2(rtb_Saturation8, &localB->sf_MATLABFunction2);

  /* Delay: '<Root>/Delay' */
  *rty_ARM_Control = localDW->Delay_DSTATE;

  /* Switch: '<Root>/Switch2' incorporates:
   *  Delay: '<Root>/Delay2'
   *  Delay: '<Root>/Delay3'
   */
  if (*rty_ARM_Control) {
    localB->Switch2 = localDW->Delay2_DSTATE;
  } else {
    localB->Switch2 = localDW->Delay3_DSTATE;
  }

  /* End of Switch: '<Root>/Switch2' */

  /* MATLAB Function: '<S3>/MATLAB Function9' incorporates:
   *  Sum: '<Root>/Sum'
   */
  /* MATLAB Function 'AttitudeControl/MATLAB Function9': '<S19>:1' */
  /* '<S19>:1:3' */
  localB->y_n = rt_roundf_snf(*rtu_attin - localB->Switch2);

  /* DataTypeConversion: '<S3>/Data Type Conversion5' */
  rtb_DataTypeConversion5 = localB->rtb_Switch1_idx_1;
  if (rtmIsSampleHit(1, 0)) {
    /* UnitDelay: '<S3>/Unit Delay1' */
    localB->UnitDelay1 = localDW->UnitDelay1_DSTATE;

    /* Sum: '<S20>/Sum' incorporates:
     *  DiscreteIntegrator: '<S20>/Integrator'
     *  Gain: '<S20>/Proportional Gain'
     */
    localB->Sum_a = 1.3 * localB->UnitDelay1 + localDW->Integrator_DSTATE_n;

    /* Saturate: '<S20>/Saturate' */
    if (localB->Sum_a > 1.0) {
      localB->Saturate_p = 1.0;
    } else if (localB->Sum_a < (-1.0)) {
      localB->Saturate_p = (-1.0);
    } else {
      localB->Saturate_p = localB->Sum_a;
    }

    /* End of Saturate: '<S20>/Saturate' */

    /* DataTypeConversion: '<S3>/Data Type Conversion7' */
    *rty_pitchout = (real32_T)localB->Saturate_p;
  }

  /* MATLAB Function: '<S3>/MATLAB Function1' */
  px4demo_attitud_MATLABFunction1(rtb_DataTypeConversion5,
    &localB->sf_MATLABFunction1);

  /* MATLAB Function: '<S3>/MATLAB Function8' incorporates:
   *  Constant: '<S3>/Constant'
   *  DataTypeConversion: '<S3>/Data Type Conversion17'
   */
  /* MATLAB Function 'AttitudeControl/MATLAB Function8': '<S18>:1' */
  /* '<S18>:1:2' */
  /* '<S18>:1:3' */
  if (localB->y_n <= 3.5 - 2.0) {
    /* '<S18>:1:4' */
    /* '<S18>:1:5' */
    localB->y = 1;
  } else if (localB->y_n >= 3.5 + 2.0) {
    /* '<S18>:1:6' */
    /* '<S18>:1:7' */
    localB->y = -1;
  } else {
    /* '<S18>:1:9' */
    localB->y = 0;
  }

  /* End of MATLAB Function: '<S3>/MATLAB Function8' */
  if (rtmIsSampleHit(1, 0)) {
    /* Sum: '<S20>/SumI1' incorporates:
     *  Gain: '<S20>/Integral Gain'
     *  Gain: '<S20>/Kb'
     *  Sum: '<S20>/SumI2'
     */
    localB->SumI1_m = (localB->Saturate_p - localB->Sum_a) * 1.0 + 0.05 *
      localB->UnitDelay1;

    /* Gain: '<Root>/Gain1' */
    localB->Gain1_k = (-1.0F) * *rty_rollout;

    /* Gain: '<Root>/Gain2' */
    *rty_attout = (-1.0F) * *rty_pitchout;

    /* Gain: '<Root>/Gain5' */
    localB->Gain5 = 1.0F * localB->DataTypeConversion11;

    /* Gain: '<Root>/Gain6' */
    localB->Gain6 = 1.0F * rtb_Saturation7;
  }

  /* Gain: '<Root>/Gain3' */
  rtb_Gain3_a = (-1.0F) * rtb_Saturation9;

  /* Gain: '<Root>/Gain4' */
  rtb_Gain4_g = (-1.0F) * rtb_Saturation8;

  /* Fcn: '<S4>/Fcn6' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion5'
   */
  u0 = ((real32_T)*rtu_ch3 - 1100.0F) / 800.0F;

  /* Saturate: '<S4>/Saturation10' */
  if (u0 > 1.0F) {
    rtb_Saturation10 = 1.0F;
  } else if (u0 < 0.0F) {
    rtb_Saturation10 = 0.0F;
  } else {
    rtb_Saturation10 = u0;
  }

  /* End of Saturate: '<S4>/Saturation10' */

  /* MATLAB Function: '<Root>/pwm_out1' */
  px4demo_attitude_contr_pwm_out1(localB->Gain1_k, *rty_attout, localB->Gain5,
    rtb_Saturation10, &localB->sf_pwm_out1);

  /* MATLAB Function: '<Root>/pwm_out2' */
  px4demo_attitude_contr_pwm_out1(rtb_Gain3_a, rtb_Gain4_g, localB->Gain6,
    rtb_Saturation10, &localB->sf_pwm_out2);

  /* Switch: '<Root>/Switch' incorporates:
   *  Delay: '<Root>/Delay1'
   *  Saturate: '<Root>/Output_Limits1'
   */
  if (localDW->Delay1_DSTATE) {
    /* Saturate: '<Root>/Output_Limits2' */
    if (localB->sf_pwm_out2.M1 > ((uint16_T)2000U)) {
      rty_PWM[0] = ((uint16_T)2000U);
    } else if (localB->sf_pwm_out2.M1 < ((uint16_T)1000U)) {
      rty_PWM[0] = ((uint16_T)1000U);
    } else {
      rty_PWM[0] = localB->sf_pwm_out2.M1;
    }

    if (localB->sf_pwm_out2.M2 > ((uint16_T)2000U)) {
      rty_PWM[1] = ((uint16_T)2000U);
    } else if (localB->sf_pwm_out2.M2 < ((uint16_T)1000U)) {
      rty_PWM[1] = ((uint16_T)1000U);
    } else {
      rty_PWM[1] = localB->sf_pwm_out2.M2;
    }

    if (localB->sf_pwm_out2.M3 > ((uint16_T)2000U)) {
      rty_PWM[2] = ((uint16_T)2000U);
    } else if (localB->sf_pwm_out2.M3 < ((uint16_T)1000U)) {
      rty_PWM[2] = ((uint16_T)1000U);
    } else {
      rty_PWM[2] = localB->sf_pwm_out2.M3;
    }

    if (localB->sf_pwm_out2.M4 > ((uint16_T)2000U)) {
      rty_PWM[3] = ((uint16_T)2000U);
    } else if (localB->sf_pwm_out2.M4 < ((uint16_T)1000U)) {
      rty_PWM[3] = ((uint16_T)1000U);
    } else {
      rty_PWM[3] = localB->sf_pwm_out2.M4;
    }

    /* End of Saturate: '<Root>/Output_Limits2' */
  } else {
    if (localB->sf_pwm_out1.M1 > ((uint16_T)2000U)) {
      /* Saturate: '<Root>/Output_Limits1' */
      rty_PWM[0] = ((uint16_T)2000U);
    } else if (localB->sf_pwm_out1.M1 < ((uint16_T)1000U)) {
      /* Saturate: '<Root>/Output_Limits1' */
      rty_PWM[0] = ((uint16_T)1000U);
    } else {
      rty_PWM[0] = localB->sf_pwm_out1.M1;
    }

    /* Saturate: '<Root>/Output_Limits1' */
    if (localB->sf_pwm_out1.M2 > ((uint16_T)2000U)) {
      rty_PWM[1] = ((uint16_T)2000U);
    } else if (localB->sf_pwm_out1.M2 < ((uint16_T)1000U)) {
      rty_PWM[1] = ((uint16_T)1000U);
    } else {
      rty_PWM[1] = localB->sf_pwm_out1.M2;
    }

    if (localB->sf_pwm_out1.M3 > ((uint16_T)2000U)) {
      rty_PWM[2] = ((uint16_T)2000U);
    } else if (localB->sf_pwm_out1.M3 < ((uint16_T)1000U)) {
      rty_PWM[2] = ((uint16_T)1000U);
    } else {
      rty_PWM[2] = localB->sf_pwm_out1.M3;
    }

    if (localB->sf_pwm_out1.M4 > ((uint16_T)2000U)) {
      rty_PWM[3] = ((uint16_T)2000U);
    } else if (localB->sf_pwm_out1.M4 < ((uint16_T)1000U)) {
      rty_PWM[3] = ((uint16_T)1000U);
    } else {
      rty_PWM[3] = localB->sf_pwm_out1.M4;
    }
  }

  /* End of Switch: '<Root>/Switch' */
  if (rtmIsSampleHit(1, 0)) {
    /* Update for UnitDelay: '<S3>/Unit Delay2' */
    localDW->UnitDelay2_DSTATE = localB->y_j;

    /* Update for UnitDelay: '<S3>/Unit Delay3' incorporates:
     *  MATLAB Function: '<S3>/MATLAB Function'
     */
    localDW->UnitDelay3_DSTATE = localB->arrival;

    /* Update for UnitDelay: '<S3>/Unit Delay4' incorporates:
     *  Sum: '<S3>/Sum4'
     */
    localDW->UnitDelay4_DSTATE = localB->Gain1 - *rty_y_out;

    /* Update for UnitDelay: '<S3>/Unit Delay' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion3'
     */
    localDW->UnitDelay_DSTATE = localB->Sum1;

    /* Update for DiscreteIntegrator: '<S21>/Integrator' */
    localDW->Integrator_DSTATE += 0.1 * localB->SumI1;
  }

  /* Update for Delay: '<Root>/Delay1' incorporates:
   *  Constant: '<S8>/Constant'
   *  RelationalOperator: '<S8>/Compare'
   */
  localDW->Delay1_DSTATE = (*rtu_ch6 >= ((uint16_T)1300U));

  /* Update for Delay: '<Root>/Delay2' */
  localDW->Delay2_DSTATE = localB->Switch2;

  /* Update for Delay: '<Root>/Delay' incorporates:
   *  Constant: '<S7>/Constant'
   *  RelationalOperator: '<S7>/Compare'
   */
  localDW->Delay_DSTATE = (*rtu_ch5 >= ((uint16_T)1500U));

  /* Update for Delay: '<Root>/Delay3' */
  localDW->Delay3_DSTATE = *rtu_attin;
  if (rtmIsSampleHit(1, 0)) {
    /* Update for UnitDelay: '<S3>/Unit Delay1' incorporates:
     *  DataTypeConversion: '<S3>/Data Type Conversion1'
     *  Gain: '<S3>/Gain'
     *  Gain: '<S3>/Gain5'
     *  Sum: '<S3>/Sum'
     */
    localDW->UnitDelay1_DSTATE = ((real_T)(1.0F * localB->sf_MATLABFunction2.y)
      - localB->sf_MATLABFunction1.y) + 0.25 * (real_T)localB->y;

    /* Update for DiscreteIntegrator: '<S20>/Integrator' */
    localDW->Integrator_DSTATE_n += 0.1 * localB->SumI1_m;
  }
}

/* Model initialize function */
void px4demo_attitude_con_initialize(const char_T **rt_errorStatus, const
  rtTimingBridge *timingBridge, int_T mdlref_TID0, int_T mdlref_TID1, int_T
  mdlref_TID2, RT_MODEL_px4demo_attitude_con_T *const
  px4demo_attitude_control2018_M, B_px4demo_attitude_control2_c_T *localB,
  DW_px4demo_attitude_control_f_T *localDW)
{
  /* Registration code */

  /* setup the global timing engine */
  px4demo_attitude_cont_GlobalTID[0] = mdlref_TID0;
  px4demo_attitude_cont_GlobalTID[1] = mdlref_TID1;
  px4demo_attitude_cont_GlobalTID[2] = mdlref_TID2;
  px4demo_attitude_con_TimingBrdg = timingBridge;

  /* initialize error status */
  rtmSetErrorStatusPointer(px4demo_attitude_control2018_M, rt_errorStatus);

  /* block I/O */
  (void) memset(((void *) localB), 0,
                sizeof(B_px4demo_attitude_control2_c_T));

  /* states (dwork) */
  (void) memset((void *)localDW, 0,
                sizeof(DW_px4demo_attitude_control_f_T));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
