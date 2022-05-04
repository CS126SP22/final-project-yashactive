//
// Created by Yashovardhan maheshwari  on 26/04/22.
//
#pragma once
#include <random>
#include <iostream>
#include "game_object.h"
#include "cinder/gl/gl.h"
#include <cinder/app/App.h>

namespace flappygame {
    class Obstacles {
    public:
        /**
         * Constructor for Obstacles
         * @param coord coordinate of the obstacle
         */
        Obstacles(const cinder::vec2 coord);

        /**
         * Updates the position of the Obstacle
         */
        void ObstaclePositionUpdate();

        /**
         * Gets the left edge X coordinate of the obstacle
         * @return left edge X coordinate of the obstacle
         */
        size_t GetXLeftLocation() const ;

        /**
         * Gets the right edge X coordinate of the obstacle
         * @return right edge X coordinate of the obstacle
         */
        size_t GetXRightLocation() const;

        /**
         * Draws the obstacle
         */
        void DrawObstacle();

        /**
         * Getter for the Random Upper Height of the Obstacle
         * @return Random Upper Height of the Obstacle
         */
        size_t GetUpperObsHeightRandom();

        /**
         * Getter for the Random Lower Height of the Obstacle
         * @return Random Lower Height of the Obstacle
         */
        size_t GetLowerObsHeightRandom();

    private:
        /** X coordinate of the Left Edge of the Obstacle **/
        size_t x_coordinate_left_ = 200;

        /** X coordinate of the Right Edge of the Obstacle **/
        size_t x_coordinate_right_ = 230;

        /** velocity of the Obstacle **/
        const double obstacle_velocity_ = 2;

        /** Random height of the Upper obstacle **/
        size_t upper_height_random_;

        /** Random height of the Lower obstacle **/
        size_t lower_height_random_;

        /** Min height of the Upper Obstacle **/
        const size_t kMinUpperHeight_ = 200;

        /** Max height of the Upper Obstacle **/
        const size_t kMaxUpperHeight_ = 300;

        /** Min height of the Lower Obstacle **/
        const size_t kMinLowerHeight_ = 795;

        /** Max height of the Lower Obstacle **/
        const size_t kMaxLowerHeight_ = 850;


    };
}

