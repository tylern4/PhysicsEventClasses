#include "TChain.h"
#include "main.hpp"

int main(int argc, char const *argv[]) {
  TChain *chain = new TChain("h10");

  if (argc > 2)
    for (int i = 1; i < argc - 1; i++) chain->Add(argv[i]);
  else
    chain->Add(argv[1]);

  getBranches(chain);

  int num_of_events = (int)chain->GetEntries();
  int current_event = 0;
  std::vector<Event> events;
  for (current_event = 0; current_event < 10; current_event++) {
    chain->GetEntry(current_event);

    Particle *elec = new Particle(p[0], cx[0], cy[0], cz[0], ELECTRON);
    Event *evt = new Event(*elec);

    for (int part_num = 1; part_num < gpart; part_num++) {
      Particle part(p[part_num], cx[part_num], cy[part_num], cz[part_num], id[part_num]);
      part.Set_charge(q[part_num]);
      part.Set_beta(b[part_num]);
      part.Set_vertex(vx[part_num], vy[part_num], vz[part_num]);

      evt->Add_Part(part);
    }
    events.emplace_back(*evt);
  }
  chain->Reset();  // delete Tree object

  for (auto e : events) {
    e.PrintSigniture();
  }

  return 0;
}
