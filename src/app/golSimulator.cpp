#include "CLI11.hpp"
#include "Grid.h"
#include "gameoflife.h"
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv) {
  // Set description of the app
  CLI::App app{"The game of life simulator"};
  app.footer("End.");
  app.require_subcommand(1);

  // Initialize all the parameters
  string filename;
  int genera_num = 0;
  vector<int> size;
  vector<int> Control;

  // Add subcommands for all the subs
  auto random_initial =
      app.add_subcommand("random_initial", "Random initial cell values");
  auto file_input = app.add_subcommand("file_input", "Input text file");
  auto find_pattern =
      app.add_subcommand("find_pattern", "Finding stationary patterns");


  return 0;
}