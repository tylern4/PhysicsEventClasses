/**************************************/
/*																		*/
/*  Created by Nick Tyler             */
/*	University Of South Carolina      */
/**************************************/

#ifndef MAIN_H_GUARD
#define MAIN_H_GUARD

#include <iostream>
#include "TFile.h"
#include "TH1.h"
#include "branches.hpp"
#include "color.hpp"
#include "reaction.hpp"
#include "histogram.hpp"

size_t run(std::shared_ptr<TChain> _chain, std::shared_ptr<Histogram> _hists) {
  size_t num_of_events = (int)_chain->GetEntries();
  auto data = std::make_shared<Branches12>(_chain);

  for (size_t current_event = 0; current_event < num_of_events; current_event++) {
    _chain->GetEntry(current_event);
    data->gpart();
    //std::cout << data->gpart() << std::endl;
    /*
    if (data->gpart() <= 1) continue;
    bool elec = true;
    elec &= (data->charge(0) == NEGATIVE);
    if (!elec) continue;

    auto event = std::make_unique<Reaction>(data);
    int part;
    for (part = 1; part < data->gpart(); part++) {
      if (data->pid(part) == PIP) {
        event->SetPip(part);
      } else if (data->pid(part) == PROTON) {
        event->SetProton(part);
      } else if (data->pid(part) == PIM) {
        event->SetPim(part);
      } else {
        event->SetOther(part);
      }
    }

    if (event->SingleP()) _hists->WvsQ2_Fill(event->W(), event->Q2());
   */
  }

  return num_of_events;
}

size_t run_files(std::vector<std::string> inputs, std::shared_ptr<Histogram> hists, int thread_id) {
  auto chain = std::make_shared<TChain>("clas12");
  for (auto in : inputs) std::cout << thread_id << "\t" << in << std::endl;
  for (auto in : inputs) chain->Add(in.c_str());
  return run(chain, hists);
}

#endif
