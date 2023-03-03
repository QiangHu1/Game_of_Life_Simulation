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

  // Add options
  random_initial
      ->add_option("-s, -S", size, "Size of grid: rows cols alive_number")
      ->check(CLI::NonNegativeNumber)
      ->required()
      ->expected(3);

  file_input->add_option("file", filename, "Path and position of the file")
      ->check(CLI::ExistingFile)
      ->required();

  find_pattern
      ->add_option("-c, -C", Control,
                   "Control grid data: rows cols alive_number  iterations")
      ->check(CLI::NonNegativeNumber)
      ->required()
      ->expected(3);

  app.add_option("-n,-N", genera_num, "Number of generations")
      ->check(CLI::NonNegativeNumber);

  CLI11_PARSE(app, argc, argv);

  // Run the selected subcommand
  if (random_initial->parsed()) {
    Gameoflife grid = *new Grid(size[0], size[1], size[2]);
    for (int iter = 0; iter < genera_num; iter++) {
      grid.takeStep();
    }
    grid.printGrid();
  } else if (file_input->parsed()) {
    Gameoflife grid = *new Grid(filename);
    for (int iter = 0; iter < genera_num; iter++) {
      grid.takeStep();
    }
    grid.printGrid();
  } else if (find_pattern->parsed()) {
    Gameoflife grid = *new Grid(Control[0], Control[1], Control[2]);
  }

  return 0;
}