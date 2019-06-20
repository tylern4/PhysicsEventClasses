/**************************************/
/*																		*/
/*  Created by Nick Tyler             */
/*	University Of South Carolina      */
/**************************************/

#ifndef HISTOGRAM_H
#define HISTOGRAM_H
#include <cmath>
#include <fstream>
#include <iostream>
#include <mutex>
#include <thread>
#include "TCanvas.h"
#include "TDirectory.h"
#include "TF1.h"
#include "TFile.h"
#include "TGraph.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "THn.h"
#include "branches.hpp"
#include "color.hpp"

using TH2D_ptr = std::shared_ptr<TH2D>;
using TH1D_ptr = std::shared_ptr<TH1D>;

class Histogram {
 protected:
  std::shared_ptr<TFile> RootOutputFile;
  TCanvas* def;

  // W and Q^2
  int BINS = 500;
  float w_min = 0;
  float w_max = 3.25;
  float q2_min = 0;
  float q2_max = 5;

  TH2D_ptr WvsQ2_hist = std::make_shared<TH2D>("WvsQ2_hist", "W vs Q^{2}", BINS, w_min, w_max, BINS, q2_min, q2_max);
  TH1D_ptr W_hist = std::make_shared<TH1D>("W", "W", BINS, w_min, w_max);
  std::vector<TH1D_ptr> W_hist_sec;
  TH1D_ptr Q2_hist = std::make_shared<TH1D>("Q2", "Q2", BINS, q2_min, w_max);

 public:
  Histogram(const std::string& output_file);
  ~Histogram();
  void Write();

  // W and Q^2
  void WvsQ2_make_hists();
  void WvsQ2_Fill(float W, float Q2, int sec);
  void WvsQ2_Write();
};

#endif
