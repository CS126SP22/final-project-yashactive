//
// Created by Yashovardhan maheshwari  on 26/04/22.
//

#include "game_object.h"
#include <iostream>
#include <catch2/catch.hpp>
using namespace flappygame;

TEST_CASE("Tests X Coord and Y Coord") {
    GameObject object_;
    REQUIRE(object_.GetYCoord() == (size_t) cinder::app::getWindowCenter().y);
    REQUIRE(object_.GetXCoord() == cinder::app::getWindowCenter().x/4);
}

TEST_CASE("Test Object move function") {
    GameObject object_;
    object_.Move();
    REQUIRE(object_.GetYCoord() == (size_t) cinder::app::getWindowCenter().y - 80);
    REQUIRE(object_.GetXCoord() == cinder::app::getWindowCenter().x/4  + 2);
}

TEST_CASE("Test Gravity accomodation function") {
    GameObject object_;
    object_.AccomodateGravity();
    REQUIRE(object_.GetTime() == 0.01);
}

TEST_CASE("Test Position Reset Function") {
    GameObject object_;
    object_.Move();
    REQUIRE(object_.GetYCoord() == (size_t) cinder::app::getWindowCenter().y);
    REQUIRE(object_.GetXCoord() == cinder::app::getWindowCenter().x/4);
}
