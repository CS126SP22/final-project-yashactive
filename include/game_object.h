//
// Created by Yashovardhan maheshwari  on 12/04/22.
//
#include <iostream>

#ifndef IDEAL_GAS_PLAYER_H
#define IDEAL_GAS_PLAYER_H

#endif //IDEAL_GAS_PLAYER_H

#include "cinder/gl/gl.h"
#include <iostream>
#include <vector>
#include "obstacles_game_engine.h"
#include "cinder/gl/Fbo.h"
#include "cinder/gl/GlslProg.h"
#include "cinder/gl/VboMesh.h"

namespace flappy_game {
    class GameObject {
    public:
        void Draw();
        size_t GetXPosition();
        size_t GetYPosition();
        void Move();
        void PositionReset();
        void AccomodateGravity();

    private:
        size_t x_coordinate_;
        size_t y_coordinate;
        double object_velocity_ = 0;
        double object_size_ = 24;
        double time_ = 0;
        double move_velocity_ = 95;

    };
}
