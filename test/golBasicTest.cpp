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

