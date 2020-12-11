//
// Created by erosp on 22/10/2020.
//

#ifndef RPG_GAME_ENEMY_H
#define RPG_GAME_ENEMY_H

#include "Character.h"
#include "Random.h"

class Enemy: public Character {
public:
    int movementLength = 20;
    int counter = 0;
    bool alive = true;
    bool aggro = false;

    Enemy();
    void UpdateMovement() override;
};


#endif //RPG_GAME_ENEMY_H
