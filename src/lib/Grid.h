#include "Cell.h"
#include <iostream>
#include <vector>
#pragma once
using namespace std;

// Class stores and operates the status of cells
class Grid {
public:
  Grid();
  // Constructor for random pick
  Grid(int rows, int cols, int num_alive);
  // Constructor for inputting file
  Grid(string filename);
  ~Grid();
  // Method to print the grid to the screen
  void printc();
  // Methods to get and set individual cell
  bool getc(int row, int col);
  void setc(int row, int col, bool value);
  // Function to count the number of alive cells neared
  int Alive(int row, int col);

  int rows;
  int cols;
  int alive_n;
  vector<vector<Cell>> cells;
};
