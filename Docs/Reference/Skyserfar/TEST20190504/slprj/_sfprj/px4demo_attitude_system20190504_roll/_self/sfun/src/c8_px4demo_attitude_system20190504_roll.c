/* Include files */

#include "px4demo_attitude_system20190504_roll_sfun.h"
#include "c8_px4demo_attitude_system20190504_roll.h"
#include <string.h>
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "px4demo_attitude_system20190504_roll_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c8_debug_family_names[4] = { "nargin", "nargout", "u", "y" };

/* Function Declarations */
static void initialize_c8_px4demo_attitude_system20190504_roll
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance);
static void initialize_params_c8_px4demo_attitude_system20190504_roll
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance);
static void enable_c8_px4demo_attitude_system20190504_roll
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance);
static void disable_c8_px4demo_attitude_system20190504_roll
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance);
static void c8_update_debugger_state_c8_px4demo_attitude_system20190504_roll
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c8_px4demo_attitude_system20190504_roll
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance);
static void set_sim_state_c8_px4demo_attitude_system20190504_roll
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance, const
   mxArray *c8_st);
static void finalize_c8_px4demo_attitude_system20190504_roll
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance);
static void sf_gateway_c8_px4demo_attitude_system20190504_roll
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance);
static void mdl_start_c8_px4demo_attitude_system20190504_roll
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance);
static void initSimStructsc8_px4demo_attitude_system20190504_roll
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber, uint32_T c8_instanceNumber);
static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData);
static real32_T c8_emlrt_marshallIn
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance, const
   mxArray *c8_b_y, const char_T *c8_identifier);
static real32_T c8_b_emlrt_marshallIn
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance, const
   mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static real_T c8_c_emlrt_marshallIn
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance, const
   mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData);
static int32_T c8_d_emlrt_marshallIn
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance, const
   mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId);
static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData);
static uint8_T c8_e_emlrt_marshallIn
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance, const
   mxArray *c8_b_is_active_c8_px4demo_attitude_system20190504_roll, const char_T
   *c8_identifier);
static uint8_T c8_f_emlrt_marshallIn
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance, const
   mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId);
static void init_dsm_address_info
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c8_px4demo_attitude_system20190504_roll
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc8_px4demo_attitude_system20190504_roll(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c8_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c8_is_active_c8_px4demo_attitude_system20190504_roll = 0U;
}

static void initialize_params_c8_px4demo_attitude_system20190504_roll
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c8_px4demo_attitude_system20190504_roll
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c8_px4demo_attitude_system20190504_roll
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c8_update_debugger_state_c8_px4demo_attitude_system20190504_roll
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c8_px4demo_attitude_system20190504_roll
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance)
{
  const mxArray *c8_st;
  const mxArray *c8_b_y = NULL;
  real32_T c8_hoistedGlobal;
  const mxArray *c8_c_y = NULL;
  uint8_T c8_b_hoistedGlobal;
  const mxArray *c8_d_y = NULL;
  c8_st = NULL;
  c8_st = NULL;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_createcellmatrix(2, 1), false);
  c8_hoistedGlobal = *chartInstance->c8_y;
  c8_c_y = NULL;
  sf_mex_assign(&c8_c_y, sf_mex_create("y", &c8_hoistedGlobal, 1, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c8_b_y, 0, c8_c_y);
  c8_b_hoistedGlobal =
    chartInstance->c8_is_active_c8_px4demo_attitude_system20190504_roll;
  c8_d_y = NULL;
  sf_mex_assign(&c8_d_y, sf_mex_create("y", &c8_b_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c8_b_y, 1, c8_d_y);
  sf_mex_assign(&c8_st, c8_b_y, false);
  return c8_st;
}

static void set_sim_state_c8_px4demo_attitude_system20190504_roll
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance, const
   mxArray *c8_st)
{
  const mxArray *c8_b_u;
  chartInstance->c8_doneDoubleBufferReInit = true;
  c8_b_u = sf_mex_dup(c8_st);
  *chartInstance->c8_y = c8_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("y", c8_b_u, 0)), "y");
  chartInstance->c8_is_active_c8_px4demo_attitude_system20190504_roll =
    c8_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "is_active_c8_px4demo_attitude_system20190504_roll", c8_b_u, 1)),
    "is_active_c8_px4demo_attitude_system20190504_roll");
  sf_mex_destroy(&c8_b_u);
  c8_update_debugger_state_c8_px4demo_attitude_system20190504_roll(chartInstance);
  sf_mex_destroy(&c8_st);
}

