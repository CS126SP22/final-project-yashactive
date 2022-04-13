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
#include "rooms.h"

class Player {
public:
    Player();
    size_t CalculatePlayerHealth();
    void PossibleNextMoves();
    size_t CluesYetToFind();

private:
    size_t player_health_;
    size_t num_of_clues_;
    std::vector<Rooms> rooms_visited_;


};
