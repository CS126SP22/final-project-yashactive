//
// Created by Yashovardhan maheshwari  on 26/04/22.
//

#include <iostream>
#include "game_engine.h"

namespace flappygame {
    void ObstacleGameEngine::DrawObstacles() {
        for (Obstacles & obstacle: obstacles_) {
            obstacle.DrawObstacle();
        }
    }

    void ObstacleGameEngine::PutObstacles(size_t number_of_obstacles_) {
        for (size_t i = 0; i < number_of_obstacles_; ++i) {
            Obstacles obstacle_to_add = Obstacles(cinder::vec2(x_coordinate_, y_coordinate));
            obstacles_.push_back(obstacle_to_add);
            y_coordinate = 0;
            x_coordinate_ -= kObstcaleDistance_;

        }
    }
    list<Obstacles> ObstacleGameEngine::getObstacles() {
        return obstacles_;
    }

    void ObstacleGameEngine::UpdateObstacleLocation() {
        for (Obstacles & obstacle: obstacles_) {
            obstacle.ObstaclePositionUpdate();
        }
    }


}


