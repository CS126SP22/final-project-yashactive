//
// Created by Yashovardhan maheshwari  on 12/04/22.
//

#ifndef IDEAL_GAS_OBSTACLESGAMEENGINE_H
#define IDEAL_GAS_OBSTACLESGAMEENGINE_H

#endif //IDEAL_GAS_OBSTACLESGAMEENGINE_H

#include "cinder/gl/gl.h"
#include <iostream>
#include <vector>
#include <string>
#include "obstacles.h"
using std::vector;

namespace flappy_game {
    class ObstaclesGameEngine {
    public:
        void DrawObstacles();
        void UpdateLocationObstacles();
        void PutObstacles(size_t number_of_obstacles_);
        vector<Obstacles> getObstacles();

    private:
        size_t x_coordinate_;
        size_t y_coordinate;
        vector <Obstacles> items_;

    };
}