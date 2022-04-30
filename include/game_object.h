//
// Created by Yashovardhan maheshwari  on 12/04/22.
//
#include <iostream>
#include "cinder/gl/gl.h"
#include <iostream>
#include <vector>
#include "cinder/gl/Fbo.h"
#include "cinder/gl/GlslProg.h"
#include "cinder/gl/VboMesh.h"
#include <cinder/app/App.h>

namespace flappygame {
    class GameObject {
    public:
        void Draw();
        size_t GetXCoord();
        size_t GetYCoord();
        void Move();
        void PositionReset();
        void AccomodateGravity();

    private:
        size_t x_coordinate_;
        size_t y_coordinate_;
        double object_velocity_ = 0;
        double object_size_ = 24;
        double time_ = 0;
        const double kMoveVelocity_ = 85;
        const double kGravity_ = 9.81;

    };
}
