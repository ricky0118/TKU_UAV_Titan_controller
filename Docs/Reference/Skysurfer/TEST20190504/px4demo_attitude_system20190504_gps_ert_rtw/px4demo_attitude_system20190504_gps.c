/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: px4demo_attitude_system20190504_gps.c
 *
 * Code generated for Simulink model 'px4demo_attitude_system20190504_gps'.
 *
 * Model version                  : 1.196
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Mar 13 20:43:33 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "px4demo_attitude_system20190504_gps.h"
#include "px4demo_attitude_system20190504_gps_private.h"
#define px4demo_attitude_system20_block (true)

const char *g_pwm_device = PWM_OUTPUT0_DEVICE_PATH;
int g_pwm_fd = -1;
bool g_pwm_enabled = false;
rtTimingBridge px4demo_attitude_sys_TimingBrdg;
const uint8_T px4demo_attitude_system20190504_gps_U8GND = 0U;/* uint8_T ground */

/* Block signals (auto storage) */
B_px4demo_attitude_system2019_T px4demo_attitude_system201905_B;

/* Block states (auto storage) */
DW_px4demo_attitude_system201_T px4demo_attitude_system20190_DW;

/* Real-time model */
RT_MODEL_px4demo_attitude_sys_T px4demo_attitude_system20190_M_;
RT_MODEL_px4demo_attitude_sys_T *const px4demo_attitude_system20190_M =
  &px4demo_attitude_system20190_M_;

/* Forward declaration for local functions */
static int8_T px4demo_attitude_syste_filedata(void);
static real_T px4demo_attitude_sy_fileManager(void);
static real_T px4demo_attitude_system20_fopen(void);
static void px4demo_attitude__fileManager_b(real_T varargin_1, FILE * *f,
  boolean_T *a);
static int32_T px4demo_attitude_sys_cfprintf_n(real_T fileID, const char
  * varargin_1);
