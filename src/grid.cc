//
// Created by Ved Shah on 4/19/21.
//
#include "grid.h"

namespace game {

    Grid::Grid() {}

    Grid::Grid(size_t length, size_t margin) {

        length_ = length;
        margin_ = margin;
        player_area_length_ = length_ - (2 * margin);
    }

    void Grid::Draw() {

        for (size_t i = 0; i < horizontal_brick_count_; ++i) {
            for (size_t j = 0; j < horizontal_brick_count_; ++j) {
                
                if (board_[i][j] == 0){
                    ci::gl::color(b0_color_);
                } else if (board_[i][j] == 1) {
                    ci::gl::color(b1_color_);
                } else if (board_[i][j] == 2) {
                    ci::gl::color(b2_color_);
                } else if (board_[i][j] == 3) {
                    ci::gl::color(b3_color_);
                }
                ci::gl::drawSolidRect(ci::Rectf(
                        vec2(margin_ + j * (player_area_length_ / horizontal_brick_count_) ,
                                 margin_ + i * (player_area_length_ / horizontal_brick_count_)),
                        vec2(margin_ + (j + 1) * (player_area_length_ / horizontal_brick_count_) ,
                                 margin_ + (i + 1) * (player_area_length_ / horizontal_brick_count_))));

            }
        }

    }
    std::istream& operator>>(std::istream& is, Grid& grid) {

        // Checking if the file cannot be opened.
        if (is.bad()) {
            throw std::invalid_argument( "File does not exist" );
        }

        size_t row = 0;
        std::string line = "";
        std::getline(is, line);
        grid.horizontal_brick_count_ = std::stoi(line);
        if (grid.horizontal_brick_count_ % 2 != 0) {
            throw std::invalid_argument( "Unreadable level file" );
        }
        grid.board_ = std::vector<std::vector<size_t>>(
                        grid.horizontal_brick_count_,
                        std::vector<size_t>(grid.horizontal_brick_count_));

        while (!is.eof()) {
            size_t col = 0;
            std::getline(is, line);
            if (grid.horizontal_brick_count_ != line.size()) {
                throw std::invalid_argument( "Bad level format" );
            }
            for (char c : line) {
                // Correcting for ASCII conversion
                grid.board_[row][col] = c % 48;
                col++;
            }
            row++;
        }
        return is;
    }

    vector<std::vector<size_t>> &Grid::GetBoard(){
        return board_;
    }

    size_t Grid::GetHorizontalBrickCount() const {
        return horizontal_brick_count_;
    }

}  // namespace idealgas
