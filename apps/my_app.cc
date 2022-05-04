//
// Created by Yashovardhan maheshwari  on 29/04/22.
//
#include <iostream>
#include "my_app.h"

#include <cinder/gl/gl.h>
#include <string>

using cinder::TextBox;
using cinder::app::KeyEvent;
using cinder::Color;
using cinder::Rectf;
using cinder::vec2;
using std::string;
using namespace cinder::app;

namespace flappygameapp {

    FlappyGame::FlappyGame() {
        score_  = 0;
        game_ended_state_ = false;
        game_main_menu_ = true;
        game_frames_count_ = 0;
    }

    void FlappyGame::setup() {
        obstacle_engine_.PutObstacles(kObstaclesCount_);
    }

    void FlappyGame::update() {
        obstacle_engine_.UpdateObstacleLocation();
        if (kStartingFramesCount_ <= game_frames_count_  && game_main_menu_ == false) {
            object_.AccomodateGravity();
        }
    }

    bool FlappyGame::CheckObjectCollision() {
        if (game_ended_state_ == true) {
            return true;
        }
        obstacles_ = obstacle_engine_.getObstacles();
        for (Obstacles& obstacle : obstacles_) {
            if  ((object_.GetYCoord() <= obstacle.GetUpperObsHeightRandom() || object_.GetYCoord() >= obstacle.GetLowerObsHeightRandom()) &&
                (object_.GetXCoord() >= obstacle.GetXLeftLocation() && object_.GetXCoord() <= obstacle.GetXRightLocation())) {
                return true;
            }
        }
        return false;
    }

    template <typename C>
    void DisplayMessage(const string& message, const cinder::ivec2& messgae_size,
                        const C& colour, const cinder::vec2 & Pos, const int font_size) {
        cinder::gl::color(colour);
        string font_type = "Times New Roman";
        auto square = cinder::TextBox().alignment(cinder::TextBox::LEFT).font(cinder::Font(font_type, font_size)).size(messgae_size)
                .color(colour)
                .backgroundColor(ColorA(0, 0, 0, 0))
                .text(message);
        auto square_size = square.getSize();
        cinder::vec2 position = {Pos.x - square_size.x / 2, Pos.y - square_size.y / 2};
        auto exterior = square.render();
        auto texture = cinder::gl::Texture::create(exterior);
        cinder::gl::draw(texture, position);
    }

    void FlappyGame::draw() {
        cinder::gl::clear(Color(0,0,0), true);
        if (kStartingFramesCount_ <= game_frames_count_ && CheckObjectCollision() == true) {
            game_ended_state_ = true;
            GameEndScreen();
        } else if (game_main_menu_ == true) {
            MainMenuScreen();
        } else {
            game_frames_count_++;
            GameScreen();
        }

    }

    void FlappyGame::GameEndScreen() {
        string end_game_message = "Game Over \n Press Delete to Play again";
        cinder::gl::clear(Color(1, 0, 0), true);
        const cinder::ivec2 message_size = {900, 400};;
        vec2 end_game_message_position = vec2(getWindowCenter().x, getWindowCenter().y - 50);
        DisplayMessage(end_game_message, message_size, kWhite_, end_game_message_position, 80);
    }

    void FlappyGame::GameScreen() {
        GameBackground();
        obstacle_engine_.DrawObstacles();
        object_.Draw();
        glm::vec2 score_position_coord = glm::vec2(1600 / kScoreXCoordDeterminer_, 1600 / kScoreYCoordDeterminer_);
        string score = std::to_string(score_);
        ci::gl::drawStringCentered(score, score_position_coord, kWhite_, ci::Font("Impact", 65));

    }

    void FlappyGame::MainMenuScreen() {
        GameBackground();
        obstacle_engine_.DrawObstacles();
        const Color title_color = Color(1, .8, 0); // Decide this color , red is not nice
        const cinder::ivec2 title_size = {900, 450};
        vec2 game_information_position = vec2 (getWindowCenter().x, getWindowCenter().y + 250);
        vec2 game_title_position = vec2 (getWindowCenter().x + 8, getWindowCenter().y);
        DisplayMessage("Flappy Game",  title_size,title_color, game_title_position, 110);
        DisplayMessage("Click Enter Button to Play", title_size,kBlack_, game_information_position, 79);

    }

    void FlappyGame::GameBackground() {
        cinder::gl::clear(Color(0.5294, 0.8078, 0.9216)); /** Sky Blue Color */
        cinder::gl::color(0.3373, 0.4902, 0.2745); /** Grass Green Color */
        cinder::gl::drawSolidRect(Rectf(0, getWindowHeight() - kHeightGround_, getWindowWidth(), getWindowHeight()));
    }

    void FlappyGame::keyDown(cinder::app::KeyEvent key) {
        if (key.getCode() == KeyEvent::KEY_SPACE) {
            if (game_main_menu_ == false && game_ended_state_ == false) {
                score_++;
                object_.Move();
            }
        }  else if (key.getCode() == KeyEvent::KEY_BACKSPACE) {
            game_ended_state_ = false;
            game_main_menu_ = true;
            score_ = 0;
            game_frames_count_ = 0;
            object_.ReinitializeObjectPos();

        } else if (key.getCode() == KeyEvent::KEY_RETURN) {
            game_main_menu_ = false;
        }
    }

}



