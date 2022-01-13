#include <catch2/catch.hpp>
#include <game_engine.h>
/**
 * This file contains tests for all the collisions in the game. This includes:
 * 1. Ball wall collision
 * 2. Ball paddle collision
 * 3. Ball brick collision
 * 4. Paddle wall collision
 * In all cases, different grid layouts with different number/type of bricks were tested.
 */
//######################################################

// Testing Methodology:

//  1. Testing the collision of the ball with the wall (9 tests).
//  2. Testing the collision of the paddle with walls (3 tests).
//  3. Testing the collision of the paddle with ball (5 tests).
//  4. Testing the collision of the ball with the brick (7 tests).

//######################################################

namespace game {
    // TESTING COLLISIONS
    TEST_CASE("1. Testing the collision of the ball with walls in an empty level") {

        SECTION("1.1 Testing Initial Position of the ball") {
            game::GameEngine engine = game::GameEngine();
            REQUIRE(engine.GetBall().GetPos() == vec2(450, 740));
        }
        SECTION("1.2 Testing Initial Velocity of the ball") {
            game::GameEngine engine = game::GameEngine();
            REQUIRE(engine.GetBall().GetVelocity() == vec2(0, 0));
        }
        SECTION("1.3 Testing Launch Velocity of the ball") {
            game::GameEngine engine = game::GameEngine();
            engine.ExecuteCommand(32);
            REQUIRE(engine.GetBall().GetVelocity() == vec2(-2.5, -2.5));
        }
        SECTION("1.4 Testing Collision with left wall") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(0);
            engine.ExecuteCommand(32);
            // Bringing ball towards the left wall.
            while (abs(engine.GetBall().GetPos().x - 50) > engine.GetBall().GetRadius()) {
                engine.Update();
            }

            REQUIRE(engine.GetBall().GetVelocity() == vec2(2.5, -2.5));
        }
        SECTION("1.5 Testing Collision with top wall") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(0);
            engine.ExecuteCommand(32);
            // Bringing ball towards the top wall.
            while (abs(engine.GetBall().GetPos().y - 50) > engine.GetBall().GetRadius()) {
                engine.Update();
            }

