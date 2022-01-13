//
// Created by Ved Shah on 5/3/21.
//
#include "game_engine.h"

namespace game {

    GameEngine::GameEngine() {

        grid_ = game::Grid(window_height_, window_margin_);
        paddle_ = game::Paddle(window_height_, window_margin_);
        ball_ = game::Ball(window_height_, window_margin_);
        lb_ = game::LeaderBoard(window_height_, window_margin_);
        LoadLeaderBoard();
        score_ = 0;

    }

    GameEngine::GameEngine(std::string name) {

        grid_ = game::Grid(window_height_, window_margin_);
        paddle_ = game::Paddle(window_height_, window_margin_);
        ball_ = game::Ball(window_height_, window_margin_);
        lb_ = game::LeaderBoard(window_height_, window_margin_);
        LoadLeaderBoard();
        score_ = 0;
        player_name_ = name;
    }

    void GameEngine::ExecuteCommand(size_t event) {

        if (event == cinder::app::KeyEvent::KEY_RIGHT) {
            paddle_.MoveRight();
        } else if (event == cinder::app::KeyEvent::KEY_LEFT) {
            paddle_.MoveLeft();
        } else if (event == cinder::app::KeyEvent::KEY_SPACE) {
            ball_.LaunchBall();
        } else if (event >= cinder::app::KeyEvent::KEY_0 &&
                   event <= cinder::app::KeyEvent::KEY_4) {
            LoadLevel(event % cinder::app::KeyEvent::KEY_0);
        }
    }

    void GameEngine::LoadLeaderBoard() {

        std::ifstream input_file(lb_path_);
        if (input_file.is_open()) {
            input_file >> lb_;
            input_file.close();
        }
    }

    void GameEngine::LoadLevel(size_t level) {

        level_ = level;
        paths_.push_back(l0_path_);
        paths_.push_back(l1_path_);
        paths_.push_back(l2_path_);
        paths_.push_back(l3_path_);
        paths_.push_back(t1_path_);

        std::ifstream input_file(paths_[level_]);
        if (input_file.is_open()) {
            input_file >> grid_;
            input_file.close();
        }
    }

    void GameEngine::Draw() {

        DrawScoreCard();
        grid_.Draw();
        paddle_.Draw();
        ball_.Draw();
        lb_.Draw();
    }

    void GameEngine::Update() {

        ball_.UpdatePosition();
        CheckGameEnding();
        CheckWallCollisions();
        CheckPaddleCollision();
        CheckGridCollision();
    }

    void GameEngine::DrawScoreCard() {

        int margin_multiplier = score_card_multiplier_;
        ci::gl::drawStrokedRect(ci::Rectf(
                vec2(window_height_, window_margin_),
                vec2(window_width_ - window_margin_, margin_multiplier * window_margin_)));
        --margin_multiplier;
        ci::gl::drawStringCentered(
                "Score: " + std::to_string(score_),
                glm::vec2(window_margin_ + window_height_, margin_multiplier * window_margin_),
                primary_color_);
        --margin_multiplier;
        ci::gl::drawStringCentered(
                "Player: " + player_name_,
                glm::vec2(window_margin_ + window_height_, margin_multiplier * window_margin_),
                primary_color_);

    }

    void GameEngine::CheckWallCollisions() {

        vec2 ball_pos = ball_.GetPos();
        size_t ball_rad = ball_.GetRadius();
        if (abs(ball_pos.x - (window_height_ - window_margin_)) <= ball_rad
             || abs(ball_pos.x - window_margin_) <= ball_rad) {

            ball_.HorizontalCollision();
        }
        if (abs(ball_pos.y - window_margin_) <= ball_rad) {
            ball_.VerticalCollision();
        }
    }

