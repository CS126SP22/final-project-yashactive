//
// Created by Yashovardhan maheshwari  on 12/04/22.
//
#pragma once
#include <iostream>
#include "cinder/gl/gl.h"
#include <iostream>
#include <vector>
#include "cinder/gl/Fbo.h"
#include "cinder/app/App.h"

using namespace ci;
using namespace ci::app;
using namespace cinder::app;

namespace flappygame {
    class GameObject {
    public:
        /**
         * Function to draw the game object
         */
        void Draw();

        /**
         * Getter for the X coordinate of the game object
         * @return X coordinate of the Game Object
         */
        size_t GetXCoord() const;

        /**
         * Getter for the Y coordinate of the game object
         * @return Y coordinate of the Game Object
         */
        size_t GetYCoord() const;

        /**
         * Changes the X and Y coordinate of the game object based on veclocity
         */
        void Move();

        /**
         * Reinstates the game object to its initial position once game ends
         */
        void ReinitializeObjectPos();

        /**
         * Updates the y velocity and coordinate of the game object based on gravity.
         */
        void AccomodateGravity();

        /**
         * Getter for Time
         * @return Time
         */
        double GetTime();

    private:
        /** Y coordinate of the game Object */
        size_t y_coordinate_ = getWindowCenter().y;

        /** X coordinate of the game Object */
        size_t x_coordinate_ = getWindowCenter().x / 4;

        /** Velocity of the game Object */
        double object_velocity_ = 0;

        /** Size of the game Object */
        double object_size_ = 25;

        /** time frame of the object */
        double time_ = 0;

        /** Speed of the object when it moves **/
        const double kMoveSpeed_ = 65;

        /** Rate of gravity with which the object falls */
        const double kGravityRate_ = 9.8;

        /** The image of the object */
        const ci::gl::Texture2dRef kBirdImage = ci::gl::Texture2d::create(ci::loadImage(loadAsset("flappybird.png")));

    };
}
