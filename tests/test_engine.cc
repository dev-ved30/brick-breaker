#include <catch2/catch.hpp>
#include <game_engine.h>
/**
 * This file contains tests for the engine. It tests for user input, initial state, score keeping
 * and other basic mechanics controlled by the engine.
 * In all cases, different grid layouts with different number/type of bricks were tested.
 */
//######################################################

// Testing Methodology:

//  1. Testing the initial state of the engine (7 tests).
//  2. Testing the paddle movement with keys inputs (6 tests).
//  3. Testing the movement of the ball without collision (5 tests).
//  4. Testing the score (3 tests).
//  5. Testing the level end mechanic (3 tests).

//######################################################

namespace game {

    TEST_CASE("1. Testing Initial State of the engine") {

        game::GameEngine engine = game::GameEngine();
        SECTION("1.1 Testing Initial Score") {
            REQUIRE(engine.GetScore() == 0);
        }
        SECTION("1.2 Testing Ball Radius") {
            REQUIRE(engine.GetBall().GetRadius() == 15);
        }
        SECTION("1.2 Testing Ball Velocity") {
            REQUIRE(engine.GetBall().GetVelocity() == glm::vec2(0, 0));
        }
        SECTION("1.4 Testing Ball Position") {
            REQUIRE(engine.GetBall().GetPos() == glm::vec2(450, 740));
        }
        SECTION("1.5 Testing Paddle Position") {
            REQUIRE(engine.GetPaddle().GetPos() == glm::vec2(450, 800));
        }
        SECTION("1.6 Testing Paddle Breadth") {
            REQUIRE(engine.GetPaddle().GetBreadth() == 15);
        }
        SECTION("1.7 Testing Paddle Length") {
            REQUIRE(engine.GetPaddle().GetLength() == 100);
        }
    }

    TEST_CASE("2. Testing Paddle Movement") {

        SECTION("2.1 Testing Paddle Movement - Right") {
            game::GameEngine engine = game::GameEngine();
            engine.ExecuteCommand(275); // Right keypress
            REQUIRE(engine.GetPaddle().GetPos() == glm::vec2(480, 800));
        }
        SECTION("2.2 Testing Paddle Movement - Left") {
            game::GameEngine engine = game::GameEngine();
            engine.ExecuteCommand(276); // Left keypress
            REQUIRE(engine.GetPaddle().GetPos() == glm::vec2(420, 800));
        }
        SECTION("2.3 Testing Paddle Movement - Top") {
            game::GameEngine engine = game::GameEngine();
            engine.ExecuteCommand(273); // Up Keypress
            REQUIRE(engine.GetPaddle().GetPos() == glm::vec2(450, 800));
        }
        SECTION("2.4 Testing Top Paddle Movement - Bottom") {
            game::GameEngine engine = game::GameEngine();
            engine.ExecuteCommand(274); // Down Keypress
            REQUIRE(engine.GetPaddle().GetPos() == glm::vec2(450, 800));
        }
        SECTION("2.5 Testing Top Paddle Movement - Left, Right") {
            game::GameEngine engine = game::GameEngine();
            engine.ExecuteCommand(276); // Left Keypress
            engine.ExecuteCommand(275); // Right Keypress
            REQUIRE(engine.GetPaddle().GetPos() == glm::vec2(450, 800));
        }
        SECTION("2.6 Testing Top Paddle Movement - Right, Left") {
            game::GameEngine engine = game::GameEngine();
            engine.ExecuteCommand(275); // Right Keypress
            engine.ExecuteCommand(276); // Left Keypress
            REQUIRE(engine.GetPaddle().GetPos() == glm::vec2(450, 800));
        }
    }

