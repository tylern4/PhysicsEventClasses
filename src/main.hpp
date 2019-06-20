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
#include "histogram.hpp"
#include "reaction.hpp"

size_t run(std::shared_ptr<TChain> _chain, std::shared_ptr<Histogram> _hists, int thread_id) {
  size_t num_of_events = (int)_chain->GetEntries();

  std::cout << "=============== " << RED << "Thread " << thread_id << DEF << " =============== " << BLUE
            << num_of_events << " Events " << DEF << "===============\n";
  auto data = std::make_shared<Branches6>(_chain);

  size_t total = 0;
  for (size_t current_event = 0; current_event < num_of_events; current_event++) {
    _chain->GetEntry(current_event);
    if (thread_id == 0 && current_event % 1000 == 0)
      std::cout << "\t" << (100 * current_event / num_of_events) << " %\r" << std::flush;

    bool elec = true;
    elec &= (data->q(0) == NEGATIVE);
    elec &= (data->ec(0) > 0);
    elec &= (data->gpart() > 0);
    elec &= (data->gpart() < 4);
    elec &= (data->cc(0) > 0);
    elec &= (data->stat(0) > 0);
    elec &= (data->sc(0) > 0);
    elec &= (data->dc(0) > 0);
    elec &= (data->nphe(0) > 30);
    elec &= (data->dc_stat(0) > 0);
    if (!elec) continue;

    total++;

    auto event = std::make_unique<Reaction>(data);
    for (int part = 1; part < data->gpart(); part++) {
      if (data->id(part) == PIP) {
        event->SetPip(part);
      } else if (data->id(part) == PROTON) {
        event->SetProton(part);
      } else if (data->id(part) == PIM) {
        event->SetPim(part);
      } else {
        event->SetOther(part);
      }
    }

    if (event->SingleP()) _hists->WvsQ2_Fill(event->W(), event->Q2(), data->dc_sect(0));
  }

  return total;
}

size_t run_files(std::vector<std::string> inputs, std::shared_ptr<Histogram> hists, int thread_id) {
  auto chain = std::make_shared<TChain>("h10");
  for (auto in : inputs) chain->Add(in.c_str());
  return run(chain, hists, thread_id);
}

#endif
