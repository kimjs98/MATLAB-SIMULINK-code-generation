/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sf_simulink_types.h
 *
 * Code generated for Simulink model 'sf_simulink'.
 *
 * Model version                  : 1.621
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Wed Oct  5 21:38:35 2022
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
  uint8_T line_angle;
  uint8_T object_id[10];
  uint16_T object_angle[10];
  uint8_T car_check_flag;
  uint8_T crack_flag;
  uint8_T sig_flag;
  real_T stop_line_dist;
  uint8_T change_lane_dir;
} CAM;

#endif

#ifndef DEFINED_TYPEDEF_FOR_LIDAR_
#define DEFINED_TYPEDEF_FOR_LIDAR_

typedef struct {
  uint8_T detected_number;
  uint16_T angle[10];
  uint16_T dist[10];
} LIDAR;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CORE_
#define DEFINED_TYPEDEF_FOR_CORE_

typedef struct {
  int32_T time;
} CORE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_C_BUS_
#define DEFINED_TYPEDEF_FOR_C_BUS_

typedef struct {
  uint8_T object_id[10];
  uint16_T object_angle[10];
  uint8_T change_lane_dir;
} C_BUS;

#endif

#ifndef DEFINED_TYPEDEF_FOR_OBJECT_
#define DEFINED_TYPEDEF_FOR_OBJECT_

typedef struct {
  uint8_T who;
  uint32_T id;
  uint32_T dist;
} OBJECT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_CRUISER_
#define DEFINED_TYPEDEF_FOR_CRUISER_

typedef struct {
  uint8_T line_angle;
  uint8_T car_check_flag;
  uint8_T change_lane_dir;
} CRUISER;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SIGNAL_
#define DEFINED_TYPEDEF_FOR_SIGNAL_

typedef struct {
  uint8_T sig_flag;
  real_T stop_line_dist;
} SIGNAL;

#endif

#ifndef DEFINED_TYPEDEF_FOR_OUTPUT_
#define DEFINED_TYPEDEF_FOR_OUTPUT_

typedef struct {
  real_T front_car_speed;
  uint8_T overfast_flag;
  uint8_T signal_violation_flag;
  uint8_T crack_flag;
} OUTPUT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_MCU_CONTROL_
#define DEFINED_TYPEDEF_FOR_MCU_CONTROL_

typedef struct {
  uint8_T steering_angle;
  uint8_T speed;
  uint8_T blinker_onoff;
  uint8_T blinker_dir;
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
