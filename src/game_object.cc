//
// Created by Yashovardhan maheshwari  on 12/04/22.
//

#include <iostream>
#include "game_object.h"
#include <cinder/app/App.h>

namespace flappygame {
        void GameObject::Draw() {
            cinder::gl::color(4, 2, 0);
            cinder::gl::drawSolidCircle(cinder::vec2(x_coordinate_, y_coordinate_),object_size_);
        }

        void GameObject::Move() {
            time_ = 0;
            x_coordinate_ = x_coordinate_ + 1;
            y_coordinate_ = y_coordinate_ - kMoveVelocity_;
        }

        size_t GameObject::GetXCoord() {
            return x_coordinate_;
        }

        size_t GameObject::GetYCoord() {
            return y_coordinate_;
        }

        void GameObject::PositionReset() {
            time_ = 0;
            object_velocity_ = 0;
            x_coordinate_ = cinder::app::getWindowCenter().x / 4;
            y_coordinate_ = cinder::app::getWindowCenter().y;
        }

        void GameObject::AccomodateGravity() {
            time_ = time_ + 0.04;
            object_velocity_ = kGravity_ * time_;
            y_coordinate_ = y_coordinate_ + object_velocity_;
        }


};
