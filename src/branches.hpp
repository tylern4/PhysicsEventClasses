/**************************************/
/*																		*/
/*  Created by Nick Tyler             */
/*	University Of South Carolina      */
/**************************************/

#ifndef BRANCHES_H
#define BRANCHES_H
#include <iostream>
#include <vector>
#include "TChain.h"
#include "constants.hpp"

using v_int = std::vector<int> *;
using v_float = std::vector<float> *;

class Branches12 {
 private:
  std::shared_ptr<TChain> _tree;
  int _NRUN;
  int _NEVENT;
  float _EVNTime;
  int _TYPE;
  int _TRG;
  float _BCG;
  float _STTime;
  float _RFTime;
  int _Helic;
  int _EvCAT;
  int _NPGP;
  double _LT;
  float _PTIME;

  v_int _pid;
  v_float _p;
  v_float _p2;
  v_float _px;
  v_float _py;
  v_float _pz;
  v_float _vx;
  v_float _vy;
  v_float _vz;
  v_int _charge;
  v_float _beta;
  v_float _chi2pid;
  v_int _status;

  v_int _dc_sec;
  v_float _dc_px;
  v_float _dc_py;
  v_float _dc_pz;
  v_float _dc_vx;
  v_float _dc_vy;
  v_float _dc_vz;

  v_float _cvt_px;
  v_float _cvt_py;
  v_float _cvt_pz;
  v_float _cvt_vx;
  v_float _cvt_vy;
  v_float _cvt_vz;

  v_float _ec_tot_energy;
  v_float _ec_pcal_energy;
  v_int _ec_pcal_sec;
  v_float _ec_pcal_time;
  v_float _ec_pcal_path;
  v_float _ec_pcal_x;
  v_float _ec_pcal_y;
  v_float _ec_pcal_z;
  v_float _ec_pcal_hx;
  v_float _ec_pcal_hy;
  v_float _ec_pcal_hz;
  v_float _ec_pcal_lu;
  v_float _ec_pcal_lv;
  v_float _ec_pcal_lw;
  v_float _ec_pcal_du;
  v_float _ec_pcal_dv;
  v_float _ec_pcal_dw;
  v_float _ec_pcal_m2u;
  v_float _ec_pcal_m2v;
  v_float _ec_pcal_m2w;
  v_float _ec_pcal_m3u;
  v_float _ec_pcal_m3v;
  v_float _ec_pcal_m3w;

  v_float _ec_ecin_energy;
  v_int _ec_ecin_sec;
  v_float _ec_ecin_time;
  v_float _ec_ecin_path;
  v_float _ec_ecin_x;
  v_float _ec_ecin_y;
  v_float _ec_ecin_z;
  v_float _ec_ecin_hx;
  v_float _ec_ecin_hy;
  v_float _ec_ecin_hz;
  v_float _ec_ecin_lu;
  v_float _ec_ecin_lv;
  v_float _ec_ecin_lw;
  v_float _ec_ecin_du;
  v_float _ec_ecin_dv;
  v_float _ec_ecin_dw;
  v_float _ec_ecin_m2u;
  v_float _ec_ecin_m2v;
  v_float _ec_ecin_m2w;
  v_float _ec_ecin_m3u;
  v_float _ec_ecin_m3v;
  v_float _ec_ecin_m3w;

  v_float _ec_ecout_energy;
  v_int _ec_ecout_sec;
  v_float _ec_ecout_time;
  v_float _ec_ecout_path;
  v_float _ec_ecout_x;
  v_float _ec_ecout_y;
  v_float _ec_ecout_z;
  v_float _ec_ecout_hx;
  v_float _ec_ecout_hy;
  v_float _ec_ecout_hz;
  v_float _ec_ecout_lu;
  v_float _ec_ecout_lv;
  v_float _ec_ecout_lw;
  v_float _ec_ecout_du;
  v_float _ec_ecout_dv;
  v_float _ec_ecout_dw;
  v_float _ec_ecout_m2u;
  v_float _ec_ecout_m2v;
  v_float _ec_ecout_m2w;
  v_float _ec_ecout_m3u;
  v_float _ec_ecout_m3v;
  v_float _ec_ecout_m3w;

