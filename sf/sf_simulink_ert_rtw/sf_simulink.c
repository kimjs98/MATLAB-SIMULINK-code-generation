/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sf_simulink.c
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

#include "sf_simulink.h"
#include "sf_simulink_private.h"

/* Named constants for Chart: '<S2>/check speed chart' */
#define sf_simul_IN_calculate_the_speed ((uint8_T)1U)
#define sf_simulink_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define sf_simulink_IN_define_variable ((uint8_T)2U)
#define sf_simulink_IN_exist_car       ((uint8_T)1U)
#define sf_simulink_IN_not_exist_car   ((uint8_T)2U)

/* Named constants for Chart: '<S2>/cruser chart' */
#define sf_simulink_IN_change_lane     ((uint8_T)1U)
#define sf_simulink_IN_discover_car    ((uint8_T)3U)
#define sf_simulink_IN_stop            ((uint8_T)4U)
#define sf_simulink_IN_undiscover_car  ((uint8_T)5U)

/* Model step function */
void sf_simulink_step(RT_MODEL_sf_simulink_T *const sf_simulink_M)
{
  B_sf_simulink_T *sf_simulink_B = ((B_sf_simulink_T *) sf_simulink_M->blockIO);
  DW_sf_simulink_T *sf_simulink_DW = ((DW_sf_simulink_T *) sf_simulink_M->dwork);
  ExtU_sf_simulink_T *sf_simulink_U = (ExtU_sf_simulink_T *)
    sf_simulink_M->inputs;
  ExtY_sf_simulink_T *sf_simulink_Y = (ExtY_sf_simulink_T *)
    sf_simulink_M->outputs;
  real_T save_time;
  real_T save_dist[10];
  int32_T i;

  /* Chart: '<S2>/cruser chart' incorporates:
   *  BusCreator generated from: '<S2>/cruser chart'
   *  Inport: '<Root>/Input'
   *  Inport: '<Root>/Input1'
   */
  if (sf_simulink_DW->is_active_c3_sf_simulink == 0U) {
    sf_simulink_DW->is_active_c3_sf_simulink = 1U;
    sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_define_variable;

    /* local */
    sf_simulink_DW->car_check_f_g = sf_simulink_U->Input.car_check_flag;
    memcpy(&sf_simulink_DW->object_angle[0], &sf_simulink_U->Input.object_angle
           [0], 10U * sizeof(real_T));
    memcpy(&sf_simulink_DW->lidar_angle[0], &sf_simulink_U->Input1.angle[0], 10U
           * sizeof(real_T));
    memcpy(&sf_simulink_DW->lidar_dist[0], &sf_simulink_U->Input1.dist[0], 10U *
           sizeof(real_T));

    /* output */
    if (sf_simulink_U->Input.line_angle < 65536.0) {
      if (sf_simulink_U->Input.line_angle >= 0.0) {
        sf_simulink_B->steering_angle = (uint16_T)
          sf_simulink_U->Input.line_angle;
      } else {
        sf_simulink_B->steering_angle = 0U;
      }
    } else {
      sf_simulink_B->steering_angle = MAX_uint16_T;
    }

    sf_simulink_B->speed = 0U;
    sf_simulink_B->lane_change_flag = 0U;
  } else {
    switch (sf_simulink_DW->is_c3_sf_simulink) {
     case sf_simulink_IN_change_lane:
      if (sf_simulink_B->lane_change_flag == 0) {
        if (sf_simulink_DW->car_check_f_g == 0) {
          sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_undiscover_car;
        } else if (sf_simulink_DW->lidar_dist[0] < 300.0) {
          sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_stop;
          sf_simulink_B->steering_angle = 0U;
          sf_simulink_B->speed = 0U;
        } else {
          sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_discover_car;
        }
      } else if (sf_simulink_DW->lidar_dist[0] < 100.0) {
        sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_stop;
        sf_simulink_B->steering_angle = 0U;
        sf_simulink_B->speed = 0U;
      } else {
        if (sf_simulink_DW->lidar_angle[0] >= 0.0) {
          sf_simulink_B->steering_angle = 180U;
        } else {
          sf_simulink_B->steering_angle = 0U;
        }

        if (sf_simulink_DW->car_check_f_g == 0) {
          sf_simulink_B->lane_change_flag = 0U;
        }
      }
      break;

     case sf_simulink_IN_define_variable:
      if (sf_simulink_DW->car_check_f_g == 0) {
        sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_undiscover_car;
      } else if (sf_simulink_DW->lidar_dist[0] < 300.0) {
        sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_stop;
        sf_simulink_B->steering_angle = 0U;
        sf_simulink_B->speed = 0U;
      } else {
        sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_discover_car;
      }
      break;

     case sf_simulink_IN_discover_car:
      sf_simulink_B->speed = 150U;
      if (sf_simulink_DW->lidar_dist[0] < 300.0) {
        sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_stop;
        sf_simulink_B->steering_angle = 0U;
        sf_simulink_B->speed = 0U;
      } else if (fabs(sf_simulink_DW->object_angle[0] -
                      sf_simulink_DW->lidar_angle[0]) < 5.0) {
        sf_simulink_B->lane_change_flag = 1U;
        sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_change_lane;
      } else {
        sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_undiscover_car;
      }
      break;

     case sf_simulink_IN_stop:
      if (sf_simulink_DW->lidar_dist[0] > 300.0) {
        if (sf_simulink_DW->car_check_f_g == 0) {
          sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_undiscover_car;
        } else if (sf_simulink_DW->lidar_dist[0] < 300.0) {
          sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_stop;
          sf_simulink_B->steering_angle = 0U;
          sf_simulink_B->speed = 0U;
        } else {
          sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_discover_car;
        }
      } else {
        sf_simulink_B->steering_angle = 0U;
        sf_simulink_B->speed = 0U;
        if ((sf_simulink_B->lane_change_flag == 1) &&
            (!(sf_simulink_DW->lidar_dist[0] < 100.0))) {
          sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_change_lane;
        }
      }
      break;

     default:
      /* case IN_undiscover_car: */
      if (sf_simulink_DW->car_check_f_g == 0) {
        if (sf_simulink_U->Input.line_angle < 65536.0) {
          if (sf_simulink_U->Input.line_angle >= 0.0) {
            sf_simulink_B->steering_angle = (uint16_T)
              sf_simulink_U->Input.line_angle;
          } else {
            sf_simulink_B->steering_angle = 0U;
          }
        } else {
          sf_simulink_B->steering_angle = MAX_uint16_T;
        }

        sf_simulink_B->speed = 300U;
        sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_undiscover_car;
      } else if (sf_simulink_DW->lidar_dist[0] < 300.0) {
        sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_stop;
        sf_simulink_B->steering_angle = 0U;
        sf_simulink_B->speed = 0U;
      } else {
        if (sf_simulink_U->Input.line_angle < 65536.0) {
          if (sf_simulink_U->Input.line_angle >= 0.0) {
            sf_simulink_B->steering_angle = (uint16_T)
              sf_simulink_U->Input.line_angle;
          } else {
            sf_simulink_B->steering_angle = 0U;
          }
        } else {
          sf_simulink_B->steering_angle = MAX_uint16_T;
        }

        sf_simulink_B->speed = 300U;
        sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_discover_car;
      }
      break;
    }
  }

  /* End of Chart: '<S2>/cruser chart' */

  /* Chart: '<S2>/check speed chart' incorporates:
   *  BusCreator generated from: '<S2>/check speed chart'
   *  Inport: '<Root>/Input'
   *  Inport: '<Root>/Input1'
   *  Inport: '<Root>/Input2'
   * */
  if (sf_simulink_DW->is_active_c1_sf_simulink == 0U) {
    sf_simulink_DW->is_active_c1_sf_simulink = 1U;
    sf_simulink_DW->is_c1_sf_simulink = sf_simulink_IN_define_variable;

    /* local */
    sf_simulink_DW->car_check_f = sf_simulink_U->Input.car_check_flag;
    memcpy(&sf_simulink_DW->lidar_dist_b[0], &sf_simulink_U->Input1.dist[0], 10U
           * sizeof(real_T));
    sf_simulink_DW->time = sf_simulink_U->Input2.time;

    /* output */
    sf_simulink_B->overfast_flag = 0U;
    save_time = 0.0;
  } else if (sf_simulink_DW->is_c1_sf_simulink ==
             sf_simul_IN_calculate_the_speed) {
    if (sf_simulink_DW->is_calculate_the_speed == sf_simulink_IN_exist_car) {
      if (sf_simulink_DW->car_check_f == 0.0) {
        sf_simulink_DW->is_calculate_the_speed = sf_simulink_IN_not_exist_car;
        sf_simulink_DW->time = sf_simulink_U->Input2.time;
        memcpy(&sf_simulink_DW->lidar_dist_b[0], &sf_simulink_U->Input1.dist[0],
               10U * sizeof(real_T));
        save_time = 0.0;
        sf_simulink_B->overfast_flag = 0U;
      } else {
        save_time = sf_simulink_DW->time;
        sf_simulink_DW->time = sf_simulink_U->Input2.time;
        for (i = 0; i < 10; i++) {
          save_dist[i] = sf_simulink_DW->lidar_dist_b[i];
          sf_simulink_DW->lidar_dist_b[i] = sf_simulink_U->Input1.dist[i];
        }

        save_time = (sf_simulink_DW->lidar_dist_b[0] - save_dist[0]) /
          (sf_simulink_DW->time - save_time) + (real_T)sf_simulink_B->speed;
        if (save_time >= 80.0) {
          sf_simulink_B->overfast_flag = 1U;
        }
      }
    } else {
      /* case IN_not_exist_car: */
      if (sf_simulink_DW->car_check_f == 1.0) {
        sf_simulink_DW->is_calculate_the_speed = sf_simulink_IN_exist_car;
        save_time = sf_simulink_DW->time;
        sf_simulink_DW->time = sf_simulink_U->Input2.time;
        for (i = 0; i < 10; i++) {
          save_dist[i] = sf_simulink_DW->lidar_dist_b[i];
          sf_simulink_DW->lidar_dist_b[i] = sf_simulink_U->Input1.dist[i];
        }

        save_time = (sf_simulink_DW->lidar_dist_b[0] - save_dist[0]) /
          (sf_simulink_DW->time - save_time) + (real_T)sf_simulink_B->speed;
      } else {
        sf_simulink_DW->time = sf_simulink_U->Input2.time;
        memcpy(&sf_simulink_DW->lidar_dist_b[0], &sf_simulink_U->Input1.dist[0],
               10U * sizeof(real_T));
        save_time = 0.0;
        sf_simulink_B->overfast_flag = 0U;
      }
    }
  } else {
    /* case IN_define_variable: */
    sf_simulink_DW->is_c1_sf_simulink = sf_simul_IN_calculate_the_speed;
    sf_simulink_DW->time = 0.0;
    sf_simulink_DW->is_calculate_the_speed = sf_simulink_IN_exist_car;
    save_time = sf_simulink_DW->time;
    sf_simulink_DW->time = sf_simulink_U->Input2.time;
    for (i = 0; i < 10; i++) {
      sf_simulink_DW->lidar_dist_b[i] = (rtInf);
      save_dist[i] = sf_simulink_DW->lidar_dist_b[i];
      sf_simulink_DW->lidar_dist_b[i] = sf_simulink_U->Input1.dist[i];
    }

    save_time = (sf_simulink_DW->lidar_dist_b[0] - save_dist[0]) /
      (sf_simulink_DW->time - save_time) + (real_T)sf_simulink_B->speed;
  }

  /* End of Chart: '<S2>/check speed chart' */

  /* BusCreator generated from: '<Root>/Output' incorporates:
   *  Inport: '<Root>/Input'
   *  Outport: '<Root>/Output'
   */
  sf_simulink_Y->Output.front_car_speed = save_time;
  sf_simulink_Y->Output.overfast_flag = sf_simulink_B->overfast_flag;
  sf_simulink_Y->Output.lane_change_flag = sf_simulink_B->lane_change_flag;
  sf_simulink_Y->Output.bad_lane_flag = sf_simulink_U->Input.bad_lane_flag;
  sf_simulink_Y->Output.accident_flag = sf_simulink_U->Input.accident_flag;

  /* Chart: '<S2>/light on-off chart' */
  if (sf_simulink_DW->is_active_c2_sf_simulink == 0U) {
    sf_simulink_DW->is_active_c2_sf_simulink = 1U;
    sf_simulink_Y->Output1.blinker_onoff = 0U;
    sf_simulink_Y->Output1.blinker_dir = 0U;
    sf_simulink_Y->Output1.break_light_onoff = 0U;
  } else {
    sf_simulink_Y->Output1.blinker_onoff = 0U;
    sf_simulink_Y->Output1.blinker_dir = 0U;
    sf_simulink_Y->Output1.break_light_onoff = 0U;
  }

  /* End of Chart: '<S2>/light on-off chart' */

  /* BusCreator generated from: '<Root>/Output1' incorporates:
   *  Outport: '<Root>/Output1'
   */
  sf_simulink_Y->Output1.steering_angle = sf_simulink_B->steering_angle;
  sf_simulink_Y->Output1.speed = sf_simulink_B->speed;
}

