/* Include files */

#include "pixhawk_slib_misc_utils_sfun.h"
#include "c3_pixhawk_slib_misc_utils.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "pixhawk_slib_misc_utils_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c3_const_cacheflag             (false)
#define c3_const_numRecs               (1000U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[20] = { "elsize", "eltype",
  "elem_type", "mlStrVer", "tm", "tmptr", "recSize", "logname", "cacheflag",
  "numRecs", "nargin", "nargout", "en", "data", "isflushed", "isopen", "count",
  "lognumstr", "elem_size", "vect_size" };

static const char * c3_b_debug_family_names[4] = { "dtype", "elem_size",
  "nargin", "nargout" };

/* Function Declarations */
static void initialize_c3_pixhawk_slib_misc_utils
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance);
static void initialize_params_c3_pixhawk_slib_misc_utils
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance);
static void enable_c3_pixhawk_slib_misc_utils
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance);
static void disable_c3_pixhawk_slib_misc_utils
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_pixhawk_slib_misc_utils
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_pixhawk_slib_misc_utils
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance);
static void set_sim_state_c3_pixhawk_slib_misc_utils
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance, const mxArray
   *c3_st);
static void finalize_c3_pixhawk_slib_misc_utils
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance);
static void sf_gateway_c3_pixhawk_slib_misc_utils
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance);
static void mdl_start_c3_pixhawk_slib_misc_utils
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance);
static void c3_chartstep_c3_pixhawk_slib_misc_utils
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance);
static void initSimStructsc3_pixhawk_slib_misc_utils
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static uint8_T c3_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance, const mxArray *c3_b_vect_size, const char_T *c3_identifier,
  boolean_T *c3_svPtr);
static uint8_T c3_b_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T *c3_svPtr);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint16_T c3_c_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance, const mxArray *c3_b_elem_size, const char_T *c3_identifier,
  boolean_T *c3_svPtr);
static uint16_T c3_d_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T *c3_svPtr);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_e_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance, const mxArray *c3_b_lognumstr, const char_T *c3_identifier,
  boolean_T *c3_svPtr);
static real_T c3_f_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T *c3_svPtr);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint32_T c3_g_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance, const mxArray *c3_b_count, const char_T *c3_identifier,
  boolean_T *c3_svPtr);
static uint32_T c3_h_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T *c3_svPtr);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_i_emlrt_marshallIn
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance, const mxArray
   *c3_b_isopen, const char_T *c3_identifier, boolean_T *c3_svPtr);
static boolean_T c3_j_emlrt_marshallIn
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T *c3_svPtr);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_k_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_k_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint16_T c3_l_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint32_T c3_m_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_l_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_n_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y[8]);
static void c3_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_m_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static uint8_T c3_o_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct *
  chartInstance, const mxArray *c3_elem_type, const char_T *c3_identifier);
static uint8_T c3_p_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_n_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_q_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_r_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  uint8_T c3_y[15]);
static void c3_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static boolean_T c3_s_emlrt_marshallIn
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void init_dsm_address_info(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc3_pixhawk_slib_misc_utilsInstanceStruct *
  chartInstance);

/* Function Definitions */
static void initialize_c3_pixhawk_slib_misc_utils
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc3_pixhawk_slib_misc_utils(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_fp_not_empty = false;
  chartInstance->c3_isflushed_not_empty = false;
  chartInstance->c3_isopen_not_empty = false;
  chartInstance->c3_count_not_empty = false;
  chartInstance->c3_lognumstr_not_empty = false;
  chartInstance->c3_elem_size_not_empty = false;
  chartInstance->c3_vect_size_not_empty = false;
  chartInstance->c3_is_active_c3_pixhawk_slib_misc_utils = 0U;
}

