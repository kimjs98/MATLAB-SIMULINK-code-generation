/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sf_simulink.c
 *
 * Code generated for Simulink model 'sf_simulink'.
 *
 * Model version                  : 1.45
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Jun 28 17:38:49 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
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

/* Named constants for Chart: '<S3>/acceident' */
#define sf_simu_IN_decide_accident_flag ((uint8_T)1U)

const OUTPUT sf_simulink_rtZOUTPUT = {
  0.0,                                 /* steering_angle */
  0.0,                                 /* next_vel */
  0.0,                                 /* front_car_vel */
  0U,                                  /* lane_change_flag */
  0U,                                  /* overfast_flag */
  0U,                                  /* bad_lane_flag */
  0U                                   /* accident_flag */
} ;                                    /* OUTPUT ground */

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
  real_T save_dist;

  /* Chart: '<S2>/cruser chart' incorporates:
   *  BusCreator: '<S2>/Bus Creator'
   *  Inport: '<Root>/Input'
   *  Inport: '<Root>/Input1'
   */
  if (sf_simulink_DW->is_active_c3_sf_simulink == 0U) {
    sf_simulink_DW->is_active_c3_sf_simulink = 1U;
    sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_define_variable;

    /* local */
    sf_simulink_DW->car_check_f = sf_simulink_U->Input.car_check_flag;
    sf_simulink_DW->object_angle = sf_simulink_U->Input.object_angle;
    sf_simulink_DW->angle_fov = sf_simulink_U->Input1.angle_fov;
    sf_simulink_DW->dist_fov = sf_simulink_U->Input1.dist_fov;
    sf_simulink_DW->angle_nfov = sf_simulink_U->Input1.angle_nfov;
    sf_simulink_DW->dist_nfov = sf_simulink_U->Input1.dist_nfov;

    /* output */
    sf_simulink_B->steering_angle = sf_simulink_U->Input.line_angle;
    sf_simulink_B->next_vel = 0.0;
    sf_simulink_B->lane_change_flag = 0U;
  } else {
    switch (sf_simulink_DW->is_c3_sf_simulink) {
     case sf_simulink_IN_change_lane:
      if (sf_simulink_B->lane_change_flag == 0) {
        if (sf_simulink_DW->car_check_f == 0.0) {
          sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_undiscover_car;
        } else if (sf_simulink_DW->dist_fov < 300.0) {
          sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_stop;
          sf_simulink_B->steering_angle = 0.0;
          sf_simulink_B->next_vel = 0.0;
        } else {
          sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_discover_car;
        }
      } else if (sf_simulink_DW->dist_nfov < 100.0) {
        sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_stop;
        sf_simulink_B->steering_angle = 0.0;
        sf_simulink_B->next_vel = 0.0;
      } else {
        if (sf_simulink_DW->angle_nfov >= 0.0) {
          sf_simulink_B->steering_angle = 180.0;
        } else {
          sf_simulink_B->steering_angle = 0.0;
        }

        if (sf_simulink_DW->car_check_f == 0.0) {
          sf_simulink_B->lane_change_flag = 0U;
        }
      }
      break;

     case sf_simulink_IN_define_variable:
      if (sf_simulink_DW->car_check_f == 0.0) {
        sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_undiscover_car;
      } else if (sf_simulink_DW->dist_fov < 300.0) {
        sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_stop;
        sf_simulink_B->steering_angle = 0.0;
        sf_simulink_B->next_vel = 0.0;
      } else {
        sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_discover_car;
      }
      break;

     case sf_simulink_IN_discover_car:
      sf_simulink_B->next_vel = 150.0;
      if (sf_simulink_DW->dist_fov < 300.0) {
        sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_stop;
        sf_simulink_B->steering_angle = 0.0;
        sf_simulink_B->next_vel = 0.0;
      } else if (fabs(sf_simulink_DW->object_angle - sf_simulink_DW->angle_fov) <
                 5.0) {
        sf_simulink_B->lane_change_flag = 1U;
        sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_change_lane;
      } else {
        sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_undiscover_car;
      }
      break;

     case sf_simulink_IN_stop:
      if (sf_simulink_DW->dist_fov > 300.0) {
        if (sf_simulink_DW->car_check_f == 0.0) {
          sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_undiscover_car;
        } else if (sf_simulink_DW->dist_fov < 300.0) {
          sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_stop;
          sf_simulink_B->steering_angle = 0.0;
          sf_simulink_B->next_vel = 0.0;
        } else {
          sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_discover_car;
        }
      } else {
        sf_simulink_B->steering_angle = 0.0;
        sf_simulink_B->next_vel = 0.0;
        if ((sf_simulink_B->lane_change_flag == 1) &&
            (!(sf_simulink_DW->dist_nfov < 100.0))) {
          sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_change_lane;
        }
      }
      break;

     default:
      /* case IN_undiscover_car: */
      if (sf_simulink_DW->car_check_f == 0.0) {
        sf_simulink_B->steering_angle = sf_simulink_U->Input.line_angle;
        sf_simulink_B->next_vel = 300.0;
        sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_undiscover_car;
      } else if (sf_simulink_DW->dist_fov < 300.0) {
        sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_stop;
        sf_simulink_B->steering_angle = 0.0;
        sf_simulink_B->next_vel = 0.0;
      } else {
        sf_simulink_B->steering_angle = sf_simulink_U->Input.line_angle;
        sf_simulink_B->next_vel = 300.0;
        sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_discover_car;
      }
      break;
    }
  }

  /* End of Chart: '<S2>/cruser chart' */

  /* Chart: '<S2>/check speed chart' incorporates:
   *  BusCreator: '<S2>/Bus Creator'
   *  BusCreator generated from: '<S2>/check speed chart'
   *  Inport: '<Root>/Input'
   *  Inport: '<Root>/Input1'
   *  Inport: '<Root>/Input2'
   */
  if (sf_simulink_DW->is_active_c1_sf_simulink == 0U) {
    sf_simulink_DW->is_active_c1_sf_simulink = 1U;
    sf_simulink_DW->is_c1_sf_simulink = sf_simulink_IN_define_variable;

    /* local */
    sf_simulink_DW->car_check_f_f = sf_simulink_U->Input.car_check_flag;
    sf_simulink_DW->dist_fov_m = sf_simulink_U->Input1.dist_fov;
    sf_simulink_DW->time = sf_simulink_U->Input2.time;

    /* output */
    sf_simulink_B->overfast_flag = 0U;
    save_time = 0.0;
  } else if (sf_simulink_DW->is_c1_sf_simulink ==
             sf_simul_IN_calculate_the_speed) {
    if (sf_simulink_DW->is_calculate_the_speed == sf_simulink_IN_exist_car) {
      if (sf_simulink_DW->car_check_f_f == 0.0) {
        sf_simulink_DW->is_calculate_the_speed = sf_simulink_IN_not_exist_car;
        sf_simulink_DW->time = sf_simulink_U->Input2.time;
        sf_simulink_DW->dist_fov_m = sf_simulink_U->Input1.dist_fov;
        save_time = 0.0;
        sf_simulink_B->overfast_flag = 0U;
      } else {
        save_time = sf_simulink_DW->time;
        sf_simulink_DW->time = sf_simulink_U->Input2.time;
        save_dist = sf_simulink_DW->dist_fov_m;
        sf_simulink_DW->dist_fov_m = sf_simulink_U->Input1.dist_fov;
        save_time = (sf_simulink_DW->dist_fov_m - save_dist) /
          (sf_simulink_DW->time - save_time) + sf_simulink_B->next_vel;
        if (save_time >= 80.0) {
          sf_simulink_B->overfast_flag = 1U;
        }
      }
    } else {
      /* case IN_not_exist_car: */
      if (sf_simulink_DW->car_check_f_f == 1.0) {
        sf_simulink_DW->is_calculate_the_speed = sf_simulink_IN_exist_car;
        save_time = sf_simulink_DW->time;
        sf_simulink_DW->time = sf_simulink_U->Input2.time;
        save_dist = sf_simulink_DW->dist_fov_m;
        sf_simulink_DW->dist_fov_m = sf_simulink_U->Input1.dist_fov;
        save_time = (sf_simulink_DW->dist_fov_m - save_dist) /
          (sf_simulink_DW->time - save_time) + sf_simulink_B->next_vel;
      } else {
        sf_simulink_DW->time = sf_simulink_U->Input2.time;
        sf_simulink_DW->dist_fov_m = sf_simulink_U->Input1.dist_fov;
        save_time = 0.0;
        sf_simulink_B->overfast_flag = 0U;
      }
    }
  } else {
    /* case IN_define_variable: */
    sf_simulink_DW->is_c1_sf_simulink = sf_simul_IN_calculate_the_speed;
    sf_simulink_DW->dist_fov_m = (rtInf);
    sf_simulink_DW->time = 0.0;
    sf_simulink_DW->is_calculate_the_speed = sf_simulink_IN_exist_car;
    save_time = sf_simulink_DW->time;
    sf_simulink_DW->time = sf_simulink_U->Input2.time;
    save_dist = sf_simulink_DW->dist_fov_m;
    sf_simulink_DW->dist_fov_m = sf_simulink_U->Input1.dist_fov;
    save_time = (sf_simulink_DW->dist_fov_m - save_dist) / (sf_simulink_DW->time
      - save_time) + sf_simulink_B->next_vel;
  }

  /* End of Chart: '<S2>/check speed chart' */

  /* Chart: '<S3>/acceident' incorporates:
   *  BusCreator: '<S3>/Bus Creator'
   *  Inport: '<Root>/Input'
   */
  if (sf_simulink_DW->is_active_c2_sf_simulink == 0U) {
    sf_simulink_DW->is_active_c2_sf_simulink = 1U;
    sf_simulink_DW->is_c2_sf_simulink = sf_simulink_IN_define_variable;

    /* BusCreator generated from: '<Root>/Output' incorporates:
     *  BusCreator: '<S3>/Bus Creator'
     *  Inport: '<Root>/Input'
     *  Outport: '<Root>/Output'
     */
    /* local
       accident_flag = bus_accident.accident_flag; */
    /* output */
    sf_simulink_Y->Output.accident_flag = sf_simulink_U->Input.accident_flag;
  } else if (sf_simulink_DW->is_c2_sf_simulink ==
             sf_simu_IN_decide_accident_flag) {
    if ((sf_simulink_U->Input.accident_flag == 1) && ((fabs((real_T)
           sf_simulink_U->Input.accident_angle - sf_simulink_U->Input1.angle_fov)
          < 5.0) || (fabs((real_T)sf_simulink_U->Input.accident_angle -
                          sf_simulink_U->Input1.angle_nfov) < 5.0))) {
      /* BusCreator generated from: '<Root>/Output' incorporates:
       *  Outport: '<Root>/Output'
       */
      sf_simulink_Y->Output.accident_flag = 1U;
    } else {
      /* BusCreator generated from: '<Root>/Output' incorporates:
       *  Outport: '<Root>/Output'
       */
      sf_simulink_Y->Output.accident_flag = 0U;
    }
  } else {
    /* case IN_define_variable: */
    sf_simulink_DW->is_c2_sf_simulink = sf_simu_IN_decide_accident_flag;

    /* BusCreator generated from: '<Root>/Output' incorporates:
     *  BusCreator: '<S3>/Bus Creator'
     *  Inport: '<Root>/Input'
     *  Outport: '<Root>/Output'
     */
    sf_simulink_Y->Output.accident_flag = sf_simulink_U->Input.accident_flag;
  }

  /* End of Chart: '<S3>/acceident' */

  /* BusCreator generated from: '<Root>/Output' incorporates:
   *  Inport: '<Root>/Input'
   *  Outport: '<Root>/Output'
   */
  sf_simulink_Y->Output.steering_angle = sf_simulink_B->steering_angle;
  sf_simulink_Y->Output.next_vel = sf_simulink_B->next_vel;
  sf_simulink_Y->Output.front_car_vel = save_time;
  sf_simulink_Y->Output.lane_change_flag = sf_simulink_B->lane_change_flag;
  sf_simulink_Y->Output.overfast_flag = sf_simulink_B->overfast_flag;
  sf_simulink_Y->Output.bad_lane_flag = sf_simulink_U->Input.bad_lane_flag;
}

