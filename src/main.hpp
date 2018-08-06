#include <iostream>
#include "Event.hpp"
#include "TChain.h"

Int_t npart;
Int_t evstat;
Int_t intt;
Int_t evntid;
Int_t evtype;
Int_t evntclas;
Int_t evthel;
Int_t evntclas2;
Float_t q_l;
Float_t t_l;
Float_t tr_time;
Float_t rf_time1;
Float_t rf_time2;
Int_t gpart;
Int_t id[MAX_PARTS];    //[gpart]
Int_t stat[MAX_PARTS];  //[gpart]
Int_t dc[MAX_PARTS];    //[gpart]
Int_t cc[MAX_PARTS];    //[gpart]
Int_t sc[MAX_PARTS];    //[gpart]
Int_t ec[MAX_PARTS];    //[gpart]
Int_t lec[MAX_PARTS];   //[gpart]
Int_t ccst[MAX_PARTS];  //[gpart]
Float_t p[MAX_PARTS];   //[gpart]
Float_t m[MAX_PARTS];   //[gpart]
Int_t q[MAX_PARTS];     //[gpart]
Float_t b[MAX_PARTS];   //[gpart]
Float_t cx[MAX_PARTS];  //[gpart]
Float_t cy[MAX_PARTS];  //[gpart]
Float_t cz[MAX_PARTS];  //[gpart]
Float_t vx[MAX_PARTS];  //[gpart]
Float_t vy[MAX_PARTS];  //[gpart]
Float_t vz[MAX_PARTS];  //[gpart]
Int_t dc_part;
Int_t dc_sect[MAX_PARTS];    //[dc_part]
Int_t dc_trk[MAX_PARTS];     //[dc_part]
Int_t dc_stat[MAX_PARTS];    //[dc_part]
Float_t dc_vx[MAX_PARTS];    //[dc_part]
Float_t dc_vy[MAX_PARTS];    //[dc_part]
Float_t dc_vz[MAX_PARTS];    //[dc_part]
Float_t dc_vr[MAX_PARTS];    //[dc_part]
Float_t dc_xsc[MAX_PARTS];   //[dc_part]
Float_t dc_ysc[MAX_PARTS];   //[dc_part]
Float_t dc_zsc[MAX_PARTS];   //[dc_part]
Float_t dc_cxsc[MAX_PARTS];  //[dc_part]
Float_t dc_cysc[MAX_PARTS];  //[dc_part]
Float_t dc_czsc[MAX_PARTS];  //[dc_part]
Float_t dc_c2[MAX_PARTS];    //[dc_part]
Int_t ec_part;
Int_t ec_stat[MAX_PARTS];  //[ec_part]
Int_t ec_sect[MAX_PARTS];  //[ec_part]
Int_t ec_whol[MAX_PARTS];  //[ec_part]
Int_t ec_inst[MAX_PARTS];  //[ec_part]
Int_t ec_oust[MAX_PARTS];  //[ec_part]
Float_t etot[MAX_PARTS];   //[ec_part]
Float_t ec_ei[MAX_PARTS];  //[ec_part]
Float_t ec_eo[MAX_PARTS];  //[ec_part]
Float_t ec_t[MAX_PARTS];   //[ec_part]
Float_t ec_r[MAX_PARTS];   //[ec_part]
Float_t ech_x[MAX_PARTS];  //[ec_part]
Float_t ech_y[MAX_PARTS];  //[ec_part]
Float_t ech_z[MAX_PARTS];  //[ec_part]
Float_t ec_m2[MAX_PARTS];  //[ec_part]
Float_t ec_m3[MAX_PARTS];  //[ec_part]
Float_t ec_m4[MAX_PARTS];  //[ec_part]
Float_t ec_c2[MAX_PARTS];  //[ec_part]
Int_t sc_part;
Int_t sc_sect[MAX_PARTS];  //[sc_part]
Int_t sc_hit[MAX_PARTS];   //[sc_part]
Int_t sc_pd[MAX_PARTS];    //[sc_part]
Int_t sc_stat[MAX_PARTS];  //[sc_part]
Float_t edep[MAX_PARTS];   //[sc_part]
Float_t sc_t[MAX_PARTS];   //[sc_part]
Float_t sc_r[MAX_PARTS];   //[sc_part]
Float_t sc_c2[MAX_PARTS];  //[sc_part]
Int_t cc_part;
Int_t cc_sect[MAX_PARTS];  //[cc_part]
Int_t cc_hit[MAX_PARTS];   //[cc_part]
Int_t cc_segm[MAX_PARTS];  //[cc_part]
Int_t nphe[MAX_PARTS];     //[cc_part]
Float_t cc_t[MAX_PARTS];   //[cc_part]
Float_t cc_r[MAX_PARTS];   //[cc_part]
Float_t cc_c2[MAX_PARTS];  //[cc_part]
Int_t lac_part;
Int_t lec_sect[MAX_PARTS];    //[lac_part]
Int_t lec_hit[MAX_PARTS];     //[lac_part]
Int_t lec_stat[MAX_PARTS];    //[lac_part]
Float_t lec_etot[MAX_PARTS];  //[lac_part]
Float_t lec_ein[MAX_PARTS];   //[lac_part]
Float_t lec_t[MAX_PARTS];     //[lac_part]
Float_t lec_r[MAX_PARTS];     //[lac_part]
Float_t lec_x[MAX_PARTS];     //[lac_part]
Float_t lec_y[MAX_PARTS];     //[lac_part]
Float_t lec_z[MAX_PARTS];     //[lac_part]
Float_t lec_c2[MAX_PARTS];    //[lac_part]
Int_t st_part;
Int_t st_status[MAX_PARTS];  //[st_part]
Float_t st_time[MAX_PARTS];  //[st_part]
Float_t st_rtrk[MAX_PARTS];  //[st_part]

