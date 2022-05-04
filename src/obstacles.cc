//
// Created by Yashovardhan maheshwari  on 12/04/22.
//

#include <iostream>
#include <random>
#include "obstacles.h"
#include "game_object.h"

namespace flappygame {
    Obstacles::Obstacles(const cinder::vec2 coord) {
        x_coordinate_right_ = 100 +  coord.x;
        x_coordinate_left_ = coord.x;
        upper_height_random_  = rand() % (kMaxUpperHeight_ - kMinUpperHeight_ + 1) + kMinUpperHeight_;
        lower_height_random_ = rand() % (kMaxLowerHeight_ - kMinLowerHeight_ + 1) + (kMinLowerHeight_ - 20) ;
        //std::cout<<"This is lower \t"<<lower_height_random << "\n";
        //std::cout<<"This is upper \t"<<upper_height_random << "\n";
    }

    void Obstacles::DrawObstacle() {
        cinder::gl::color(0.30196, 0.90196, 0.443137);
        cinder::gl::drawSolidRect(cinder::Rectf(x_coordinate_left_,cinder::app::getWindowHeight() - 400, x_coordinate_right_,cinder::app::getWindowHeight() - lower_height_random_));
        cinder::gl::drawSolidRect(cinder::Rectf(x_coordinate_left_,0, x_coordinate_right_, upper_height_random_));
    }

    size_t Obstacles::GetXLeftLocation() const {
        return x_coordinate_left_;
    }

    size_t Obstacles::GetXRightLocation() const {
        return x_coordinate_right_;
    }

    void Obstacles::ObstaclePositionUpdate() {
        if (x_coordinate_left_ > 0) {
            x_coordinate_left_ = x_coordinate_left_ - obstacle_velocity_;
            x_coordinate_right_ = x_coordinate_right_ - obstacle_velocity_;
        } else {
            x_coordinate_left_ = cinder::app::getWindowWidth() + 150;
            x_coordinate_right_ = cinder::app::getWindowWidth() + 250;
        }
    }

    size_t Obstacles::GetLowerObsHeightRandom() {
        return cinder::app::getWindowHeight() - lower_height_random_;
    }

    size_t Obstacles::GetUpperObsHeightRandom() {
        return upper_height_random_;
    }


}
