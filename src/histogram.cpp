/**************************************/
/*																		*/
/*  Created by Nick Tyler             */
/*	University Of South Carolina      */
/**************************************/
#include "histogram.hpp"

Histogram::Histogram(const std::string& output_file) {
  RootOutputFile = std::make_shared<TFile>(output_file.c_str(), "RECREATE");
  def = new TCanvas("def");
  WvsQ2_make_hists();
}

Histogram::~Histogram() { this->Write(); }

void Histogram::Write() {
  std::cout << GREEN << "Writting" << DEF << std::endl;

  std::cerr << BOLDBLUE << "WvsQ2()" << DEF << std::endl;
  TDirectory* WvsQ2_folder = RootOutputFile->mkdir("W vs Q2");
  WvsQ2_folder->cd();
  WvsQ2_Write();
  std::cerr << BOLDBLUE << "Done Writing!!!" << DEF << std::endl;
}

void Histogram::WvsQ2_make_hists() {
  W_hist_sec.reserve(6);
  for (int i = 0; i < 6; i++)
    W_hist_sec[i] = std::make_shared<TH1D>(Form("W_%d", i + 1), Form("W_%d", i + 1), BINS, w_min, w_max);
}

void Histogram::WvsQ2_Fill(float W, float Q2, int sec) {
  WvsQ2_hist->Fill(W, Q2);
  W_hist->Fill(W);
  Q2_hist->Fill(Q2);
  if (sec > 0 && sec <= 6) {
    W_hist_sec[sec - 1]->Fill(W);
  }
}

void Histogram::WvsQ2_Write() {
  WvsQ2_hist->SetXTitle("W (GeV)");
  WvsQ2_hist->SetYTitle("Q^{2} (GeV^{2})");
  WvsQ2_hist->SetOption("COLZ");
  WvsQ2_hist->Write();

  W_hist->SetXTitle("W (GeV)");
  W_hist->Write();

  for (int i = 0; i < 6; i++) {
    W_hist_sec[i]->SetXTitle("W (GeV)");
    W_hist_sec[i]->Write();
  }

  Q2_hist->SetXTitle("Q^{2} (GeV^{2})");
  Q2_hist->Write();
}
