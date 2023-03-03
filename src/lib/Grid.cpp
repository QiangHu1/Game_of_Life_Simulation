#include "Grid.h"
#include <fstream>
#include <random>
#include <vector>
using namespace std;
Grid::Grid() {}
Grid::Grid(int rows, int cols, int num_alive) {
  if (rows * cols <= num_alive || num_alive < 0) {
    throw logic_error("Number of alive cells are invalid.");
  }
  // Randomly select alive cells
  this->rows = rows;
  this->cols = cols;
  random_device rand;
  mt19937 rng(rand());
  uniform_int_distribution<int> rand_row(0, rows - 1);
  uniform_int_distribution<int> rand_col(0, cols - 1);
  auto grid = *new vector<vector<Cell>>();
  for (int r = 0; r < rows; r++) {
    vector<Cell> line = *new vector<Cell>();
    for (int c = 0; c < cols; c++) {
      Cell i = *new Cell();
      i.alive = false;
      line.push_back(i);
    }
    grid.push_back(line);
  }
  for (int i = 0; i < num_alive; i++) {
    int row1 = rand_row(rng);
    int col1 = rand_col(rng);
    // Avoid selecting the same cell
    while (grid[row1][col1].alive) {
      row1 = rand_row(rng);
      col1 = rand_col(rng);
    };
    grid[row1][col1].alive = true;
  }
  cells = grid;
}
Grid::~Grid() {}