/* Model initialize function */
void sf_simulink_initialize(RT_MODEL_sf_simulink_T *const sf_simulink_M)
{
  B_sf_simulink_T *sf_simulink_B = ((B_sf_simulink_T *) sf_simulink_M->blockIO);
  DW_sf_simulink_T *sf_simulink_DW = ((DW_sf_simulink_T *) sf_simulink_M->dwork);

  /* SystemInitialize for Chart: '<S2>/cruser chart' */
  sf_simulink_DW->is_active_c3_sf_simulink = 0U;
  sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_NO_ACTIVE_CHILD;
  sf_simulink_DW->car_check_f_g = 0U;
  sf_simulink_B->steering_angle = 0U;
  sf_simulink_B->speed = 0U;
  sf_simulink_B->lane_change_flag = 0U;

  /* SystemInitialize for Chart: '<S2>/check speed chart' */
  sf_simulink_DW->is_calculate_the_speed = sf_simulink_IN_NO_ACTIVE_CHILD;
  sf_simulink_DW->is_active_c1_sf_simulink = 0U;
  sf_simulink_DW->is_c1_sf_simulink = sf_simulink_IN_NO_ACTIVE_CHILD;
  sf_simulink_DW->car_check_f = 0.0;
  sf_simulink_DW->time = 0.0;

  /* SystemInitialize for Chart: '<S2>/cruser chart' */
  memset(&sf_simulink_DW->object_angle[0], 0, 10U * sizeof(real_T));
  memset(&sf_simulink_DW->lidar_angle[0], 0, 10U * sizeof(real_T));
  memset(&sf_simulink_DW->lidar_dist[0], 0, 10U * sizeof(real_T));

  /* SystemInitialize for Chart: '<S2>/check speed chart' */
  memset(&sf_simulink_DW->lidar_dist_b[0], 0, 10U * sizeof(real_T));
  sf_simulink_B->overfast_flag = 0U;

  /* SystemInitialize for Chart: '<S2>/light on-off chart' */
  sf_simulink_DW->is_active_c2_sf_simulink = 0U;
}

