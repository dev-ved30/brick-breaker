//
// Created by Ved Shah on 4/19/21.
//

#include "paddle.h"

namespace game {

    Paddle::Paddle(){}

    Paddle::Paddle(size_t length, size_t margin) {

        left_edge_ = margin;
        right_edge_ = length - margin;
        // Positioning the paddle in the centre of the play area, below the ball
        pos_ = vec2(length / 2 , length - 2 * margin);
    }

    void Paddle::Draw() {
        ci::gl::color(color_);
        ci::gl::drawSolidRect(ci::Rectf(
                pos_ + vec2(length_ , breadth_),
                pos_ - vec2(length_ , breadth_)));
    }

    void Paddle::MoveRight() {

        if (abs(pos_.x - right_edge_) > length_) {
            pos_ += speed_vector_;
        }
    }
    void Paddle::MoveLeft() {

        if (abs(pos_.x - left_edge_) > length_) {
            pos_ -= speed_vector_;
        }
    }

    const vec2 &Paddle::GetPos() const {
        return pos_;
    }

    size_t Paddle::GetLength() const {
        return length_;
    }

    size_t Paddle::GetBreadth() const {
        return breadth_;
    }


}  // namespace game

