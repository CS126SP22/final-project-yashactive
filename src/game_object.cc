//
// Created by Yashovardhan maheshwari  on 12/04/22.
//

#include <iostream>
#include "game_object.h"
#include <cinder/app/App.h>

namespace flappygame {
        void GameObject::Draw() {
            cinder::gl::color(0.8627, 0.9412, 0.9373); //clear color
            ci::Rectf bird_body;
            bird_body = ci::Rectf(vec2(x_coordinate_ - object_size_, y_coordinate_ - object_size_),
                                  vec2(x_coordinate_ + object_size_, y_coordinate_ + object_size_));
            cinder::gl::draw(kBirdImage, bird_body);
        }

        void GameObject::Move() {
            time_ = 0.005;
            x_coordinate_ = x_coordinate_ + 2;
            y_coordinate_ = y_coordinate_ - kMoveSpeed_;
        }

        size_t GameObject::GetXCoord() const {
            return x_coordinate_;
        }

        size_t GameObject::GetYCoord() const {
            return y_coordinate_;
        }

        void GameObject::ReinitializeObjectPos() {
            time_ = 0;
            object_velocity_ = 0;
            x_coordinate_ = getWindowCenter().x / 4;
            y_coordinate_ = getWindowCenter().y;
        }

        void GameObject::AccomodateGravity() {
            time_ = time_ + 0.01;
            object_velocity_ = time_ * kGravityRate_;
            y_coordinate_ = y_coordinate_ + object_velocity_;
        }

        double GameObject::GetTime() {
            return time_;
        }
};
