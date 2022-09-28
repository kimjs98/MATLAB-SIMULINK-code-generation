/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sf_simulink.c
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

#include "sf_simulink.h"
#include "sf_simulink_private.h"

/* Named constants for Chart: '<S2>/cruser chart' */
#define sf_simulink_EXTRA_SPEED        (10.0)
#define sf_simulink_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define sf_simulink_IN_change_lane     ((uint8_T)1U)
#define sf_simulink_IN_init            ((uint8_T)2U)
#define sf_simulink_IN_normal_running  ((uint8_T)3U)
#define sf_simulink_STOP_DISTANCE      (0.5)
#define sf_simulink_TIME_UNIT          (1.0E+6)

/* Named constants for Chart: '<S1>/object fetch' */
#define sf_simulink_DIFF_ANGLE         (3.0)
#define sf_simulink_IN_running         ((uint8_T)2U)

/* Forward declaration for local functions */
static void sf_simulink_signal_processing(const CORE
  *BusConversion_InsertedFor_cru_p, B_sf_simulink_T *sf_simulink_B,
  DW_sf_simulink_T *sf_simulink_DW);
static real_T sf_simulink_qsort(real_T x);
static real_T sf_simulink_nonzero_front(const OBJECT x[360]);
static void sf_simulink_merge(int32_T idx_data[], real_T x_data[], int32_T np,
  int32_T nq, int32_T iwork_data[], real_T xwork_data[]);
static void sf_simulink_sort(real_T x_data[], int32_T x_size[2]);
static real_T sf_simulink_front_ele(const OBJECT x[360]);
static void sf_simulink_accelerator(B_sf_simulink_T *sf_simulink_B);
static void sf_simulink_time_reprocessing(real_T *dt, DW_sf_simulink_T
  *sf_simulink_DW);
static void sf_simulink_brake(B_sf_simulink_T *sf_simulink_B);
static void sf_simulink_check_speeding(B_sf_simulink_T *sf_simulink_B);
static void sf_simulink_up_count(real_T *cnt, real_T limit);
static real_T sf_simulink_search(const real_T x[10], const real_T y[10], real_T
  val);

/* Function for Chart: '<S2>/cruser chart' */
static void sf_simulink_signal_processing(const CORE
  *BusConversion_InsertedFor_cru_p, B_sf_simulink_T *sf_simulink_B,
  DW_sf_simulink_T *sf_simulink_DW)
{
  /*  yellow or red signal  */
  if (sf_simulink_B->cruiser.line_angle < 32768.0) {
    if (sf_simulink_B->cruiser.line_angle >= -32768.0) {
      sf_simulink_B->steering_angle = (int16_T)sf_simulink_B->cruiser.line_angle;
    } else {
      sf_simulink_B->steering_angle = MIN_int16_T;
    }
  } else {
    sf_simulink_B->steering_angle = MAX_int16_T;
  }

  sf_simulink_DW->save_time = sf_simulink_DW->time;
  sf_simulink_DW->time = BusConversion_InsertedFor_cru_p->time;
}

/* Function for Chart: '<S1>/object fetch' */
static real_T sf_simulink_qsort(real_T x)
{
  return x;
}

/* Function for Chart: '<S2>/cruser chart' */
static real_T sf_simulink_nonzero_front(const OBJECT x[360])
{
  int32_T n;
  int32_T k;
  int32_T b_k;
  n = 0;
  if (x[0].id != 0U) {
    for (k = 0; k < 10; k++) {
      n++;
    }
  }

  k = 0;
  if (x[0].id != 0U) {
    for (b_k = 0; b_k < 11; b_k++) {
      k++;
    }
  }

  return (real_T)n + (real_T)k;
}