static void finalize_c8_px4demo_attitude_system20190504_roll
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c8_px4demo_attitude_system20190504_roll
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance)
{
  int32_T c8_i0;
  int32_T c8_i1;
  uint32_T c8_debug_family_var_map[4];
  real32_T c8_b_u[4];
  real_T c8_nargin = 1.0;
  real_T c8_nargout = 1.0;
  real32_T c8_b_y;
  int32_T c8_i2;
  uint8_T c8_x[4];
  real32_T c8_f0;
  uint8_T c8_u0;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  for (c8_i0 = 0; c8_i0 < 4; c8_i0++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c8_u)[c8_i0], 0U, 1U, 0U,
                          chartInstance->c8_sfEvent, false);
  }

  chartInstance->c8_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  for (c8_i1 = 0; c8_i1 < 4; c8_i1++) {
    c8_b_u[c8_i1] = (*chartInstance->c8_u)[c8_i1];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c8_debug_family_names,
    c8_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargin, 0U, c8_c_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_nargout, 1U, c8_c_sf_marshallOut,
    c8_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c8_b_u, 2U, c8_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c8_b_y, 3U, c8_sf_marshallOut,
    c8_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 3);
  c8_b_y = 0.0F;
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, 4);
  for (c8_i2 = 0; c8_i2 < 4; c8_i2++) {
    c8_f0 = muSingleScalarRound(c8_b_u[c8_i2]);
    if (c8_f0 < 256.0F) {
      if (CV_SATURATION_EVAL(4, 0, 0, 1, c8_f0 >= 0.0F)) {
        c8_u0 = (uint8_T)c8_f0;
      } else {
        c8_u0 = 0U;
      }
    } else if (CV_SATURATION_EVAL(4, 0, 0, 0, c8_f0 >= 256.0F)) {
      c8_u0 = MAX_uint8_T;
    } else {
      c8_u0 = 0U;
    }

    c8_x[c8_i2] = c8_u0;
  }

  memcpy(&c8_b_y, &c8_x[0], (size_t)1 * sizeof(real32_T));
  _SFD_EML_CALL(0U, chartInstance->c8_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c8_y = c8_b_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c8_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_px4demo_attitude_system20190504_rollMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c8_y, 1U, 1U, 0U,
                        chartInstance->c8_sfEvent, false);
}

static void mdl_start_c8_px4demo_attitude_system20190504_roll
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc8_px4demo_attitude_system20190504_roll
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c8_machineNumber, uint32_T
  c8_chartNumber, uint32_T c8_instanceNumber)
{
  (void)c8_machineNumber;
  (void)c8_chartNumber;
  (void)c8_instanceNumber;
}

static const mxArray *c8_sf_marshallOut(void *chartInstanceVoid, void *c8_inData)
{
  const mxArray *c8_mxArrayOutData;
  real32_T c8_b_u;
  const mxArray *c8_b_y = NULL;
  SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance;
  chartInstance = (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_mxArrayOutData = NULL;
  c8_b_u = *(real32_T *)c8_inData;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_b_u, 1, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_b_y, false);
  return c8_mxArrayOutData;
}

static real32_T c8_emlrt_marshallIn
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance, const
   mxArray *c8_b_y, const char_T *c8_identifier)
{
  real32_T c8_c_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_c_y = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_y), &c8_thisId);
  sf_mex_destroy(&c8_b_y);
  return c8_c_y;
}

static real32_T c8_b_emlrt_marshallIn
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance, const
   mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId)
{
  real32_T c8_b_y;
  real32_T c8_f1;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_b_u), &c8_f1, 1, 1, 0U, 0, 0U, 0);
  c8_b_y = c8_f1;
  sf_mex_destroy(&c8_b_u);
  return c8_b_y;
}

static void c8_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_y;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real32_T c8_c_y;
  SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance;
  chartInstance = (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *)
    chartInstanceVoid;
  c8_b_y = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_c_y = c8_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_y), &c8_thisId);
  sf_mex_destroy(&c8_b_y);
  *(real32_T *)c8_outData = c8_c_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static const mxArray *c8_b_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData;
  int32_T c8_i3;
  const mxArray *c8_b_y = NULL;
  real32_T c8_b_u[4];
  SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance;
  chartInstance = (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_mxArrayOutData = NULL;
  for (c8_i3 = 0; c8_i3 < 4; c8_i3++) {
    c8_b_u[c8_i3] = (*(real32_T (*)[4])c8_inData)[c8_i3];
  }

  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", c8_b_u, 1, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_b_y, false);
  return c8_mxArrayOutData;
}

static const mxArray *c8_c_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData;
  real_T c8_b_u;
  const mxArray *c8_b_y = NULL;
  SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance;
  chartInstance = (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_mxArrayOutData = NULL;
  c8_b_u = *(real_T *)c8_inData;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_b_y, false);
  return c8_mxArrayOutData;
}