void getBranches(TTree *myTree) {
  myTree->SetBranchAddress("npart", &npart);
  myTree->SetBranchAddress("evstat", &evstat);
  myTree->SetBranchAddress("intt", &intt);
  myTree->SetBranchAddress("evntid", &evntid);
  myTree->SetBranchAddress("evtype", &evtype);
  myTree->SetBranchAddress("evntclas", &evntclas);
  myTree->SetBranchAddress("evthel", &evthel);
  myTree->SetBranchAddress("evntclas2", &evntclas2);
  myTree->SetBranchAddress("q_l", &q_l);
  myTree->SetBranchAddress("t_l", &t_l);
  myTree->SetBranchAddress("tr_time", &tr_time);
  myTree->SetBranchAddress("rf_time1", &rf_time1);
  myTree->SetBranchAddress("rf_time2", &rf_time2);
  myTree->SetBranchAddress("gpart", &gpart);
  myTree->SetBranchAddress("id", id);
  myTree->SetBranchAddress("stat", stat);
  myTree->SetBranchAddress("dc", dc);
  myTree->SetBranchAddress("cc", cc);
  myTree->SetBranchAddress("sc", sc);
  myTree->SetBranchAddress("ec", ec);
  myTree->SetBranchAddress("lec", lec);
  myTree->SetBranchAddress("ccst", ccst);
  myTree->SetBranchAddress("p", p);
  myTree->SetBranchAddress("m", m);
  myTree->SetBranchAddress("q", q);
  myTree->SetBranchAddress("b", b);
  myTree->SetBranchAddress("cx", cx);
  myTree->SetBranchAddress("cy", cy);
  myTree->SetBranchAddress("cz", cz);
  myTree->SetBranchAddress("vx", vx);
  myTree->SetBranchAddress("vy", vy);
  myTree->SetBranchAddress("vz", vz);
  myTree->SetBranchAddress("dc_part", &dc_part);
  myTree->SetBranchAddress("dc_sect", dc_sect);
  myTree->SetBranchAddress("dc_trk", dc_trk);
  myTree->SetBranchAddress("dc_stat", dc_stat);
  myTree->SetBranchAddress("dc_vx", dc_vx);
  myTree->SetBranchAddress("dc_vy", dc_vy);
  myTree->SetBranchAddress("dc_vz", dc_vz);
  myTree->SetBranchAddress("dc_vr", dc_vr);
  myTree->SetBranchAddress("dc_xsc", dc_xsc);
  myTree->SetBranchAddress("dc_ysc", dc_ysc);
  myTree->SetBranchAddress("dc_zsc", dc_zsc);
  myTree->SetBranchAddress("dc_cxsc", dc_cxsc);
  myTree->SetBranchAddress("dc_cysc", dc_cysc);
  myTree->SetBranchAddress("dc_czsc", dc_czsc);
  myTree->SetBranchAddress("dc_c2", dc_c2);
  myTree->SetBranchAddress("ec_part", &ec_part);
  myTree->SetBranchAddress("ec_stat", ec_stat);
  myTree->SetBranchAddress("ec_sect", ec_sect);
  myTree->SetBranchAddress("ec_whol", ec_whol);
  myTree->SetBranchAddress("ec_inst", ec_inst);
  myTree->SetBranchAddress("ec_oust", ec_oust);
  myTree->SetBranchAddress("etot", etot);
  myTree->SetBranchAddress("ec_ei", ec_ei);
  myTree->SetBranchAddress("ec_eo", ec_eo);
  myTree->SetBranchAddress("ec_t", ec_t);
  myTree->SetBranchAddress("ec_r", ec_r);
  myTree->SetBranchAddress("ech_x", ech_x);
  myTree->SetBranchAddress("ech_y", ech_y);
  myTree->SetBranchAddress("ech_z", ech_z);
  myTree->SetBranchAddress("ec_m2", ec_m2);
  myTree->SetBranchAddress("ec_m3", ec_m3);
  myTree->SetBranchAddress("ec_m4", ec_m4);
  myTree->SetBranchAddress("ec_c2", ec_c2);
  myTree->SetBranchAddress("sc_part", &sc_part);
  myTree->SetBranchAddress("sc_sect", sc_sect);
  myTree->SetBranchAddress("sc_hit", sc_hit);
  myTree->SetBranchAddress("sc_pd", sc_pd);
  myTree->SetBranchAddress("sc_stat", sc_stat);
  myTree->SetBranchAddress("edep", edep);
  myTree->SetBranchAddress("sc_t", sc_t);
  myTree->SetBranchAddress("sc_r", sc_r);
  myTree->SetBranchAddress("sc_c2", sc_c2);
  myTree->SetBranchAddress("cc_part", &cc_part);
  myTree->SetBranchAddress("cc_sect", cc_sect);
  myTree->SetBranchAddress("cc_hit", cc_hit);
  myTree->SetBranchAddress("cc_segm", cc_segm);
  myTree->SetBranchAddress("nphe", nphe);
  myTree->SetBranchAddress("cc_t", cc_t);
  myTree->SetBranchAddress("cc_r", cc_r);
  myTree->SetBranchAddress("cc_c2", cc_c2);
  myTree->SetBranchAddress("lac_part", &lac_part);
  myTree->SetBranchAddress("lec_sect", &lec_sect);
  myTree->SetBranchAddress("lec_hit", &lec_hit);
  myTree->SetBranchAddress("lec_stat", &lec_stat);
  myTree->SetBranchAddress("lec_etot", &lec_etot);
  myTree->SetBranchAddress("lec_ein", &lec_ein);
  myTree->SetBranchAddress("lec_t", &lec_t);
  myTree->SetBranchAddress("lec_r", &lec_r);
  myTree->SetBranchAddress("lec_x", &lec_x);
  myTree->SetBranchAddress("lec_y", &lec_y);
  myTree->SetBranchAddress("lec_z", &lec_z);
  myTree->SetBranchAddress("lec_c2", &lec_c2);
  myTree->SetBranchAddress("st_part", &st_part);
  myTree->SetBranchAddress("st_status", &st_status);
  myTree->SetBranchAddress("st_time", &st_time);
  myTree->SetBranchAddress("st_rtrk", &st_rtrk);
  myTree->SetBranchStatus("*", 1);
}

