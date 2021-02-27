//
// Created by Francesco on 22/10/2020.
//
#include "StBullet.h"

StBullet::StBullet() {
    movementSpeed = 15;
    attackDamage = 5;
    rect.setSize(sf::Vector2f(10, 10));
    rect.setPosition(0, 0);
    sprite.setTextureRect(sf::IntRect(0,0,55,42));
}

void StBullet::Update() {
    if (direction == U) //up
        rect.move(0, -movementSpeed);
    if (direction == D) //down
        rect.move(0, movementSpeed);
    if (direction == L) //left
        rect.move(-movementSpeed, 0);
    if (direction == R) //right
        rect.move(movementSpeed, 0);

    //lifetime
    counterLifetime++;
    if (counterLifetime >= lifetime)
        destroy = true;

    //sprite
    sprite.setPosition(rect.getPosition());
}