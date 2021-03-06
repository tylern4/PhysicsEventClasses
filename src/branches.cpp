/**************************************/
/*																		*/
/*  Created by Nick Tyler             */
/*	University Of South Carolina      */
/**************************************/

#include "branches.hpp"

Branches6::Branches6(std::shared_ptr<TChain> tree) {
  _tree = tree;
  Branches6::init();
}

void Branches6::init() {
  _tree->SetBranchAddress("npart", &_npart);
  _tree->SetBranchAddress("evstat", &_evstat);
  _tree->SetBranchAddress("intt", &_intt);
  _tree->SetBranchAddress("evntid", &_evntid);
  _tree->SetBranchAddress("evtype", &_evtype);
  _tree->SetBranchAddress("evntclas", &_evntclas);
  _tree->SetBranchAddress("evthel", &_evthel);
  _tree->SetBranchAddress("evntclas2", &_evntclas2);
  _tree->SetBranchAddress("q_l", &_q_l);
  _tree->SetBranchAddress("t_l", &_t_l);
  _tree->SetBranchAddress("tr_time", &_tr_time);
  _tree->SetBranchAddress("rf_time1", &_rf_time1);
  _tree->SetBranchAddress("rf_time2", &_rf_time2);
  _tree->SetBranchAddress("gpart", &_gpart);
  _tree->SetBranchAddress("id", _id);
  _tree->SetBranchAddress("stat", _stat);
  _tree->SetBranchAddress("dc", _dc);
  _tree->SetBranchAddress("cc", _cc);
  _tree->SetBranchAddress("sc", _sc);
  _tree->SetBranchAddress("ec", _ec);
  _tree->SetBranchAddress("lec", _lec);
  _tree->SetBranchAddress("ccst", _ccst);
  _tree->SetBranchAddress("p", _p);
  _tree->SetBranchAddress("q", _q);
  _tree->SetBranchAddress("b", _b);
  _tree->SetBranchAddress("cx", _cx);
  _tree->SetBranchAddress("cy", _cy);
  _tree->SetBranchAddress("cz", _cz);
  _tree->SetBranchAddress("vx", _vx);
  _tree->SetBranchAddress("vy", _vy);
  _tree->SetBranchAddress("vz", _vz);
  _tree->SetBranchAddress("dc_part", &_dc_part);
  _tree->SetBranchAddress("dc_sect", _dc_sect);
  _tree->SetBranchAddress("dc_trk", _dc_trk);
  _tree->SetBranchAddress("dc_stat", _dc_stat);
  _tree->SetBranchAddress("dc_vx", _dc_vx);
  _tree->SetBranchAddress("dc_vy", _dc_vy);
  _tree->SetBranchAddress("dc_vz", _dc_vz);
  _tree->SetBranchAddress("dc_vr", _dc_vr);
  _tree->SetBranchAddress("dc_xsc", _dc_xsc);
  _tree->SetBranchAddress("dc_ysc", _dc_ysc);
  _tree->SetBranchAddress("dc_zsc", _dc_zsc);
  _tree->SetBranchAddress("dc_cxsc", _dc_cxsc);
  _tree->SetBranchAddress("dc_cysc", _dc_cysc);
  _tree->SetBranchAddress("dc_czsc", _dc_czsc);
  _tree->SetBranchAddress("dc_c2", _dc_c2);
  _tree->SetBranchAddress("ec_part", &_ec_part);
  _tree->SetBranchAddress("ec_stat", _ec_stat);
  _tree->SetBranchAddress("ec_sect", _ec_sect);
  _tree->SetBranchAddress("ec_whol", _ec_whol);
  _tree->SetBranchAddress("ec_inst", _ec_inst);
  _tree->SetBranchAddress("ec_oust", _ec_oust);
  _tree->SetBranchAddress("etot", _etot);
  _tree->SetBranchAddress("ec_ei", _ec_ei);
  _tree->SetBranchAddress("ec_eo", _ec_eo);
  _tree->SetBranchAddress("ec_t", _ec_t);
  _tree->SetBranchAddress("ec_r", _ec_r);
  _tree->SetBranchAddress("ech_x", _ech_x);
  _tree->SetBranchAddress("ech_y", _ech_y);
  _tree->SetBranchAddress("ech_z", _ech_z);
  _tree->SetBranchAddress("ec_m2", _ec_m2);
  _tree->SetBranchAddress("ec_m3", _ec_m3);
  _tree->SetBranchAddress("ec_m4", _ec_m4);
  _tree->SetBranchAddress("ec_c2", _ec_c2);
  _tree->SetBranchAddress("sc_part", &_sc_part);
  _tree->SetBranchAddress("sc_sect", _sc_sect);
  _tree->SetBranchAddress("sc_hit", _sc_hit);
  _tree->SetBranchAddress("sc_pd", _sc_pd);
  _tree->SetBranchAddress("sc_stat", _sc_stat);
  _tree->SetBranchAddress("edep", _edep);
  _tree->SetBranchAddress("sc_t", _sc_t);
  _tree->SetBranchAddress("sc_r", _sc_r);
  _tree->SetBranchAddress("sc_c2", _sc_c2);
  _tree->SetBranchAddress("cc_part", &_cc_part);
  _tree->SetBranchAddress("cc_sect", _cc_sect);
  _tree->SetBranchAddress("cc_hit", _cc_hit);
  _tree->SetBranchAddress("cc_segm", _cc_segm);
  _tree->SetBranchAddress("nphe", _nphe);
  _tree->SetBranchAddress("cc_t", _cc_t);
  _tree->SetBranchAddress("cc_r", _cc_r);
  _tree->SetBranchAddress("cc_c2", _cc_c2);
  if (_MC) {
    _tree->SetBranchAddress("nprt", &_nprt);
    _tree->SetBranchAddress("pidpart", _pidpart);
    _tree->SetBranchAddress("xpart", _xpart);
    _tree->SetBranchAddress("ypart", _ypart);
    _tree->SetBranchAddress("zpart", _zpart);
    _tree->SetBranchAddress("epart", _epart);
    _tree->SetBranchAddress("pxpart", _pxpart);
    _tree->SetBranchAddress("pypart", _pypart);
    _tree->SetBranchAddress("pzpart", _pzpart);
    _tree->SetBranchAddress("qpart", _qpart);
  }
}

