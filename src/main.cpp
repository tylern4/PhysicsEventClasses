#include "clipp.h"
#include "main.hpp"

int main(int argc, char **argv) {
  std::string InFileName = "";
  std::string OutFileName = "";
  bool is_mc = false;
  bool print_help = false;

  auto cli = (clipp::option("-h", "--help").set(print_help) % "print help", clipp::value("inputFile.root", InFileName),
              clipp::opt_value("outputFile.root", OutFileName));

  clipp::parse(argc, argv, cli);
  if (print_help || InFileName == "") {
    std::cout << clipp::make_man_page(cli, argv[0]);
    exit(0);
  } else {
    run(InFileName, OutFileName);
  }

  return 0;
}
