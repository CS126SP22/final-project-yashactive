//
// Created by Yashovardhan maheshwari  on 03/05/22.
//

#include "obstacles.h"
#include <iostream>
#include <catch2/catch.hpp>
using namespace flappygame;

TEST_CASE("Tests X coordinates of Obstacles") {
    Obstacles obs(cinder::vec2(200,500));
    REQUIRE(obs.GetXLeftLocation() == 200);
    REQUIRE(obs.GetXRightLocation() == 300);
}

TEST_CASE("Tests Upper and lower height Obstacles") {
    Obstacles obs(cinder::vec2(200,500));
    REQUIRE(obs.GetLowerObsHeightRandom() > 200);
    REQUIRE(obs.GetUpperObsHeightRandom() > 790);
}