    TEST_CASE("3. Testing Ball Movement with no grid loaded") {

        SECTION("3.1 Testing Initial Position of the ball") {
            game::GameEngine engine = game::GameEngine();
            REQUIRE(engine.GetBall().GetPos() == glm::vec2(450, 740));
        }
        SECTION("3.2 Testing Initial Velocity of the ball") {
            game::GameEngine engine = game::GameEngine();
            REQUIRE(engine.GetBall().GetVelocity() == glm::vec2(0, 0));
        }
        SECTION("3.3 Testing the Velocity of the ball after the launch") {
            game::GameEngine engine = game::GameEngine();
            engine.ExecuteCommand(32);
            REQUIRE(engine.GetBall().GetVelocity() == glm::vec2(-2.5, -2.5));
            REQUIRE(engine.GetBall().GetPos() == glm::vec2(450, 740));
        }
        SECTION("3.4 Testing the Position of the ball after the launch and advancing one frame") {
            game::GameEngine engine = game::GameEngine();
            engine.ExecuteCommand(32);
            Ball ball = engine.GetBall();
            ball.UpdatePosition();
            REQUIRE(ball.GetVelocity() == glm::vec2(-2.5, -2.5));
            REQUIRE(ball.GetPos() == glm::vec2(447.5, 737.5));
        }
        SECTION("3.5 Testing the Position of the ball after the launch and advancing four frame") {
            game::GameEngine engine = game::GameEngine();
            engine.ExecuteCommand(32);
            Ball ball = engine.GetBall();
            ball.UpdatePosition();
            ball.UpdatePosition();
            ball.UpdatePosition();
            ball.UpdatePosition();
            REQUIRE(ball.GetVelocity() == glm::vec2(-2.5, -2.5));
            REQUIRE(ball.GetPos() == glm::vec2(440, 730));
        }
    }


    TEST_CASE("4. Testing the score.") {

        SECTION("4.1 Testing the initial state after ball launch") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(4);
            engine.ExecuteCommand(32);
            Grid grid = engine.GetGrid();

            REQUIRE(engine.GetBall().GetPos() == vec2(450, 740));
            REQUIRE(engine.GetBall().GetVelocity() == vec2(-2.5, -2.5));
            REQUIRE(engine.GetScore() == 0);

        }
        SECTION("4.2 Testing the score after brick collision") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(4);
            engine.ExecuteCommand(32);
            while (abs(engine.GetBall().GetPos().y - 450) > engine.GetBall().GetRadius()) {
                engine.Update();
            }
            REQUIRE(engine.GetBall().GetVelocity() == vec2(-2.5, 2.5));
            REQUIRE(engine.GetScore() == 10);
        }
        SECTION("4.3 Testing the score after multiple brick collision - different grid size.") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(3);
            engine.ExecuteCommand(32);
            while (engine.GetBall().GetPos().y  < 850) {
                engine.Update();
            }
            REQUIRE(engine.GetBall().GetVelocity() == vec2(2.5, 2.5));
            REQUIRE(engine.GetScore() == 220);
        }
    }

    TEST_CASE("5. Testing game ending.") {

        SECTION("5.1 Testing if the level resets after losing - level 1") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(1);
            engine.ExecuteCommand(32);
            REQUIRE(engine.GetLevel() == 1);
            while (engine.GetBall().GetPos().y  <= 850) {
                engine.Update();
            }
            REQUIRE(engine.GetLevel() == 0);
        }
        SECTION("5.2 Testing if the level resets after losing - level 2") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(2);
            engine.ExecuteCommand(32);
            REQUIRE(engine.GetLevel() == 2);
            while (engine.GetBall().GetPos().y  <= 850) {
                engine.Update();
            }
            REQUIRE(engine.GetLevel() == 0);
        }
        SECTION("5.3 Testing if the level resets after losing - level 3") {
            game::GameEngine engine = game::GameEngine();
            engine.LoadLevel(3);
            engine.ExecuteCommand(32);
            REQUIRE(engine.GetLevel() == 3);
            while (engine.GetBall().GetPos().y  <= 850) {
                engine.Update();
            }
            REQUIRE(engine.GetLevel() == 0);
        }

    }

}

