//
// Created by Francesco on 22/10/2020.
//

#ifndef RPG_GAME_AOEBULLET_H
#define RPG_GAME_AOEBULLET_H
#include "Bullet.h"

class AoeBullet: public Bullet {
public:
    AoeBullet();
    void Update() override;
};


#endif //RPG_GAME_AOEBULLET_H