            REQUIRE(engine.GetBall().GetVelocity() == vec2(2.5, 2.5));
        }
        SECTION("1.6 Testing Collision with right wall") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(0);
            engine.ExecuteCommand(32);
            // Bringing ball towards the right wall.
            while (abs(engine.GetBall().GetPos().y - 850) > engine.GetBall().GetRadius()) {
                engine.Update();
            }

            REQUIRE(engine.GetBall().GetVelocity() == vec2(2.5, 2.5));
        }

    }

    TEST_CASE("2. Testing the collision of the paddle with walls") {

        SECTION("2.1 Testing Initial Position of the paddle") {
            game::GameEngine engine = game::GameEngine();
            REQUIRE(engine.GetPaddle().GetPos() == vec2(450, 800));
        }
        SECTION("2.2 Testing collision of paddle with the left wall") {
            game::GameEngine engine = game::GameEngine();
            while (abs(engine.GetPaddle().GetPos().x - 50) > engine.GetPaddle().GetLength()) {
                engine.ExecuteCommand(276);
            }
            REQUIRE(engine.GetPaddle().GetPos() == vec2(150, 800));
            engine.ExecuteCommand(276);
            REQUIRE(engine.GetPaddle().GetPos() == vec2(150, 800));

        }
        SECTION("2.3 Testing collision of paddle with the right wall") {
            game::GameEngine engine = game::GameEngine();
            while (abs(engine.GetPaddle().GetPos().x - 850) > engine.GetPaddle().GetLength()) {
                engine.ExecuteCommand(275);
            }
            REQUIRE(engine.GetPaddle().GetPos() == vec2(750, 800));
            engine.ExecuteCommand(275);
            REQUIRE(engine.GetPaddle().GetPos() == vec2(750, 800));

        }
    }

    TEST_CASE("3. Testing the collision of the paddle with ball") {

        SECTION("3.1 Testing Initial Position of the paddle") {
            game::GameEngine engine = game::GameEngine();
            REQUIRE(engine.GetPaddle().GetPos() == vec2(450, 800));
        }
        SECTION("3.2 Testing Initial Position of the ball") {
            game::GameEngine engine = game::GameEngine();
            REQUIRE(engine.GetBall().GetPos() == vec2(450, 740));
        }
        SECTION("3.3 Testing collision of the ball with the paddle - top") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(0);
            engine.ExecuteCommand(32);
            vec2 initial_velocity = engine.GetBall().GetVelocity();
            engine.ExecuteCommand(275);
            engine.ExecuteCommand(275);

            while (abs(engine.GetBall().GetPos().y - engine.GetPaddle().GetPos().y) >
                   engine.GetPaddle().GetBreadth() + engine.GetBall().GetRadius()) {
                engine.Update();
            }
            REQUIRE(initial_velocity == engine.GetBall().GetVelocity());
        }
        SECTION("3.4 Testing collision of the ball with the paddle - right") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(0);
            engine.ExecuteCommand(32);
            vec2 initial_velocity = engine.GetBall().GetVelocity();
            engine.ExecuteCommand(275);

            while (engine.GetBall().GetPos().y < engine.GetPaddle().GetPos().y) {
                engine.Update();
            }
            engine.Update();
            REQUIRE(engine.GetBall().GetVelocity().x == Approx(-1 * initial_velocity.x));
            REQUIRE(engine.GetBall().GetVelocity().y == Approx(-1 * initial_velocity.y));
        }
        SECTION("3.5 Testing fall through of the ball with the paddle") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(0);
            engine.ExecuteCommand(32);

            while (abs(engine.GetBall().GetPos().y - engine.GetPaddle().GetPos().y) >
                   engine.GetPaddle().GetBreadth() + engine.GetBall().GetRadius()) {
                engine.Update();
            }
            REQUIRE(engine.GetBall().GetVelocity() == vec2(-2.5,2.5));
        }
    }

    TEST_CASE("4. Testing the collision of the ball with the brick.") {

        SECTION("4.1 Testing the initial position and velocity of the ball after launch") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(4);
            engine.ExecuteCommand(32);
            Grid grid = engine.GetGrid();

            REQUIRE(engine.GetBall().GetPos() == vec2(450, 740));
            REQUIRE(engine.GetBall().GetVelocity() == vec2(-2.5, -2.5));

        }
        SECTION("4.2 Testing the initial state of the bricks") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(4);
            engine.ExecuteCommand(32);
            Grid grid = engine.GetGrid();

            REQUIRE(grid.GetBoard()[0][0] == 2);
            REQUIRE(grid.GetBoard()[0][1] == 2);
        }
        SECTION("4.3 Testing velocity of ball after collision with the brick") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(4);
            engine.ExecuteCommand(32);
            while (abs(engine.GetBall().GetPos().y - 450) > engine.GetBall().GetRadius()) {
                engine.Update();
            }
            REQUIRE(engine.GetBall().GetVelocity() == vec2(-2.5, 2.5));
        }
        SECTION("4.4 Testing the state of the bricks after the collision") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(4);
            engine.ExecuteCommand(32);
            while (abs(engine.GetBall().GetPos().y - 450) > engine.GetBall().GetRadius()) {
                engine.Update();
            }
            Grid grid = engine.GetGrid();
            REQUIRE(grid.GetBoard()[0][0] == 1);
            REQUIRE(grid.GetBoard()[0][1] == 2);
        }
        SECTION("4.5 Testing passthrough of the ball in empty grid") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(0);
            engine.ExecuteCommand(32);
            vec2 initial_velocity = engine.GetBall().GetVelocity();
            while (abs(engine.GetBall().GetPos().y - 450) > engine.GetBall().GetRadius()) {
                engine.Update();
            }
            REQUIRE(engine.GetBall().GetVelocity() == initial_velocity);
        }
        SECTION("4.6 Testing the state of the brick and ball before the collision - different grid size") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(3);
            engine.ExecuteCommand(32);
            Grid grid1 = engine.GetGrid();
            Grid grid = engine.GetGrid();
            REQUIRE(engine.GetBall().GetVelocity() == vec2(-2.5, -2.5));
            REQUIRE(grid.GetBoard()[5][0] == 0);
        }
        SECTION("4.7 Testing the state of the brick and ball after the collision - different grid size") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(3);
            engine.ExecuteCommand(32);
            Grid grid1 = engine.GetGrid();
            while (abs(engine.GetBall().GetPos().y - 400) > engine.GetBall().GetRadius()) {
                engine.Update();
            }
            Grid grid = engine.GetGrid();
            REQUIRE(engine.GetBall().GetVelocity() == vec2(2.5, -2.5));
            REQUIRE(grid.GetBoard()[5][0] == 0);
        }
    }
}

