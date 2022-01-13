//
// Created by Ved Shah on 4/19/21.
//
#pragma once

#include "cinder/gl/gl.h"

using glm::vec2;
using std::vector;

namespace game {
    /**
     * A class to store a ball object and its attributes.
     */
    class Ball {
    public:

        Ball();

        Ball(size_t length, size_t margin);

        /**
         * Draws the ball.
         */
        void Draw();

        /**
         * Updates the position of the ball by the velocity value.
         */
        void UpdatePosition();

        /**
         * Flips the y component of the velocity.
         */
        void VerticalCollision();

        /**
         * Flips the x component of the velocity.
         */
        void HorizontalCollision();

        /**
         * Sets the initial velocity for the ball.
         */
        void LaunchBall();

        const vec2 &GetPos() const;

        size_t GetRadius() const;

        const vec2& GetVelocity() const;


    private:
        vec2 pos_;
        vec2 velocity_;

        size_t radius_ = 15;
        size_t padding_ = 60;
        vec2 initial_velocity_ = vec2(-2.5, -2.5);
        ci::Color color_ = ci::Color("cyan");

    };

}  // namespace game