static void initialize_params_c3_pixhawk_slib_misc_utils
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance)
{
  real_T c3_dv0[15];
  int32_T c3_i0;
  real_T c3_d0;
  real_T c3_d1;
  sf_mex_import_named("logname", sf_mex_get_sfun_param(chartInstance->S, 1, 0),
                      c3_dv0, 0, 0, 0U, 1, 0U, 2, 1, 15);
  for (c3_i0 = 0; c3_i0 < 15; c3_i0++) {
    chartInstance->c3_logname[c3_i0] = (uint8_T)c3_dv0[c3_i0];
  }

  sf_mex_import_named("cacheflag", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c3_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_cacheflag = (c3_d0 != 0.0);
  sf_mex_import_named("numRecs", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      &c3_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_numRecs = (uint32_T)c3_d1;
}

static void enable_c3_pixhawk_slib_misc_utils
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_pixhawk_slib_misc_utils
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_pixhawk_slib_misc_utils
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c3_pixhawk_slib_misc_utils
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  uint32_T c3_hoistedGlobal;
  const mxArray *c3_b_y = NULL;
  uint16_T c3_b_hoistedGlobal;
  const mxArray *c3_c_y = NULL;
  boolean_T c3_c_hoistedGlobal;
  const mxArray *c3_d_y = NULL;
  boolean_T c3_d_hoistedGlobal;
  const mxArray *c3_e_y = NULL;
  real_T c3_e_hoistedGlobal;
  const mxArray *c3_f_y = NULL;
  uint8_T c3_f_hoistedGlobal;
  const mxArray *c3_g_y = NULL;
  uint8_T c3_g_hoistedGlobal;
  const mxArray *c3_h_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(7, 1), false);
  c3_hoistedGlobal = chartInstance->c3_count;
  c3_b_y = NULL;
  if (!chartInstance->c3_count_not_empty) {
    sf_mex_assign(&c3_b_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_hoistedGlobal, 7, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = chartInstance->c3_elem_size;
  c3_c_y = NULL;
  if (!chartInstance->c3_elem_size_not_empty) {
    sf_mex_assign(&c3_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_hoistedGlobal, 5, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = chartInstance->c3_isflushed;
  c3_d_y = NULL;
  if (!chartInstance->c3_isopen_not_empty) {
    sf_mex_assign(&c3_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_hoistedGlobal, 11, 0U, 0U,
      0U, 0), false);
  }

  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal = chartInstance->c3_isopen;
  c3_e_y = NULL;
  if (!chartInstance->c3_isopen_not_empty) {
    sf_mex_assign(&c3_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_hoistedGlobal, 11, 0U, 0U,
      0U, 0), false);
  }

  sf_mex_setcell(c3_y, 3, c3_e_y);
  c3_e_hoistedGlobal = chartInstance->c3_lognumstr;
  c3_f_y = NULL;
  if (!chartInstance->c3_lognumstr_not_empty) {
    sf_mex_assign(&c3_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_e_hoistedGlobal, 0, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c3_y, 4, c3_f_y);
  c3_f_hoistedGlobal = chartInstance->c3_vect_size;
  c3_g_y = NULL;
  if (!chartInstance->c3_vect_size_not_empty) {
    sf_mex_assign(&c3_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_f_hoistedGlobal, 3, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c3_y, 5, c3_g_y);
  c3_g_hoistedGlobal = chartInstance->c3_is_active_c3_pixhawk_slib_misc_utils;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c3_y, 6, c3_h_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_pixhawk_slib_misc_utils
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance, const mxArray
   *c3_st)
{
  const mxArray *c3_u;
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  chartInstance->c3_count = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("count", c3_u, 0)), "count",
    &chartInstance->c3_count_not_empty);
  chartInstance->c3_elem_size = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("elem_size", c3_u, 1)), "elem_size",
    &chartInstance->c3_elem_size_not_empty);
  chartInstance->c3_isflushed = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("isflushed", c3_u, 2)), "isflushed",
    &chartInstance->c3_isflushed_not_empty);
  chartInstance->c3_isopen = c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("isopen", c3_u, 3)), "isopen",
    &chartInstance->c3_isopen_not_empty);
  chartInstance->c3_lognumstr = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("lognumstr", c3_u, 4)), "lognumstr",
    &chartInstance->c3_lognumstr_not_empty);
  chartInstance->c3_vect_size = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("vect_size", c3_u, 5)), "vect_size",
    &chartInstance->c3_vect_size_not_empty);
  chartInstance->c3_is_active_c3_pixhawk_slib_misc_utils = c3_o_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(
       "is_active_c3_pixhawk_slib_misc_utils", c3_u, 6)),
     "is_active_c3_pixhawk_slib_misc_utils");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_pixhawk_slib_misc_utils(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_pixhawk_slib_misc_utils
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c3_pixhawk_slib_misc_utils
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance)
{
  int32_T c3_i1;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  for (c3_i1 = 0; c3_i1 < 6; c3_i1++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c3_data)[c3_i1], 1U, 1U, 0U,
                          chartInstance->c3_sfEvent, false);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c3_en, 0U, 1U, 0U,
                        chartInstance->c3_sfEvent, false);
  chartInstance->c3_sfEvent = CALL_EVENT;
  c3_chartstep_c3_pixhawk_slib_misc_utils(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_pixhawk_slib_misc_utilsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c3_pixhawk_slib_misc_utils
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_chartstep_c3_pixhawk_slib_misc_utils
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance)
{
  boolean_T c3_hoistedGlobal;
  boolean_T c3_b_en;
  int32_T c3_i2;
  uint32_T c3_debug_family_var_map[20];
  real32_T c3_b_data[6];
  uint16_T c3_elsize;
  uint8_T c3_eltype;
  uint8_T c3_elem_type;
  char_T c3_mlStrVer[8];
  uint32_T c3_tm;
  uint32_T c3_tmptr;
  uint16_T c3_recSize;
  uint8_T c3_b_logname[15];
  boolean_T c3_b_cacheflag;
  uint32_T c3_b_numRecs;
  real_T c3_nargin = 5.0;
  real_T c3_nargout = 0.0;
  int32_T c3_i3;
  static uint8_T c3_b_x[15] = { 47U, 102U, 115U, 47U, 109U, 105U, 99U, 114U,
    111U, 115U, 100U, 47U, 108U, 111U, 103U };

  uint32_T c3_b_debug_family_var_map[4];
  uint8_T c3_dtype;
  int32_T c3_i4;
  uint16_T c3_b_elem_size;
  real_T c3_c_elem_size;
  real_T c3_b_dtype;
  char_T c3_cv0[28];
  static char_T c3_cv1[28] = { 'C', 'L', 'O', 'S', 'I', 'N', 'G', ' ', 'f', 'i',
    'l', 'e', '.', ' ', 'c', 'o', 'u', 'n', 't', ' ', '=', ' ', '%', 'd', ' ',
    '%', 'c', '\x00' };

  uint32_T c3_q0;
  real_T c3_b_nargin = 1.0;
  uint32_T c3_qY;
  real_T c3_b_nargout = 2.0;
  real_T c3_b_hoistedGlobal;
  real_T c3_varargin_1;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_e_x;
  boolean_T c3_b0;
  const mxArray *c3_y = NULL;
  static char_T c3_cv2[44] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'O', 'u', 't', 'O', 'f', 'T', 'a', 'r', 'g', 'e', 't',
    'R', 'a', 'n', 'g', 'e', 'T', 'r', 'u', 'n', 'c', 'a', 't', 'e', 'd', 'F',
    'l', 'o', 'a', 't' };

  char_T c3_b_y;
  real_T c3_u;
  int32_T c3_i5;
  const mxArray *c3_c_y = NULL;
  real_T c3_b_u;
  char_T c3_cv3[22];
  static char_T c3_cv4[15] = { '/', 'f', 's', '/', 'm', 'i', 'c', 'r', 'o', 's',
    'd', '/', 'l', 'o', 'g' };

  const mxArray *c3_d_y = NULL;
  int32_T c3_i6;
  static char_T c3_cv5[4] = { '.', 'b', 'i', 'n' };

  int32_T c3_i7;
  char_T c3_cv6[56];
  static char_T c3_cv7[56] = { 'O', 'P', 'E', 'N', 'I', 'N', 'G', ' ', 'f', 'i',
    'l', 'e', ' ', '%', 's', ' ', 'v', 'e', 'c', 't', '_', 's', 'i', 'z', 'e',
    ' ', '%', 'd', ' ', 'e', 'l', 'e', 'm', '_', 's', 'i', 'z', 'e', ' ', '%',
    'd', ' ', 'n', 'u', 'm', 'R', 'e', 'c', 's', ' ', '%', 'd', ' ', '%', 'c',
    '\x00' };

  real_T c3_c_hoistedGlobal;
  real_T c3_b_varargin_1;
  real_T c3_f_x;
  real_T c3_g_x;
  real_T c3_h_x;
  boolean_T c3_b1;
  const mxArray *c3_e_y = NULL;
  static char_T c3_cv8[44] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'O', 'u', 't', 'O', 'f', 'T', 'a', 'r', 'g', 'e', 't',
    'R', 'a', 'n', 'g', 'e', 'T', 'r', 'u', 'n', 'c', 'a', 't', 'e', 'd', 'F',
    'l', 'o', 'a', 't' };

  char_T c3_f_y;
  real_T c3_c_u;
  int32_T c3_i8;
  const mxArray *c3_g_y = NULL;
  real_T c3_d_u;
  const mxArray *c3_h_y = NULL;
  int32_T c3_i9;
  int32_T c3_i10;
  char_T c3_cv9[3];
  static char_T c3_cv10[3] = { 'w', 'b', '\x00' };

  int32_T c3_i11;
  static char_T c3_cv11[8] = { 'M', 'W', 'L', 'O', 'G', 'V', '0', '1' };

  uint32_T c3_u0;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *chartInstance->c3_en;
  c3_b_en = c3_hoistedGlobal;
  for (c3_i2 = 0; c3_i2 < 6; c3_i2++) {
    c3_b_data[c3_i2] = (*chartInstance->c3_data)[c3_i2];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 20U, 20U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_elsize, 0U, c3_k_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_eltype, 1U, c3_m_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_elem_type, 2U, c3_m_sf_marshallOut,
    c3_j_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_mlStrVer, 3U, c3_l_sf_marshallOut,
    c3_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_tm, 4U, c3_i_sf_marshallOut,
    c3_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_tmptr, 5U, c3_i_sf_marshallOut,
    c3_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_recSize, 6U, c3_k_sf_marshallOut,
    c3_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_b_logname, 7U, c3_j_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_cacheflag, 8U, c3_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_numRecs, 9U, c3_i_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 10U, c3_h_sf_marshallOut,
    c3_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 11U, c3_h_sf_marshallOut,
    c3_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_en, 12U, c3_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_b_data, 13U, c3_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_isflushed, 14U,
    c3_e_sf_marshallOut, c3_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_isopen, 15U,
    c3_e_sf_marshallOut, c3_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_count, 16U,
    c3_d_sf_marshallOut, c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_lognumstr, 17U,
    c3_c_sf_marshallOut, c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_elem_size, 18U,
    c3_b_sf_marshallOut, c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c3_vect_size, 19U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  c3_b_numRecs = 1000U;
  c3_b_cacheflag = false;
  for (c3_i3 = 0; c3_i3 < 15; c3_i3++) {
    c3_b_logname[c3_i3] = c3_b_x[c3_i3];
  }

  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 15);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 16);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 17);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 19);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c3_count_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 20);
    chartInstance->c3_count = 0U;
    chartInstance->c3_count_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 21);
    chartInstance->c3_lognumstr = 65.0;
    chartInstance->c3_lognumstr_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 22);
    chartInstance->c3_isopen = false;
    chartInstance->c3_isopen_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 23);
    chartInstance->c3_fp = NULL;
    chartInstance->c3_fp_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 24);
    chartInstance->c3_isflushed = false;
    chartInstance->c3_isflushed_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 25);
    chartInstance->c3_elem_size = 1U;
    chartInstance->c3_elem_size_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 26);
    chartInstance->c3_vect_size = 6U;
    chartInstance->c3_vect_size_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 27);
    CV_EML_IF(0, 1, 1, false);
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 32);
  if (CV_EML_IF(0, 1, 2, c3_b_en)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 33);
    if (CV_EML_IF(0, 1, 3, !chartInstance->c3_isopen)) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 34);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 6U, c3_b_debug_family_names,
        c3_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_dtype, MAX_uint32_T,
        c3_m_sf_marshallOut, c3_j_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_elem_size, MAX_uint32_T,
        c3_k_sf_marshallOut, c3_g_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML(&c3_c_elem_size, MAX_uint32_T,
        c3_h_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_dtype, MAX_uint32_T, c3_h_sf_marshallOut);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargin, 2U, c3_h_sf_marshallOut,
        c3_f_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_nargout, 3U,
        c3_h_sf_marshallOut, c3_f_sf_marshallIn);
      CV_EML_FCN(0, 1);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 106);
      CV_EML_SWITCH(0, 1, 0, 2);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 111);
      c3_c_elem_size = 4.0;
      _SFD_SYMBOL_SWITCH(1U, 2U);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 112);
      c3_b_dtype = 2.0;
      _SFD_SYMBOL_SWITCH(0U, 3U);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 139U);
      CV_EML_COND(0, 1, 1, true);
      CV_EML_MCDC(0, 1, 1, false);
      CV_EML_IF(0, 1, 10, false);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 143U);
      c3_b_elem_size = 4U;
      _SFD_SYMBOL_SWITCH(1U, 1U);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 144U);
      c3_dtype = 2U;
      _SFD_SYMBOL_SWITCH(0U, 0U);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -144);
      _SFD_SYMBOL_SCOPE_POP();
      c3_elsize = 4U;
      c3_eltype = 2U;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 35);
      chartInstance->c3_elem_size = 4U;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 36);
      c3_elem_type = 2U;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 37);
      chartInstance->c3_vect_size = 6U;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 38);
      c3_b_hoistedGlobal = chartInstance->c3_lognumstr;
      c3_varargin_1 = c3_b_hoistedGlobal;
      c3_c_x = c3_varargin_1;
      c3_d_x = c3_c_x;
      c3_e_x = c3_d_x;
      if ((0.0 <= c3_e_x) && (c3_e_x <= 255.0)) {
        c3_b0 = true;
      } else {
        c3_b0 = false;
      }

      if (c3_b0) {
      } else {
        c3_y = NULL;
        sf_mex_assign(&c3_y, sf_mex_create("y", c3_cv2, 10, 0U, 1U, 0U, 2, 1, 44),
                      false);
        c3_u = 0.0;
        c3_c_y = NULL;
        sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0),
                      false);
        c3_b_u = 255.0;
        c3_d_y = NULL;
        sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                          sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "message", 1U, 3U, 14, c3_y, 14, c3_c_y, 14, c3_d_y));
      }

      c3_b_y = (char_T)c3_d_x;
      for (c3_i5 = 0; c3_i5 < 15; c3_i5++) {
        c3_cv3[c3_i5] = c3_cv4[c3_i5];
      }

      c3_cv3[15] = '_';
      c3_cv3[16] = c3_b_y;
      for (c3_i6 = 0; c3_i6 < 4; c3_i6++) {
        c3_cv3[c3_i6 + 17] = c3_cv5[c3_i6];
      }

      c3_cv3[21] = '\x00';
      for (c3_i7 = 0; c3_i7 < 56; c3_i7++) {
        c3_cv6[c3_i7] = c3_cv7[c3_i7];
      }

      printf(c3_cv6, c3_cv3, (uint32_T)chartInstance->c3_vect_size, (uint32_T)
             chartInstance->c3_elem_size, 1000U, 10U);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 40);
      c3_c_hoistedGlobal = chartInstance->c3_lognumstr;
      c3_b_varargin_1 = c3_c_hoistedGlobal;
      c3_f_x = c3_b_varargin_1;
      c3_g_x = c3_f_x;
      c3_h_x = c3_g_x;
      if ((0.0 <= c3_h_x) && (c3_h_x <= 255.0)) {
        c3_b1 = true;
      } else {
        c3_b1 = false;
      }

      if (c3_b1) {
      } else {
        c3_e_y = NULL;
        sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_cv8, 10, 0U, 1U, 0U, 2, 1,
          44), false);
        c3_c_u = 0.0;
        c3_g_y = NULL;
        sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0),
                      false);
        c3_d_u = 255.0;
        c3_h_y = NULL;
        sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0),
                      false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                          sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "message", 1U, 3U, 14, c3_e_y, 14, c3_g_y, 14, c3_h_y));
      }

      c3_f_y = (char_T)c3_g_x;
      for (c3_i8 = 0; c3_i8 < 15; c3_i8++) {
        c3_cv3[c3_i8] = c3_cv4[c3_i8];
      }

      c3_cv3[15] = '_';
      c3_cv3[16] = c3_f_y;
      for (c3_i9 = 0; c3_i9 < 4; c3_i9++) {
        c3_cv3[c3_i9 + 17] = c3_cv5[c3_i9];
      }

      c3_cv3[21] = '\x00';
      for (c3_i10 = 0; c3_i10 < 3; c3_i10++) {
        c3_cv9[c3_i10] = c3_cv10[c3_i10];
      }

      chartInstance->c3_fp = fopen(c3_cv3, c3_cv9);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 41);
      chartInstance->c3_lognumstr++;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 42);
      chartInstance->c3_isflushed = false;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 43);
      chartInstance->c3_count = 0U;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 44);
      chartInstance->c3_isopen = true;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 47);
      for (c3_i11 = 0; c3_i11 < 8; c3_i11++) {
        c3_mlStrVer[c3_i11] = c3_cv11[c3_i11];
      }

      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 48);
      fwrite(c3_mlStrVer, 1U, 8.0, chartInstance->c3_fp);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 50);
      c3_tm = 0U;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 51);
      c3_tmptr = 0U;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 52);
      c3_tm = time(&c3_tmptr);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 53);
      fwrite(&c3_tm, 4U, 1U, chartInstance->c3_fp);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 55);
      fwrite(&chartInstance->c3_vect_size, 1U, 1U, chartInstance->c3_fp);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 57);
      fwrite(&c3_elem_type, 1U, 1U, chartInstance->c3_fp);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 59);
      c3_u0 = (uint32_T)chartInstance->c3_elem_size * (uint32_T)
        chartInstance->c3_vect_size;
      if (CV_SATURATION_EVAL(4, 0, 0, 0, c3_u0 > 65535U)) {
        c3_u0 = 65535U;
      }

      c3_recSize = (uint16_T)c3_u0;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 60);
      fwrite(&c3_recSize, 2U, 1U, chartInstance->c3_fp);
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 63);
    CV_EML_IF(0, 1, 4, false);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 70);
    fwrite(c3_b_data, chartInstance->c3_elem_size, chartInstance->c3_vect_size,
           chartInstance->c3_fp);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 72);
    c3_q0 = chartInstance->c3_count;
    c3_qY = c3_q0 + 1U;
    if (CV_SATURATION_EVAL(4, 0, 1, 0, c3_qY < c3_q0)) {
      c3_qY = MAX_uint32_T;
    }

    chartInstance->c3_count = c3_qY;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 74);
    if (CV_EML_IF(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 0, (real_T)
          chartInstance->c3_count, 1000.0, 0, 5U, chartInstance->c3_count >=
          1000U))) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 75);
      CV_EML_IF(0, 1, 6, false);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 80);
      fflush(chartInstance->c3_fp);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 81);
      chartInstance->c3_isflushed = false;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 82);
      chartInstance->c3_count = 0U;
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 85);
    if (CV_EML_IF(0, 1, 7, chartInstance->c3_isopen)) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 86);
      if (CV_EML_IF(0, 1, 8, CV_EML_MCDC(0, 1, 0, !CV_EML_COND(0, 1, 0,
             chartInstance->c3_isflushed)))) {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 87);
        for (c3_i4 = 0; c3_i4 < 28; c3_i4++) {
          c3_cv0[c3_i4] = c3_cv1[c3_i4];
        }

        printf(c3_cv0, chartInstance->c3_count, 10U);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 88);
        CV_EML_IF(0, 1, 9, false);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 94);
        fflush(chartInstance->c3_fp);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 95);
        chartInstance->c3_isflushed = true;
      }

      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 97);
      fclose(chartInstance->c3_fp);
    }

    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 99);
    chartInstance->c3_isopen = false;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 100);
    chartInstance->c3_count = 0U;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -100);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c3_sfEvent);
}

