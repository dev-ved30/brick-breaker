#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "game_engine.h"

#include <vector>


using glm::vec2;
namespace game {
/**
 * The cinder app for the entire game.
 */
class Game : public ci::app::App {
 public:
  Game();

  /**
   * Draws the board, the particles, the bricks and the walls of the container.
   */
  void draw() override;

  /**
   * Updates the state of the container. Checks for any particle - particle
   * or particle wall collisions.
   */
  void update() override;

  /**
   * Triggers actions based on user input.
   * @param event The keyboard event.
   */
  void keyDown(cinder::app::KeyEvent event) override;

  /**
   * Takes user name input from the console.
   * @return String of the user name.
   */
  std::string TakeUserNameFromConsole() const;

  /**
   * Draws the frame of the play area.
   */
  void DrawPlayArea();

private:
    size_t window_height_ = 900;
    size_t window_width_ = 1300;
    size_t window_margin_ = 50;

    ci::Color primary_color_ = ci::Color("black");
    ci::Color border_color_ = ci::Color("white");
    ci::Color c2_ = ci::Color("green");
    ci::Color c3_ = ci::Color("teal");

    GameEngine engine_;
    ci::Color play_area_color_;



};

}  // namespace idealgas
