//
// Created by Yashovardhan maheshwari  on 26/04/22.
//
#include <random>
#include <iostream>
#include "game_object.h"
#include "cinder/gl/gl.h"
#include <cinder/app/App.h>

namespace flappygame {
    class Obstacles {
    public:
        Obstacles(cinder::vec2 coord);
        void ObstaclePositionUpdate();
        size_t GetXLocation();
        size_t GetX2Location();
        void DrawObstacle();

    private:
        size_t x_coordinate_ = 100;
        size_t x2_coordinate = 170;
        double obstacle_velocity_ = 2;
        size_t min_lower_height = 650;
        size_t max_lower_height = 950;
        size_t min_upper_height = 600;
        size_t max_upper_height = 150;
        size_t upper_height_random;
        size_t lower_height_random;
    };
}

