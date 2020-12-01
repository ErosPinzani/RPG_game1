//
// Created by Francesco on 22/10/2020.
//

#ifndef RPG_GAME_STBULLET_H
#define RPG_GAME_STBULLET_H
#include "Bullet.h"

class StBullet: public Bullet {
public:
    StBullet();
    void Update() override;
};



#endif //RPG_GAME_STBULLET_H