#ifdef CLAS12
std::vector<int> *REC_Event_NRUN;
std::vector<int> *REC_Event_NEVENT;
std::vector<float> *REC_Event_EVNTime;
std::vector<int> *REC_Event_TYPE;
std::vector<int> *REC_Event_TRG;
std::vector<float> *REC_Event_BCG;
std::vector<float> *REC_Event_STTime;
std::vector<float> *REC_Event_RFTime;
std::vector<int> *REC_Event_Helic;
std::vector<int> *pid;
std::vector<float> *px;
std::vector<float> *py;
std::vector<float> *pz;
std::vector<float> *vx;
std::vector<float> *vy;
std::vector<float> *vz;
std::vector<int> *charge;
std::vector<float> *beta;
std::vector<int> *status;
std::vector<int> *ec_index;
std::vector<int> *ec_pindex;
std::vector<int> *ec_detector;
std::vector<int> *ec_sector;
std::vector<int> *ec_layer;
std::vector<float> *ec_energy;
std::vector<float> *ec_time;
std::vector<float> *ec_path;
std::vector<float> *ec_chi2;
std::vector<float> *ec_x;
std::vector<float> *ec_y;
std::vector<float> *ec_z;
std::vector<float> *ec_lu;
std::vector<float> *ec_lv;
std::vector<float> *ec_lw;
std::vector<int> *ec_status;
std::vector<int> *cc_pindex;
std::vector<int> *cc_detector;
std::vector<int> *cc_sector;
std::vector<float> *cc_nphe;
std::vector<float> *cc_time;
std::vector<float> *cc_path;
std::vector<float> *cc_x;
std::vector<float> *cc_y;
std::vector<float> *cc_z;
std::vector<float> *cc_theta;
std::vector<float> *cc_phi;
std::vector<int> *ft_index;
std::vector<int> *ft_pindex;
std::vector<int> *ft_detector;
std::vector<float> *ft_energy;
std::vector<float> *ft_time;
std::vector<float> *ft_path;
std::vector<float> *ft_chi2;
std::vector<float> *ft_x;
std::vector<float> *ft_y;
std::vector<float> *ft_z;
std::vector<float> *ft_dx;
std::vector<float> *ft_dy;
std::vector<float> *ft_radius;
std::vector<int> *ft_size;
std::vector<int> *ft_status;
std::vector<int> *sc_pindex;
std::vector<int> *sc_detector;
std::vector<int> *sc_sector;
std::vector<int> *sc_layer;
std::vector<int> *sc_component;
std::vector<float> *sc_energy;
std::vector<float> *sc_time;
std::vector<float> *sc_path;

