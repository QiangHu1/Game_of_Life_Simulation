/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Game of Life Simulation.

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "Cell.h"
#include "Grid.h"
#include "catch.hpp"
#include "gameoflife.h"
#include "golCatchMain.h"
#include "golMyFunctions.h"
#include <iostream>
#include <vector>
using namespace std;

TEST_CASE("Check instantiation of Grid") {
  Grid gd = *new Grid("../../test/data/glider.txt");
  REQUIRE(gd.rows == 10);
  REQUIRE(gd.cols == 10);
  REQUIRE(gd.Alive(3, 3) == 2);
  gd.setc(3, 3, true);
  REQUIRE(gd.getc(3, 3));
  REQUIRE_THROWS(gd.getc(60, 90));
  REQUIRE_THROWS(gd.setc(80, 90, true));
}

TEST_CASE("Check randomly initialising") {
  REQUIRE_THROWS(new Grid(7, 8, 77));
  REQUIRE_THROWS(new Grid(7, 8, -77));
  Gameoflife grid = *new Grid(50, 50, 12);
  Grid grid2 = *new Grid(50, 50, 12);
  bool same = grid.compare(grid2);
  REQUIRE(!same);
  int num_alive = 0;
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) {
      if (grid2.getc(i, j)) {
        num_alive++;
      }
    }
  }
  REQUIRE(num_alive == 12);
}

TEST_CASE("Check initialising the grid from a file") {
  Grid gd = *new Grid("../../test/data/glider.txt");
  REQUIRE(gd.rows == 10);
  REQUIRE(gd.cols == 10);
  REQUIRE(gd.getc(1, 2));
  REQUIRE(gd.getc(2, 2));
  REQUIRE(gd.getc(3, 2));
  REQUIRE(gd.getc(2, 0));
  REQUIRE(gd.getc(3, 1));
  gd.setc(1, 2, false);
  gd.setc(2, 2, false);
  gd.setc(3, 2, false);
  gd.setc(2, 0, false);
  gd.setc(3, 1, false);
  Gameoflife grid = *new Grid(10, 10, 0);
  bool same = grid.compare(gd);
  REQUIRE(same);
}

