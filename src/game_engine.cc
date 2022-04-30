//
// Created by Yashovardhan maheshwari  on 26/04/22.
//

#include <iostream>
#include "game_engine.h"

namespace flappygame {
    void ObstacleGameEngine::DrawObstacles() {
        for (Obstacles &obs: items_) {
            obs.DrawObstacle();
        }
    }

    void ObstacleGameEngine::PutObstacles(size_t number_of_obstacles_) {
        for (size_t i = 0; i < number_of_obstacles_; i++) {
            items_.push_back(Obstacles(cinder::vec2(x_coordinate_, y_coordinate)));
            y_coordinate = 0;
            x_coordinate_ = x_coordinate_ - kObstcaleDistance_;

        }

    }
    list<Obstacles> ObstacleGameEngine::getObstacles() {
        return items_;
    }

    void ObstacleGameEngine::LocationUpdateObstacles() {
        for (Obstacles &obs: items_) {
            obs.ObstaclePositionUpdate();
        }
    }


}