void getBranches12(TTree *myTree) {
  myTree->SetBranchAddress("REC_Particle_pid", &pid);
  myTree->SetBranchAddress("REC_Particle_px", &px);
  myTree->SetBranchAddress("REC_Particle_py", &py);
  myTree->SetBranchAddress("REC_Particle_pz", &pz);
  myTree->SetBranchAddress("REC_Particle_vx", &vx);
  myTree->SetBranchAddress("REC_Particle_vy", &vy);
  myTree->SetBranchAddress("REC_Particle_vz", &vz);
  myTree->SetBranchAddress("REC_Particle_charge", &charge);
  myTree->SetBranchAddress("REC_Particle_beta", &beta);
  myTree->SetBranchAddress("REC_Particle_status", &status);
  myTree->SetBranchAddress("REC_Event_NRUN", &REC_Event_NRUN);
  myTree->SetBranchAddress("REC_Event_NEVENT", &REC_Event_NEVENT);
  myTree->SetBranchAddress("REC_Event_EVNTime", &REC_Event_EVNTime);
  myTree->SetBranchAddress("REC_Event_TYPE", &REC_Event_TYPE);
  myTree->SetBranchAddress("REC_Event_TRG", &REC_Event_TRG);
  myTree->SetBranchAddress("REC_Event_BCG", &REC_Event_BCG);
  myTree->SetBranchAddress("REC_Event_STTime", &REC_Event_STTime);
  myTree->SetBranchAddress("REC_Event_RFTime", &REC_Event_RFTime);
  myTree->SetBranchAddress("REC_Event_Helic", &REC_Event_Helic);
  myTree->SetBranchAddress("REC_Calorimeter_pindex", &ec_pindex);
  myTree->SetBranchAddress("REC_Calorimeter_detector", &ec_detector);
  myTree->SetBranchAddress("REC_Calorimeter_sector", &ec_sector);
  myTree->SetBranchAddress("REC_Calorimeter_layer", &ec_layer);
  myTree->SetBranchAddress("REC_Calorimeter_energy", &ec_energy);
  myTree->SetBranchAddress("REC_Calorimeter_time", &ec_time);
  myTree->SetBranchAddress("REC_Calorimeter_path", &ec_path);
  myTree->SetBranchAddress("REC_Calorimeter_x", &ec_x);
  myTree->SetBranchAddress("REC_Calorimeter_y", &ec_y);
  myTree->SetBranchAddress("REC_Calorimeter_z", &ec_z);
  myTree->SetBranchAddress("REC_Calorimeter_lu", &ec_lu);
  myTree->SetBranchAddress("REC_Calorimeter_lv", &ec_lv);
  myTree->SetBranchAddress("REC_Calorimeter_lw", &ec_lw);
  myTree->SetBranchAddress("REC_Cherenkov_pindex", &cc_pindex);
  myTree->SetBranchAddress("REC_Cherenkov_detector", &cc_detector);
  myTree->SetBranchAddress("REC_Cherenkov_sector", &cc_sector);
  myTree->SetBranchAddress("REC_Cherenkov_nphe", &cc_nphe);
  myTree->SetBranchAddress("REC_Cherenkov_time", &cc_time);
  myTree->SetBranchAddress("REC_Cherenkov_path", &cc_path);
  myTree->SetBranchAddress("REC_Cherenkov_theta", &cc_theta);
  myTree->SetBranchAddress("REC_Cherenkov_phi", &cc_phi);
  myTree->SetBranchAddress("REC_ForwardTagger_pindex", &ft_pindex);
  myTree->SetBranchAddress("REC_ForwardTagger_detector", &ft_detector);
  myTree->SetBranchAddress("REC_ForwardTagger_energy", &ft_energy);
  myTree->SetBranchAddress("REC_ForwardTagger_time", &ft_time);
  myTree->SetBranchAddress("REC_ForwardTagger_path", &ft_path);
  myTree->SetBranchAddress("REC_ForwardTagger_x", &ft_x);
  myTree->SetBranchAddress("REC_ForwardTagger_y", &ft_y);
  myTree->SetBranchAddress("REC_ForwardTagger_z", &ft_z);
  myTree->SetBranchAddress("REC_ForwardTagger_dx", &ft_dx);
  myTree->SetBranchAddress("REC_ForwardTagger_dy", &ft_dy);
  myTree->SetBranchAddress("REC_ForwardTagger_radius", &ft_radius);
  myTree->SetBranchAddress("REC_ForwardTagger_size", &ft_size);
  myTree->SetBranchAddress("REC_Scintillator_pindex", &sc_pindex);
  myTree->SetBranchAddress("REC_Scintillator_detector", &sc_detector);
  myTree->SetBranchAddress("REC_Scintillator_sector", &sc_sector);
  myTree->SetBranchAddress("REC_Scintillator_layer", &sc_layer);
  myTree->SetBranchAddress("REC_Scintillator_component", &sc_component);
  myTree->SetBranchAddress("REC_Scintillator_energy", &sc_energy);
  myTree->SetBranchAddress("REC_Scintillator_time", &sc_time);
  myTree->SetBranchAddress("REC_Scintillator_path", &sc_path);
  myTree->SetBranchStatus("*", 1);
}
#endif
