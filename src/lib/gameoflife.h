#include "Grid.h"
#include <iostream>
using namespace std;

// Class for implementing the game of life
class Gameoflife {
public:
  // Constuctor
  Gameoflife(Grid g);
  ~Gameoflife();
  // Initialise grid
  Grid grid;
  // Function to make a step of game of life
  void takeStep();
  // Function to print current status of grid
  void printGrid();
  // Function to compare two grid
  bool compare(Grid grid_nex);
};