  v_float _cc_nphe_tot;
  v_int _cc_ltcc_sec;
  v_float _cc_ltcc_nphe;
  v_float _cc_ltcc_time;
  v_float _cc_ltcc_path;
  v_float _cc_ltcc_theta;
  v_float _cc_ltcc_phi;
  v_float _cc_ltcc_x;
  v_float _cc_ltcc_y;
  v_float _cc_ltcc_z;
  v_int _cc_htcc_sec;
  v_float _cc_htcc_nphe;
  v_float _cc_htcc_time;
  v_float _cc_htcc_path;
  v_float _cc_htcc_theta;
  v_float _cc_htcc_phi;
  v_float _cc_htcc_x;
  v_float _cc_htcc_y;
  v_float _cc_htcc_z;
  v_int _cc_rich_sec;
  v_float _cc_rich_nphe;
  v_float _cc_rich_time;
  v_float _cc_rich_path;
  v_float _cc_rich_theta;
  v_float _cc_rich_phi;
  v_float _cc_rich_x;
  v_float _cc_rich_y;
  v_float _cc_rich_z;

  v_int _sc_ftof_1a_sec;
  v_float _sc_ftof_1a_time;
  v_float _sc_ftof_1a_path;
  v_float _sc_ftof_1a_energy;
  v_int _sc_ftof_1a_component;
  v_float _sc_ftof_1a_x;
  v_float _sc_ftof_1a_y;
  v_float _sc_ftof_1a_z;
  v_float _sc_ftof_1a_hx;
  v_float _sc_ftof_1a_hy;
  v_float _sc_ftof_1a_hz;

  v_int _sc_ftof_1b_sec;
  v_float _sc_ftof_1b_time;
  v_float _sc_ftof_1b_path;
  v_float _sc_ftof_1b_energy;
  v_int _sc_ftof_1b_component;
  v_float _sc_ftof_1b_x;
  v_float _sc_ftof_1b_y;
  v_float _sc_ftof_1b_z;
  v_float _sc_ftof_1b_hx;
  v_float _sc_ftof_1b_hy;
  v_float _sc_ftof_1b_hz;

  v_int _sc_ftof_2_sec;
  v_float _sc_ftof_2_time;
  v_float _sc_ftof_2_path;
  v_float _sc_ftof_2_energy;
  v_int _sc_ftof_2_component;
  v_float _sc_ftof_2_x;
  v_float _sc_ftof_2_y;
  v_float _sc_ftof_2_z;
  v_float _sc_ftof_2_hx;
  v_float _sc_ftof_2_hy;
  v_float _sc_ftof_2_hz;

  v_float _sc_ctof_time;
  v_float _sc_ctof_path;
  v_float _sc_ctof_energy;
  v_int _sc_ctof_component;
  v_float _sc_ctof_x;
  v_float _sc_ctof_y;
  v_float _sc_ctof_z;
  v_float _sc_ctof_hx;
  v_float _sc_ctof_hy;
  v_float _sc_ctof_hz;

  v_float _sc_cnd_time;
  v_float _sc_cnd_path;
  v_float _sc_cnd_energy;
  v_int _sc_cnd_component;
  v_float _sc_cnd_x;
  v_float _sc_cnd_y;
  v_float _sc_cnd_z;
  v_float _sc_cnd_hx;
  v_float _sc_cnd_hy;
  v_float _sc_cnd_hz;

  v_float _ft_cal_energy;
  v_float _ft_cal_time;
  v_float _ft_cal_path;
  v_float _ft_cal_x;
  v_float _ft_cal_y;
  v_float _ft_cal_z;
  v_float _ft_cal_dx;
  v_float _ft_cal_dy;
  v_float _ft_cal_radius;

  v_float _ft_hodo_energy;
  v_float _ft_hodo_time;
  v_float _ft_hodo_path;
  v_float _ft_hodo_x;
  v_float _ft_hodo_y;
  v_float _ft_hodo_z;
  v_float _ft_hodo_dx;
  v_float _ft_hodo_dy;
  v_float _ft_hodo_radius;

