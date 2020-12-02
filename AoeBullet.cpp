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

void AoeBullet::Update() {
    if (direction == 1) //up
        rect.move(0, -movementSpeed);
    if (direction == 2) //down
        rect.move(0, movementSpeed);
    if (direction == 3) //left
        rect.move(-movementSpeed, 0);
    if (direction == 4) //right
        rect.move(movementSpeed, 0);

    //lifetime
    counterLifetime++;
    if (counterLifetime >= lifetime)
        destroy = true;

    //sprite
    sprite.setPosition(rect.getPosition());
}
