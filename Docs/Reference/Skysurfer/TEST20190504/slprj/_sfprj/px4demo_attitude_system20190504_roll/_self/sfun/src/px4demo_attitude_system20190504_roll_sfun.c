/* Include files */

#include "px4demo_attitude_system20190504_roll_sfun.h"
#include "px4demo_attitude_system20190504_roll_sfun_debug_macros.h"
#include "c1_px4demo_attitude_system20190504_roll.h"
#include "c7_px4demo_attitude_system20190504_roll.h"
#include "c8_px4demo_attitude_system20190504_roll.h"
#include "c15_px4demo_attitude_system20190504_roll.h"
#include "c19_px4demo_attitude_system20190504_roll.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _px4demo_attitude_system20190504_rollMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void px4demo_attitude_system20190504_roll_initializer(void)
{
}

void px4demo_attitude_system20190504_roll_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_px4demo_attitude_system20190504_roll_method_dispatcher(SimStruct
  *simstructPtr, unsigned int chartFileNumber, const char* specsCksum, int_T
  method, void *data)
{
  if (chartFileNumber==1) {
    c1_px4demo_attitude_system20190504_roll_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_px4demo_attitude_system20190504_roll_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_px4demo_attitude_system20190504_roll_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_px4demo_attitude_system20190504_roll_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  if (chartFileNumber==19) {
    c19_px4demo_attitude_system20190504_roll_method_dispatcher(simstructPtr,
      method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_px4demo_attitude_system20190504_roll_process_check_sum_call( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2486770927U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(363137476U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2217399885U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(821699285U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_px4demo_attitude_system20190504_roll_get_check_sum
            (mxArray *plhs[]);
          sf_c1_px4demo_attitude_system20190504_roll_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_px4demo_attitude_system20190504_roll_get_check_sum
            (mxArray *plhs[]);
          sf_c7_px4demo_attitude_system20190504_roll_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_px4demo_attitude_system20190504_roll_get_check_sum
            (mxArray *plhs[]);
          sf_c8_px4demo_attitude_system20190504_roll_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_px4demo_attitude_system20190504_roll_get_check_sum
            (mxArray *plhs[]);
          sf_c15_px4demo_attitude_system20190504_roll_get_check_sum(plhs);
          break;
        }

       case 19:
        {
          extern void sf_c19_px4demo_attitude_system20190504_roll_get_check_sum
            (mxArray *plhs[]);
          sf_c19_px4demo_attitude_system20190504_roll_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3429898665U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(479754071U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3100092396U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1773797558U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2910700888U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(82843379U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3172943982U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2898684264U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_px4demo_attitude_system20190504_roll_autoinheritance_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "r1lW1ftBcUmdELO1tTCKkF") == 0) {
          extern mxArray
            *sf_c1_px4demo_attitude_system20190504_roll_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c1_px4demo_attitude_system20190504_roll_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "r1lW1ftBcUmdELO1tTCKkF") == 0) {
          extern mxArray
            *sf_c7_px4demo_attitude_system20190504_roll_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c7_px4demo_attitude_system20190504_roll_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "r1lW1ftBcUmdELO1tTCKkF") == 0) {
          extern mxArray
            *sf_c8_px4demo_attitude_system20190504_roll_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c8_px4demo_attitude_system20190504_roll_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "r1lW1ftBcUmdELO1tTCKkF") == 0) {
          extern mxArray
            *sf_c15_px4demo_attitude_system20190504_roll_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c15_px4demo_attitude_system20190504_roll_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 19:
      {
        if (strcmp(aiChksum, "r1lW1ftBcUmdELO1tTCKkF") == 0) {
          extern mxArray
            *sf_c19_px4demo_attitude_system20190504_roll_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c19_px4demo_attitude_system20190504_roll_get_autoinheritance_info
            ();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int
  sf_px4demo_attitude_system20190504_roll_get_eml_resolved_functions_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray
          *sf_c1_px4demo_attitude_system20190504_roll_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_px4demo_attitude_system20190504_roll_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_px4demo_attitude_system20190504_roll_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_px4demo_attitude_system20190504_roll_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_px4demo_attitude_system20190504_roll_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_px4demo_attitude_system20190504_roll_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_px4demo_attitude_system20190504_roll_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_px4demo_attitude_system20190504_roll_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 19:
      {
        extern const mxArray
          *sf_c19_px4demo_attitude_system20190504_roll_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c19_px4demo_attitude_system20190504_roll_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_px4demo_attitude_system20190504_roll_third_party_uses_info( int
  nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "sCvg3KDx4g5R3NWdktYk2VB") == 0) {
          extern mxArray
            *sf_c1_px4demo_attitude_system20190504_roll_third_party_uses_info
            (void);
          plhs[0] =
            sf_c1_px4demo_attitude_system20190504_roll_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "sCvg3KDx4g5R3NWdktYk2VB") == 0) {
          extern mxArray
            *sf_c7_px4demo_attitude_system20190504_roll_third_party_uses_info
            (void);
          plhs[0] =
            sf_c7_px4demo_attitude_system20190504_roll_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "sCvg3KDx4g5R3NWdktYk2VB") == 0) {
          extern mxArray
            *sf_c8_px4demo_attitude_system20190504_roll_third_party_uses_info
            (void);
          plhs[0] =
            sf_c8_px4demo_attitude_system20190504_roll_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "sCvg3KDx4g5R3NWdktYk2VB") == 0) {
          extern mxArray
            *sf_c15_px4demo_attitude_system20190504_roll_third_party_uses_info
            (void);
          plhs[0] =
            sf_c15_px4demo_attitude_system20190504_roll_third_party_uses_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "sCvg3KDx4g5R3NWdktYk2VB") == 0) {
          extern mxArray
            *sf_c19_px4demo_attitude_system20190504_roll_third_party_uses_info
            (void);
          plhs[0] =
            sf_c19_px4demo_attitude_system20190504_roll_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_px4demo_attitude_system20190504_roll_jit_fallback_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the jit_fallback_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_jit_fallback_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "sCvg3KDx4g5R3NWdktYk2VB") == 0) {
          extern mxArray
            *sf_c1_px4demo_attitude_system20190504_roll_jit_fallback_info(void);
          plhs[0] = sf_c1_px4demo_attitude_system20190504_roll_jit_fallback_info
            ();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "sCvg3KDx4g5R3NWdktYk2VB") == 0) {
          extern mxArray
            *sf_c7_px4demo_attitude_system20190504_roll_jit_fallback_info(void);
          plhs[0] = sf_c7_px4demo_attitude_system20190504_roll_jit_fallback_info
            ();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "sCvg3KDx4g5R3NWdktYk2VB") == 0) {
          extern mxArray
            *sf_c8_px4demo_attitude_system20190504_roll_jit_fallback_info(void);
          plhs[0] = sf_c8_px4demo_attitude_system20190504_roll_jit_fallback_info
            ();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "sCvg3KDx4g5R3NWdktYk2VB") == 0) {
          extern mxArray
            *sf_c15_px4demo_attitude_system20190504_roll_jit_fallback_info(void);
          plhs[0] =
            sf_c15_px4demo_attitude_system20190504_roll_jit_fallback_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "sCvg3KDx4g5R3NWdktYk2VB") == 0) {
          extern mxArray
            *sf_c19_px4demo_attitude_system20190504_roll_jit_fallback_info(void);
          plhs[0] =
            sf_c19_px4demo_attitude_system20190504_roll_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_px4demo_attitude_system20190504_roll_updateBuildInfo_args_info
  ( int nlhs, mxArray * plhs[], int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "sCvg3KDx4g5R3NWdktYk2VB") == 0) {
          extern mxArray
            *sf_c1_px4demo_attitude_system20190504_roll_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c1_px4demo_attitude_system20190504_roll_updateBuildInfo_args_info
            ();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "sCvg3KDx4g5R3NWdktYk2VB") == 0) {
          extern mxArray
            *sf_c7_px4demo_attitude_system20190504_roll_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c7_px4demo_attitude_system20190504_roll_updateBuildInfo_args_info
            ();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "sCvg3KDx4g5R3NWdktYk2VB") == 0) {
          extern mxArray
            *sf_c8_px4demo_attitude_system20190504_roll_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c8_px4demo_attitude_system20190504_roll_updateBuildInfo_args_info
            ();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "sCvg3KDx4g5R3NWdktYk2VB") == 0) {
          extern mxArray
            *sf_c15_px4demo_attitude_system20190504_roll_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c15_px4demo_attitude_system20190504_roll_updateBuildInfo_args_info
            ();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "sCvg3KDx4g5R3NWdktYk2VB") == 0) {
          extern mxArray
            *sf_c19_px4demo_attitude_system20190504_roll_updateBuildInfo_args_info
            (void);
          plhs[0] =
            sf_c19_px4demo_attitude_system20190504_roll_updateBuildInfo_args_info
            ();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void px4demo_attitude_system20190504_roll_debug_initialize(struct
  SfDebugInstanceStruct* debugInstance)
{
  _px4demo_attitude_system20190504_rollMachineNumber_ =
    sf_debug_initialize_machine(debugInstance,
    "px4demo_attitude_system20190504_roll","sfun",0,19,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _px4demo_attitude_system20190504_rollMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _px4demo_attitude_system20190504_rollMachineNumber_,0);
}

void px4demo_attitude_system20190504_roll_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
typedef struct SfOptimizationInfoFlagsTag {
  boolean_T isRtwGen;
  boolean_T isModelRef;
  boolean_T isExternal;
} SfOptimizationInfoFlags;

static SfOptimizationInfoFlags sOptimizationInfoFlags;
void unload_px4demo_attitude_system20190504_roll_optimization_info(void);
mxArray* load_px4demo_attitude_system20190504_roll_optimization_info(boolean_T
  isRtwGen, boolean_T isModelRef, boolean_T isExternal)
{
  if (sOptimizationInfoFlags.isRtwGen != isRtwGen ||
      sOptimizationInfoFlags.isModelRef != isModelRef ||
      sOptimizationInfoFlags.isExternal != isExternal) {
    unload_px4demo_attitude_system20190504_roll_optimization_info();
  }

  sOptimizationInfoFlags.isRtwGen = isRtwGen;
  sOptimizationInfoFlags.isModelRef = isModelRef;
  sOptimizationInfoFlags.isExternal = isExternal;
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "px4demo_attitude_system20190504_roll",
      "px4demo_attitude_system20190504_roll");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_px4demo_attitude_system20190504_roll_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
