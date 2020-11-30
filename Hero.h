//
// Created by Eros on 22/10/2020.
//

#ifndef RPG_GAME_HERO_H
#define RPG_GAME_HERO_H

#include "Character.h"

class Hero: public Character {
public:


    Hero();
    void Update() override;
    void UpdateMovement() override;
    //void Loot();
};


#endif //RPG_GAME_HERO_H