static void initSimStructsc3_pixhawk_slib_misc_utils
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  (void)c3_chartNumber;
  (void)c3_instanceNumber;
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_vect_size_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance, const mxArray *c3_b_vect_size, const char_T *c3_identifier,
  boolean_T *c3_svPtr)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_vect_size),
    &c3_thisId, c3_svPtr);
  sf_mex_destroy(&c3_b_vect_size);
  return c3_y;
}

static uint8_T c3_b_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T *c3_svPtr)
{
  uint8_T c3_y;
  uint8_T c3_u1;
  (void)chartInstance;
  if (mxIsEmpty(c3_u)) {
    *c3_svPtr = false;
  } else {
    *c3_svPtr = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u1, 1, 3, 0U, 0, 0U, 0);
    c3_y = c3_u1;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_vect_size;
  const char_T *c3_identifier;
  boolean_T *c3_svPtr;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_b_vect_size = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_svPtr = &chartInstance->c3_vect_size_not_empty;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_vect_size),
    &c3_thisId, c3_svPtr);
  sf_mex_destroy(&c3_b_vect_size);
  *(uint8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  uint16_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint16_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_elem_size_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 5, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint16_T c3_c_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance, const mxArray *c3_b_elem_size, const char_T *c3_identifier,
  boolean_T *c3_svPtr)
{
  uint16_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_elem_size),
    &c3_thisId, c3_svPtr);
  sf_mex_destroy(&c3_b_elem_size);
  return c3_y;
}

