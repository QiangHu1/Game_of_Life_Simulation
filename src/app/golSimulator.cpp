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
  random_initial->fallthrough();
  file_input->fallthrough();
  find_pattern->fallthrough();
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
                   "Control grid data: rows cols alive_number")
      ->check(CLI::NonNegativeNumber)
      ->required()
      ->expected(3);

  app.add_option("-n,-N", genera_num, "Number of generations")
      ->check(CLI::PositiveNumber);

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
    for (int i = 0; i < 100; i++) {
      Gameoflife grid = *new Grid(Control[0], Control[1], Control[2]);
      Gameoflife grid_bef = *new Grid(Control[0], Control[1], 0);
      Grid last_grid;
      bool same = true;
      for (int iter = 0; iter < genera_num - 1; iter++) {
        // The last two grid
        grid.takeStep();
      }
      // Compare the last two grid to last one
      grid_bef = grid;
      grid.takeStep();
      int count = 0;
      for (int r = 0; r < Control[0]; r++) {
        for (int c = 0; c < Control[1]; c++) {
          count += grid.grid.getc(r, c);
          // If one cell different, those two grid are different
          if (grid_bef.grid.getc(r, c) != grid.grid.getc(r, c)) {
            same = false;
          }
        }
      }
      // Print the result if grids are same and not all dead
      if (same && count != 0) {
        grid.printGrid();
        break;
      }
    }
    cout
        << "Can't find the stationary pattern, please change the configuration."
        << endl;
  }

  return 0;
}