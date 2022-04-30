//
// Created by Yashovardhan maheshwari  on 29/04/22.
//

#ifndef FLAPPY_GAME_GAME_ENGINE_H
#define FLAPPY_GAME_GAME_ENGINE_H

//
// Created by Yashovardhan maheshwari  on 12/04/22.
//

#include "cinder/gl/gl.h"
#include <iostream>
#include <vector>
#include <string>
#include "obstacles.h"
using std::vector;
using std::list;

namespace flappygame {
    class ObstacleGameEngine {
    public:
        void DrawObstacles();
        void UpdateLocationObstacles();
        void PutObstacles(size_t number_of_obstacles_);
        list<Obstacles> getObstacles();

    private:
        size_t x_coordinate_;
        size_t y_coordinate;
        lits <Obstacles> items_;
        const size_t kObstcaleDistance_ = 350;

    };
}

#endif //FLAPPY_GAME_GAME_ENGINE_H