  v_int _MC_pid;
  v_float _MC_helicity;
  v_float _MC_px;
  v_float _MC_py;
  v_float _MC_pz;
  v_float _MC_vx;
  v_float _MC_vy;
  v_float _MC_vz;
  v_float _MC_vt;

  v_int _Lund_pid;
  v_float _Lund_px;
  v_float _Lund_py;
  v_float _Lund_pz;
  v_float _Lund_E;
  v_float _Lund_vx;
  v_float _Lund_vy;
  v_float _Lund_vz;
  v_float _Lund_ltime;

  v_float _CovMat_11;
  v_float _CovMat_12;
  v_float _CovMat_13;
  v_float _CovMat_14;
  v_float _CovMat_15;
  v_float _CovMat_22;
  v_float _CovMat_23;
  v_float _CovMat_24;
  v_float _CovMat_25;
  v_float _CovMat_33;
  v_float _CovMat_34;
  v_float _CovMat_35;
  v_float _CovMat_44;
  v_float _CovMat_45;
  v_float _CovMat_55;

  v_int _VertDoca_index1_vec;
  v_int _VertDoca_index2_vec;
  v_float _VertDoca_x_vec;
  v_float _VertDoca_y_vec;
  v_float _VertDoca_z_vec;
  v_float _VertDoca_x1_vec;
  v_float _VertDoca_y1_vec;
  v_float _VertDoca_z1_vec;
  v_float _VertDoca_cx1_vec;
  v_float _VertDoca_cy1_vec;
  v_float _VertDoca_cz1_vec;
  v_float _VertDoca_x2_vec;
  v_float _VertDoca_y2_vec;
  v_float _VertDoca_z2_vec;
  v_float _VertDoca_cx2_vec;
  v_float _VertDoca_cy2_vec;
  v_float _VertDoca_cz2_vec;
  v_float _VertDoca_r_vec;

  v_int _traj_pindex_vec;
  v_int _traj_index_vec;
  v_int _traj_detId_vec;
  v_int _traj_q_vec;
  v_float _traj_x_vec;
  v_float _traj_y_vec;
  v_float _traj_z_vec;
  v_float _traj_cx_vec;
  v_float _traj_cy_vec;
  v_float _traj_cz_vec;
  v_float _traj_pathlength_vec;

 public:
  Branches12(std::shared_ptr<TChain> tree);
  ~Branches12(){};
  void init();
  int NRUN();
  int NEVENT();
  float EVNTime();
  int TYPE();
  int TRG();
  float BCG();
  float STTime();
  float RFTime();
  int Helic();
  int EvCAT();
  int NPGP();
  double LT();
  float PTIME();

