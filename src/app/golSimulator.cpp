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


  return 0;
}