static real_T c8_c_emlrt_marshallIn
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance, const
   mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId)
{
  real_T c8_b_y;
  real_T c8_d0;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_b_u), &c8_d0, 1, 0, 0U, 0, 0U, 0);
  c8_b_y = c8_d0;
  sf_mex_destroy(&c8_b_u);
  return c8_b_y;
}

static void c8_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_nargout;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  real_T c8_b_y;
  SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance;
  chartInstance = (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *)
    chartInstanceVoid;
  c8_nargout = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_b_y = c8_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_nargout),
    &c8_thisId);
  sf_mex_destroy(&c8_nargout);
  *(real_T *)c8_outData = c8_b_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

const mxArray
  *sf_c8_px4demo_attitude_system20190504_roll_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c8_nameCaptureInfo = NULL;
  c8_nameCaptureInfo = NULL;
  sf_mex_assign(&c8_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c8_nameCaptureInfo;
}

static const mxArray *c8_d_sf_marshallOut(void *chartInstanceVoid, void
  *c8_inData)
{
  const mxArray *c8_mxArrayOutData;
  int32_T c8_b_u;
  const mxArray *c8_b_y = NULL;
  SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance;
  chartInstance = (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *)
    chartInstanceVoid;
  c8_mxArrayOutData = NULL;
  c8_mxArrayOutData = NULL;
  c8_b_u = *(int32_T *)c8_inData;
  c8_b_y = NULL;
  sf_mex_assign(&c8_b_y, sf_mex_create("y", &c8_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c8_mxArrayOutData, c8_b_y, false);
  return c8_mxArrayOutData;
}

static int32_T c8_d_emlrt_marshallIn
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance, const
   mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId)
{
  int32_T c8_b_y;
  int32_T c8_i4;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_b_u), &c8_i4, 1, 6, 0U, 0, 0U, 0);
  c8_b_y = c8_i4;
  sf_mex_destroy(&c8_b_u);
  return c8_b_y;
}

static void c8_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c8_mxArrayInData, const char_T *c8_varName, void *c8_outData)
{
  const mxArray *c8_b_sfEvent;
  const char_T *c8_identifier;
  emlrtMsgIdentifier c8_thisId;
  int32_T c8_b_y;
  SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance;
  chartInstance = (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *)
    chartInstanceVoid;
  c8_b_sfEvent = sf_mex_dup(c8_mxArrayInData);
  c8_identifier = c8_varName;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_b_y = c8_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c8_b_sfEvent),
    &c8_thisId);
  sf_mex_destroy(&c8_b_sfEvent);
  *(int32_T *)c8_outData = c8_b_y;
  sf_mex_destroy(&c8_mxArrayInData);
}

static uint8_T c8_e_emlrt_marshallIn
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance, const
   mxArray *c8_b_is_active_c8_px4demo_attitude_system20190504_roll, const char_T
   *c8_identifier)
{
  uint8_T c8_b_y;
  emlrtMsgIdentifier c8_thisId;
  c8_thisId.fIdentifier = c8_identifier;
  c8_thisId.fParent = NULL;
  c8_thisId.bParentIsCell = false;
  c8_b_y = c8_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c8_b_is_active_c8_px4demo_attitude_system20190504_roll), &c8_thisId);
  sf_mex_destroy(&c8_b_is_active_c8_px4demo_attitude_system20190504_roll);
  return c8_b_y;
}

static uint8_T c8_f_emlrt_marshallIn
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance, const
   mxArray *c8_b_u, const emlrtMsgIdentifier *c8_parentId)
{
  uint8_T c8_b_y;
  uint8_T c8_u1;
  (void)chartInstance;
  sf_mex_import(c8_parentId, sf_mex_dup(c8_b_u), &c8_u1, 1, 3, 0U, 0, 0U, 0);
  c8_b_y = c8_u1;
  sf_mex_destroy(&c8_b_u);
  return c8_b_y;
}

