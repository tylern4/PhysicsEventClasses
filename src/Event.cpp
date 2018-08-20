/**************************************/
/*																		*/
/*  Created by Nick Tyler             */
/*	University Of South Carolina      */
/**************************************/
#include "Event.hpp"

Event::Event() {}

Event::Event(Particle Electron, TLorentzVector Beam) {
  _electron = Electron;
  _W = physics::W_calc(Beam, _electron.Particle4Vec());
  _Q2 = physics::Q2_calc(Beam, _electron.Particle4Vec());
  Add_Part(Electron);
}
Event::~Event() {}

void Event::Add_Part(Particle p) {
  _events.emplace_back(p);
  _PID.emplace_back(p.PID());
}

std::vector<int> Event::Signiture() {
  for (auto id : _PID) _event_sig.push_back(id);
  std::sort(_event_sig.begin(), _event_sig.end());
  return _event_sig;
}

void Event::PrintSigniture() {
  std::vector<int> s = Signiture();
  std::cout << "Event Signiture: ";
  for (auto e : s) std::cout << e << "\t";
  std::cout << std::endl;
}

void Event::PrintWQ2() {
  std::vector<int> s = Signiture();
  std::cout << _W << "," << _Q2 << ",";
  for (auto e : s) std::cout << e << ":";
  std::cout << std::endl;
}
