//
// Created by Yashovardhan maheshwari  on 12/04/22.
//

#ifndef IDEAL_GAS_ROOMS_H
#define IDEAL_GAS_ROOMS_H

#endif //IDEAL_GAS_ROOMS_H

#include "cinder/gl/gl.h"
#include <iostream>
#include <vector>
#include <string>

class Rooms {
public:
    void RoomsVisited();
    void CluesUnlocked();
    void ItemsInRooms();

private:
    vector<std::string> items_;

};