static void init_dsm_address_info
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance)
{
  chartInstance->c8_u = (real32_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c8_y = (real32_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c8_px4demo_attitude_system20190504_roll_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3357969365U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3812220321U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(568158394U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2003454283U);
}

mxArray* sf_c8_px4demo_attitude_system20190504_roll_get_post_codegen_info(void);
mxArray *sf_c8_px4demo_attitude_system20190504_roll_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("r1lW1ftBcUmdELO1tTCKkF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c8_px4demo_attitude_system20190504_roll_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c8_px4demo_attitude_system20190504_roll_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c8_px4demo_attitude_system20190504_roll_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("memcpy");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c8_px4demo_attitude_system20190504_roll_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c8_px4demo_attitude_system20190504_roll_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray
  *sf_get_sim_state_info_c8_px4demo_attitude_system20190504_roll(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c8_px4demo_attitude_system20190504_roll\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c8_px4demo_attitude_system20190504_roll_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance =
      (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _px4demo_attitude_system20190504_rollMachineNumber_,
           8,
           1,
           1,
           0,
           2,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation
          (_px4demo_attitude_system20190504_rollMachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _px4demo_attitude_system20190504_rollMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _px4demo_attitude_system20190504_rollMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"y");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,86);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,65,-1,73);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c8_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_SINGLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c8_sf_marshallOut,(MexInFcnForType)c8_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _px4demo_attitude_system20190504_rollMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance =
      (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c8_u);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c8_y);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sCvg3KDx4g5R3NWdktYk2VB";
}

static void sf_opaque_initialize_c8_px4demo_attitude_system20190504_roll(void
  *chartInstanceVar)
{
  chart_debug_initialization
    (((SFc8_px4demo_attitude_system20190504_rollInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c8_px4demo_attitude_system20190504_roll
    ((SFc8_px4demo_attitude_system20190504_rollInstanceStruct*) chartInstanceVar);
  initialize_c8_px4demo_attitude_system20190504_roll
    ((SFc8_px4demo_attitude_system20190504_rollInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c8_px4demo_attitude_system20190504_roll(void
  *chartInstanceVar)
{
  enable_c8_px4demo_attitude_system20190504_roll
    ((SFc8_px4demo_attitude_system20190504_rollInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c8_px4demo_attitude_system20190504_roll(void
  *chartInstanceVar)
{
  disable_c8_px4demo_attitude_system20190504_roll
    ((SFc8_px4demo_attitude_system20190504_rollInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c8_px4demo_attitude_system20190504_roll(void
  *chartInstanceVar)
{
  sf_gateway_c8_px4demo_attitude_system20190504_roll
    ((SFc8_px4demo_attitude_system20190504_rollInstanceStruct*) chartInstanceVar);
}

static const mxArray*
  sf_opaque_get_sim_state_c8_px4demo_attitude_system20190504_roll(SimStruct* S)
{
  return get_sim_state_c8_px4demo_attitude_system20190504_roll
    ((SFc8_px4demo_attitude_system20190504_rollInstanceStruct *)
     sf_get_chart_instance_ptr(S));    /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c8_px4demo_attitude_system20190504_roll
  (SimStruct* S, const mxArray *st)
{
  set_sim_state_c8_px4demo_attitude_system20190504_roll
    ((SFc8_px4demo_attitude_system20190504_rollInstanceStruct*)
     sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c8_px4demo_attitude_system20190504_roll(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc8_px4demo_attitude_system20190504_rollInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_px4demo_attitude_system20190504_roll_optimization_info();
    }

    finalize_c8_px4demo_attitude_system20190504_roll
      ((SFc8_px4demo_attitude_system20190504_rollInstanceStruct*)
       chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc8_px4demo_attitude_system20190504_roll
    ((SFc8_px4demo_attitude_system20190504_rollInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c8_px4demo_attitude_system20190504_roll
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c8_px4demo_attitude_system20190504_roll
      ((SFc8_px4demo_attitude_system20190504_rollInstanceStruct*)
       sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c8_px4demo_attitude_system20190504_roll(SimStruct
  *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_px4demo_attitude_system20190504_roll_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,8);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,8,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 8);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,8);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,8,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,8,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,8);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(383256990U));
  ssSetChecksum1(S,(1825110235U));
  ssSetChecksum2(S,(2710547781U));
  ssSetChecksum3(S,(2260845998U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c8_px4demo_attitude_system20190504_roll(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c8_px4demo_attitude_system20190504_roll(SimStruct *S)
{
  SFc8_px4demo_attitude_system20190504_rollInstanceStruct *chartInstance;
  chartInstance = (SFc8_px4demo_attitude_system20190504_rollInstanceStruct *)
    utMalloc(sizeof(SFc8_px4demo_attitude_system20190504_rollInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof
         (SFc8_px4demo_attitude_system20190504_rollInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c8_px4demo_attitude_system20190504_roll;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c8_px4demo_attitude_system20190504_roll;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c8_px4demo_attitude_system20190504_roll;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c8_px4demo_attitude_system20190504_roll;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c8_px4demo_attitude_system20190504_roll;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c8_px4demo_attitude_system20190504_roll;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c8_px4demo_attitude_system20190504_roll;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c8_px4demo_attitude_system20190504_roll;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c8_px4demo_attitude_system20190504_roll;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c8_px4demo_attitude_system20190504_roll;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c8_px4demo_attitude_system20190504_roll;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c8_px4demo_attitude_system20190504_roll(chartInstance);
}

void c8_px4demo_attitude_system20190504_roll_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c8_px4demo_attitude_system20190504_roll(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c8_px4demo_attitude_system20190504_roll(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c8_px4demo_attitude_system20190504_roll(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c8_px4demo_attitude_system20190504_roll_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
