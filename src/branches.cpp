/**************************************/
/*																		*/
/*  Created by Nick Tyler             */
/*	University Of South Carolina      */
/**************************************/

#include "branches.hpp"

Branches12::Branches12(std::shared_ptr<TChain> tree) {
  _tree = tree;
  Branches12::init();
}

void Branches12::init() {
  _tree->SetBranchStatus("*", 0);
  /*
  _tree->SetBranchAddress("NRUN", &_NRUN);
  _tree->SetBranchAddress("NEVENT", &_NEVENT);
  _tree->SetBranchAddress("EVNTime", &_EVNTime);
  _tree->SetBranchAddress("TYPE", &_TYPE);
  _tree->SetBranchAddress("TRG", &_TRG);
  _tree->SetBranchAddress("BCG", &_BCG);
  _tree->SetBranchAddress("STTime", &_STTime);
  _tree->SetBranchAddress("RFTime", &_RFTime);
  _tree->SetBranchAddress("Helic", &_Helic);
  _tree->SetBranchAddress("EvCAT", &_EvCAT);
  _tree->SetBranchAddress("NPGP", &_NPGP);
  _tree->SetBranchAddress("LT", &_LT);
  _tree->SetBranchAddress("PTIME", &_PTIME);
  */
  _tree->SetBranchAddress("pid", &_pid);
  _tree->SetBranchAddress("p", &_p);
  _tree->SetBranchAddress("p2", &_p2);
  _tree->SetBranchAddress("px", &_px);
  _tree->SetBranchAddress("py", &_py);
  _tree->SetBranchAddress("pz", &_pz);
  _tree->SetBranchAddress("vx", &_vx);
  _tree->SetBranchAddress("vy", &_vy);
  _tree->SetBranchAddress("vz", &_vz);
  _tree->SetBranchAddress("charge", &_charge);
  _tree->SetBranchAddress("beta", &_beta);
  _tree->SetBranchAddress("chi2pid", &_chi2pid);
  _tree->SetBranchAddress("status", &_status);
  _tree->SetBranchAddress("ec_tot_energy", &_ec_tot_energy);
  _tree->SetBranchAddress("ec_pcal_energy", &_ec_pcal_energy);
  _tree->SetBranchAddress("ec_pcal_sec", &_ec_pcal_sec);
  _tree->SetBranchAddress("ec_pcal_time", &_ec_pcal_time);
  _tree->SetBranchAddress("ec_pcal_path", &_ec_pcal_path);
  _tree->SetBranchAddress("ec_pcal_x", &_ec_pcal_x);
  _tree->SetBranchAddress("ec_pcal_y", &_ec_pcal_y);
  _tree->SetBranchAddress("ec_pcal_z", &_ec_pcal_z);
  _tree->SetBranchAddress("ec_pcal_lu", &_ec_pcal_lu);
  _tree->SetBranchAddress("ec_pcal_lv", &_ec_pcal_lv);
  _tree->SetBranchAddress("ec_pcal_lw", &_ec_pcal_lw);
  _tree->SetBranchAddress("ec_ecin_energy", &_ec_ecin_energy);
  _tree->SetBranchAddress("ec_ecin_sec", &_ec_ecin_sec);
  _tree->SetBranchAddress("ec_ecin_time", &_ec_ecin_time);
  _tree->SetBranchAddress("ec_ecin_path", &_ec_ecin_path);
  _tree->SetBranchAddress("ec_ecin_x", &_ec_ecin_x);
  _tree->SetBranchAddress("ec_ecin_y", &_ec_ecin_y);
  _tree->SetBranchAddress("ec_ecin_z", &_ec_ecin_z);
  _tree->SetBranchAddress("ec_ecin_lu", &_ec_ecin_lu);
  _tree->SetBranchAddress("ec_ecin_lv", &_ec_ecin_lv);
  _tree->SetBranchAddress("ec_ecin_lw", &_ec_ecin_lw);
  _tree->SetBranchAddress("ec_ecout_energy", &_ec_ecout_energy);
  _tree->SetBranchAddress("ec_ecout_sec", &_ec_ecout_sec);
  _tree->SetBranchAddress("ec_ecout_time", &_ec_ecout_time);
  _tree->SetBranchAddress("ec_ecout_path", &_ec_ecout_path);
  _tree->SetBranchAddress("ec_ecout_x", &_ec_ecout_x);
  _tree->SetBranchAddress("ec_ecout_y", &_ec_ecout_y);
  _tree->SetBranchAddress("ec_ecout_z", &_ec_ecout_z);
  _tree->SetBranchAddress("ec_ecout_lu", &_ec_ecout_lu);
  _tree->SetBranchAddress("ec_ecout_lv", &_ec_ecout_lv);
  _tree->SetBranchAddress("ec_ecout_lw", &_ec_ecout_lw);
  _tree->SetBranchAddress("dc_sec", &_dc_sec);
  _tree->SetBranchAddress("dc_px", &_dc_px);
  _tree->SetBranchAddress("dc_py", &_dc_py);
  _tree->SetBranchAddress("dc_pz", &_dc_pz);
  _tree->SetBranchAddress("dc_vx", &_dc_vx);
  _tree->SetBranchAddress("dc_vy", &_dc_vy);
  _tree->SetBranchAddress("dc_vz", &_dc_vz);
  _tree->SetBranchAddress("cvt_px", &_cvt_px);
  _tree->SetBranchAddress("cvt_py", &_cvt_py);
  _tree->SetBranchAddress("cvt_pz", &_cvt_pz);
  _tree->SetBranchAddress("cvt_vx", &_cvt_vx);
  _tree->SetBranchAddress("cvt_vy", &_cvt_vy);
  _tree->SetBranchAddress("cvt_vz", &_cvt_vz);
  _tree->SetBranchAddress("cc_nphe_tot", &_cc_nphe_tot);
  _tree->SetBranchAddress("cc_ltcc_sec", &_cc_ltcc_sec);
  _tree->SetBranchAddress("cc_ltcc_nphe", &_cc_ltcc_nphe);
  _tree->SetBranchAddress("cc_ltcc_time", &_cc_ltcc_time);
  _tree->SetBranchAddress("cc_ltcc_path", &_cc_ltcc_path);
  _tree->SetBranchAddress("cc_ltcc_theta", &_cc_ltcc_theta);
  _tree->SetBranchAddress("cc_ltcc_phi", &_cc_ltcc_phi);
  _tree->SetBranchAddress("cc_htcc_sec", &_cc_htcc_sec);
  _tree->SetBranchAddress("cc_htcc_nphe", &_cc_htcc_nphe);
  _tree->SetBranchAddress("cc_htcc_time", &_cc_htcc_time);
  _tree->SetBranchAddress("cc_htcc_path", &_cc_htcc_path);
  _tree->SetBranchAddress("cc_htcc_theta", &_cc_htcc_theta);
  _tree->SetBranchAddress("cc_htcc_phi", &_cc_htcc_phi);
  _tree->SetBranchAddress("cc_rich_sec", &_cc_rich_sec);
  _tree->SetBranchAddress("cc_rich_nphe", &_cc_rich_nphe);
  _tree->SetBranchAddress("cc_rich_time", &_cc_rich_time);
  _tree->SetBranchAddress("cc_rich_path", &_cc_rich_path);
  _tree->SetBranchAddress("cc_rich_theta", &_cc_rich_theta);
  _tree->SetBranchAddress("cc_rich_phi", &_cc_rich_phi);
  _tree->SetBranchAddress("sc_ftof_1a_sec", &_sc_ftof_1a_sec);
  _tree->SetBranchAddress("sc_ftof_1a_time", &_sc_ftof_1a_time);
  _tree->SetBranchAddress("sc_ftof_1a_path", &_sc_ftof_1a_path);
  _tree->SetBranchAddress("sc_ftof_1a_energy", &_sc_ftof_1a_energy);
  _tree->SetBranchAddress("sc_ftof_1a_component", &_sc_ftof_1a_component);
  _tree->SetBranchAddress("sc_ftof_1a_x", &_sc_ftof_1a_x);
  _tree->SetBranchAddress("sc_ftof_1a_y", &_sc_ftof_1a_y);
  _tree->SetBranchAddress("sc_ftof_1a_z", &_sc_ftof_1a_z);
  _tree->SetBranchAddress("sc_ftof_1a_hx", &_sc_ftof_1a_hx);
  _tree->SetBranchAddress("sc_ftof_1a_hy", &_sc_ftof_1a_hy);
  _tree->SetBranchAddress("sc_ftof_1a_hz", &_sc_ftof_1a_hz);
  _tree->SetBranchAddress("sc_ftof_1b_sec", &_sc_ftof_1b_sec);
  _tree->SetBranchAddress("sc_ftof_1b_time", &_sc_ftof_1b_time);
  _tree->SetBranchAddress("sc_ftof_1b_path", &_sc_ftof_1b_path);
  _tree->SetBranchAddress("sc_ftof_1b_energy", &_sc_ftof_1b_energy);
  _tree->SetBranchAddress("sc_ftof_1b_component", &_sc_ftof_1b_component);
  _tree->SetBranchAddress("sc_ftof_1b_x", &_sc_ftof_1b_x);
  _tree->SetBranchAddress("sc_ftof_1b_y", &_sc_ftof_1b_y);
  _tree->SetBranchAddress("sc_ftof_1b_z", &_sc_ftof_1b_z);
  _tree->SetBranchAddress("sc_ftof_1b_hx", &_sc_ftof_1b_hx);
  _tree->SetBranchAddress("sc_ftof_1b_hy", &_sc_ftof_1b_hy);
  _tree->SetBranchAddress("sc_ftof_1b_hz", &_sc_ftof_1b_hz);
  _tree->SetBranchAddress("sc_ftof_2_sec", &_sc_ftof_2_sec);
  _tree->SetBranchAddress("sc_ftof_2_time", &_sc_ftof_2_time);
  _tree->SetBranchAddress("sc_ftof_2_path", &_sc_ftof_2_path);
  _tree->SetBranchAddress("sc_ftof_2_energy", &_sc_ftof_2_energy);
  _tree->SetBranchAddress("sc_ftof_2_component", &_sc_ftof_2_component);
  _tree->SetBranchAddress("sc_ftof_2_x", &_sc_ftof_2_x);
  _tree->SetBranchAddress("sc_ftof_2_y", &_sc_ftof_2_y);
  _tree->SetBranchAddress("sc_ftof_2_z", &_sc_ftof_2_z);
  _tree->SetBranchAddress("sc_ftof_2_hx", &_sc_ftof_2_hx);
  _tree->SetBranchAddress("sc_ftof_2_hy", &_sc_ftof_2_hy);
  _tree->SetBranchAddress("sc_ftof_2_hz", &_sc_ftof_2_hz);
  _tree->SetBranchAddress("sc_ctof_time", &_sc_ctof_time);
  _tree->SetBranchAddress("sc_ctof_path", &_sc_ctof_path);
  _tree->SetBranchAddress("sc_ctof_energy", &_sc_ctof_energy);
  _tree->SetBranchAddress("sc_ctof_component", &_sc_ctof_component);
  _tree->SetBranchAddress("sc_ctof_x", &_sc_ctof_x);
  _tree->SetBranchAddress("sc_ctof_y", &_sc_ctof_y);
  _tree->SetBranchAddress("sc_ctof_z", &_sc_ctof_z);
  _tree->SetBranchAddress("sc_ctof_hx", &_sc_ctof_hx);
  _tree->SetBranchAddress("sc_ctof_hy", &_sc_ctof_hy);
  _tree->SetBranchAddress("sc_ctof_hz", &_sc_ctof_hz);
  _tree->SetBranchAddress("sc_cnd_time", &_sc_cnd_time);
  _tree->SetBranchAddress("sc_cnd_path", &_sc_cnd_path);
  _tree->SetBranchAddress("sc_cnd_energy", &_sc_cnd_energy);
  _tree->SetBranchAddress("sc_cnd_component", &_sc_cnd_component);
  _tree->SetBranchAddress("sc_cnd_x", &_sc_cnd_x);
  _tree->SetBranchAddress("sc_cnd_y", &_sc_cnd_y);
  _tree->SetBranchAddress("sc_cnd_z", &_sc_cnd_z);
  _tree->SetBranchAddress("sc_cnd_hx", &_sc_cnd_hx);
  _tree->SetBranchAddress("sc_cnd_hy", &_sc_cnd_hy);
  _tree->SetBranchAddress("sc_cnd_hz", &_sc_cnd_hz);
  _tree->SetBranchAddress("ft_cal_energy", &_ft_cal_energy);
  _tree->SetBranchAddress("ft_cal_time", &_ft_cal_time);
  _tree->SetBranchAddress("ft_cal_path", &_ft_cal_path);
  _tree->SetBranchAddress("ft_cal_x", &_ft_cal_x);
  _tree->SetBranchAddress("ft_cal_y", &_ft_cal_y);
  _tree->SetBranchAddress("ft_cal_z", &_ft_cal_z);
  _tree->SetBranchAddress("ft_cal_dx", &_ft_cal_dx);
  _tree->SetBranchAddress("ft_cal_dy", &_ft_cal_dy);
  _tree->SetBranchAddress("ft_cal_radius", &_ft_cal_radius);
  _tree->SetBranchAddress("ft_hodo_energy", &_ft_hodo_energy);
  _tree->SetBranchAddress("ft_hodo_time", &_ft_hodo_time);
  _tree->SetBranchAddress("ft_hodo_path", &_ft_hodo_path);
  _tree->SetBranchAddress("ft_hodo_x", &_ft_hodo_x);
  _tree->SetBranchAddress("ft_hodo_y", &_ft_hodo_y);
  _tree->SetBranchAddress("ft_hodo_z", &_ft_hodo_z);
  _tree->SetBranchAddress("ft_hodo_dx", &_ft_hodo_dx);
  _tree->SetBranchAddress("ft_hodo_dy", &_ft_hodo_dy);
  _tree->SetBranchAddress("ft_hodo_radius", &_ft_hodo_radius);
}