static uint16_T c3_d_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T *c3_svPtr)
{
  uint16_T c3_y;
  uint16_T c3_u2;
  (void)chartInstance;
  if (mxIsEmpty(c3_u)) {
    *c3_svPtr = false;
  } else {
    *c3_svPtr = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u2, 1, 5, 0U, 0, 0U, 0);
    c3_y = c3_u2;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_elem_size;
  const char_T *c3_identifier;
  boolean_T *c3_svPtr;
  emlrtMsgIdentifier c3_thisId;
  uint16_T c3_y;
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_b_elem_size = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_svPtr = &chartInstance->c3_elem_size_not_empty;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_elem_size),
    &c3_thisId, c3_svPtr);
  sf_mex_destroy(&c3_b_elem_size);
  *(uint16_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_lognumstr_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_e_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance, const mxArray *c3_b_lognumstr, const char_T *c3_identifier,
  boolean_T *c3_svPtr)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_lognumstr),
    &c3_thisId, c3_svPtr);
  sf_mex_destroy(&c3_b_lognumstr);
  return c3_y;
}

static real_T c3_f_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T *c3_svPtr)
{
  real_T c3_y;
  real_T c3_d2;
  (void)chartInstance;
  if (mxIsEmpty(c3_u)) {
    *c3_svPtr = false;
  } else {
    *c3_svPtr = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d2, 1, 0, 0U, 0, 0U, 0);
    c3_y = c3_d2;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_lognumstr;
  const char_T *c3_identifier;
  boolean_T *c3_svPtr;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_b_lognumstr = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_svPtr = &chartInstance->c3_lognumstr_not_empty;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_lognumstr),
    &c3_thisId, c3_svPtr);
  sf_mex_destroy(&c3_b_lognumstr);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  uint32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint32_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_count_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 7, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint32_T c3_g_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance, const mxArray *c3_b_count, const char_T *c3_identifier,
  boolean_T *c3_svPtr)
{
  uint32_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_count), &c3_thisId,
    c3_svPtr);
  sf_mex_destroy(&c3_b_count);
  return c3_y;
}

