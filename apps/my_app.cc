//
// Created by Yashovardhan maheshwari  on 29/04/22.
//
#include <iostream>
#include "my_app.h"

#include <cinder/gl/gl.h>
#include <string>

namespace flappygameapp {
    FlappyGame::FlappyGame() {
        score_  = 0;
        game_ended_ = false;
        game_main_menu_state_ = true;
    }

    void FlappyGame::setup() {
        obs_engine_.PutObstacles(10);
    }

    void FlappyGame::update() {
        obs_engine_.LocationUpdateObstacles();
        if (playing_frames_ > 10 && !game_main_menu_state_) {
            object_.AccomodateGravity();
        }
    }

    bool FlappyGame::ObjectCollide() {
        obstacles_ = obs_engine_.GetPipes();
        if (game_ended_ == true) {
            return true;
        }
        for (Obstacles& obs_ : obstacles_) {
            if ((object_.GetXCoord() >= obs_.GetXLocation() && object_.GetXCoord() <= obs_.GetX2Location())) {
                return true;
            }
        }
        return false;
    }
}



