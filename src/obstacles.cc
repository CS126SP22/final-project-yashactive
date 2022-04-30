//
// Created by Yashovardhan maheshwari  on 12/04/22.
//

#include <iostream>
#include "obstacles.h"
#include "game_object.h"

namespace flappygame {
    Obstacles::Obstacles(const cinder::vec2 coord) {
        x_coordinate_ = coord.x;
        x2_coordinate = 80 +  coord.x;
        upper_height_random = rand() % (max_upper_height - min_upper_height + 1) + min_upper_height;
        lower_height_random = rand() % (max_lower_height - min_lower_height + 1) + min_lower_height;
    }

    void Obstacles::DrawObstacle() {
        cinder::gl::color(3.0, 0.8, 1.2);
        cinder::gl::drawSolidRect(cinder::Rectf(x_coordinate_,0, x2_coordinate, upper_height_random));
        cinder::gl::drawSolidRect(cinder::Rectf(x_coordinate_,cinder::app::getWindowHeight() - 250, x2_coordinate,cinder::app::getWindowHeight() - lower_height_random));
    }

    size_t Obstacles::GetXLocation() {
        return x_coordinate_;
    }

    size_t Obstacles::GetX2Location() {
        return x2_coordinate;
    }

    void Obstacles::ObstaclePositionUpdate() {
        if (x_coordinate_ > 0) {
            x_coordinate_ = x_coordinate_ - obstacle_velocity_;
            x2_coordinate = x2_coordinate - obstacle_velocity_;
        } else {
            x_coordinate_ = cinder::app::getWindowWidth() + 150;
            x2_coordinate = cinder::app::getWindowWidth() + 250;
        }
    }


}
