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

  // Gotten from root's MakeClass
  Int_t _NRUN;
  Int_t _NEVENT;
  Float_t _EVNTime;
  Int_t _TYPE;
  Int_t _TRG;
  Float_t _BCG;
  Float_t _STTime;
  Float_t _RFTime;
  Int_t _Helic;
  Int_t _EvCAT;
  Int_t _NPGP;
  Double_t _LT;
  Float_t _PTIME;

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
  v_float _dc_r1_x;
  v_float _dc_r1_y;
  v_float _dc_r1_z;
  v_float _dc_r2_x;
  v_float _dc_r2_y;
  v_float _dc_r2_z;
  v_float _dc_r3_x;
  v_float _dc_r3_y;
  v_float _dc_r3_z;
  v_float _cvt_px;
  v_float _cvt_py;
  v_float _cvt_pz;
  v_float _cvt_vx;
  v_float _cvt_vy;
  v_float _cvt_vz;
  v_float _cvt_x;
  v_float _cvt_y;
  v_float _cvt_z;
  v_float _fmt_x;
  v_float _fmt_y;
  v_float _fmt_z;
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

 public:
  Branches12(std::shared_ptr<TChain> tree);
  ~Branches12(){};
  void init();

  int gpart();
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
  // TODO: Need to fill in all the banks
};

#endif
