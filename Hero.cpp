//
// Created by Eros on 22/10/2020.
//

#include "Hero.h"

Hero::Hero() {
    setHp(20);
    setMaxhp(20);
    setMovementSpeed(5);

    rect.setSize(sf::Vector2f(31.7, 31.7));
    rect.setPosition(200-24, 200-32);
    rect.setFillColor(sf::Color::Blue);
    sprite.setTextureRect(sf::IntRect(0, 0, 31.7, 31.7));
}
