#pragma once

#include "cinder/gl/gl.h"

using glm::vec2;
using std::vector;

namespace game {
    /**
     * A class to store the grid object and its attributes including the values and operators.
     */
    class Grid {
    public:

        Grid();

        Grid(size_t length, size_t margin);

        /**
         * Draws the grid of blocks.
         */
        void Draw();

        /**
         * Reads the grid layout from the text file.
         * @param is Input stream object
         * @param grid Grid object that needs to be constructed.
         * @return The input stream object.
         */
        friend std::istream& operator>>(std::istream& is, Grid& grid);

        vector<std::vector<size_t>> &GetBoard();

        size_t GetHorizontalBrickCount() const;

    private:
        size_t horizontal_brick_count_;
        size_t length_;
        size_t margin_;
        size_t player_area_length_;
        std::vector<std::vector<size_t>> board_;

        ci::Color b0_color_ = ci::Color("black");
        ci::Color b1_color_ = ci::Color("purple");
        ci::Color b2_color_ = ci::Color("red");
        ci::Color b3_color_ = ci::Color("blue");


    };

}  // namespace game