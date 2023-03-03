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
// Method to print the grid
void Grid::printc() {
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      cout << (cells[r][c].alive ? "o" : "-") << " ";
    }
    cout << '\n';
  }
  cout << endl;
}

// Methods to get cell
bool Grid::getc(int row, int col) {
  if (row < 0 || row >= rows || col < 0 || col >= cols) {
    throw logic_error("row or column input is invalid.");
  }
  return cells[row][col].alive;
}

// Methods to set cell
void Grid::setc(int row, int col, bool value) {
  if (row < 0 || row >= rows || col < 0 || col >= cols) {
    throw logic_error("row or column input is invalid.");
  }
  cells[row][col].alive = value;
}

Grid::Grid(string filename) {
  // Open file
  ifstream infile;
  infile.open(filename.data());
  if (!infile) {
    throw logic_error("Input file is invalid or not found.");
  }
  string s;
  // load data
  cells = *new vector<vector<Cell>>();
  while (getline(infile, s)) {
    vector<Cell> rows = *new vector<Cell>();
    for (char cell : s) {
      Cell c = *new Cell();
      if (cell == 'o') {
        c.alive = true;
        rows.push_back(c);
      }
      if (cell == '-') {
        c.alive = false;
        rows.push_back(c);
      }
    }
    cells.push_back(rows);
  }
  rows = cells.size();
  cols = cells[0].size();

  // Close the input file
  infile.close();
}

int Grid::Alive(int row_i, int col_i) {
  if (row_i < 0 || col_i >= rows || col_i < 0 || col_i >= cols) {
    throw logic_error("row or column input is invalid.");
  }
  int alive_n = 0;
  for (int r = row_i - 1; r < row_i + 2; r++) {
    for (int c = col_i - 1; c < col_i + 2; c++) {
      if ((0 <= r && r < rows && 0 <= c && c < cols) &&
          (r != row_i || c != col_i)) {
        alive_n += cells[r][c].alive;
      } else {
        alive_n += 0;
      }
    }
  }
  return alive_n;
}