/* Model terminate function */
void sf_simulink_terminate(RT_MODEL_sf_simulink_T * sf_simulink_M)
{
  /* model code */
  rt_FREE(sf_simulink_M->blockIO);
  rt_FREE(sf_simulink_M->inputs);
  rt_FREE(sf_simulink_M->outputs);
  rt_FREE(sf_simulink_M->dwork);
  rt_FREE(sf_simulink_M);
}

/* Model data allocation function */
RT_MODEL_sf_simulink_T *sf_simulink(void)
{
  RT_MODEL_sf_simulink_T *sf_simulink_M;
  sf_simulink_M = (RT_MODEL_sf_simulink_T *) malloc(sizeof
    (RT_MODEL_sf_simulink_T));
  if (sf_simulink_M == NULL) {
    return NULL;
  }

  (void) memset((char *)sf_simulink_M, 0,
                sizeof(RT_MODEL_sf_simulink_T));

  /* block I/O */
  {
    B_sf_simulink_T *b = (B_sf_simulink_T *) malloc(sizeof(B_sf_simulink_T));
    rt_VALIDATE_MEMORY(sf_simulink_M,b);
    sf_simulink_M->blockIO = (b);
  }

  /* states (dwork) */
  {
    DW_sf_simulink_T *dwork = (DW_sf_simulink_T *) malloc(sizeof
      (DW_sf_simulink_T));
    rt_VALIDATE_MEMORY(sf_simulink_M,dwork);
    sf_simulink_M->dwork = (dwork);
  }

  /* external inputs */
  {
    ExtU_sf_simulink_T *sf_simulink_U = (ExtU_sf_simulink_T *) malloc(sizeof
      (ExtU_sf_simulink_T));
    rt_VALIDATE_MEMORY(sf_simulink_M,sf_simulink_U);
    sf_simulink_M->inputs = (((ExtU_sf_simulink_T *) sf_simulink_U));
  }

  /* external outputs */
  {
    ExtY_sf_simulink_T *sf_simulink_Y = (ExtY_sf_simulink_T *) malloc(sizeof
      (ExtY_sf_simulink_T));
    rt_VALIDATE_MEMORY(sf_simulink_M,sf_simulink_Y);
    sf_simulink_M->outputs = (sf_simulink_Y);
  }

  {
    B_sf_simulink_T *sf_simulink_B = ((B_sf_simulink_T *) sf_simulink_M->blockIO);
    DW_sf_simulink_T *sf_simulink_DW = ((DW_sf_simulink_T *)
      sf_simulink_M->dwork);
    ExtU_sf_simulink_T *sf_simulink_U = (ExtU_sf_simulink_T *)
      sf_simulink_M->inputs;
    ExtY_sf_simulink_T *sf_simulink_Y = (ExtY_sf_simulink_T *)
      sf_simulink_M->outputs;

    /* initialize non-finites */
    rt_InitInfAndNaN(sizeof(real_T));

    /* block I/O */
    (void) memset(((void *) sf_simulink_B), 0,
                  sizeof(B_sf_simulink_T));

    /* states (dwork) */
    (void) memset((void *)sf_simulink_DW, 0,
                  sizeof(DW_sf_simulink_T));

    /* external inputs */
    (void)memset(sf_simulink_U, 0, sizeof(ExtU_sf_simulink_T));

    /* external outputs */
    (void) memset((void *)sf_simulink_Y, 0,
                  sizeof(ExtY_sf_simulink_T));
  }

  return sf_simulink_M;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