int Branches6::npart() { return _npart; }
int Branches6::evstat() { return _evstat; }
int Branches6::intt() { return _intt; }
int Branches6::evntid() { return _evntid; }
int Branches6::evtype() { return _evtype; }
int Branches6::evntclas() { return _evntclas; }
int Branches6::evthel() { return _evthel; }
int Branches6::evntclas2() { return _evntclas2; }
float Branches6::q_l() { return _q_l; }
float Branches6::t_l() { return _t_l; }
float Branches6::tr_time() { return _tr_time; }
float Branches6::rf_time1() { return _rf_time1; }
float Branches6::rf_time2() { return _rf_time2; }
int Branches6::gpart() { return _gpart; }

int Branches6::dc_part() { return _dc_part; }
int Branches6::ec_part() { return _ec_part; }
int Branches6::sc_part() { return _sc_part; }
int Branches6::cc_part() { return _cc_part; }

int Branches6::nprt() { return _nprt; }

int Branches6::id(int i) {
  if (i < _gpart) {
    return _id[i];
  } else {
    return int(NULL);
  }
}  // [gpart]
int Branches6::stat(int i) {
  if (i < _gpart) {
    return _stat[i];
  } else {
    return int(NULL);
  }
}  // [gpart]
int Branches6::dc(int i) {
  if (i < _gpart) {
    return _dc[i];
  } else {
    return int(NULL);
  }
}  // [gpart]
int Branches6::cc(int i) {
  if (i < _gpart) {
    return _cc[i];
  } else {
    return int(NULL);
  }
}  // [gpart]
int Branches6::sc(int i) {
  if (i < _gpart) {
    return _sc[i];
  } else {
    return int(NULL);
  }
}  // [gpart]
int Branches6::ec(int i) {
  if (i < _gpart) {
    return _ec[i];
  } else {
    return int(NULL);
  }
}  // [gpart]
int Branches6::lec(int i) {
  if (i < _gpart) {
    return _lec[i];
  } else {
    return int(NULL);
  }
}  // [gpart]
int Branches6::ccst(int i) {
  if (i < _gpart) {
    return _ccst[i];
  } else {
    return int(NULL);
  }
}  // [gpart]
float Branches6::p(int i) {
  if (i < _gpart) {
    return _p[i];
  } else {
    return std::nanf("NULL");
  }
}  // [gpart]
float Branches6::px(int i) {
  if (i < _gpart) {
    return _p[i] * _cx[i];
  } else {
    return std::nanf("NULL");
  }
}  // [gpart]
float Branches6::py(int i) {
  if (i < _gpart) {
    return _p[i] * _cy[i];
  } else {
    return std::nanf("NULL");
  }
}  // [gpart]
float Branches6::pz(int i) {
  if (i < _gpart) {
    return _p[i] * _cz[i];
  } else {
    return std::nanf("NULL");
  }
}  // [gpart]
float Branches6::m(int i) {
  if (i < _gpart) {
    return _m[i];
  } else {
    return std::nanf("NULL");
  }
}  // [gpart]
int Branches6::q(int i) {
  if (i < _gpart) {
    return _q[i];
  } else {
    return int(NULL);
  }
}  // [gpart]
float Branches6::b(int i) {
  if (i < _gpart) {
    return _b[i];
  } else {
    return std::nanf("NULL");
  }
}  // [gpart]
float Branches6::cx(int i) {
  if (i < _gpart) {
    return _cx[i];
  } else {
    return std::nanf("NULL");
  }
}  // [gpart]
float Branches6::cy(int i) {
  if (i < _gpart) {
    return _cy[i];
  } else {
    return std::nanf("NULL");
  }
}  // [gpart]
float Branches6::cz(int i) {
  if (i < _gpart) {
    return _cz[i];
  } else {
    return std::nanf("NULL");
  }
}  // [gpart]
float Branches6::vx(int i) {
  if (i < _gpart) {
    return _vx[i];
  } else {
    return std::nanf("NULL");
  }
}  // [gpart]
float Branches6::vy(int i) {
  if (i < _gpart) {
    return _vy[i];
  } else {
    return std::nanf("NULL");
  }
}  // [gpart]
float Branches6::vz(int i) {
  if (i < _gpart) {
    return _vz[i];
  } else {
    return std::nanf("NULL");
  }
}  // [gpart]

