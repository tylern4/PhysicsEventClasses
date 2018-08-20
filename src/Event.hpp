/**************************************/
/*																		*/
/*  Created by Nick Tyler             */
/*	University Of South Carolina      */
/**************************************/

#ifndef EVENT_T_H
#define EVENT_T_H

#include <iostream>
#include "Particle.hpp"
#include "physics.hpp"

class Event {
 private:
  double _W = 0.0;
  double _Q2 = 0.0;
  TLorentzVector _gamma;
  Particle _electron;
  std::vector<Particle> _events;
  std::vector<int> _PID;
  std::vector<int> _event_sig;

 public:
  Event();
  Event(Particle Electron, TLorentzVector Beam);
  ~Event();

  void Add_Part(Particle p);

  std::vector<int> Signiture();
  void PrintSigniture();
  void PrintWQ2();
};

#endif
