#include "game.h"

namespace game {

Game::Game() {

    std::string name = TakeUserNameFromConsole();
    ci::app::setWindowSize(window_width_, window_height_);
    engine_ = GameEngine(name);
    engine_.LoadLevel(0);
    play_area_color_ = primary_color_;
}

void Game::draw() {

    DrawPlayArea();
    engine_.Draw();
}

void Game::update() {

    ci::gl::clear(play_area_color_);
    engine_.Update();
}

void Game::keyDown(cinder::app::KeyEvent event) {

    if (event.getCode() == ci::app::KeyEvent::KEY_6) {
        play_area_color_ = primary_color_;
    } else if (event.getCode() == ci::app::KeyEvent::KEY_7) {
        play_area_color_ = c2_;
    } else if (event.getCode() == ci::app::KeyEvent::KEY_8) {
        play_area_color_ = c3_;
    }
    engine_.ExecuteCommand(event.getCode());
}

std::string Game::TakeUserNameFromConsole() const {

    std::string user_name = "";
    std::cout << "Enter the user name: ";
    std::cin >> user_name;
    return user_name;
}

void Game::DrawPlayArea() {

    ci::gl::color(border_color_);
    ci::gl::drawStrokedRect(ci::Rectf(
            vec2(window_margin_, window_margin_),
            vec2(window_height_ - window_margin_ + 1, window_height_ - window_margin_ + 1)));

}

}  // namespace idealgas