static uint32_T c3_h_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  boolean_T *c3_svPtr)
{
  uint32_T c3_y;
  uint32_T c3_u3;
  (void)chartInstance;
  if (mxIsEmpty(c3_u)) {
    *c3_svPtr = false;
  } else {
    *c3_svPtr = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u3, 1, 7, 0U, 0, 0U, 0);
    c3_y = c3_u3;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_count;
  const char_T *c3_identifier;
  boolean_T *c3_svPtr;
  emlrtMsgIdentifier c3_thisId;
  uint32_T c3_y;
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_b_count = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_svPtr = &chartInstance->c3_count_not_empty;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_count), &c3_thisId,
    c3_svPtr);
  sf_mex_destroy(&c3_b_count);
  *(uint32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  if (!chartInstance->c3_isopen_not_empty) {
    sf_mex_assign(&c3_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_i_emlrt_marshallIn
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance, const mxArray
   *c3_b_isopen, const char_T *c3_identifier, boolean_T *c3_svPtr)
{
  boolean_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_isopen),
    &c3_thisId, c3_svPtr);
  sf_mex_destroy(&c3_b_isopen);
  return c3_y;
}

static boolean_T c3_j_emlrt_marshallIn
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId, boolean_T *c3_svPtr)
{
  boolean_T c3_y;
  boolean_T c3_b2;
  (void)chartInstance;
  if (mxIsEmpty(c3_u)) {
    *c3_svPtr = false;
  } else {
    *c3_svPtr = true;
    sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b2, 1, 11, 0U, 0, 0U, 0);
    c3_y = c3_b2;
  }

  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_isopen;
  const char_T *c3_identifier;
  boolean_T *c3_svPtr;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_b_isopen = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_svPtr = &chartInstance->c3_isopen_not_empty;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_isopen),
    &c3_thisId, c3_svPtr);
  sf_mex_destroy(&c3_b_isopen);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_i12;
  const mxArray *c3_y = NULL;
  real32_T c3_u[6];
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  for (c3_i12 = 0; c3_i12 < 6; c3_i12++) {
    c3_u[c3_i12] = (*(real32_T (*)[6])c3_inData)[c3_i12];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 1, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_k_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d3;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d3, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d3;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  uint32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_j_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_i13;
  const mxArray *c3_y = NULL;
  uint8_T c3_u[15];
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  for (c3_i13 = 0; c3_i13 < 15; c3_i13++) {
    c3_u[c3_i13] = (*(uint8_T (*)[15])c3_inData)[c3_i13];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 3, 0U, 1U, 0U, 2, 1, 15), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_k_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  uint16_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint16_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint16_T c3_l_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint16_T c3_y;
  uint16_T c3_u4;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u4, 1, 5, 0U, 0, 0U, 0);
  c3_y = c3_u4;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_recSize;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint16_T c3_y;
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_recSize = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_recSize), &c3_thisId);
  sf_mex_destroy(&c3_recSize);
  *(uint16_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint32_T c3_m_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint32_T c3_y;
  uint32_T c3_u5;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u5, 1, 7, 0U, 0, 0U, 0);
  c3_y = c3_u5;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_tmptr;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint32_T c3_y;
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_tmptr = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_tmptr), &c3_thisId);
  sf_mex_destroy(&c3_tmptr);
  *(uint32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_l_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_i14;
  const mxArray *c3_y = NULL;
  char_T c3_u[8];
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  for (c3_i14 = 0; c3_i14 < 8; c3_i14++) {
    c3_u[c3_i14] = (*(char_T (*)[8])c3_inData)[c3_i14];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 8), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_n_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  char_T c3_y[8])
{
  char_T c3_cv12[8];
  int32_T c3_i15;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_cv12, 1, 10, 0U, 1, 0U, 2, 1,
                8);
  for (c3_i15 = 0; c3_i15 < 8; c3_i15++) {
    c3_y[c3_i15] = c3_cv12[c3_i15];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_mlStrVer;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  char_T c3_y[8];
  int32_T c3_i16;
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_mlStrVer = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_mlStrVer), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_mlStrVer);
  for (c3_i16 = 0; c3_i16 < 8; c3_i16++) {
    (*(char_T (*)[8])c3_outData)[c3_i16] = c3_y[c3_i16];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_m_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static uint8_T c3_o_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct *
  chartInstance, const mxArray *c3_elem_type, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_elem_type),
    &c3_thisId);
  sf_mex_destroy(&c3_elem_type);
  return c3_y;
}

