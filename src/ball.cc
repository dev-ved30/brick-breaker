//
// Created by Ved Shah on 4/19/21.
//

#include "ball.h"

namespace game {

    Ball::Ball() {}

    Ball::Ball(size_t length, size_t margin) {

        //Initial position is at the centre of the play areas over the paddle
        pos_ = vec2(length / 2, length - 2 * margin - padding_);
        velocity_ = vec2(0,0);
    }

    void Ball::Draw() {

        ci::gl::color(color_);
        ci::gl::drawSolidCircle( pos_, radius_);
    }

    void Ball::LaunchBall() {

        velocity_ = initial_velocity_;
    }

    void Ball::UpdatePosition() {

        pos_ += velocity_;
    }

    const vec2 &Ball::GetPos() const {

        return pos_;
    }

    size_t Ball::GetRadius() const {

        return radius_;
    }

    void Ball::VerticalCollision() {

        velocity_.y = - velocity_.y;
    }
    void Ball::HorizontalCollision() {

        velocity_.x = - velocity_.x;
    }

    const vec2& Ball::GetVelocity() const {

        return velocity_;
    }


}  // namespace game