int Branches6::dc_sect(int i) {
  if (i < _dc_part) {
    return _dc_sect[_dc[i] - 1];
  } else {
    return int(NULL);
  }
}  //[dc_part]
int Branches6::dc_trk(int i) {
  if (i < _dc_part) {
    return _dc_trk[_dc[i] - 1];
  } else {
    return int(NULL);
  }
}  //[dc_part]
int Branches6::dc_stat(int i) {
  if (i < _dc_part) {
    return _dc_stat[_dc[i] - 1];
  } else {
    return int(NULL);
  }
}  //[dc_part]
float Branches6::dc_vx(int i) {
  if (i < _dc_part) {
    return _dc_vx[_dc[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[dc_part]
float Branches6::dc_vy(int i) {
  if (i < _dc_part) {
    return _dc_vy[_dc[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[dc_part]
float Branches6::dc_vz(int i) {
  if (i < _dc_part) {
    return _dc_vz[_dc[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[dc_part]
float Branches6::dc_vr(int i) {
  if (i < _dc_part) {
    return _dc_vr[_dc[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[dc_part]
float Branches6::dc_xsc(int i) {
  if (i < _dc_part) {
    return _dc_xsc[_dc[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[dc_part]
float Branches6::dc_ysc(int i) {
  if (i < _dc_part) {
    return _dc_ysc[_dc[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[dc_part]
float Branches6::dc_zsc(int i) {
  if (i < _dc_part) {
    return _dc_zsc[_dc[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[dc_part]
float Branches6::dc_cxsc(int i) {
  if (i < _dc_part) {
    return _dc_cxsc[_dc[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[dc_part]
float Branches6::dc_cysc(int i) {
  if (i < _dc_part) {
    return _dc_cysc[_dc[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[dc_part]
float Branches6::dc_czsc(int i) {
  if (i < _dc_part) {
    return _dc_czsc[_dc[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[dc_part]
float Branches6::dc_c2(int i) {
  if (i < _dc_part) {
    return _dc_c2[_dc[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[dc_part]

int Branches6::ec_stat(int i) {
  if (i < _ec_part) {
    return _ec_stat[_ec[i] - 1];
  } else {
    return int(NULL);
  }
}  //[ec_part]
int Branches6::ec_sect(int i) {
  if (i < _ec_part) {
    return _ec_sect[_ec[i] - 1];
  } else {
    return int(NULL);
  }
}  //[ec_part]
int Branches6::ec_whol(int i) {
  if (i < _ec_part) {
    return _ec_whol[_ec[i] - 1];
  } else {
    return int(NULL);
  }
}  //[ec_part]
int Branches6::ec_inst(int i) {
  if (i < _ec_part) {
    return _ec_inst[_ec[i] - 1];
  } else {
    return int(NULL);
  }
}  //[ec_part]
int Branches6::ec_oust(int i) {
  if (i < _ec_part) {
    return _ec_oust[_ec[i] - 1];
  } else {
    return int(NULL);
  }
}  //[ec_part]
float Branches6::etot(int i) {
  if (i < _ec_part) {
    return _etot[_ec[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[ec_part]
float Branches6::ec_ei(int i) {
  if (i < _ec_part) {
    return _ec_ei[_ec[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[ec_part]
float Branches6::ec_eo(int i) {
  if (i < _ec_part) {
    return _ec_eo[_ec[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[ec_part]
float Branches6::ec_t(int i) {
  if (i < _ec_part) {
    return _ec_t[_ec[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[ec_part]
float Branches6::ec_r(int i) {
  if (i < _ec_part) {
    return _ec_r[_ec[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[ec_part]
float Branches6::ech_x(int i) {
  if (i < _ec_part) {
    return _ech_x[_ec[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[ec_part]
float Branches6::ech_y(int i) {
  if (i < _ec_part) {
    return _ech_y[_ec[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[ec_part]
float Branches6::ech_z(int i) {
  if (i < _ec_part) {
    return _ech_z[_ec[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[ec_part]
float Branches6::ec_m2(int i) {
  if (i < _ec_part) {
    return _ec_m2[_ec[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[ec_part]
float Branches6::ec_m3(int i) {
  if (i < _ec_part) {
    return _ec_m3[_ec[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[ec_part]
float Branches6::ec_m4(int i) {
  if (i < _ec_part) {
    return _ec_m4[_ec[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[ec_part]
float Branches6::ec_c2(int i) {
  if (i < _ec_part) {
    return _ec_c2[_ec[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[ec_part]

int Branches6::sc_sect(int i) {
  if (i < _sc_part) {
    return _sc_sect[_sc[i] - 1];
  } else {
    return int(NULL);
  }
}  //[sc_part]
int Branches6::sc_hit(int i) {
  if (i < _sc_part) {
    return _sc_hit[_sc[i] - 1];
  } else {
    return int(NULL);
  }
}  //[sc_part]
int Branches6::sc_pd(int i) {
  if (i < _sc_part) {
    return _sc_pd[_sc[i] - 1];
  } else {
    return int(NULL);
  }
}  //[sc_part]
int Branches6::sc_stat(int i) {
  if (i < _sc_part) {
    return _sc_stat[_sc[i] - 1];
  } else {
    return int(NULL);
  }
}  //[sc_part]
float Branches6::edep(int i) {
  if (i < _sc_part) {
    return _edep[_sc[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[sc_part]
float Branches6::sc_t(int i) {
  if (i < _sc_part) {
    return _sc_t[_sc[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[sc_part]
float Branches6::sc_r(int i) {
  if (i < _sc_part) {
    return _sc_r[_sc[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[sc_part]
float Branches6::sc_c2(int i) {
  if (i < _sc_part) {
    return _sc_c2[_sc[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[sc_part]

int Branches6::cc_sect(int i) {
  if (i < _cc_part) {
    return _cc_sect[_cc[i] - 1];
  } else {
    return int(NULL);
  }
}  //[cc_part]
int Branches6::cc_hit(int i) {
  if (i < _cc_part) {
    return _cc_hit[_cc[i] - 1];
  } else {
    return int(NULL);
  }
}  //[cc_part]
int Branches6::cc_segm(int i) {
  if (i < _cc_part) {
    return _cc_segm[_cc[i] - 1];
  } else {
    return int(NULL);
  }
}  //[cc_part]
int Branches6::nphe(int i) {
  if (i < _cc_part) {
    return _nphe[_cc[i] - 1];
  } else {
    return int(NULL);
  }
}  //[cc_part]
float Branches6::cc_t(int i) {
  if (i < _cc_part) {
    return _cc_t[_cc[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[cc_part]
float Branches6::cc_r(int i) {
  if (i < _cc_part) {
    return _cc_r[_cc[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[cc_part]
float Branches6::cc_c2(int i) {
  if (i < _cc_part) {
    return _cc_c2[_cc[i] - 1];
  } else {
    return std::nanf("NULL");
  }
}  //[cc_part]

int Branches6::pidpart(int i) {
  if (i < _nprt) {
    return _pidpart[i];
  } else {
    return (int)NULL;
  }
}  //[nprt]

float Branches6::xpart(int i) {
  if (i < _nprt) {
    return _xpart[i];
  } else {
    return (float)NULL;
  }
}  //[nprt]

float Branches6::ypart(int i) {
  if (i < _nprt) {
    return _ypart[i];
  } else {
    return (float)NULL;
  }
}  //[nprt]

float Branches6::zpart(int i) {
  if (i < _nprt) {
    return _zpart[i];
  } else {
    return (float)NULL;
  }
}  //[nprt]

float Branches6::epart(int i) {
  if (i < _nprt) {
    return _epart[i];
  } else {
    return (float)NULL;
  }
}  //[nprt]

float Branches6::pxpart(int i) {
  if (i < _nprt) {
    return _pxpart[i];
  } else {
    return (float)NULL;
  }
}  //[nprt]

float Branches6::pypart(int i) {
  if (i < _nprt) {
    return _pypart[i];
  } else {
    return (float)NULL;
  }
}  //[nprt]

float Branches6::pzpart(int i) {
  if (i < _nprt) {
    return _pzpart[i];
  } else {
    return (float)NULL;
  }
}  //[nprt]

float Branches6::qpart(int i) {
  if (i < _nprt) {
    return _qpart[i];
  } else {
    return (float)NULL;
  }
}  //[nprt]