  size_t gpart();
  int pid(int i);
  float p(int i);
  float p2(int i);
  float px(int i);
  float py(int i);
  float pz(int i);
  float vx(int i);
  float vy(int i);
  float vz(int i);
  int charge(int i);
  float beta(int i);
  float chi2pid(int i);
  int status(int i);
  /*
  float ec_tot_energy(int i);
  float ec_pcal_energy(int i);
  int ec_pcal_sec(int i);
  float ec_pcal_time(int i);
  float ec_pcal_path(int i);
  float ec_pcal_x(int i);
  float ec_pcal_y(int i);
  float ec_pcal_z(int i);
  float ec_pcal_lu(int i);
  float ec_pcal_lv(int i);
  float ec_pcal_lw(int i);
  float ec_ecin_energy(int i);
  int ec_ecin_sec(int i);
  float ec_ecin_time(int i);
  float ec_ecin_path(int i);
  float ec_ecin_x(int i);
  float ec_ecin_y(int i);
  float ec_ecin_z(int i);
  float ec_ecin_lu(int i);
  float ec_ecin_lv(int i);
  float ec_ecin_lw(int i);
  float ec_ecout_energy(int i);
  int ec_ecout_sec(int i);
  float ec_ecout_time(int i);
  float ec_ecout_path(int i);
  float ec_ecout_x(int i);
  float ec_ecout_y(int i);
  float ec_ecout_z(int i);
  float ec_ecout_lu(int i);
  float ec_ecout_lv(int i);
  float ec_ecout_lw(int i);
  int dc_sec(int i);
  float dc_px(int i);
  float dc_py(int i);
  float dc_pz(int i);
  float dc_vx(int i);
  float dc_vy(int i);
  float dc_vz(int i);
  float cvt_px(int i);
  float cvt_py(int i);
  float cvt_pz(int i);
  float cvt_vx(int i);
  float cvt_vy(int i);
  float cvt_vz(int i);
  float cc_nphe_tot(int i);
  int cc_ltcc_sec(int i);
  float cc_ltcc_nphe(int i);
  float cc_ltcc_time(int i);
  float cc_ltcc_path(int i);
  float cc_ltcc_theta(int i);
  float cc_ltcc_phi(int i);
  int cc_htcc_sec(int i);
  float cc_htcc_nphe(int i);
  float cc_htcc_time(int i);
  float cc_htcc_path(int i);
  float cc_htcc_theta(int i);
  float cc_htcc_phi(int i);
  int cc_rich_sec(int i);
  float cc_rich_nphe(int i);
  float cc_rich_time(int i);
  float cc_rich_path(int i);
  float cc_rich_theta(int i);
  float cc_rich_phi(int i);
  float sc_ftof_1a_sec(int i);
  float sc_ftof_1a_time(int i);
  float sc_ftof_1a_path(int i);
  float sc_ftof_1a_energy(int i);
  int sc_ftof_1a_component(int i);
  float sc_ftof_1a_x(int i);
  float sc_ftof_1a_y(int i);
  float sc_ftof_1a_z(int i);
  float sc_ftof_1a_hx(int i);
  float sc_ftof_1a_hy(int i);
  float sc_ftof_1a_hz(int i);
  int sc_ftof_1b_sec(int i);
  float sc_ftof_1b_time(int i);
  float sc_ftof_1b_path(int i);
  float sc_ftof_1b_energy(int i);
  int sc_ftof_1b_component(int i);
  float sc_ftof_1b_x(int i);
  float sc_ftof_1b_y(int i);
  float sc_ftof_1b_z(int i);
  float sc_ftof_1b_hx(int i);
  float sc_ftof_1b_hy(int i);
  float sc_ftof_1b_hz(int i);
  int sc_ftof_2_sec(int i);
  float sc_ftof_2_time(int i);
  float sc_ftof_2_path(int i);
  float sc_ftof_2_energy(int i);
  int sc_ftof_2_component(int i);
  float sc_ftof_2_x(int i);
  float sc_ftof_2_y(int i);
  float sc_ftof_2_z(int i);
  float sc_ftof_2_hx(int i);
  float sc_ftof_2_hy(int i);
  float sc_ftof_2_hz(int i);
  float sc_ctof_time(int i);
  float sc_ctof_path(int i);
  float sc_ctof_energy(int i);
  int sc_ctof_component(int i);
  float sc_ctof_x(int i);
  float sc_ctof_y(int i);
  float sc_ctof_z(int i);
  float sc_ctof_hx(int i);
  float sc_ctof_hy(int i);
  float sc_ctof_hz(int i);
  float sc_cnd_time(int i);
  float sc_cnd_path(int i);
  float sc_cnd_energy(int i);
  int sc_cnd_component(int i);
  float sc_cnd_x(int i);
  float sc_cnd_y(int i);
  float sc_cnd_z(int i);
  float sc_cnd_hx(int i);
  float sc_cnd_hy(int i);
  float sc_cnd_hz(int i);
  float ft_cal_energy(int i);
  float ft_cal_time(int i);
  float ft_cal_path(int i);
  float ft_cal_x(int i);
  float ft_cal_y(int i);
  float ft_cal_z(int i);
  float ft_cal_dx(int i);
  float ft_cal_dy(int i);
  float ft_cal_radius(int i);
  float ft_hodo_energy(int i);
  float ft_hodo_time(int i);
  float ft_hodo_path(int i);
  float ft_hodo_x(int i);
  float ft_hodo_y(int i);
  float ft_hodo_z(int i);
  float ft_hodo_dx(int i);
  float ft_hodo_dy(int i);
  float ft_hodo_radius(int i);
  */
};

#endif
