//
// Created by Francesco on 22/10/2020.
//

#include "../../h/Projectiles/AoeBullet.h"

AoeBullet::AoeBullet() {
    setMovementSpeed(8);
    setAttackDamage(2);
    rect.setSize(sf::Vector2f(35, 34));
    rect.setPosition(0, 0);
    sprite.setTextureRect(sf::IntRect(0,0,35,34));
}