/* Model initialize function */
void sf_simulink_initialize(RT_MODEL_sf_simulink_T *const sf_simulink_M)
{
  B_sf_simulink_T *sf_simulink_B = ((B_sf_simulink_T *) sf_simulink_M->blockIO);
  DW_sf_simulink_T *sf_simulink_DW = ((DW_sf_simulink_T *) sf_simulink_M->dwork);

  /* SystemInitialize for Chart: '<S2>/cruser chart' */
  sf_simulink_DW->is_active_c3_sf_simulink = 0U;
  sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_NO_ACTIVE_CHILD;
  sf_simulink_DW->angle_fov = 0.0;
  sf_simulink_DW->angle_nfov = 0.0;
  sf_simulink_DW->car_check_f = 0.0;
  sf_simulink_DW->dist_fov = 0.0;
  sf_simulink_DW->dist_nfov = 0.0;
  sf_simulink_DW->object_angle = 0.0;
  sf_simulink_B->steering_angle = 0.0;
  sf_simulink_B->next_vel = 0.0;
  sf_simulink_B->lane_change_flag = 0U;

  /* SystemInitialize for Chart: '<S2>/check speed chart' */
  sf_simulink_DW->is_calculate_the_speed = sf_simulink_IN_NO_ACTIVE_CHILD;
  sf_simulink_DW->is_active_c1_sf_simulink = 0U;
  sf_simulink_DW->is_c1_sf_simulink = sf_simulink_IN_NO_ACTIVE_CHILD;
  sf_simulink_DW->car_check_f_f = 0.0;
  sf_simulink_DW->dist_fov_m = 0.0;
  sf_simulink_DW->time = 0.0;
  sf_simulink_B->overfast_flag = 0U;

  /* SystemInitialize for Chart: '<S3>/acceident' */
  sf_simulink_DW->is_active_c2_sf_simulink = 0U;
  sf_simulink_DW->is_c2_sf_simulink = sf_simulink_IN_NO_ACTIVE_CHILD;
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
    sf_simulink_Y->Output = sf_simulink_rtZOUTPUT;
  }

  return sf_simulink_M;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
