/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sf_simulink.h
 *
 * Code generated for Simulink model 'sf_simulink'.
 *
 * Model version                  : 1.468
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Thu Sep 29 00:57:19 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_sf_simulink_h_
#define RTW_HEADER_sf_simulink_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef sf_simulink_COMMON_INCLUDES_
# define sf_simulink_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#endif                                 /* sf_simulink_COMMON_INCLUDES_ */

#include "sf_simulink_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
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

#define sf_simulink_M_TYPE             RT_MODEL_sf_simulink_T

/* Block signals (default storage) */
typedef struct {
  OBJECT object[360];                  /* '<S1>/object fetch' */
  CRUISER cruiser;                     /* '<S1>/object fetch' */
  real_T front_car_speed;              /* '<S2>/cruser chart' */
  int16_T steering_angle;              /* '<S2>/cruser chart' */
  int16_T speed;                       /* '<S2>/cruser chart' */
  uint8_T overfast_flag;               /* '<S2>/cruser chart' */
} B_sf_simulink_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  OBJECT each_object;                  /* '<S1>/object fetch' */
  real_T time;                         /* '<S2>/cruser chart' */
  real_T save_time;                    /* '<S2>/cruser chart' */
  real_T save_dist;                    /* '<S2>/cruser chart' */
  uint8_T is_active_c1_sf_simulink;    /* '<S1>/object fetch' */
  uint8_T is_c1_sf_simulink;           /* '<S1>/object fetch' */
  uint8_T is_active_c4_sf_simulink; /* '<S2>/signal violation checking chart' */
  uint8_T is_active_c2_sf_simulink;    /* '<S2>/light on-off chart' */
  uint8_T is_active_c3_sf_simulink;    /* '<S2>/cruser chart' */
  uint8_T is_c3_sf_simulink;           /* '<S2>/cruser chart' */
} DW_sf_simulink_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  CAM Input;                           /* '<Root>/Input' */
  LIDAR Input1;                        /* '<Root>/Input1' */
  CORE Input2;                         /* '<Root>/Input2' */
} ExtU_sf_simulink_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  OUTPUT Output;                       /* '<Root>/Output' */
  MCU_CONTROL Output1;                 /* '<Root>/Output1' */
} ExtY_sf_simulink_T;

/* Real-time Model Data Structure */
struct tag_RTM_sf_simulink_T {
  const char_T *errorStatus;
  B_sf_simulink_T *blockIO;
  ExtU_sf_simulink_T *inputs;
  ExtY_sf_simulink_T *outputs;
  DW_sf_simulink_T *dwork;
};

/* External data declarations for dependent source files */
extern const char *RT_MEMORY_ALLOCATION_ERROR;

/* Model entry point functions */
RT_MODEL_sf_simulink_T *sf_simulink(void);
void sf_simulink_initialize(RT_MODEL_sf_simulink_T *const sf_simulink_M);
void sf_simulink_step(RT_MODEL_sf_simulink_T *const sf_simulink_M);
void sf_simulink_terminate(RT_MODEL_sf_simulink_T * sf_simulink_M);

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
 * '<S3>'   : 'sf_simulink/top model of sf/object fetch'
 * '<S4>'   : 'sf_simulink/top model of sf/cruser and checking speed model/cruser chart'
 * '<S5>'   : 'sf_simulink/top model of sf/cruser and checking speed model/light on-off chart'
 * '<S6>'   : 'sf_simulink/top model of sf/cruser and checking speed model/signal violation checking chart'
 */
#endif                                 /* RTW_HEADER_sf_simulink_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
