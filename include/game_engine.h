//
// Created by Yashovardhan maheshwari  on 29/04/22.
//
#pragma once
#ifndef FLAPPY_GAME_GAME_ENGINE_H
#define FLAPPY_GAME_GAME_ENGINE_H

//
// Created by Yashovardhan maheshwari  on 12/04/22.
//

#include "cinder/gl/gl.h"
#include <iostream>
#include <string>
#include <vector>
#include "obstacles.h"
#include "cinder/app/App.h"

using std::list;
using namespace cinder::app;

namespace flappygame {
    class ObstacleGameEngine {
    public:
        /**
         * Draws all the Obstacles
         */
        void DrawObstacles();

        /**
         * Updates the position of all obstacles as time passes
         */
        void UpdateObstacleLocation();

        /**
         * Getter for a list of all obstacles
         * @return A list of all obstacles
         */
        list<Obstacles> getObstacles();

        /**
         * Adds obstacles to the game
         * @param number_of_obstacles_ the number of obstacles to add
         */
        void PutObstacles(size_t number_of_obstacles_);

    private:
        /** Distance between the obstacles */
        const size_t kObstcaleDistance_ = 400;

        /** X coordinate of the obstacles */
        size_t x_coordinate_ = cinder::app::getWindowWidth();

        /** Y coordinate of the obstacles */
        size_t y_coordinate = 0;

        /** List of obstacles */
        list <Obstacles> obstacles_;

    };
}

#endif //FLAPPY_GAME_GAME_ENGINE_H