static uint8_T c3_p_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u6;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u6, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u6;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_elem_type;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y;
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_elem_type = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_elem_type),
    &c3_thisId);
  sf_mex_destroy(&c3_elem_type);
  *(uint8_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_pixhawk_slib_misc_utils_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c3_nameCaptureInfo;
}

static const mxArray *c3_n_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_q_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct *
  chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i17;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i17, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i17;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static void c3_r_emlrt_marshallIn(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  uint8_T c3_y[15])
{
  uint8_T c3_uv0[15];
  int32_T c3_i18;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_uv0, 1, 3, 0U, 1, 0U, 2, 1, 15);
  for (c3_i18 = 0; c3_i18 < 15; c3_i18++) {
    c3_y[c3_i18] = c3_uv0[c3_i18];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_logname;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  uint8_T c3_y[15];
  int32_T c3_i19;
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_b_logname = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_logname), &c3_thisId,
                        c3_y);
  sf_mex_destroy(&c3_b_logname);
  for (c3_i19 = 0; c3_i19 < 15; c3_i19++) {
    (*(uint8_T (*)[15])c3_outData)[c3_i19] = c3_y[c3_i19];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static boolean_T c3_s_emlrt_marshallIn
  (SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b3;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b3, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b3;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_cacheflag;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)
    chartInstanceVoid;
  c3_b_cacheflag = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_thisId.bParentIsCell = false;
  c3_y = c3_s_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_cacheflag),
    &c3_thisId);
  sf_mex_destroy(&c3_b_cacheflag);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static void init_dsm_address_info(SFc3_pixhawk_slib_misc_utilsInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_pixhawk_slib_misc_utilsInstanceStruct *
  chartInstance)
{
  chartInstance->c3_en = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c3_data = (real32_T (*)[6])ssGetInputPortSignal_wrapper
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

void sf_c3_pixhawk_slib_misc_utils_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1096216885U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1100550230U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2932693165U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2007938665U);
}

