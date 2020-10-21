//
// Created by Francesco on 22/10/2020.
//

#ifndef RPG_GAME_STWEAPON_H
#define RPG_GAME_STWEAPON_H
#include "Weapon.h"

class StWeapon:public Weapon {
public:
    void shoot() override;
};


#endif //RPG_GAME_STWEAPON_H