    void GameEngine::CheckPaddleCollision() {

        vec2 paddle_pos = paddle_.GetPos();
        size_t paddle_length = paddle_.GetLength();
        size_t paddle_breadth = paddle_.GetBreadth();

        if (abs(paddle_pos.x - ball_.GetPos().x) <= paddle_length + ball_.GetRadius() &&
            abs(paddle_pos.y - ball_.GetPos().y) <= paddle_breadth + ball_.GetRadius()) {

            if (paddle_pos.y - ball_.GetPos().y >= paddle_breadth + ball_.GetRadius()) {
                ball_.VerticalCollision();
            } else {
                ball_.HorizontalCollision();
            }
        }
    }

    void GameEngine::CheckGridCollision() {

        vec2 ball_pos = ball_.GetPos();
        std::vector<std::vector<size_t>> board = grid_.GetBoard();

        for (size_t i = 0; i < grid_.GetHorizontalBrickCount(); ++i) {
            for (size_t j = 0; j < grid_.GetHorizontalBrickCount() / 2; ++j) {

                if (grid_.GetBoard()[j][i] == 0) {
                    continue;
                }

                // Computing the play area.
                size_t play_length = window_height_ - (2 * window_margin_);
                // Computing the top, bottom, right and left surface lines.
                size_t x1 = window_margin_ + i * (play_length / grid_.GetHorizontalBrickCount());
                size_t x2 = window_margin_ + (i + 1) * (play_length / grid_.GetHorizontalBrickCount());
                size_t y1 = window_margin_ + j * (play_length / grid_.GetHorizontalBrickCount());
                size_t y2 = window_margin_ + (j + 1) * (play_length / grid_.GetHorizontalBrickCount());

                if (abs(x1 - ball_.GetPos().x) <= ball_.GetRadius() &&
                    ball_.GetPos().y >= y1 && ball_.GetPos().y <= y2) {
                    // Checking for collision with the top surface of the brick
                    ball_.HorizontalCollision();
                    grid_.GetBoard()[j][i] -= 1;
                    score_ += damage_point_;
                    lb_.UpdatePlayerScore(player_name_, damage_point_);

                } else if (abs(x2 - ball_.GetPos().x) <= ball_.GetRadius() &&
                           ball_.GetPos().y >= y1 && ball_.GetPos().y <= y2) {
                    // Checking for collision with the bottom surface of the brick
                    ball_.HorizontalCollision();
                    grid_.GetBoard()[j][i] -= 1;
                    score_ += damage_point_;
                    lb_.UpdatePlayerScore(player_name_, damage_point_);

                } else if (abs(y1 - ball_.GetPos().y) <= ball_.GetRadius() &&
                           ball_.GetPos().x >= x1 && ball_.GetPos().x <= x2) {
                    // Checking for collision with the left surface of the brick
                    ball_.VerticalCollision();
                    grid_.GetBoard()[j][i] -= 1;
                    score_ += damage_point_;
                    lb_.UpdatePlayerScore(player_name_, damage_point_);

                } else if (abs(y2 - ball_.GetPos().y) <= ball_.GetRadius() &&
                           ball_.GetPos().x >= x1 && ball_.GetPos().x <= x2) {
                    // Checking for collision with the right surface of the brick
                    ball_.VerticalCollision();
                    grid_.GetBoard()[j][i] -= 1;
                    score_ += damage_point_;
                    lb_.UpdatePlayerScore(player_name_, damage_point_);

                }
            }
        }
    }

    void GameEngine::CheckGameEnding() {

        if (ball_.GetPos().y > window_height_ - window_margin_) {
            LoadLevel(0);
            std::ofstream output_file(lb_path_);
            if (output_file.is_open()) {
                output_file << lb_;
                output_file.close();
            }
        }
    }

    const Paddle &GameEngine::GetPaddle() const {
        return paddle_;
    }

    const Ball &GameEngine::GetBall() const {
        return ball_;
    }

    const std::vector<std::string>& GameEngine::GetPaths() const {
        return paths_;
    }

    const Grid &GameEngine::GetGrid() const {
        return grid_;
    }

    const size_t GameEngine::GetScore() const {
        return score_;
    }

    size_t GameEngine::GetLevel() const {
        return level_;
    }


}  // namespace idealgas