/* Function for Chart: '<S2>/cruser chart' */
static void sf_simulink_merge(int32_T idx_data[], real_T x_data[], int32_T np,
  int32_T nq, int32_T iwork_data[], real_T xwork_data[])
{
  int32_T p;
  int32_T q;
  int32_T iout;
  int32_T offset1;
  int32_T exitg1;
  if ((np != 0) && (nq != 0)) {
    offset1 = np + nq;
    for (p = 0; p < offset1; p++) {
      iwork_data[p] = idx_data[p];
      xwork_data[p] = x_data[p];
    }

    p = 0;
    q = np;
    iout = -1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork_data[p] <= xwork_data[q]) {
        idx_data[iout] = iwork_data[p];
        x_data[iout] = xwork_data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx_data[iout] = iwork_data[q];
        x_data[iout] = xwork_data[q];
        if (q + 1 < offset1) {
          q++;
        } else {
          offset1 = iout - p;
          while (p + 1 <= np) {
            q = (offset1 + p) + 1;
            idx_data[q] = iwork_data[p];
            x_data[q] = xwork_data[p];
            p++;
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

/* Function for Chart: '<S2>/cruser chart' */
static void sf_simulink_sort(real_T x_data[], int32_T x_size[2])
{
  int32_T idx_data[11];
  real_T b_x_data[11];
  int32_T iwork_data[11];
  real_T xwork_data[11];
  int32_T n;
  real_T x4[4];
  int8_T idx4[4];
  int32_T ib;
  int8_T perm[4];
  int32_T bLen;
  int32_T i1;
  int32_T i2;
  int32_T i4;
  int32_T b_x_size[2];
  real_T tmp;
  real_T tmp_0;
  if (x_size[1] != 0) {
    b_x_size[1] = x_size[1];
    n = x_size[0] * x_size[1] - 1;
    if (0 <= n) {
      memcpy(&b_x_data[0], &x_data[0], (n + 1) * sizeof(real_T));
    }

    n = x_size[1] - 1;
    if (0 <= n) {
      memset(&idx_data[0], 0, (n + 1) * sizeof(int32_T));
    }

    n = x_size[1] - 1;
    x4[0] = 0.0;
    idx4[0] = 0;
    x4[1] = 0.0;
    idx4[1] = 0;
    x4[2] = 0.0;
    idx4[2] = 0;
    x4[3] = 0.0;
    idx4[3] = 0;
    ib = 0;
    for (bLen = 0; bLen <= n; bLen++) {
      ib++;
      idx4[ib - 1] = (int8_T)(bLen + 1);
      x4[ib - 1] = b_x_data[bLen];
      if (ib == 4) {
        if (x4[0] <= x4[1]) {
          i1 = 1;
          i2 = 2;
        } else {
          i1 = 2;
          i2 = 1;
        }

        if (x4[2] <= x4[3]) {
          ib = 3;
          i4 = 4;
        } else {
          ib = 4;
          i4 = 3;
        }

        tmp = x4[i1 - 1];
        tmp_0 = x4[ib - 1];
        if (tmp <= tmp_0) {
          tmp = x4[i2 - 1];
          if (tmp <= tmp_0) {
            perm[0] = (int8_T)i1;
            perm[1] = (int8_T)i2;
            perm[2] = (int8_T)ib;
            perm[3] = (int8_T)i4;
          } else if (tmp <= x4[i4 - 1]) {
            perm[0] = (int8_T)i1;
            perm[1] = (int8_T)ib;
            perm[2] = (int8_T)i2;
            perm[3] = (int8_T)i4;
          } else {
            perm[0] = (int8_T)i1;
            perm[1] = (int8_T)ib;
            perm[2] = (int8_T)i4;
            perm[3] = (int8_T)i2;
          }
        } else {
          tmp_0 = x4[i4 - 1];
          if (tmp <= tmp_0) {
            if (x4[i2 - 1] <= tmp_0) {
              perm[0] = (int8_T)ib;
              perm[1] = (int8_T)i1;
              perm[2] = (int8_T)i2;
              perm[3] = (int8_T)i4;
            } else {
              perm[0] = (int8_T)ib;
              perm[1] = (int8_T)i1;
              perm[2] = (int8_T)i4;
              perm[3] = (int8_T)i2;
            }
          } else {
            perm[0] = (int8_T)ib;
            perm[1] = (int8_T)i4;
            perm[2] = (int8_T)i1;
            perm[3] = (int8_T)i2;
          }
        }

        i1 = perm[0] - 1;
        idx_data[bLen - 3] = idx4[i1];
        i2 = perm[1] - 1;
        idx_data[bLen - 2] = idx4[i2];
        ib = perm[2] - 1;
        idx_data[bLen - 1] = idx4[ib];
        i4 = perm[3] - 1;
        idx_data[bLen] = idx4[i4];
        b_x_data[bLen - 3] = x4[i1];
        b_x_data[bLen - 2] = x4[i2];
        b_x_data[bLen - 1] = x4[ib];
        b_x_data[bLen] = x4[i4];
        ib = 0;
      }
    }

    if (ib > 0) {
      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      if (ib == 1) {
        perm[0] = 1;
      } else if (ib == 2) {
        if (x4[0] <= x4[1]) {
          perm[0] = 1;
          perm[1] = 2;
        } else {
          perm[0] = 2;
          perm[1] = 1;
        }
      } else if (x4[0] <= x4[1]) {
        if (x4[1] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] <= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] <= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }

      for (bLen = 0; bLen < ib; bLen++) {
        i1 = perm[bLen] - 1;
        i2 = ((n - ib) + bLen) + 1;
        idx_data[i2] = idx4[i1];
        b_x_data[i2] = x4[i1];
      }
    }

    if (x_size[1] > 1) {
      n = (int8_T)x_size[1];
      if (0 <= n - 1) {
        memset(&xwork_data[0], 0, n * sizeof(real_T));
      }

      n = (int8_T)x_size[1];
      if (0 <= n - 1) {
        memset(&iwork_data[0], 0, n * sizeof(int32_T));
      }

      n = x_size[1] >> 2;
      bLen = 4;
      while (n > 1) {
        sf_simulink_merge(idx_data, b_x_data, bLen, bLen, iwork_data, xwork_data);
        bLen <<= 1;
        n = 1;
      }

      if (x_size[1] > bLen) {
        sf_simulink_merge(idx_data, b_x_data, bLen, x_size[1] - bLen, iwork_data,
                          xwork_data);
      }
    }

    x_size[0] = 1;
    x_size[1] = b_x_size[1];
    n = b_x_size[1];
    if (0 <= n - 1) {
      memcpy(&x_data[0], &b_x_data[0], n * sizeof(real_T));
    }
  }
}

/* Function for Chart: '<S2>/cruser chart' */
static real_T sf_simulink_front_ele(const OBJECT x[360])
{
  real_T y;
  uint32_T id;
  int8_T f1_data[10];
  real_T f2_data[11];
  real_T mn;
  real_T mx;
  int8_T ii_data[10];
  int8_T b_ii_data[11];
  boolean_T b_y;
  boolean_T b_x[2];
  real_T c_x_data[11];
  int32_T idx;
  int32_T b_idx;
  real_T d_data[11];
  int32_T loop_ub;
  int32_T i;
  int32_T f2_size[2];
  int32_T c_x_size[2];
  int32_T d_size[2];
  boolean_T exitg1;
  id = x[0].id;
  idx = 0;
  b_idx = 0;
  exitg1 = false;
  while ((!exitg1) && (b_idx < 10)) {
    if (id != 0U) {
      idx++;
      ii_data[idx - 1] = (int8_T)(b_idx + 1);
      if (idx >= 10) {
        exitg1 = true;
      } else {
        b_idx++;
      }
    } else {
      b_idx++;
    }
  }

  if (1 > idx) {
    idx = 0;
  }

  loop_ub = idx - 1;
  if (0 <= loop_ub) {
    memcpy(&f1_data[0], &ii_data[0], (loop_ub + 1) * sizeof(int8_T));
  }

  b_idx = 0;
  loop_ub = 0;
  exitg1 = false;
  while ((!exitg1) && (loop_ub < 11)) {
    if (id != 0U) {
      b_idx++;
      b_ii_data[b_idx - 1] = (int8_T)(loop_ub + 1);
      if (b_idx >= 11) {
        exitg1 = true;
      } else {
        loop_ub++;
      }
    } else {
      loop_ub++;
    }
  }

  if (1 > b_idx) {
    b_idx = 0;
  }

  f2_size[0] = 1;
  f2_size[1] = b_idx;
  loop_ub = b_idx - 1;
  for (i = 0; i <= loop_ub; i++) {
    f2_data[i] = b_ii_data[i];
  }

  mn = 0.0;
  mx = 0.0;
  b_x[0] = true;
  b_x[1] = (idx > 0);
  b_y = true;
  loop_ub = 0;
  exitg1 = false;
  while ((!exitg1) && (loop_ub < 2)) {
    if (!b_x[loop_ub]) {
      b_y = false;
      exitg1 = true;
    } else {
      loop_ub++;
    }
  }

  if (b_y) {
    c_x_size[0] = 1;
    c_x_size[1] = idx;
    loop_ub = idx - 1;
    for (i = 0; i <= loop_ub; i++) {
      c_x_data[i] = f1_data[i];
    }

    sf_simulink_sort(c_x_data, c_x_size);
    d_size[0] = 1;
    d_size[1] = idx;
    loop_ub = idx - 1;
    for (i = 0; i <= loop_ub; i++) {
      d_data[i] = f1_data[i];
    }

    sf_simulink_sort(d_data, d_size);
    if (d_size[1] <= 2) {
      if (d_size[1] == 1) {
        mn = c_x_data[0];
      } else if (c_x_data[0] > c_x_data[1]) {
        mn = c_x_data[1];
      } else {
        mn = c_x_data[0];
      }
    } else {
      mn = c_x_data[0];
      for (idx = 1; idx < c_x_size[1]; idx++) {
        if (mn > c_x_data[idx]) {
          mn = c_x_data[idx];
        }
      }
    }
  }

  b_x[0] = true;
  b_x[1] = (b_idx > 0);
  b_y = true;
  idx = 0;
  exitg1 = false;
  while ((!exitg1) && (idx < 2)) {
    if (!b_x[idx]) {
      b_y = false;
      exitg1 = true;
    } else {
      idx++;
    }
  }

  if (b_y) {
    sf_simulink_sort(f2_data, f2_size);
    if (f2_size[1] <= 2) {
      if (f2_size[1] == 1) {
        mx = f2_data[0];
      } else if (f2_data[0] < f2_data[1]) {
        mx = f2_data[1];
      } else {
        mx = f2_data[0];
      }
    } else {
      mx = f2_data[0];
      for (idx = 1; idx < f2_size[1]; idx++) {
        if (mx < f2_data[idx]) {
          mx = f2_data[idx];
        }
      }
    }
  }

  if ((mn == 0.0) || (mx == 0.0)) {
    if (mn != 0.0) {
      y = mn - 1.0;
    } else {
      y = mx - 1.0;
    }
  } else {
    y = mn - 1.0;
  }

  return y;
}

/* Function for Chart: '<S2>/cruser chart' */
static void sf_simulink_accelerator(B_sf_simulink_T *sf_simulink_B)
{
  int32_T tmp;
  tmp = sf_simulink_B->speed + (int32_T)sf_simulink_EXTRA_SPEED;
  if (tmp < 32768) {
    sf_simulink_B->speed = (int16_T)tmp;
  } else {
    sf_simulink_B->speed = MAX_int16_T;
  }

  if (sf_simulink_B->speed > 500) {
    sf_simulink_B->speed = 500;
  }
}

/* Function for Chart: '<S2>/cruser chart' */
static void sf_simulink_time_reprocessing(real_T *dt, DW_sf_simulink_T
  *sf_simulink_DW)
{
  /*  time is mircoseconds.
     range is 0 ~ 999999 */
  if (sf_simulink_DW->time < sf_simulink_DW->save_time) {
    *dt = (sf_simulink_TIME_UNIT - sf_simulink_DW->save_time) +
      sf_simulink_DW->time;
  } else {
    *dt = sf_simulink_DW->save_time - sf_simulink_DW->time;
  }

  *dt /= sf_simulink_TIME_UNIT;
}

/* Function for Chart: '<S2>/cruser chart' */
static void sf_simulink_brake(B_sf_simulink_T *sf_simulink_B)
{
  int32_T tmp;
  tmp = sf_simulink_B->speed - (int32_T)sf_simulink_EXTRA_SPEED;
  if (tmp >= -32768) {
    sf_simulink_B->speed = (int16_T)tmp;
  } else {
    sf_simulink_B->speed = MIN_int16_T;
  }

  if (sf_simulink_B->speed < 0) {
    sf_simulink_B->speed = 0;
  }
}

/* Function for Chart: '<S2>/cruser chart' */
static void sf_simulink_check_speeding(B_sf_simulink_T *sf_simulink_B)
{
  /*  overfast checking  */
  sf_simulink_B->overfast_flag = (uint8_T)(sf_simulink_B->front_car_speed > 0.6);
}

/* Function for Chart: '<S1>/object fetch' */
static void sf_simulink_up_count(real_T *cnt, real_T limit)
{
  if (*cnt < limit) {
    (*cnt)++;
  }
}

/* Function for Chart: '<S1>/object fetch' */
static real_T sf_simulink_search(const real_T x[10], const real_T y[10], real_T
  val)
{
  int32_T b_ii;
  int8_T ii_data_idx_0;
  boolean_T exitg1;
  b_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (b_ii < 10)) {
    if (x[b_ii] == val) {
      ii_data_idx_0 = (int8_T)(b_ii + 1);
      exitg1 = true;
    } else {
      b_ii++;
    }
  }

  return y[ii_data_idx_0 - 1];
}

/* Model step function */
void sf_simulink_step(RT_MODEL_sf_simulink_T *const sf_simulink_M)
{
  B_sf_simulink_T *sf_simulink_B = ((B_sf_simulink_T *) sf_simulink_M->blockIO);
  DW_sf_simulink_T *sf_simulink_DW = ((DW_sf_simulink_T *) sf_simulink_M->dwork);
  ExtU_sf_simulink_T *sf_simulink_U = (ExtU_sf_simulink_T *)
    sf_simulink_M->inputs;
  ExtY_sf_simulink_T *sf_simulink_Y = (ExtY_sf_simulink_T *)
    sf_simulink_M->outputs;
  real_T local_angle_cam[10];
  real_T local_angle_lidar[10];
  int8_T c;
  int8_T l;
  int16_T i;
  real_T car_num;
  real_T local_angle_cam_tmp[10];
  real_T local_angle_lidar_tmp[10];
  int32_T i_0;
  real_T tmp[10];
  boolean_T guard1 = false;

  /* Chart: '<S1>/object fetch' incorporates:
   *  BusCreator generated from: '<S1>/object fetch'
   *  Inport: '<Root>/Input'
   *  Inport: '<Root>/Input1'
   * */
  if (sf_simulink_DW->is_active_c1_sf_simulink == 0U) {
    sf_simulink_DW->is_active_c1_sf_simulink = 1U;
    sf_simulink_DW->is_c1_sf_simulink = 1;
  } else if (sf_simulink_DW->is_c1_sf_simulink == 1) {
    sf_simulink_DW->is_c1_sf_simulink = sf_simulink_IN_running;
  } else {
    /* case IN_running: */
    /*  local data qsort  */
    for (i_0 = 0; i_0 < 10; i_0++) {
      local_angle_cam[i_0] = sf_simulink_qsort((real_T)
        sf_simulink_U->Input.object_angle[i_0]);
      local_angle_lidar[i_0] = sf_simulink_qsort((real_T)
        sf_simulink_U->Input1.angle[i_0]);
      local_angle_cam_tmp[i_0] = sf_simulink_U->Input.object_angle[i_0];
      local_angle_lidar_tmp[i_0] = sf_simulink_U->Input1.angle[i_0];
    }

    i = 0;
    c = 0;
    l = 0;
    while (i < 360) {
      /* NEW_PATTERN */
      guard1 = false;
      if ((c >= 10) && (l >= 10)) {
        guard1 = true;
      } else {
        /*  each data is bigger than zero,
           the absolute value of diff between local angles is smaller than three.
           !!! used data is set minus one !!!
           data is existed, what...  */
        if ((local_angle_cam[c] >= 0.0) && (local_angle_lidar[l] >= 0.0) &&
            (fabs(local_angle_cam[c] - (real_T)i) < sf_simulink_DIFF_ANGLE) &&
            (fabs(local_angle_lidar[l] - (real_T)i) < sf_simulink_DIFF_ANGLE) &&
            ((local_angle_cam[c] + local_angle_lidar[l]) / 2.0 == i)) {
          sf_simulink_DW->each_object.who = 3U;
          for (i_0 = 0; i_0 < 10; i_0++) {
            tmp[i_0] = sf_simulink_U->Input.object_id[i_0];
          }

          car_num = sf_simulink_search(local_angle_cam_tmp, tmp,
            local_angle_cam[c]);
          if (car_num < 4.294967296E+9) {
            if (car_num >= 0.0) {
              sf_simulink_DW->each_object.id = (uint32_T)car_num;
            } else {
              sf_simulink_DW->each_object.id = 0U;
            }
          } else {
            sf_simulink_DW->each_object.id = MAX_uint32_T;
          }

          sf_simulink_DW->each_object.dist = sf_simulink_search
            (local_angle_lidar_tmp, sf_simulink_U->Input1.dist,
             local_angle_lidar[l]);
          sf_simulink_B->object[i] = sf_simulink_DW->each_object;
          car_num = c;
          sf_simulink_up_count(&car_num, 10.0);
          if (car_num < 128.0) {
            if (car_num >= -128.0) {
              c = (int8_T)car_num;
            } else {
              c = MIN_int8_T;
            }
          } else {
            c = MAX_int8_T;
          }

          car_num = l;
          sf_simulink_up_count(&car_num, 10.0);
          if (car_num < 128.0) {
            if (car_num >= -128.0) {
              l = (int8_T)car_num;
            } else {
              l = MIN_int8_T;
            }
          } else {
            l = MAX_int8_T;
          }
        } else {
          if ((local_angle_cam[c] < (real_T)i - sf_simulink_DIFF_ANGLE) &&
              (local_angle_cam[c] >= 0.0)) {
            car_num = c;
            sf_simulink_up_count(&car_num, 10.0);
            if (car_num < 128.0) {
              if (car_num >= -128.0) {
                c = (int8_T)car_num;
              } else {
                c = MIN_int8_T;
              }
            } else {
              c = MAX_int8_T;
            }
          }

          if ((local_angle_lidar[l] < (real_T)i - sf_simulink_DIFF_ANGLE) &&
              (local_angle_lidar[l] >= 0.0)) {
            car_num = l;
            sf_simulink_up_count(&car_num, 10.0);
            if (car_num < 128.0) {
              if (car_num >= -128.0) {
                l = (int8_T)car_num;
              } else {
                l = MIN_int8_T;
              }
            } else {
              l = MAX_int8_T;
            }
          }

          guard1 = true;
        }
      }

      if (guard1) {
        sf_simulink_DW->each_object.who = 0U;
        sf_simulink_DW->each_object.id = 0U;
        sf_simulink_DW->each_object.dist = 0.0;
        sf_simulink_B->object[i] = sf_simulink_DW->each_object;
      }

      i++;
    }

    /*  data fetch */
    sf_simulink_B->cruiser.line_angle = sf_simulink_U->Input.line_angle;
    sf_simulink_B->cruiser.car_check_flag = sf_simulink_U->Input.car_check_flag;
    sf_simulink_B->cruiser.change_lane_dir =
      sf_simulink_U->Input.change_lane_dir;
    sf_simulink_DW->is_c1_sf_simulink = sf_simulink_IN_running;
  }

  /* End of Chart: '<S1>/object fetch' */

  /* Chart: '<S2>/cruser chart' incorporates:
   *  Inport: '<Root>/Input2'
   */
  if (sf_simulink_DW->is_active_c3_sf_simulink == 0U) {
    sf_simulink_DW->is_active_c3_sf_simulink = 1U;
    sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_init;

    /* local */
    sf_simulink_DW->save_dist = 0.0;
    sf_simulink_DW->save_time = 0.0;
    sf_simulink_DW->time = sf_simulink_U->Input2.time;

    /* output */
    if (sf_simulink_B->cruiser.line_angle < 32768.0) {
      if (sf_simulink_B->cruiser.line_angle >= -32768.0) {
        sf_simulink_B->steering_angle = (int16_T)
          sf_simulink_B->cruiser.line_angle;
      } else {
        sf_simulink_B->steering_angle = MIN_int16_T;
      }
    } else {
      sf_simulink_B->steering_angle = MAX_int16_T;
    }

    sf_simulink_B->speed = 0;
    sf_simulink_B->overfast_flag = 0U;
    sf_simulink_B->front_car_speed = 0.0;
  } else {
    guard1 = false;
    switch (sf_simulink_DW->is_c3_sf_simulink) {
     case sf_simulink_IN_change_lane:
      sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_normal_running;
      break;

     case sf_simulink_IN_init:
      sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_normal_running;
      break;

     default:
      /* case IN_normal_running: */
      sf_simulink_signal_processing(&sf_simulink_U->Input2, sf_simulink_B,
        sf_simulink_DW);

      /*  discover the car in front  */
      if ((sf_simulink_B->cruiser.car_check_flag == 1) &&
          (sf_simulink_nonzero_front(sf_simulink_B->object) != 0.0)) {
        car_num = sf_simulink_front_ele(sf_simulink_B->object);
        if (car_num < 2.147483648E+9) {
          if (car_num >= -2.147483648E+9) {
            i_0 = (int32_T)car_num;
          } else {
            i_0 = MIN_int32_T;
          }
        } else {
          i_0 = MAX_int32_T;
        }

        sf_simulink_time_reprocessing(&car_num, sf_simulink_DW);
        car_num = (sf_simulink_B->object[i_0].dist - sf_simulink_DW->save_dist) /
          car_num;

        /*  speed unit is centimeters, relative_velovity unit is meters  */
        sf_simulink_B->front_car_speed = (real_T)(sf_simulink_B->speed / 100) +
          car_num;
        sf_simulink_check_speeding(sf_simulink_B);

        /*  the front car is getting closer
           If the front car is already close, can't change lane  */
        if ((car_num < 0.0) && (sf_simulink_B->object[i_0].dist > 1.0)) {
          sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_change_lane;
        } else {
          /*  the front car is close
             if it insisted accelerate */
          if (sf_simulink_B->object[i_0].dist < sf_simulink_STOP_DISTANCE) {
            guard1 = true;
          } else {
            sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_normal_running;
          }
        }
      } else {
        /*  undiscover the car in front  */
        /*  signal light color isn't yellow or red  */
        if (sf_simulink_U->Input.sig_flag == 0) {
          sf_simulink_accelerator(sf_simulink_B);
          sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_normal_running;
        } else {
          /*  stop line is close  */
          if (sf_simulink_U->Input.stop_line_dist < sf_simulink_STOP_DISTANCE) {
            guard1 = true;
          } else {
            sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_normal_running;
          }
        }
      }
      break;
    }

    if (guard1) {
      sf_simulink_brake(sf_simulink_B);
      sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_normal_running;
    }
  }

  /* End of Chart: '<S2>/cruser chart' */

  /* Chart: '<S2>/signal violation checking chart' */
  if (sf_simulink_DW->is_active_c4_sf_simulink == 0U) {
    sf_simulink_DW->is_active_c4_sf_simulink = 1U;
    sf_simulink_Y->Output.signal_violation_flag = 0U;
  } else {
    sf_simulink_Y->Output.signal_violation_flag = 0U;
  }

  /* End of Chart: '<S2>/signal violation checking chart' */

  /* BusCreator generated from: '<Root>/Output' incorporates:
   *  Inport: '<Root>/Input'
   *  Outport: '<Root>/Output'
   */
  sf_simulink_Y->Output.front_car_speed = sf_simulink_B->front_car_speed;
  sf_simulink_Y->Output.overfast_flag = sf_simulink_B->overfast_flag;
  sf_simulink_Y->Output.crack_flag = sf_simulink_U->Input.crack_flag;

  /* Chart: '<S2>/light on-off chart' */
  if (sf_simulink_DW->is_active_c2_sf_simulink == 0U) {
    sf_simulink_DW->is_active_c2_sf_simulink = 1U;
    sf_simulink_Y->Output1.blinker_onoff = 0U;
    sf_simulink_Y->Output1.blinker_dir = 0U;
  } else {
    sf_simulink_Y->Output1.blinker_onoff = 0U;
    sf_simulink_Y->Output1.blinker_dir = 0U;
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

  {
    OBJECT struct_temp;
    int32_T i;

    /* SystemInitialize for Chart: '<S1>/object fetch' */
    sf_simulink_DW->is_active_c1_sf_simulink = 0U;
    sf_simulink_DW->is_c1_sf_simulink = sf_simulink_IN_NO_ACTIVE_CHILD;
    sf_simulink_DW->each_object.who = 0U;
    sf_simulink_DW->each_object.id = 0U;
    sf_simulink_DW->each_object.dist = 0.0;
    sf_simulink_B->cruiser.line_angle = 0.0;
    sf_simulink_B->cruiser.car_check_flag = 0U;
    sf_simulink_B->cruiser.change_lane_dir = 0U;
    struct_temp.who = 0U;
    struct_temp.id = 0U;
    struct_temp.dist = 0.0;
    for (i = 0; i < 360; i++) {
      sf_simulink_B->object[i] = struct_temp;
    }

    /* End of SystemInitialize for Chart: '<S1>/object fetch' */

    /* SystemInitialize for Chart: '<S2>/cruser chart' */
    sf_simulink_DW->is_active_c3_sf_simulink = 0U;
    sf_simulink_DW->is_c3_sf_simulink = sf_simulink_IN_NO_ACTIVE_CHILD;
    sf_simulink_DW->time = 0.0;
    sf_simulink_DW->save_time = 0.0;
    sf_simulink_DW->save_dist = 0.0;
    sf_simulink_B->steering_angle = 0;
    sf_simulink_B->speed = 0;
    sf_simulink_B->overfast_flag = 0U;
    sf_simulink_B->front_car_speed = 0.0;

    /* SystemInitialize for Chart: '<S2>/signal violation checking chart' */
    sf_simulink_DW->is_active_c4_sf_simulink = 0U;

    /* SystemInitialize for Chart: '<S2>/light on-off chart' */
    sf_simulink_DW->is_active_c2_sf_simulink = 0U;
  }
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
