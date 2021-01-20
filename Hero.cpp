//
// Created by Eros on 22/10/2020.
//

#include "Hero.h"

Hero::Hero() {
    //hp
    getHp();
    setHp(20);
    //maxhp
    getMaxhp();
    setMaxhp(20);
    //movementSpeed
    getMovementSpeed();
    setMovementSpeed(5);
    //attackDamage
    getAttackDamage();
    setAttackDamage(5);
    //direction
    getDirection();
    setDirection(0);
    //counterwalking
    getCounterWalking();
    setCounterWalking(0);

    rect.setSize(sf::Vector2f(31.7, 31.7));
    rect.setPosition(200-24, 200-32);
    rect.setFillColor(sf::Color::Blue);
    sprite.setTextureRect(sf::IntRect(0, 0, 31.7, 31.7));
}
