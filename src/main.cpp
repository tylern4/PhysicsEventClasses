#include "main.hpp"
#include <future>
#include <thread>
#include "clipp.h"

#define NUM_THREADS 2

int main(int argc, char **argv) {
  ROOT::EnableThreadSafety();
  auto start = std::chrono::high_resolution_clock::now();
  std::vector<std::vector<std::string>> infilenames(NUM_THREADS);
  std::string outfilename;
  if (argc >= 2) {
    outfilename = argv[1];
    for (int i = 2; i < argc; i++) {
      infilenames[i % NUM_THREADS].push_back(argv[i]);
    }
  } else {
    return 1;
  }

  std::future<size_t> t[NUM_THREADS];
  size_t events = 0;

  auto hists = std::make_shared<Histogram>(outfilename);

  for (size_t i = 0; i < NUM_THREADS; i++) {
    t[i] = std::async(run_files, infilenames.at(i), hists, i);
  }
  for (size_t i = 0; i < NUM_THREADS; i++) {
    events += t[i].get();
  }
  std::cout.imbue(std::locale(""));  // Puts commas in
  std::chrono::duration<double> elapsed_full = (std::chrono::high_resolution_clock::now() - start);
  std::cout << RED << elapsed_full.count() << " sec" << DEF << std::endl;
  std::cout << BOLDYELLOW << events / elapsed_full.count() << " Hz" << DEF << std::endl;
  return 0;
}