mxArray* sf_c3_pixhawk_slib_misc_utils_get_post_codegen_info(void);
mxArray *sf_c3_pixhawk_slib_misc_utils_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("5TQ6Q3Tsew2lZ0Yu98sYk");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(9));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(15);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(7));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c3_pixhawk_slib_misc_utils_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_pixhawk_slib_misc_utils_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_pixhawk_slib_misc_utils_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("printf");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c3_pixhawk_slib_misc_utils_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_pixhawk_slib_misc_utils_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c3_pixhawk_slib_misc_utils(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[4],M[0],T\"count\",S'l','i','p'{{M1x2[627 632],M[0],}}},{M[4],M[0],T\"elem_size\",S'l','i','p'{{M1x2[643 652],M[0],}}},{M[4],M[0],T\"isflushed\",S'l','i','p'{{M1x2[610 619],M[0],}}},{M[4],M[0],T\"isopen\",S'l','i','p'{{M1x2[620 626],M[0],}}},{M[4],M[0],T\"lognumstr\",S'l','i','p'{{M1x2[633 642],M[0],}}},{M[4],M[0],T\"vect_size\",S'l','i','p'{{M1x2[653 662],M[0],}}},{M[8],M[0],T\"is_active_c3_pixhawk_slib_misc_utils\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_pixhawk_slib_misc_utils_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance =
      (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _pixhawk_slib_misc_utilsMachineNumber_,
           3,
           1,
           1,
           0,
           5,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_pixhawk_slib_misc_utilsMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_pixhawk_slib_misc_utilsMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _pixhawk_slib_misc_utilsMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"en");
          _SFD_SET_DATA_PROPS(1,1,1,0,"data");
          _SFD_SET_DATA_PROPS(2,10,0,0,"cacheflag");
          _SFD_SET_DATA_PROPS(3,10,0,0,"logname");
          _SFD_SET_DATA_PROPS(4,10,0,0,"numRecs");
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
        _SFD_CV_INIT_EML(0,1,2,0,11,0,2,1,3,0,2,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",520,-1,4153);
        _SFD_CV_INIT_EML_FCN(0,1,"get_elem_size",4197,-1,5204);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,2601,-1,2630);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,3096,-1,3113);
        _SFD_CV_INIT_EML_IF(0,1,0,743,760,-1,1129);
        _SFD_CV_INIT_EML_IF(0,1,1,999,1019,-1,1121);
        _SFD_CV_INIT_EML_IF(0,1,2,1135,1142,3507,4149);
        _SFD_CV_INIT_EML_IF(0,1,3,1151,1169,-1,2725);
        _SFD_CV_INIT_EML_IF(0,1,4,2779,2799,2984,3079);
        _SFD_CV_INIT_EML_IF(0,1,5,3160,3179,-1,3502);
        _SFD_CV_INIT_EML_IF(0,1,6,3192,3204,-1,3389);
        _SFD_CV_INIT_EML_IF(0,1,7,3520,3537,-1,4090);
        _SFD_CV_INIT_EML_IF(0,1,8,3550,3563,-1,4039);
        _SFD_CV_INIT_EML_IF(0,1,9,3686,3698,-1,3946);
        _SFD_CV_INIT_EML_IF(0,1,10,5077,5093,-1,5134);
        _SFD_CV_INIT_EML_FOR(0,1,0,2860,2882,2975);
        _SFD_CV_INIT_EML_FOR(0,1,1,3221,3257,3373);
        _SFD_CV_INIT_EML_FOR(0,1,2,3766,3802,3926);

        {
          static int caseStart[] = { -1, 4279, 4351, 4423, 4494, 4566, 4637,
            4709, 4779, 4850, 4923 };

          static int caseExprEnd[] = { 8, 4292, 4364, 4435, 4507, 4578, 4650,
            4720, 4791, 4864, 4941 };

          _SFD_CV_INIT_EML_SWITCH(0,1,0,4251,4270,5072,11,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        {
          static int condStart[] = { 3554 };

          static int condEnd[] = { 3563 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,3553,3563,1,0,&(condStart[0]),&(condEnd[0]),
                                2,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 5081 };

          static int condEnd[] = { 5093 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,5080,5093,1,1,&(condStart[0]),&(condEnd[0]),
                                2,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,3163,3179,0,5);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_g_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_SINGLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_g_sf_marshallOut,(MexInFcnForType)c3_m_sf_marshallIn);

        {
          unsigned int dimVector[2];
          dimVector[0]= 1U;
          dimVector[1]= 15U;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_j_sf_marshallOut,(MexInFcnForType)
            c3_l_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_i_sf_marshallOut,(MexInFcnForType)c3_h_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _pixhawk_slib_misc_utilsMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance =
      (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c3_en);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c3_data);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c3_logname);
        _SFD_SET_DATA_VALUE_PTR(2U, &chartInstance->c3_cacheflag);
        _SFD_SET_DATA_VALUE_PTR(4U, &chartInstance->c3_numRecs);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "suhZP2NPVfu6W5FrhE1hv7D";
}