float _BCG;
float _STTime;
float _RFTime;
int _Helic;
int _EvCAT;
int _NPGP;
double _LT;
float _PTIME;

int Branches12::NRUN() { return _NRUN; }
int Branches12::NEVENT() { return _NEVENT; }
float Branches12::EVNTime() { return _EVNTime; }
int Branches12::TYPE() { return _TYPE; }
int Branches12::TRG() { return _TRG; }
float Branches12::BCG() { return _BCG; }
float Branches12::STTime() { return _STTime; }
float Branches12::RFTime() { return _RFTime; }
int Branches12::Helic() { return _Helic; }
int Branches12::EvCAT() { return _EvCAT; }
int Branches12::NPGP() { return _NPGP; }
double Branches12::LT() { return _LT; }
float Branches12::PTIME() { return _PTIME; }
size_t Branches12::gpart() {
  return _pid->size();
}
int Branches12::pid(int i) { 
    return _pid->at(i);
}
float Branches12::p(int i) { 
return _p->at(i); }
float Branches12::p2(int i) { 
return _p2->at(i); }
float Branches12::px(int i) { 
return _px->at(i); }
float Branches12::py(int i) { 
return _py->at(i); }
float Branches12::pz(int i) { 
return _pz->at(i); }
float Branches12::vx(int i) { 
return _vx->at(i); }
float Branches12::vy(int i) { 
return _vy->at(i); }
float Branches12::vz(int i) { 
return _vz->at(i); }
int Branches12::charge(int i) {  return _charge->at(i); }
float Branches12::beta(int i) { 
return _beta->at(i); }
float Branches12::chi2pid(int i) { 
return _chi2pid->at(i); }
int Branches12::status(int i) {  return _status->at(i); }
/*
float Branches12::ec_tot_energy(int i) { return _ec_tot_energy->at(i); }
float Branches12::ec_pcal_energy(int i) { return _ec_pcal_energy->at(i); }
int Branches12::ec_pcal_sec(int i) { return _ec_pcal_sec->at(i); }
float Branches12::ec_pcal_time(int i) { return _ec_pcal_time->at(i); }
float Branches12::ec_pcal_path(int i) { return _ec_pcal_path->at(i); }
float Branches12::ec_pcal_x(int i) { return _ec_pcal_x->at(i); }
float Branches12::ec_pcal_y(int i) { return _ec_pcal_y->at(i); }
float Branches12::ec_pcal_z(int i) { return _ec_pcal_z->at(i); }
float Branches12::ec_pcal_lu(int i) { return _ec_pcal_lu->at(i); }
float Branches12::ec_pcal_lv(int i) { return _ec_pcal_lv->at(i); }
float Branches12::ec_pcal_lw(int i) { return _ec_pcal_lw->at(i); }
float Branches12::ec_ecin_energy(int i) { return _ec_ecin_energy->at(i); }
int Branches12::ec_ecin_sec(int i) { return _ec_ecin_sec->at(i); }
float Branches12::ec_ecin_time(int i) { return _ec_ecin_time->at(i); }
float Branches12::ec_ecin_path(int i) { return _ec_ecin_path->at(i); }
float Branches12::ec_ecin_x(int i) { return _ec_ecin_x->at(i); }
float Branches12::ec_ecin_y(int i) { return _ec_ecin_y->at(i); }
float Branches12::ec_ecin_z(int i) { return _ec_ecin_z->at(i); }
float Branches12::ec_ecin_lu(int i) { return _ec_ecin_lu->at(i); }
float Branches12::ec_ecin_lv(int i) { return _ec_ecin_lv->at(i); }
float Branches12::ec_ecin_lw(int i) { return _ec_ecin_lw->at(i); }
float Branches12::ec_ecout_energy(int i) { return _ec_ecout_energy->at(i); }
int Branches12::ec_ecout_sec(int i) { return _ec_ecout_sec->at(i); }
float Branches12::ec_ecout_time(int i) { return _ec_ecout_time->at(i); }
float Branches12::ec_ecout_path(int i) { return _ec_ecout_path->at(i); }
float Branches12::ec_ecout_x(int i) { return _ec_ecout_x->at(i); }
float Branches12::ec_ecout_y(int i) { return _ec_ecout_y->at(i); }
float Branches12::ec_ecout_z(int i) { return _ec_ecout_z->at(i); }
float Branches12::ec_ecout_lu(int i) { return _ec_ecout_lu->at(i); }
float Branches12::ec_ecout_lv(int i) { return _ec_ecout_lv->at(i); }
float Branches12::ec_ecout_lw(int i) { return _ec_ecout_lw->at(i); }
int Branches12::dc_sec(int i) { return NAN; }
float Branches12::dc_px(int i) { return NAN; }
float Branches12::dc_py(int i) { return NAN; }
float Branches12::dc_pz(int i) { return NAN; }
float Branches12::dc_vx(int i) { return NAN; }
float Branches12::dc_vy(int i) { return NAN; }
float Branches12::dc_vz(int i) { return NAN; }
float Branches12::cvt_px(int i) { return NAN; }
float Branches12::cvt_py(int i) { return NAN; }
float Branches12::cvt_pz(int i) { return NAN; }
float Branches12::cvt_vx(int i) { return NAN; }
float Branches12::cvt_vy(int i) { return NAN; }
float Branches12::cvt_vz(int i) { return NAN; }
float Branches12::cc_nphe_tot(int i) { return NAN; }
int Branches12::cc_ltcc_sec(int i) { return -1; }
float Branches12::cc_ltcc_nphe(int i) { return NAN; }
float Branches12::cc_ltcc_time(int i) { return NAN; }
float Branches12::cc_ltcc_path(int i) { return NAN; }
float Branches12::cc_ltcc_theta(int i) { return NAN; }
float Branches12::cc_ltcc_phi(int i) { return NAN; }
int Branches12::cc_htcc_sec(int i) { return -1; }
float Branches12::cc_htcc_nphe(int i) { return NAN; }
float Branches12::cc_htcc_time(int i) { return NAN; }
float Branches12::cc_htcc_path(int i) { return NAN; }
float Branches12::cc_htcc_theta(int i) { return NAN; }
float Branches12::cc_htcc_phi(int i) { return NAN; }
int Branches12::cc_rich_sec(int i) { return -1; }
float Branches12::cc_rich_nphe(int i) { return NAN; }
float Branches12::cc_rich_time(int i) { return NAN; }
float Branches12::cc_rich_path(int i) { return NAN; }
float Branches12::cc_rich_theta(int i) { return NAN; }
float Branches12::cc_rich_phi(int i) { return NAN; }
float Branches12::sc_ftof_1a_sec(int i) { return NAN; }
float Branches12::sc_ftof_1a_time(int i) { return NAN; }
float Branches12::sc_ftof_1a_path(int i) { return NAN; }
float Branches12::sc_ftof_1a_energy(int i) { return NAN; }
int Branches12::sc_ftof_1a_component(int i) { return -999; }
float Branches12::sc_ftof_1a_x(int i) { return NAN; }
float Branches12::sc_ftof_1a_y(int i) { return NAN; }
float Branches12::sc_ftof_1a_z(int i) { return NAN; }
float Branches12::sc_ftof_1a_hx(int i) { return NAN; }
float Branches12::sc_ftof_1a_hy(int i) { return NAN; }
float Branches12::sc_ftof_1a_hz(int i) { return NAN; }
int Branches12::sc_ftof_1b_sec(int i) { return -1; }
float Branches12::sc_ftof_1b_time(int i) { return NAN; }
float Branches12::sc_ftof_1b_path(int i) { return NAN; }
float Branches12::sc_ftof_1b_energy(int i) { return NAN; }
int Branches12::sc_ftof_1b_component(int i) { return -999; }
float Branches12::sc_ftof_1b_x(int i) { return NAN; }
float Branches12::sc_ftof_1b_y(int i) { return NAN; }
float Branches12::sc_ftof_1b_z(int i) { return NAN; }
float Branches12::sc_ftof_1b_hx(int i) { return NAN; }
float Branches12::sc_ftof_1b_hy(int i) { return NAN; }
float Branches12::sc_ftof_1b_hz(int i) { return NAN; }
int Branches12::sc_ftof_2_sec(int i) { return -1; }
float Branches12::sc_ftof_2_time(int i) { return NAN; }
float Branches12::sc_ftof_2_path(int i) { return NAN; }
float Branches12::sc_ftof_2_energy(int i) { return NAN; }
int Branches12::sc_ftof_2_component(int i) { return -999; }
float Branches12::sc_ftof_2_x(int i) { return NAN; }
float Branches12::sc_ftof_2_y(int i) { return NAN; }
float Branches12::sc_ftof_2_z(int i) { return NAN; }
float Branches12::sc_ftof_2_hx(int i) { return NAN; }
float Branches12::sc_ftof_2_hy(int i) { return NAN; }
float Branches12::sc_ftof_2_hz(int i) { return NAN; }
float Branches12::sc_ctof_time(int i) { return NAN; }
float Branches12::sc_ctof_path(int i) { return NAN; }
float Branches12::sc_ctof_energy(int i) { return NAN; }
int Branches12::sc_ctof_component(int i) { return -999; }
float Branches12::sc_ctof_x(int i) { return NAN; }
float Branches12::sc_ctof_y(int i) { return NAN; }
float Branches12::sc_ctof_z(int i) { return NAN; }
float Branches12::sc_ctof_hx(int i) { return NAN; }
float Branches12::sc_ctof_hy(int i) { return NAN; }
float Branches12::sc_ctof_hz(int i) { return NAN; }
float Branches12::sc_cnd_time(int i) { return NAN; }
float Branches12::sc_cnd_path(int i) { return NAN; }
float Branches12::sc_cnd_energy(int i) { return NAN; }
int Branches12::sc_cnd_component(int i) { return -999; }
float Branches12::sc_cnd_x(int i) { return NAN; }
float Branches12::sc_cnd_y(int i) { return NAN; }
float Branches12::sc_cnd_z(int i) { return NAN; }
float Branches12::sc_cnd_hx(int i) { return NAN; }
float Branches12::sc_cnd_hy(int i) { return NAN; }
float Branches12::sc_cnd_hz(int i) { return NAN; }
float Branches12::ft_cal_energy(int i) { return NAN; }
float Branches12::ft_cal_time(int i) { return NAN; }
float Branches12::ft_cal_path(int i) { return NAN; }
float Branches12::ft_cal_x(int i) { return NAN; }
float Branches12::ft_cal_y(int i) { return NAN; }
float Branches12::ft_cal_z(int i) { return NAN; }
float Branches12::ft_cal_dx(int i) { return NAN; }
float Branches12::ft_cal_dy(int i) { return NAN; }
float Branches12::ft_cal_radius(int i) { return NAN; }
float Branches12::ft_hodo_energy(int i) { return NAN; }
float Branches12::ft_hodo_time(int i) { return NAN; }
float Branches12::ft_hodo_path(int i) { return NAN; }
float Branches12::ft_hodo_x(int i) { return NAN; }
float Branches12::ft_hodo_y(int i) { return NAN; }
float Branches12::ft_hodo_z(int i) { return NAN; }
float Branches12::ft_hodo_dx(int i) { return NAN; }
float Branches12::ft_hodo_dy(int i) { return NAN; }
float Branches12::ft_hodo_radius(int i) { return NAN; }
*/
