/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test.h
 *
 * Code generated for Simulink model 'test'.
 *
 * Model version                  : 1.23
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Mar 30 02:20:57 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_test_h_
#define RTW_HEADER_test_h_
#include <string.h>
#ifndef test_COMMON_INCLUDES_
# define test_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* test_COMMON_INCLUDES_ */

#include "test_types.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<S2>/cruise_mode_stateflow' */
typedef struct {
  real_T local_data;                   /* '<S2>/cruise_mode_stateflow' */
  uint8_T is_active_c3_test;           /* '<S2>/cruise_mode_stateflow' */
  uint8_T is_c3_test;                  /* '<S2>/cruise_mode_stateflow' */
} DW_cruise_mode_stateflow_test_T;

/* Block states (default storage) for system '<S1>/cruise_mode' */
typedef struct {
  DW_cruise_mode_stateflow_test_T sf_cruise_mode_stateflow;/* '<S2>/cruise_mode_stateflow' */
} DW_cruise_mode_test_T;

/* Block states (default storage) for system '<Root>/call_sensor_fusion' */
typedef struct {
  DW_cruise_mode_test_T cruise_mode;   /* '<S1>/cruise_mode' */
} DW_call_sensor_fusion_test_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  DW_call_sensor_fusion_test_T call_sensor_fusion;/* '<Root>/call_sensor_fusion' */
} DW_test_T;

/* Real-time Model Data Structure */
struct tag_RTM_test_T {
  const char_T * volatile errorStatus;
  DW_test_T *dwork;
};

/* Model entry point functions */
extern void test_initialize(RT_MODEL_test_T *const test_M, real_T
  *test_U_cam_line_angle, real_T *test_U_cam_object_angle, real_T
  *test_U_Iidar_angle_fov, real_T *test_U_Iidar_dist_fov, real_T
  *test_U_bad_lane_flag, real_T *test_U_accident_flag, real_T
  *test_U_accident_location_angle, real_T *test_U_Iidar_angle_nfov, real_T
  *test_U_Iidar_dist_nfov);
extern void test_step(RT_MODEL_test_T *const test_M, real_T
                      test_U_cam_object_angle, real_T test_U_Iidar_angle_fov);
extern void test_terminate(RT_MODEL_test_T *const test_M);

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
 * '<Root>' : 'test'
 * '<S1>'   : 'test/call_sensor_fusion'
 * '<S2>'   : 'test/call_sensor_fusion/cruise_mode'
 * '<S3>'   : 'test/call_sensor_fusion/lane_change_mode'
 * '<S4>'   : 'test/call_sensor_fusion/cruise_mode/cruise_mode_stateflow'
 * '<S5>'   : 'test/call_sensor_fusion/lane_change_mode/lane_change_mode_stateflow'
 */
#endif                                 /* RTW_HEADER_test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
