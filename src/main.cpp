#include "TChain.h"
#include "main.hpp"

int main(int argc, char const *argv[]) {
  TChain *chain = new TChain("h10");
  double Energy = 4.8;
  TLorentzVector beam = TLorentzVector(0, 0, Energy, Energy);

  if (argc > 2)
    for (int i = 1; i < argc - 1; i++) chain->Add(argv[i]);
  else
    chain->Add(argv[1]);

  getBranches(chain);

  int num_of_events = (int)chain->GetEntries();
  int current_event = 0;
  std::vector<Event> events;
  for (current_event = 0; current_event < num_of_events; current_event++) {
    chain->GetEntry(current_event);

    Particle *elec = new Particle(p[0], cx[0], cy[0], cz[0], ELECTRON);
    Event *evt = new Event(*elec, beam);
    for (int part_num = 1; part_num < gpart; part_num++) {
      Particle part(p[part_num], cx[part_num], cy[part_num], cz[part_num], id[part_num]);
      part.Set_charge(q[part_num]);
      part.Set_beta(b[part_num]);
      part.Set_vertex(vx[part_num], vy[part_num], vz[part_num]);

      evt->Add_Part(part);
    }
    events.emplace_back(*evt);
    delete evt;
  }
  chain->Reset();  // delete Tree object

  std::cout << "W,Q2,event" << std::endl;
  for (auto e : events) {
    e.PrintWQ2();
  }

  return 0;
}
