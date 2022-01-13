//
// Created by Ved Shah on 4/19/21.
//

#pragma once

#include "cinder/gl/gl.h"

using glm::vec2;
using std::vector;

namespace game {
    /**
    * A class to store a paddle object and its attributes.
    */
    class Paddle {
    public:

        Paddle();

        Paddle(size_t length, size_t margin);

        /**
         * Draws the paddle.
         */
        void Draw();

        /**
         * Moves the paddle to the right by the velocity vector.
         */
        void MoveRight();

        /**
         * Moves the paddle to the left by the velocity vector.
         */
        void MoveLeft();

        size_t GetBreadth() const;

        size_t GetLength() const;

        const vec2 &GetPos() const;

    private:
        size_t right_edge_;
        size_t left_edge_;
        vec2 pos_;

        size_t length_ = 100;
        size_t breadth_ = 15;
        vec2 speed_vector_ = vec2(30, 0);
        ci::Color color_ = ci::Color("orange");

    };

}  // namespace game