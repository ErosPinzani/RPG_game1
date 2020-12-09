//
// Created by Francesco on 22/10/2020.
//

#include "AoeBullet.h"

AoeBullet::AoeBullet() {
    movementSpeed = 8;
    attackDamage = 8;
    rect.setSize(sf::Vector2f(35, 34));
    rect.setPosition(0, 0);
    sprite.setTextureRect(sf::IntRect(0,0,35,34));
}
