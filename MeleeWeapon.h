//
// Created by Francesco on 22/10/2020.
//

#ifndef RPG_GAME_MELEEWEAPON_H
#define RPG_GAME_MELEEWEAPON_H
#include "Weapon.h"

class MeleeWeapon:public Weapon {
public:
    void shoot() override;

    float getRange() const;

    void setRange(float range);

    int getPower() const;

    void setPower(int power);

    bool isHit() const;

    void setHit(bool hit);

private:
    float range;
    int power;
    bool hit;
};


#endif //RPG_GAME_MELEEWEAPON_H
