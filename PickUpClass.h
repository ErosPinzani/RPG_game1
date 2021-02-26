//
// Created by Francesco on 22/10/2020.
//

#ifndef RPG_GAME_PICKUP_H
#define RPG_GAME_PICKUP_H
#include "Character.h"

class PickUpClass: public Character {
public:
    bool isCoin = true;
    int coinValue = 5;
    bool destroy = false;

    void Update();

    PickUpClass();
};


#endif //RPG_GAME_PICKUP_H
