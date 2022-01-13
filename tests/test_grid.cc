#include <catch2/catch.hpp>
#include <game_engine.h>
/**
 * This file contains tests for grid related functionality including level loading, grid contruction
 * and operation overloading.
 * In all cases, different grid layouts with different number/type of bricks were tested.
 */
//######################################################

// Testing Methodology:

//  1. Testing the grid and level loading functionality (13 tests).
//  2. Testing the grid and overloading capability (7 tests).

//######################################################

namespace game {

    TEST_CASE("1. Testing Grid and level loading") {

        SECTION("1.1 Testing level 1 grid size") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(1);
            REQUIRE(engine.GetGrid().GetHorizontalBrickCount() == 10);
        }
        SECTION("1.2 Testing level 2 grid size") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(2);
            REQUIRE(engine.GetGrid().GetHorizontalBrickCount() == 10);
        }
        SECTION("1.3 Testing level 3 grid size") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(3);
            REQUIRE(engine.GetGrid().GetHorizontalBrickCount() == 10);
        }
        SECTION("1.4 Testing level 1 grid component - row 1") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(1);
            game::Grid grid = engine.GetGrid();
            REQUIRE(grid.GetBoard()[0][0] == 1);
            REQUIRE(grid.GetBoard()[0][1] == 2);
            REQUIRE(grid.GetBoard()[0][2] == 0);
            REQUIRE(grid.GetBoard()[0][3] == 3);
            REQUIRE(grid.GetBoard()[0][4] == 0);
            REQUIRE(grid.GetBoard()[0][5] == 0);
            REQUIRE(grid.GetBoard()[0][6] == 1);
            REQUIRE(grid.GetBoard()[0][7] == 3);
            REQUIRE(grid.GetBoard()[0][8] == 1);
            REQUIRE(grid.GetBoard()[0][9] == 2);
        }
        SECTION("1.5 Testing level 1 grid component - row 2") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(1);
            game::Grid grid = engine.GetGrid();
            REQUIRE(grid.GetBoard()[1][0] == 2);
            REQUIRE(grid.GetBoard()[1][1] == 1);
            REQUIRE(grid.GetBoard()[1][2] == 3);
            REQUIRE(grid.GetBoard()[1][3] == 1);
            REQUIRE(grid.GetBoard()[1][4] == 0);
            REQUIRE(grid.GetBoard()[1][5] == 0);
            REQUIRE(grid.GetBoard()[1][6] == 1);
            REQUIRE(grid.GetBoard()[1][7] == 2);
            REQUIRE(grid.GetBoard()[1][8] == 2);
            REQUIRE(grid.GetBoard()[1][9] == 1);
        }
        SECTION("1.6 Testing level 1 grid component - row 3") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(1);
            game::Grid grid = engine.GetGrid();
            REQUIRE(grid.GetBoard()[2][0] == 3);
            REQUIRE(grid.GetBoard()[2][1] == 0);
            REQUIRE(grid.GetBoard()[2][2] == 0);
            REQUIRE(grid.GetBoard()[2][3] == 1);
            REQUIRE(grid.GetBoard()[2][4] == 2);
            REQUIRE(grid.GetBoard()[2][5] == 0);
            REQUIRE(grid.GetBoard()[2][6] == 2);
            REQUIRE(grid.GetBoard()[2][7] == 2);
            REQUIRE(grid.GetBoard()[2][8] == 3);
            REQUIRE(grid.GetBoard()[2][9] == 0);
        }
        SECTION("1.7 Testing level 1 grid component - row 4") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(1);
            game::Grid grid = engine.GetGrid();
            REQUIRE(grid.GetBoard()[3][0] == 1);
            REQUIRE(grid.GetBoard()[3][1] == 0);
            REQUIRE(grid.GetBoard()[3][2] == 1);
            REQUIRE(grid.GetBoard()[3][3] == 0);
            REQUIRE(grid.GetBoard()[3][4] == 0);
            REQUIRE(grid.GetBoard()[3][5] == 1);
            REQUIRE(grid.GetBoard()[3][6] == 1);
            REQUIRE(grid.GetBoard()[3][7] == 3);
            REQUIRE(grid.GetBoard()[3][8] == 1);
            REQUIRE(grid.GetBoard()[3][9] == 0);
        }
        SECTION("1.8 Testing level 1 grid component - row 5") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(1);
            game::Grid grid = engine.GetGrid();
            REQUIRE(grid.GetBoard()[4][0] == 1);
            REQUIRE(grid.GetBoard()[4][1] == 2);
            REQUIRE(grid.GetBoard()[4][2] == 0);
            REQUIRE(grid.GetBoard()[4][3] == 3);
            REQUIRE(grid.GetBoard()[4][4] == 0);
            REQUIRE(grid.GetBoard()[4][5] == 0);
            REQUIRE(grid.GetBoard()[4][6] == 1);
            REQUIRE(grid.GetBoard()[4][7] == 3);
            REQUIRE(grid.GetBoard()[4][8] == 1);
            REQUIRE(grid.GetBoard()[4][9] == 2);
        }
        SECTION("1.9 Testing level 1 grid component size") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(1);
            game::Grid grid = engine.GetGrid();
            REQUIRE(grid.GetBoard().size() == 10);
            REQUIRE(grid.GetBoard()[0].size() == 10);
            REQUIRE(grid.GetBoard()[1].size() == 10);
            REQUIRE(grid.GetBoard()[2].size() == 10);
            REQUIRE(grid.GetBoard()[3].size() == 10);
            REQUIRE(grid.GetBoard()[4].size() == 10);
        }
        SECTION("1.10 Testing level 2 grid component size") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(2);
            game::Grid grid = engine.GetGrid();
            REQUIRE(grid.GetBoard().size() == 10);
            REQUIRE(grid.GetBoard()[0].size() == 10);
            REQUIRE(grid.GetBoard()[1].size() == 10);
            REQUIRE(grid.GetBoard()[2].size() == 10);
            REQUIRE(grid.GetBoard()[3].size() == 10);
            REQUIRE(grid.GetBoard()[4].size() == 10);
        }
        SECTION("1.11 Testing level 3 grid component size") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(3);
            game::Grid grid = engine.GetGrid();
            REQUIRE(grid.GetBoard().size() == 10);
            REQUIRE(grid.GetBoard()[0].size() == 10);
            REQUIRE(grid.GetBoard()[1].size() == 10);
            REQUIRE(grid.GetBoard()[2].size() == 10);
            REQUIRE(grid.GetBoard()[3].size() == 10);
            REQUIRE(grid.GetBoard()[4].size() == 10);
        }
        SECTION("1.12 Testing level 4 grid size") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(4);
            REQUIRE(engine.GetGrid().GetHorizontalBrickCount() == 2);
        }
        SECTION("1.13 Testing level 4 grid component size") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(4);
            game::Grid grid = engine.GetGrid();
            REQUIRE(grid.GetBoard().size() == 2);
            REQUIRE(grid.GetBoard()[0].size() == 2);
            REQUIRE(grid.GetBoard()[1].size() == 2);
        }
    }
    TEST_CASE("2. Testing grid and overloading capability.") {

        SECTION("2.1 Testing the attributes of the grid - level 1") {
            Grid grid = Grid();
            std::ifstream input_file("/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/l1.txt");
            if (input_file.is_open()) {
                input_file >> grid;
                input_file.close();
            }
            REQUIRE(grid.GetHorizontalBrickCount() == 4);
        }
        SECTION("2.2 Testing the attributes of the grid - level 2") {
            Grid grid = Grid();
            std::ifstream input_file("/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/l2.txt");
            if (input_file.is_open()) {
                input_file >> grid;
                input_file.close();
            }
            REQUIRE(grid.GetHorizontalBrickCount() == 8);
        }
        SECTION("2.3 Testing the attributes of the grid - level 3") {
            Grid grid = Grid();
            std::ifstream input_file("/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/l3.txt");
            if (input_file.is_open()) {
                input_file >> grid;
                input_file.close();
            }
            REQUIRE(grid.GetHorizontalBrickCount() == 2);
        }
        SECTION("2.4 Testing the values in  the board of the grid - level 1") {
            Grid grid = Grid();
            std::ifstream input_file("/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/l1.txt");
            if (input_file.is_open()) {
                input_file >> grid;
                input_file.close();
            }
            REQUIRE(grid.GetBoard()[0][0] == 1);
            REQUIRE(grid.GetBoard()[0][1] == 2);
            REQUIRE(grid.GetBoard()[1][0] == 2);
            REQUIRE(grid.GetBoard()[1][1] == 1);
            REQUIRE(grid.GetBoard()[2][0] == 0);
            REQUIRE(grid.GetBoard()[2][1] == 0);
            REQUIRE(grid.GetBoard()[3][0] == 0);
            REQUIRE(grid.GetBoard()[3][1] == 0);
        }
        SECTION("2.5 Testing the values in  the board of the grid - level 1") {
            Grid grid = Grid();
            std::ifstream input_file("/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/l3.txt");
            if (input_file.is_open()) {
                input_file >> grid;
                input_file.close();
            }
            REQUIRE(grid.GetBoard()[0][0] == 2);
            REQUIRE(grid.GetBoard()[0][1] == 2);
        }
        SECTION("2.6 Testing bad level file - Odd number of bricks") {
            Grid grid = Grid();
            std::ifstream input_file("/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/b1.txt");
            REQUIRE_THROWS_AS(input_file >> grid, std::invalid_argument);
        }
        SECTION("2.7 Testing bad level file - Invalid file format with different grid size") {
            Grid grid = Grid();
            std::ifstream input_file("/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/b2.txt");
            REQUIRE_THROWS_AS(input_file >> grid, std::invalid_argument);
        }
    }


}