static FILE * px4demo_attitud_fileManager_bxg(int8_T varargin_1);
static int32_T px4demo_attitude_fileManager_bx(real_T varargin_1);
static void px4demo_attitude_system2_fclose(real_T fileID);
static int32_T px4demo_attitude_syste_cfprintf(real_T fileID, int32_T varargin_1);
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (px4demo_attitude_system20190_M->Timing.TaskCounters.TID[1])++;
  if ((px4demo_attitude_system20190_M->Timing.TaskCounters.TID[1]) > 24) {/* Sample time: [0.1s, 0.0s] */
    px4demo_attitude_system20190_M->Timing.TaskCounters.TID[1] = 0;
  }

  (px4demo_attitude_system20190_M->Timing.TaskCounters.TID[2])++;
  if ((px4demo_attitude_system20190_M->Timing.TaskCounters.TID[2]) > 74) {/* Sample time: [0.3s, 0.0s] */
    px4demo_attitude_system20190_M->Timing.TaskCounters.TID[2] = 0;
  }

  (px4demo_attitude_system20190_M->Timing.TaskCounters.TID[3])++;
  if ((px4demo_attitude_system20190_M->Timing.TaskCounters.TID[3]) > 124) {/* Sample time: [0.5s, 0.0s] */
    px4demo_attitude_system20190_M->Timing.TaskCounters.TID[3] = 0;
  }

  (px4demo_attitude_system20190_M->Timing.TaskCounters.TID[4])++;
  if ((px4demo_attitude_system20190_M->Timing.TaskCounters.TID[4]) > 4999) {/* Sample time: [20.0s, 0.0s] */
    px4demo_attitude_system20190_M->Timing.TaskCounters.TID[4] = 0;
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static int8_T px4demo_attitude_syste_filedata(void)
{
  int8_T f;
  boolean_T exitg1;
  f = 0;
  px4demo_attitude_system201905_B.k = 1;
  exitg1 = false;
  while ((!exitg1) && (px4demo_attitude_system201905_B.k < 21)) {
    if (px4demo_attitude_system20190_DW.eml_openfiles[px4demo_attitude_system201905_B.k
        - 1] == NULL) {
      f = px4demo_attitude_system201905_B.k;
      exitg1 = true;
    } else {
      px4demo_attitude_system201905_B.k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static real_T px4demo_attitude_sy_fileManager(void)
{
  FILE * filestar;
  static const char_T b[24] = { '/', 'f', 's', '/', 'm', 'i', 'c', 'r', 'o', 's',
    'd', '/', 'h', 'i', 's', 't', 'o', 'r', 'y', '.', 't', 'x', 't', '\x00' };

  px4demo_attitude_system201905_B.fileid = -1;
  px4demo_attitude_system201905_B.j = px4demo_attitude_syste_filedata();
  if (!(px4demo_attitude_system201905_B.j < 1)) {
    for (px4demo_attitude_system201905_B.i0 = 0;
         px4demo_attitude_system201905_B.i0 < 24;
         px4demo_attitude_system201905_B.i0++) {
      px4demo_attitude_system201905_B.b[px4demo_attitude_system201905_B.i0] =
        b[px4demo_attitude_system201905_B.i0];
    }

    px4demo_attitude_system201905_B.c[0] = 'a';
    px4demo_attitude_system201905_B.c[1] = 'b';
    px4demo_attitude_system201905_B.c[2] = '\x00';
    filestar = fopen(px4demo_attitude_system201905_B.b,
                     px4demo_attitude_system201905_B.c);
    if (filestar != NULL) {
      px4demo_attitude_system20190_DW.eml_openfiles[px4demo_attitude_system201905_B.j
        - 1] = filestar;
      px4demo_attitude_system20190_DW.eml_autoflush[px4demo_attitude_system201905_B.j
        - 1] = true;
      px4demo_attitude_system201905_B.i0 = px4demo_attitude_system201905_B.j + 2;
      if (px4demo_attitude_system201905_B.i0 > 127) {
        px4demo_attitude_system201905_B.i0 = 127;
      }

      px4demo_attitude_system201905_B.fileid = (int8_T)
        px4demo_attitude_system201905_B.i0;
    }
  }

  return px4demo_attitude_system201905_B.fileid;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static real_T px4demo_attitude_system20_fopen(void)
{
  return px4demo_attitude_sy_fileManager();
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void px4demo_attitude__fileManager_b(real_T varargin_1, FILE * *f,
  boolean_T *a)
{
  px4demo_attitude_system201905_B.fileid_cx = (int8_T)rt_roundd_snf(varargin_1);
  if ((px4demo_attitude_system201905_B.fileid_cx > 22) ||
      (px4demo_attitude_system201905_B.fileid_cx < 0) || (varargin_1 !=
       px4demo_attitude_system201905_B.fileid_cx)) {
    px4demo_attitude_system201905_B.fileid_cx = -1;
  }

  if (px4demo_attitude_system201905_B.fileid_cx >= 3) {
    px4demo_attitude_system201905_B.fileid_cx = (int8_T)
      (px4demo_attitude_system201905_B.fileid_cx - 2);
    *f =
      px4demo_attitude_system20190_DW.eml_openfiles[px4demo_attitude_system201905_B.fileid_cx
      - 1];
    *a =
      px4demo_attitude_system20190_DW.eml_autoflush[px4demo_attitude_system201905_B.fileid_cx
      - 1];
  } else if (px4demo_attitude_system201905_B.fileid_cx == 0) {
    *f = stdin;
    *a = true;
  } else if (px4demo_attitude_system201905_B.fileid_cx == 1) {
    *f = stdout;
    *a = true;
  } else if (px4demo_attitude_system201905_B.fileid_cx == 2) {
    *f = stderr;
    *a = true;
  } else {
    *f = NULL;
    *a = true;
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static int32_T px4demo_attitude_sys_cfprintf_n(real_T fileID, const char
  * varargin_1)
{
  int32_T nbytesint;
  FILE * b_NULL;
  FILE * filestar;
  static const char_T cfmt[4] = { '%', 's', '\x0a', '\x00' };

  b_NULL = NULL;
  nbytesint = 0;
  px4demo_attitude__fileManager_b(fileID, &filestar,
    &px4demo_attitude_system201905_B.autoflush_b);
  if (!(filestar == b_NULL)) {
    nbytesint = fprintf(filestar, cfmt, varargin_1);
    if (px4demo_attitude_system201905_B.autoflush_b) {
      fflush(filestar);
    }
  }

  return nbytesint;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static FILE * px4demo_attitud_fileManager_bxg(int8_T varargin_1)
{
  FILE * f;
  px4demo_attitude_system201905_B.fileid_k = varargin_1;
  if ((varargin_1 > 22) || (varargin_1 < 0)) {
    px4demo_attitude_system201905_B.fileid_k = -1;
  }

  if (px4demo_attitude_system201905_B.fileid_k >= 3) {
    f =
      px4demo_attitude_system20190_DW.eml_openfiles[px4demo_attitude_system201905_B.fileid_k
      - 3];
  } else if (px4demo_attitude_system201905_B.fileid_k == 0) {
    f = stdin;
  } else if (px4demo_attitude_system201905_B.fileid_k == 1) {
    f = stdout;
  } else if (px4demo_attitude_system201905_B.fileid_k == 2) {
    f = stderr;
  } else {
    f = NULL;
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static int32_T px4demo_attitude_fileManager_bx(real_T varargin_1)
{
  int32_T f;
  FILE * filestar;
  f = -1;
  px4demo_attitude_system201905_B.fileid_c = (int8_T)rt_roundd_snf(varargin_1);
  if ((px4demo_attitude_system201905_B.fileid_c > 22) ||
      (px4demo_attitude_system201905_B.fileid_c < 0) || (varargin_1 !=
       px4demo_attitude_system201905_B.fileid_c)) {
    px4demo_attitude_system201905_B.fileid_c = -1;
  }

  filestar = px4demo_attitud_fileManager_bxg
    (px4demo_attitude_system201905_B.fileid_c);
  if (!((filestar == NULL) || (px4demo_attitude_system201905_B.fileid_c < 3))) {
    px4demo_attitude_system201905_B.cst = fclose(filestar);
    if (px4demo_attitude_system201905_B.cst == 0) {
      f = 0;
      px4demo_attitude_system201905_B.fileid_c = (int8_T)
        (px4demo_attitude_system201905_B.fileid_c - 2);
      px4demo_attitude_system20190_DW.eml_openfiles[px4demo_attitude_system201905_B.fileid_c
        - 1] = NULL;
      px4demo_attitude_system20190_DW.eml_autoflush[px4demo_attitude_system201905_B.fileid_c
        - 1] = true;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void px4demo_attitude_system2_fclose(real_T fileID)
{
  px4demo_attitude_fileManager_bx(fileID);
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static int32_T px4demo_attitude_syste_cfprintf(real_T fileID, int32_T varargin_1)
{
  int32_T nbytesint;
  FILE * b_NULL;
  FILE * filestar;
  static const char_T cfmt[5] = { '%', 'l', 'd', '/', '\x00' };

  b_NULL = NULL;
  nbytesint = 0;
  px4demo_attitude__fileManager_b(fileID, &filestar,
    &px4demo_attitude_system201905_B.autoflush);
  if (!(filestar == b_NULL)) {
    nbytesint = fprintf(filestar, cfmt, varargin_1);
    if (px4demo_attitude_system201905_B.autoflush) {
      fflush(filestar);
    }
  }

  return nbytesint;
}

/* Model step function */
void px4demo_attitude_system20190504_gps_step(void)
{
  /* S-Function (sfun_px4_vehicle_attitude): '<Root>/vehicle_attitude' */
  {
    bool updated;
    orb_check(px4demo_attitude_system20190_DW.vehicle_attitude_vehicle_attitu.fd,
              &updated);
    if (updated) {
      struct vehicle_attitude_s raw;
      orb_copy(ORB_ID(vehicle_attitude),
               px4demo_attitude_system20190_DW.vehicle_attitude_vehicle_attitu.fd,
               &raw);

      /* read out the Roll value */
      px4demo_attitude_system201905_B.phi = raw.roll;// phi

      /* read out the Pitch value */
      px4demo_attitude_system201905_B.theta = raw.pitch;// theta

      /* read out the Yaw value */
      px4demo_attitude_system201905_B.vehicle_attitude_o3 = raw.yaw;// psi
    }
  }

  /* Gain: '<Root>/Gain3' */
  px4demo_attitude_system201905_B.Gain3 = 57.2957802F *
    px4demo_attitude_system201905_B.phi;

  /* Gain: '<Root>/Gain2' */
  px4demo_attitude_system201905_B.Gain2 = 57.2957802F *
    px4demo_attitude_system201905_B.theta;

  /* Gain: '<Root>/Gain1' */
  px4demo_attitude_system201905_B.Gain1 = 57.2957802F *
    px4demo_attitude_system201905_B.vehicle_attitude_o3;

  /* MATLAB Function: '<Root>/MATLAB Function7' */
  /* MATLAB Function 'MATLAB Function7': '<S2>:1' */
  if (px4demo_attitude_system201905_B.Gain1 <= 0.0F) {
    /* '<S2>:1:2' */
    /* '<S2>:1:3' */
    px4demo_attitude_system201905_B.Gain1 += 360.0F;
  } else {
    /* '<S2>:1:5' */
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function7' */

  /* S-Function (sfun_px4_gps): '<Root>/vehicle_gps' */
  {
    int poll_ret;
    bool updated;
    orb_check(px4demo_attitude_system20190_DW.vehicle_gps_gps_fd.fd, &updated);
    if (updated) {
      /* obtained GPS data */
      struct vehicle_gps_position_s raw;

      /* copy sensors raw data into local buffer */
      orb_copy(ORB_ID(vehicle_gps_position),
               px4demo_attitude_system20190_DW.vehicle_gps_gps_fd.fd, &raw);

      /* read out Lat/Lon Values */
      px4demo_attitude_system201905_B.vehicle_gps_o1 = raw.lat;
      px4demo_attitude_system201905_B.vehicle_gps_o2 = raw.lon;

      /* 0-1: no fix, 2: 2D fix, 3: 3D fix. Some applications will not use the value of this field unless it is at least two, so always correctly fill in the fix.   */
      px4demo_attitude_system201905_B.vehicle_gps_o3 = raw.fix_type;
    }
  }

  /* DataTypeConversion: '<Root>/Data Type Conversion13' */
  px4demo_attitude_system201905_B.f0 = (real32_T)floor
    (px4demo_attitude_system201905_B.Gain3);
  if (rtIsNaNF(px4demo_attitude_system201905_B.f0) || rtIsInfF
      (px4demo_attitude_system201905_B.f0)) {
    px4demo_attitude_system201905_B.f0 = 0.0F;
  } else {
    px4demo_attitude_system201905_B.f0 = (real32_T)fmod
      (px4demo_attitude_system201905_B.f0, 4.2949673E+9F);
  }

  /* SignalConversion: '<S1>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion13'
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  px4demo_attitude_system201905_B.TmpSignalConversionAtSFunctionI[0] =
    px4demo_attitude_system201905_B.f0 < 0.0F ? -(int32_T)(uint32_T)
    -px4demo_attitude_system201905_B.f0 : (int32_T)(uint32_T)
    px4demo_attitude_system201905_B.f0;

  /* DataTypeConversion: '<Root>/Data Type Conversion11' */
  px4demo_attitude_system201905_B.f0 = (real32_T)floor
    (px4demo_attitude_system201905_B.Gain2);
  if (rtIsNaNF(px4demo_attitude_system201905_B.f0) || rtIsInfF
      (px4demo_attitude_system201905_B.f0)) {
    px4demo_attitude_system201905_B.f0 = 0.0F;
  } else {
    px4demo_attitude_system201905_B.f0 = (real32_T)fmod
      (px4demo_attitude_system201905_B.f0, 4.2949673E+9F);
  }

  /* SignalConversion: '<S1>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion11'
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  px4demo_attitude_system201905_B.TmpSignalConversionAtSFunctionI[1] =
    px4demo_attitude_system201905_B.f0 < 0.0F ? -(int32_T)(uint32_T)
    -px4demo_attitude_system201905_B.f0 : (int32_T)(uint32_T)
    px4demo_attitude_system201905_B.f0;

  /* DataTypeConversion: '<Root>/Data Type Conversion10' */
  px4demo_attitude_system201905_B.f0 = (real32_T)floor
    (px4demo_attitude_system201905_B.Gain1);
  if (rtIsNaNF(px4demo_attitude_system201905_B.f0) || rtIsInfF
      (px4demo_attitude_system201905_B.f0)) {
    px4demo_attitude_system201905_B.f0 = 0.0F;
  } else {
    px4demo_attitude_system201905_B.f0 = (real32_T)fmod
      (px4demo_attitude_system201905_B.f0, 4.2949673E+9F);
  }

  /* SignalConversion: '<S1>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion10'
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  px4demo_attitude_system201905_B.TmpSignalConversionAtSFunctionI[2] =
    px4demo_attitude_system201905_B.f0 < 0.0F ? -(int32_T)(uint32_T)
    -px4demo_attitude_system201905_B.f0 : (int32_T)(uint32_T)
    px4demo_attitude_system201905_B.f0;
  px4demo_attitude_system201905_B.TmpSignalConversionAtSFunctionI[3] =
    px4demo_attitude_system201905_B.vehicle_gps_o2;
  px4demo_attitude_system201905_B.TmpSignalConversionAtSFunctionI[4] =
    px4demo_attitude_system201905_B.vehicle_gps_o1;

  /* MATLAB Function: '<Root>/MATLAB Function' */
  /* MATLAB Function 'MATLAB Function': '<S1>:1' */
  /* '<S1>:1:2' */
  px4demo_attitude_system201905_B.file = px4demo_attitude_system20_fopen();

  /* '<S1>:1:3' */
  for (px4demo_attitude_system201905_B.i = 0; px4demo_attitude_system201905_B.i <
       5; px4demo_attitude_system201905_B.i++) {
    /* '<S1>:1:3' */
    /* '<S1>:1:4' */
    px4demo_attitude_syste_cfprintf(px4demo_attitude_system201905_B.file,
      px4demo_attitude_system201905_B.TmpSignalConversionAtSFunctionI[px4demo_attitude_system201905_B.i]);
  }

  /* '<S1>:1:6' */
  px4demo_attitude_sys_cfprintf_n(px4demo_attitude_system201905_B.file, " ");

  /* '<S1>:1:7' */
  px4demo_attitude_system2_fclose(px4demo_attitude_system201905_B.file);

  /* S-Function (sfun_px4_input_rc): '<Root>/input_rc' */
  {
    bool updated;
    orb_check(px4demo_attitude_system20190_DW.input_rc_input_rc_fd.fd, &updated);
    if (updated) {
      struct rc_input_values pwm_inputs;

      /* copy input_rc raw data into local buffer (uint16)*/
      orb_copy(ORB_ID(input_rc),
               px4demo_attitude_system20190_DW.input_rc_input_rc_fd.fd,
               &pwm_inputs);
      px4demo_attitude_system201905_B.input_rc_o1 = pwm_inputs.values[0];
      px4demo_attitude_system201905_B.input_rc_o2 = pwm_inputs.values[1];
      px4demo_attitude_system201905_B.input_rc_o3 = pwm_inputs.values[2];
      px4demo_attitude_system201905_B.input_rc_o4 = pwm_inputs.values[3];
      px4demo_attitude_system201905_B.input_rc_o5 = pwm_inputs.values[4];
      px4demo_attitude_system201905_B.input_rc_o6 = pwm_inputs.values[5];
    }
  }

  /* S-Function (sfun_px4_sensor_combined): '<Root>/sensor_combined' */
  {
    bool updated;
    orb_check(px4demo_attitude_system20190_DW.sensor_combined_sensor_fd.fd,
              &updated);
    if (updated) {
      /* obtained data sensor combined */
      struct sensor_combined_s raw;

      /* copy sensors raw data into local buffer */
      orb_copy(ORB_ID(sensor_combined),
               px4demo_attitude_system20190_DW.sensor_combined_sensor_fd.fd,
               &raw);

      /* read out the gyro X,Y,Z */
      px4demo_attitude_system201905_B.sensor_combined_o1 = (float)
        raw.gyro_rad_s[0];
      px4demo_attitude_system201905_B.sensor_combined_o2 = (float)
        raw.gyro_rad_s[1];
      px4demo_attitude_system201905_B.sensor_combined_o3 = (float)
        raw.gyro_rad_s[2];

      /* read out the baro altimeter */
      px4demo_attitude_system201905_B.sensor_combined_o4 = (float)
        raw.baro_alt_meter[0];
    }
  }

  /* ModelReference: '<Root>/ControlSubsystem' */
  px4demo_attitude_control2019031(&px4demo_attitude_system201905_B.phi,
    &px4demo_attitude_system201905_B.theta,
    &px4demo_attitude_system201905_B.input_rc_o1,
    &px4demo_attitude_system201905_B.input_rc_o2,
    &px4demo_attitude_system201905_B.input_rc_o3,
    &px4demo_attitude_system201905_B.input_rc_o4,
    &px4demo_attitude_system201905_B.input_rc_o5,
    &px4demo_attitude_system201905_B.input_rc_o6,
    &px4demo_attitude_system201905_B.sensor_combined_o1,
    &px4demo_attitude_system201905_B.sensor_combined_o2,
    &px4demo_attitude_system201905_B.vehicle_attitude_o3,
    &px4demo_attitude_system201905_B.vehicle_gps_o1,
    &px4demo_attitude_system201905_B.vehicle_gps_o2,
    &px4demo_attitude_system201905_B.sensor_combined_o4,
    &px4demo_attitude_system201905_B.ControlSubsystem_o1[0],
    &px4demo_attitude_system201905_B.ControlSubsystem_o2,
    &px4demo_attitude_system201905_B.ControlSubsystem_o3,
    &px4demo_attitude_system201905_B.ControlSubsystem_o4,
    &px4demo_attitude_system201905_B.ControlSubsystem_o5,
    &px4demo_attitude_system201905_B.ControlSubsystem_o6,
    &px4demo_attitude_system201905_B.ControlSubsystem_o7,
    &px4demo_attitude_system201905_B.ControlSubsystem_o8,
    &px4demo_attitude_system201905_B.ControlSubsystem_o9,
    &px4demo_attitude_system201905_B.ControlSubsystem_o10,
    &px4demo_attitude_system201905_B.ControlSubsystem_o11,
    &px4demo_attitude_system201905_B.ControlSubsystem_o12,
    &(px4demo_attitude_system20190_DW.ControlSubsystem_DWORK1.rtb),
    &(px4demo_attitude_system20190_DW.ControlSubsystem_DWORK1.rtdw));

  /* S-Function (sfun_px4_pwm): '<Root>/PWM_output' */
  if (px4demo_attitude_system201905_B.ControlSubsystem_o2 == true) {
    if (g_pwm_enabled == false) {
      int rc;

      /* arm system */
      rc = ioctl(g_pwm_fd, PWM_SERVO_ARM, 0);
      if (rc != OK)
        err(1,"PWM_SERVO_ARM");
      else {
        ioctl(g_pwm_fd, PWM_SERVO_SET(0), 900);
        ioctl(g_pwm_fd, PWM_SERVO_SET(1), 900);
        ioctl(g_pwm_fd, PWM_SERVO_SET(2), 900);
        ioctl(g_pwm_fd, PWM_SERVO_SET(3), 900);
        g_pwm_enabled = true;
        printf("***ARMED*** PWM fd = %d\n", g_pwm_fd);
      }
    }
  } else {
    if (g_pwm_enabled == true) {
      int rc;

      /* disarm system if enabled */
      ioctl(g_pwm_fd, PWM_SERVO_SET(0), 900);
      ioctl(g_pwm_fd, PWM_SERVO_SET(1), 900);
      ioctl(g_pwm_fd, PWM_SERVO_SET(2), 900);
      ioctl(g_pwm_fd, PWM_SERVO_SET(3), 900);
      rc = ioctl(g_pwm_fd, PWM_SERVO_DISARM, 0);
      g_pwm_enabled = false;
      if (rc != OK)
        err(1, "PWM_SERVO_DISARM");
      else
        printf("***DISARMED*** PWM fd = %d\n", g_pwm_fd);
    }
  }

  if (g_pwm_enabled) {
    /* output the PWM signals */
    ioctl(g_pwm_fd, PWM_SERVO_SET(0), (unsigned int)
          px4demo_attitude_system201905_B.ControlSubsystem_o1[0]);
    ioctl(g_pwm_fd, PWM_SERVO_SET(1), (unsigned int)
          px4demo_attitude_system201905_B.ControlSubsystem_o1[1]);
    ioctl(g_pwm_fd, PWM_SERVO_SET(2), (unsigned int)
          px4demo_attitude_system201905_B.ControlSubsystem_o1[2]);
    ioctl(g_pwm_fd, PWM_SERVO_SET(3), (unsigned int)
          px4demo_attitude_system201905_B.ControlSubsystem_o1[3]);
  }

  if (px4demo_attitude_system20190_M->Timing.TaskCounters.TID[3] == 0) {
    /* Switch: '<S3>/Switch' incorporates:
     *  Constant: '<S3>/Constant'
     *  Constant: '<S3>/Constant1'
     *  Constant: '<S3>/Constant2'
     *  Constant: '<S3>/Constant3'
     *  Switch: '<S3>/Switch1'
     */
    if (px4demo_attitude_system201905_B.ControlSubsystem_o2) {
      px4demo_attitude_system201905_B.Switch = MODE_BLINK_FAST;
      px4demo_attitude_system201905_B.Switch1 = COLOR_RED;
    } else {
      px4demo_attitude_system201905_B.Switch = MODE_BREATHE;
      px4demo_attitude_system201905_B.Switch1 = COLOR_GREEN;
    }

    /* End of Switch: '<S3>/Switch' */

    /* S-Function (sfun_px4_rgbled): '<Root>/RGB_LED' */
    ioctl(px4demo_attitude_system20190_DW.RGB_LED_rgbled_fd, RGBLED_SET_MODE,
          px4demo_attitude_system201905_B.Switch);
    ioctl(px4demo_attitude_system20190_DW.RGB_LED_rgbled_fd, RGBLED_SET_COLOR,
          px4demo_attitude_system201905_B.Switch1);
  }

  /* RateTransition: '<Root>/Rate Transition' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion2'
   *  DataTypeConversion: '<Root>/Data Type Conversion3'
   */
  if (px4demo_attitude_system20190_M->Timing.TaskCounters.TID[2] == 0) {
    px4demo_attitude_system201905_B.RateTransition_m[0] = (real32_T)
      px4demo_attitude_system201905_B.vehicle_gps_o1;
    px4demo_attitude_system201905_B.RateTransition_m[1] = (real32_T)
      px4demo_attitude_system201905_B.vehicle_gps_o2;
    px4demo_attitude_system201905_B.RateTransition_m[2] =
      px4demo_attitude_system201905_B.sensor_combined_o4;
    px4demo_attitude_system201905_B.RateTransition_m[3] =
      px4demo_attitude_system201905_B.ControlSubsystem_o8;
    px4demo_attitude_system201905_B.RateTransition_m[4] =
      px4demo_attitude_system201905_B.ControlSubsystem_o9;
    px4demo_attitude_system201905_B.RateTransition_m[5] =
      px4demo_attitude_system201905_B.Gain3;
    px4demo_attitude_system201905_B.RateTransition_m[6] =
      px4demo_attitude_system201905_B.Gain2;
    px4demo_attitude_system201905_B.RateTransition_m[7] =
      px4demo_attitude_system201905_B.Gain1;

    /* Start for MATLABSystem: '<Root>/Serial' incorporates:
     *  DataTypeConversion: '<Root>/Data Type Conversion2'
     *  DataTypeConversion: '<Root>/Data Type Conversion3'
     *  MATLABSystem: '<Root>/Serial'
     */
    MW_writeSerial(px4demo_attitude_system20190_DW.obj.fh_index,
                   px4demo_attitude_system201905_B.RateTransition_m, 32U);
  }

  /* End of RateTransition: '<Root>/Rate Transition' */

  /* Switch: '<S4>/Switch1' incorporates:
   *  Constant: '<S4>/ARM_Tune'
   *  Constant: '<S4>/ARM_Tune1'
   */
  if (px4demo_attitude_system201905_B.ControlSubsystem_o2) {
    px4demo_attitude_system201905_B.Switch1_i = ARMING_WARNING_TUNE;
  } else {
    px4demo_attitude_system201905_B.Switch1_i = NOTIFY_POSITIVE_TUNE;
  }

  /* End of Switch: '<S4>/Switch1' */

  /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
   *  Logic: '<S4>/Logical Operator'
   *  UnitDelay: '<S4>/Unit Delay'
   */
  px4demo_attitude_system201905_B.DataTypeConversion = (uint8_T)((int8_T)
    px4demo_attitude_system20190_DW.UnitDelay_DSTATE ^ (int8_T)
    px4demo_attitude_system201905_B.ControlSubsystem_o2);

  /* S-Function (sfun_px4_tune): '<Root>/Speaker_Tune' */
  if (px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd == -1) {
    px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd = open
      (TONEALARM0_DEVICE_PATH, O_WRONLY);
    if ((px4demo_attitude_system201905_B.DataTypeConversion > 0) &&
        (px4demo_attitude_system201905_B.DataTypeConversion !=
         px4demo_attitude_system20190_DW.Speaker_Tune_triggerState)) {
      if (px4demo_attitude_system201905_B.DataTypeConversion == 1) {
        ioctl(px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd,
              TONE_SET_ALARM, px4demo_attitude_system201905_B.Switch1_i);
      } else if (px4demo_attitude_system201905_B.DataTypeConversion == 2) {
        write(px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd, (uint8_T*)
              &px4demo_attitude_system20190504_gps_U8GND, 1);
      }
    }

    // save the state of the trigger
    px4demo_attitude_system20190_DW.Speaker_Tune_triggerState =
      px4demo_attitude_system201905_B.DataTypeConversion;
  } else {
    if ((px4demo_attitude_system201905_B.DataTypeConversion > 0) &&
        (px4demo_attitude_system201905_B.DataTypeConversion !=
         px4demo_attitude_system20190_DW.Speaker_Tune_triggerState)) {
      if (px4demo_attitude_system201905_B.DataTypeConversion == 1) {
        ioctl(px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd,
              TONE_SET_ALARM, px4demo_attitude_system201905_B.Switch1_i);
      } else if (px4demo_attitude_system201905_B.DataTypeConversion == 2) {
        write(px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd, (uint8_T*)
              &px4demo_attitude_system20190504_gps_U8GND, 1);
      }
    }

    // save the state of the trigger
    px4demo_attitude_system20190_DW.Speaker_Tune_triggerState =
      px4demo_attitude_system201905_B.DataTypeConversion;
  }

  /* Update for UnitDelay: '<S4>/Unit Delay' */
  px4demo_attitude_system20190_DW.UnitDelay_DSTATE =
    px4demo_attitude_system201905_B.ControlSubsystem_o2;
  rate_scheduler();
}

/* Model initialize function */
void px4demo_attitude_system20190504_gps_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)px4demo_attitude_system20190_M, 0,
                sizeof(RT_MODEL_px4demo_attitude_sys_T));

  /* block I/O */
  (void) memset(((void *) &px4demo_attitude_system201905_B), 0,
                sizeof(B_px4demo_attitude_system2019_T));

  {
    px4demo_attitude_system201905_B.Switch = MODE_OFF;
    px4demo_attitude_system201905_B.Switch1 = COLOR_OFF;
    px4demo_attitude_system201905_B.Switch1_i = STOP_TUNE;
  }

  /* states (dwork) */
  (void) memset((void *)&px4demo_attitude_system20190_DW, 0,
                sizeof(DW_px4demo_attitude_system201_T));

  {
    static uint32_T *taskCounterPtrs;
    px4demo_attitude_sys_TimingBrdg.nTasks = 5;
    px4demo_attitude_sys_TimingBrdg.clockTick = (NULL);
    px4demo_attitude_sys_TimingBrdg.clockTickH = (NULL);
    taskCounterPtrs = &(px4demo_attitude_system20190_M->Timing.TaskCounters.TID
                        [0]);
    px4demo_attitude_sys_TimingBrdg.taskCounter = taskCounterPtrs;
  }

  /* Model Initialize fcn for ModelReference Block: '<Root>/ControlSubsystem' */
  px4demo_attitude_con_initialize(rtmGetErrorStatusPointer
    (px4demo_attitude_system20190_M), &px4demo_attitude_sys_TimingBrdg, 0, 1, 4,
    &(px4demo_attitude_system20190_DW.ControlSubsystem_DWORK1.rtm),
    &(px4demo_attitude_system20190_DW.ControlSubsystem_DWORK1.rtb),
    &(px4demo_attitude_system20190_DW.ControlSubsystem_DWORK1.rtdw));

  {
    FILE * a;
    uint8_T devName[11];
    int32_T fh_index_tmp;
    static const uint8_T tmp[11] = { 47U, 100U, 101U, 118U, 47U, 116U, 116U,
      121U, 83U, 49U, 0U };

    /* Start for S-Function (sfun_px4_vehicle_attitude): '<Root>/vehicle_attitude' */
    {
      /* S-Function Block: <Root>/vehicle_attitude */
      /* subscribe to PWM RC input topic */
      int fd = orb_subscribe(ORB_ID(vehicle_attitude));
      px4demo_attitude_system20190_DW.vehicle_attitude_vehicle_attitu.fd = fd;
      px4demo_attitude_system20190_DW.vehicle_attitude_vehicle_attitu.events =
        POLLIN;
      orb_set_interval(fd, 1);
      warnx("* Subscribed to vehicle_attitude topic (fd = %d)*\n", fd);
    }

    /* Start for S-Function (sfun_px4_gps): '<Root>/vehicle_gps' */
    {
      /* S-Function Block: <Root>/vehicle_gps */
      /* subscribe to gps topic */
      int fd = orb_subscribe(ORB_ID(vehicle_gps_position));
      px4demo_attitude_system20190_DW.vehicle_gps_gps_fd.fd = fd;
      px4demo_attitude_system20190_DW.vehicle_gps_gps_fd.events = POLLIN;
      orb_set_interval(fd, 1);
      warnx("* Subscribed to gps topic (fd = %d)*\n", fd);
    }

    /* Start for S-Function (sfun_px4_input_rc): '<Root>/input_rc' */
    {
      /* S-Function Block: <Root>/input_rc */
      /* subscribe to PWM RC input topic */
      int fd = orb_subscribe(ORB_ID(input_rc));
      px4demo_attitude_system20190_DW.input_rc_input_rc_fd.fd = fd;
      px4demo_attitude_system20190_DW.input_rc_input_rc_fd.events = POLLIN;
      orb_set_interval(fd, 1);
      warnx("* Subscribed to input_rc topic (fd = %d)*\n", fd);
    }

    /* Start for S-Function (sfun_px4_sensor_combined): '<Root>/sensor_combined' */
    {
      /* S-Function Block: <Root>/sensor_combined */
      /* subscribe to sensor_combined topic */
      int fd = orb_subscribe(ORB_ID(sensor_combined));
      px4demo_attitude_system20190_DW.sensor_combined_sensor_fd.fd = fd;
      px4demo_attitude_system20190_DW.sensor_combined_sensor_fd.events = POLLIN;
      orb_set_interval(fd, 1);
      warnx("* Subscribed to sensor_combined topic (fd = %d)*\n", fd);
    }

    /* Start for S-Function (sfun_px4_pwm): '<Root>/PWM_output' */
    {
      int rc;
      int pwm_rate = 400;              /* default PWM Rate is 400Hz */
      int chMask = 0x00;               /* change channel mask based on which are used */

      /* channel group 0 */
      chMask |= 0x03;

      /* channel group 2 */
      chMask |= 0x0C;

      /* set PWM update rate to 50Hz */
      pwm_rate = 50;

      /* enable pwm outputs, set to disarm  */
      g_pwm_fd = open(g_pwm_device, 0);
      printf("OPEN PWM fd = %d\n", g_pwm_fd);
      rc = ioctl(g_pwm_fd, PWM_SERVO_SET_UPDATE_RATE, pwm_rate);
      if (rc != OK)
        err(1, "PWM_SERVO_SET_UPDATE_RATE");
      if (chMask > 0) {
        rc = ioctl(g_pwm_fd, PWM_SERVO_SET_SELECT_UPDATE_RATE, chMask);
        if (rc != OK) {
          err(1, "PWM_SERVO_SET_SELECT_UPDATE_RATE");
        }

        printf("Set SERVO Rate (%dHz) Channel Mask:0x%08X\n", pwm_rate, chMask);
      }

      /* tell safety that its ok to disable it with the switch */
      rc = ioctl(g_pwm_fd, PWM_SERVO_SET_ARM_OK, 0);
      if (rc != OK)
        err(1, "PWM_SERVO_SET_ARM_OK");
      rc = ioctl(g_pwm_fd, PWM_SERVO_DISARM, 0);
      if (rc != OK)
        err(1, "PWM_SERVO_DISARM");
      g_pwm_enabled = false;
    }

    /* Start for S-Function (sfun_px4_rgbled): '<Root>/RGB_LED' */
    {
      // enable RGBLED, set intitial mode and color
      // more devices will be 1, 2, etc
      // #define RGBLED0_DEVICE_PATH "/dev/rgbled0"
      //px4demo_attitude_system20190_DW.RGB_LED_rgbled_fd = open("/dev/rgbled0", 0);
      px4demo_attitude_system20190_DW.RGB_LED_rgbled_fd = open
        (RGBLED0_DEVICE_PATH, 0);
      ioctl(px4demo_attitude_system20190_DW.RGB_LED_rgbled_fd, RGBLED_SET_MODE,
            RGBLED_MODE_OFF);
      ioctl(px4demo_attitude_system20190_DW.RGB_LED_rgbled_fd, RGBLED_SET_COLOR,
            RGBLED_COLOR_OFF);
    }

    /* Start for MATLABSystem: '<Root>/Serial' */
    px4demo_attitude_system20190_DW.obj.isInitialized = 0;
    px4demo_attitude_system20190_DW.obj.isInitialized = 1;
    for (fh_index_tmp = 0; fh_index_tmp < 11; fh_index_tmp++) {
      devName[fh_index_tmp] = tmp[fh_index_tmp];
    }

    MW_openSerialPort(devName, 57600U, px4demo_attitude_system20_block,
                      &fh_index_tmp);
    px4demo_attitude_system20190_DW.obj.fh_index = fh_index_tmp;

    /* End of Start for MATLABSystem: '<Root>/Serial' */
    /* Start for S-Function (sfun_px4_tune): '<Root>/Speaker_Tune' */

    // enable tune driver
    // #define TONEALARM_DEVICE_PATH "/dev/tone_alarm"
    px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd = open
      (TONEALARM0_DEVICE_PATH, O_WRONLY);
    ioctl(px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd, TONE_SET_ALARM,
          TONE_STARTUP_TUNE);
    close(px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd);// close here since this may be used in another thread
    px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd = -1;

    /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function' */
    a = NULL;
    for (fh_index_tmp = 0; fh_index_tmp < 20; fh_index_tmp++) {
      px4demo_attitude_system20190_DW.eml_autoflush[fh_index_tmp] = false;
      px4demo_attitude_system20190_DW.eml_openfiles[fh_index_tmp] = a;
    }

    /* End of SystemInitialize for MATLAB Function: '<Root>/MATLAB Function' */
    /* SystemInitialize for ModelReference: '<Root>/ControlSubsystem' */
    px4demo_attitude_control20_Init
      (&(px4demo_attitude_system20190_DW.ControlSubsystem_DWORK1.rtdw));
  }
}

/* Model terminate function */
void px4demo_attitude_system20190504_gps_terminate(void)
{
  uint8_T devName[11];
  static const uint8_T tmp[11] = { 47U, 100U, 101U, 118U, 47U, 116U, 116U, 121U,
    83U, 49U, 0U };

  int32_T i;

  /* Close uORB service used in the S-Function Block: <Root>/vehicle_attitude */
  close(px4demo_attitude_system20190_DW.vehicle_attitude_vehicle_attitu.fd);

  /* Close uORB service used in the S-Function Block: <Root>/vehicle_gps */
  close(px4demo_attitude_system20190_DW.vehicle_gps_gps_fd.fd);

  /* Close uORB service used in the S-Function Block: <Root>/input_rc */
  close(px4demo_attitude_system20190_DW.input_rc_input_rc_fd.fd);

  /* Close uORB service used in the S-Function Block: <Root>/sensor_combined */
  close(px4demo_attitude_system20190_DW.sensor_combined_sensor_fd.fd);

  /* Terminate for S-Function (sfun_px4_pwm): '<Root>/PWM_output' */
  /* disable pwm outputs */
  ioctl(g_pwm_fd, PWM_SERVO_SET(0), 900);
  ioctl(g_pwm_fd, PWM_SERVO_SET(1), 900);
  ioctl(g_pwm_fd, PWM_SERVO_SET(2), 900);
  ioctl(g_pwm_fd, PWM_SERVO_SET(3), 900);
  ioctl(g_pwm_fd, PWM_SERVO_DISARM, 0);
  g_pwm_enabled = false;

  /* Close handle used in the S-Function Block: <Root>/PWM_output */
  close(g_pwm_fd);

  /* Terminate for S-Function (sfun_px4_rgbled): '<Root>/RGB_LED' */
  ioctl(px4demo_attitude_system20190_DW.RGB_LED_rgbled_fd, RGBLED_SET_COLOR,
        RGBLED_COLOR_OFF);
  ioctl(px4demo_attitude_system20190_DW.RGB_LED_rgbled_fd, RGBLED_SET_MODE,
        RGBLED_MODE_OFF);
  usleep(100);

  /* Close uORB service used in the S-Function Block: <Root>/RGB_LED */
  close(px4demo_attitude_system20190_DW.RGB_LED_rgbled_fd);

  /* Start for MATLABSystem: '<Root>/Serial' incorporates:
   *  Terminate for MATLABSystem: '<Root>/Serial'
   */
  if (px4demo_attitude_system20190_DW.obj.isInitialized == 1) {
    px4demo_attitude_system20190_DW.obj.isInitialized = 2;
    for (i = 0; i < 11; i++) {
      devName[i] = tmp[i];
    }

    MW_closeSerialPort(devName, px4demo_attitude_system20190_DW.obj.fh_index);
  }

  /* End of Start for MATLABSystem: '<Root>/Serial' */
  /* Terminate for S-Function (sfun_px4_tune): '<Root>/Speaker_Tune' */
  if (px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd != -1) {
    close(px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd);// this may be open in a different thread. close first.
    px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd = open
      (TONEALARM0_DEVICE_PATH, O_WRONLY);// re-open
    ioctl(px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd, TONE_SET_ALARM,
          TONE_STOP_TUNE);

    /* Close service used in the S-Function Block: <Root>/Speaker_Tune */
    close(px4demo_attitude_system20190_DW.Speaker_Tune_tune_fd);// finally close device here
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
