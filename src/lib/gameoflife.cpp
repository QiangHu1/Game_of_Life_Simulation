#include "gameoflife.h"
#include "Grid.h"
#include <iostream>
using namespace std;

Gameoflife::Gameoflife(Grid g) { grid = g; }
Gameoflife::~Gameoflife() {}

void Gameoflife::takeStep() {
  // Vector to store the grid next
  vector<vector<Cell>> grid_nex;
  grid_nex = grid.cells;
  int rows = grid.rows;
  int cols = grid.cols;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      bool alive = grid.getc(i, j);
      if (alive) {
        int alive_nu = grid.Alive(i, j);
        // Ruler two of Game of Life
        if (alive_nu == 2 || alive_nu == 3) {
          grid_nex[i][j].alive = true;
        } else {
          // Ruler three of Game of Life
          grid_nex[i][j].alive = false;
        }
      }
      // Ruler one of Game of Life
      if ((!alive) && (grid.Alive(i, j) == 3)) {
        grid_nex[i][j].alive = true;
      }
    }
  }
  grid.cells = grid_nex;
}

void Gameoflife::printGrid() {
  // Print delimitator first
  cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>" << '\n' << endl;
  grid.printc();
}

