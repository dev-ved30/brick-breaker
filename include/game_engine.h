#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "grid.h"
#include "paddle.h"
#include "ball.h"
#include "leader_board.h"

#include <vector>


using glm::vec2;
namespace game {
    /**
     * A class to store the state of the game engine. This class stores the score, the paddle,
     * the ball, the grid and also checks for the game mechanics.
     */
    class GameEngine {
    public:
        GameEngine();

        GameEngine(std::string name);

        /**
         * Draws the board, the particles, the bricks and the walls of the container.
         */
        void Draw();

        /**
         * Updates the state of the container. Checks for any particle - particle
         * or particle wall collisions.
         */
        void Update();

        /**
         * Executes the command based on the keyboard command from cinder.
         * @param event The cinder app Key Event
         */
        void ExecuteCommand(size_t event);


        /**
         * Draws the score card of the current game.
         */
        void DrawScoreCard();

        /**
         * Loads the level grid corresponding to an index number
         * @param i The index number.
         */
        void LoadLevel(size_t i);

        /**
         * Loads the leaderboard from the saved file.
         */
        void LoadLeaderBoard();

        /**
         * Checks if the ball collides with the walls of the play area and updates its velocity accordingly.
         */
        void CheckWallCollisions();

        /**
         * Checks if the ball collides with the paddle and updates its velocity accordingly.
         */
        void CheckPaddleCollision();

        /**
         * Checks if the ball collides with any if the bricks in the grid and updates the velocity accordingly.
         */
        void CheckGridCollision();

        /**
         * Checks if the game has ended.
         */
        void CheckGameEnding();

        const size_t GetScore() const;

        const Grid& GetGrid() const;

        const Paddle& GetPaddle() const;

        const Ball& GetBall() const;

        const std::vector <std::string>& GetPaths() const;

        size_t GetLevel() const;

    private:

        size_t window_height_ = 900;
        size_t window_width_ = 1300;
        size_t window_margin_ = 50;
        size_t damage_point_ = 10;
        size_t score_card_multiplier_ = 5;
        ci::Color primary_color_ = ci::Color("white");

        size_t score_;
        size_t level_;
        game::Grid grid_;
        game::Paddle paddle_;
        game::Ball ball_;
        game::LeaderBoard lb_;
        std::vector<std::string> paths_;
        std::string player_name_;

        // Paths for the level files and leader board
        std::string l0_path_ = "/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/l0.txt";
        std::string l1_path_ = "/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/l1.txt";
        std::string l2_path_ = "/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/l2.txt";
        std::string l3_path_ = "/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/l3.txt";

        std::string t1_path_ = "/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/test/l3.txt";
        std::string lb_path_ = "/Users/ved/Documents/Classes/Spring-2021/CS-126/cinder_0.9.2_mac/my-projects/final-project-dev-ved30/data/lb.txt";

    };

}  // namespace idealgas
