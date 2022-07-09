/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sf_simulink_types.h
 *
 * Code generated for Simulink model 'sf_simulink'.
 *
 * Model version                  : 1.62
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Sat Jul  9 21:31:40 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_sf_simulink_types_h_
#define RTW_HEADER_sf_simulink_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_CAM_
#define DEFINED_TYPEDEF_FOR_CAM_

typedef struct {
  real_T line_angle;
  real_T object_id[10];
  real_T object_angle[10];
  uint8_T car_check_flag;
  uint8_T accident_flag;
  uint8_T bad_lane_flag;
} CAM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_LIDAR_
#define DEFINED_TYPEDEF_FOR_LIDAR_

typedef struct {
  real_T detected_number;
  real_T angle[10];
  real_T dist[10];
} LIDAR;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CORE_
#define DEFINED_TYPEDEF_FOR_CORE_

typedef struct {
  real_T time;
} CORE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CHECK_
#define DEFINED_TYPEDEF_FOR_CHECK_

typedef struct {
  real_T object_id[10];
  real_T object_angle[10];
  uint8_T car_check_flag;
  real_T detected_number;
  real_T angle[10];
  real_T dist[10];
} CHECK;

#endif

#ifndef DEFINED_TYPEDEF_FOR_OUTPUT_
#define DEFINED_TYPEDEF_FOR_OUTPUT_

typedef struct {
  real_T front_car_speed;
  uint8_T overfast_flag;
  uint8_T lane_change_flag;
  uint8_T bad_lane_flag;
  uint8_T accident_flag;
} OUTPUT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MCU_CONTROL_
#define DEFINED_TYPEDEF_FOR_MCU_CONTROL_

typedef struct {
  uint16_T steering_angle;
  uint16_T speed;
  uint8_T blinker_onoff;
  uint8_T blinker_dir;
  uint8_T break_light_onoff;
} MCU_CONTROL;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_sf_simulink_T RT_MODEL_sf_simulink_T;

#endif                                 /* RTW_HEADER_sf_simulink_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
