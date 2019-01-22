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

void run(std::string input, std::string output) {
  auto chain = new TChain("h10");
  chain->Add(input.c_str());
  auto data = new Branches(chain);
  int num_of_events = (int)chain->GetEntries();
  auto mm_neutron = new TH1F("mm_neutron", "Missing Mass Neutron", 500, 0, 3.0);
  auto w_hist = new TH1D("W", "W for #pi^{+} N", 500, 0, 3.0);
  auto start_full = std::chrono::high_resolution_clock::now();

  for (int current_event = 0; current_event < num_of_events; current_event++) {
    chain->GetEntry(current_event);
    if ((current_event % 100000) == 0) {
      std::chrono::duration<double> elapsed = (std::chrono::high_resolution_clock::now() - start_full);
      std::cout << BOLDBLUE << "\t" << std::floor(100 * current_event / num_of_events) << "%\t";
      std::cout << BOLDGREEN << "\tEvents/Sec: " << current_event / elapsed.count() << " Hz \t";
      std::cout << BOLDWHITE << "\t Estimated time remaining: "
                << (num_of_events - current_event) * (elapsed.count() / current_event) << " Sec \r\r" << RESET
                << std::flush;
    }

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

    auto event = new Reaction(data);
    int part;
    for (part = 1; part < data->gpart(); part++) {
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

    if (event->NeutronPip() || event->SinglePip()) {
      mm_neutron->Fill(event->MM());
      if (event->MM() > 0.85 && event->MM() < 1.05) w_hist->Fill(event->W());
    }

    delete event;
  }

  auto out = new TFile(output.c_str(), "RECREATE");
  out->cd();
  w_hist->Write();
  mm_neutron->Write();
  out->Close();

  delete mm_neutron;
  delete w_hist;
  delete out;
  delete data;
  std::cout << std::endl;
  std::cout << std::endl;
  std::chrono::duration<double> elapsed_full = (std::chrono::high_resolution_clock::now() - start_full);
  std::cout << BOLDCYAN << "Events/Sec: " << num_of_events / elapsed_full.count() << " Hz " << elapsed_full.count()
            << " Sec" << RESET << std::endl;
}

#endif
