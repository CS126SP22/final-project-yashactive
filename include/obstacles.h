//
// Created by Yashovardhan maheshwari  on 26/04/22.
//

#ifndef IDEAL_GAS_OBSTACLES_H
#define IDEAL_GAS_OBSTACLES_H
#include <random>
#include "game_object.h"
#include "cinder/gl/gl.h"

namespace flappy_game {
    class Obstacles {
    public:
        Obstacles();
        Obstacles(cinder::vec2 coord) ;
        void ObstaclePositionUpdate();
        size_t GetXPosition();

    private:
        size_t x_coordinate_;
        size_t y_coordinate;
        double obstacle_velocity_ = 0;




    };
}
#endif //IDEAL_GAS_OBSTACLES_H
