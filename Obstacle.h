//
// Created by erosp on 22/10/2020.
//

#ifndef RPG_GAME_OBSTACLE_H
#define RPG_GAME_OBSTACLE_H

#include "Character.h"

class Obstacle: public Character {
public:
    bool alive = true;

    Obstacle();
    void Update();
};


#endif //RPG_GAME_OBSTACLE_H