static void sf_opaque_initialize_c3_pixhawk_slib_misc_utils(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_pixhawk_slib_misc_utilsInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_pixhawk_slib_misc_utils
    ((SFc3_pixhawk_slib_misc_utilsInstanceStruct*) chartInstanceVar);
  initialize_c3_pixhawk_slib_misc_utils
    ((SFc3_pixhawk_slib_misc_utilsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_pixhawk_slib_misc_utils(void *chartInstanceVar)
{
  enable_c3_pixhawk_slib_misc_utils((SFc3_pixhawk_slib_misc_utilsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c3_pixhawk_slib_misc_utils(void *chartInstanceVar)
{
  disable_c3_pixhawk_slib_misc_utils((SFc3_pixhawk_slib_misc_utilsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c3_pixhawk_slib_misc_utils(void *chartInstanceVar)
{
  sf_gateway_c3_pixhawk_slib_misc_utils
    ((SFc3_pixhawk_slib_misc_utilsInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_pixhawk_slib_misc_utils
  (SimStruct* S)
{
  return get_sim_state_c3_pixhawk_slib_misc_utils
    ((SFc3_pixhawk_slib_misc_utilsInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_pixhawk_slib_misc_utils(SimStruct* S,
  const mxArray *st)
{
  set_sim_state_c3_pixhawk_slib_misc_utils
    ((SFc3_pixhawk_slib_misc_utilsInstanceStruct*)sf_get_chart_instance_ptr(S),
     st);
}

static void sf_opaque_terminate_c3_pixhawk_slib_misc_utils(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_pixhawk_slib_misc_utilsInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_pixhawk_slib_misc_utils_optimization_info();
    }

    finalize_c3_pixhawk_slib_misc_utils
      ((SFc3_pixhawk_slib_misc_utilsInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_pixhawk_slib_misc_utils
    ((SFc3_pixhawk_slib_misc_utilsInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_pixhawk_slib_misc_utils(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_pixhawk_slib_misc_utils
      ((SFc3_pixhawk_slib_misc_utilsInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c3_pixhawk_slib_misc_utils(SimStruct *S)
{
  /* Actual parameters from chart:
     cacheflag logname numRecs
   */
  const char_T *rtParamNames[] = { "cacheflag", "logname", "numRecs" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for cacheflag*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_BOOLEAN);

  /* registration for logname*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_UINT8);

  /* registration for numRecs*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_UINT32);

  /* Set overwritable ports for inplace optimization */
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_pixhawk_slib_misc_utils_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 3);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=0; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3517996530U));
  ssSetChecksum1(S,(973822275U));
  ssSetChecksum2(S,(263278085U));
  ssSetChecksum3(S,(986323445U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetSimStateCompliance(S, DISALLOW_SIM_STATE);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_pixhawk_slib_misc_utils(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_pixhawk_slib_misc_utils(SimStruct *S)
{
  SFc3_pixhawk_slib_misc_utilsInstanceStruct *chartInstance;
  chartInstance = (SFc3_pixhawk_slib_misc_utilsInstanceStruct *)utMalloc(sizeof
    (SFc3_pixhawk_slib_misc_utilsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc3_pixhawk_slib_misc_utilsInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_pixhawk_slib_misc_utils;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_pixhawk_slib_misc_utils;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_pixhawk_slib_misc_utils;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c3_pixhawk_slib_misc_utils;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_pixhawk_slib_misc_utils;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_pixhawk_slib_misc_utils;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_pixhawk_slib_misc_utils;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_pixhawk_slib_misc_utils;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_pixhawk_slib_misc_utils;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_pixhawk_slib_misc_utils;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_pixhawk_slib_misc_utils;
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
  mdl_start_c3_pixhawk_slib_misc_utils(chartInstance);
}

void c3_pixhawk_slib_misc_utils_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_pixhawk_slib_misc_utils(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_pixhawk_slib_misc_utils(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_pixhawk_slib_misc_utils(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_pixhawk_slib_misc_utils_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
