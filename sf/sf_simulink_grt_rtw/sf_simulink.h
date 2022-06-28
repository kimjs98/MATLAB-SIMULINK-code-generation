/*
 * sf_simulink.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "sf_simulink".
 *
 * Model version              : 1.23
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Wed Jun 22 15:35:32 2022
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_sf_simulink_h_
#define RTW_HEADER_sf_simulink_h_
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef sf_simulink_COMMON_INCLUDES_
# define sf_simulink_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* sf_simulink_COMMON_INCLUDES_ */

#include "sf_simulink_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->inputs = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

#define sf_simulink_M_TYPE             RT_MODEL_sf_simulink_T

/* Block states (default storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c4_sf_simulink;    /* '<S3>/bad lane' */
  uint8_T is_active_c2_sf_simulink;    /* '<S3>/acceident' */
  uint8_T is_active_c3_sf_simulink;    /* '<S2>/cruser chart' */
  uint8_T is_active_c1_sf_simulink;    /* '<S2>/check speed chart' */
} DW_sf_simulink_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  CAM Input;                           /* '<Root>/Input' */
  LIDAR Input1;                        /* '<Root>/Input1' */
} ExtU_sf_simulink_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  OUTPUT Output;                       /* '<Root>/Output' */
} ExtY_sf_simulink_T;

/* Real-time Model Data Structure */
struct tag_RTM_sf_simulink_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;
  ExtU_sf_simulink_T *inputs;
  ExtY_sf_simulink_T *outputs;
  DW_sf_simulink_T *dwork;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* External data declarations for dependent source files */
extern const OUTPUT sf_simulink_rtZOUTPUT;/* OUTPUT ground */
extern const char *RT_MEMORY_ALLOCATION_ERROR;

/* Model entry point functions */
extern RT_MODEL_sf_simulink_T *sf_simulink(void);
extern void sf_simulink_initialize(RT_MODEL_sf_simulink_T *const sf_simulink_M);
extern void sf_simulink_step(RT_MODEL_sf_simulink_T *const sf_simulink_M);
extern void sf_simulink_terminate(RT_MODEL_sf_simulink_T * sf_simulink_M);

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
 * '<Root>' : 'sf_simulink'
 * '<S1>'   : 'sf_simulink/top model of sf'
 * '<S2>'   : 'sf_simulink/top model of sf/cruser and checking speed model'
 * '<S3>'   : 'sf_simulink/top model of sf/mission model'
 * '<S4>'   : 'sf_simulink/top model of sf/cruser and checking speed model/check speed chart'
 * '<S5>'   : 'sf_simulink/top model of sf/cruser and checking speed model/cruser chart'
 * '<S6>'   : 'sf_simulink/top model of sf/mission model/acceident'
 * '<S7>'   : 'sf_simulink/top model of sf/mission model/bad lane'
 */
#endif                                 /* RTW_HEADER_sf_simulink_h_ */
