//
// Created by Eros on 22/10/2020.
//

#include "Hero.h"

Hero::Hero() {
    hp = 20;
    movementSpeed = 5;
    attackDamage = 5;
    rect.setSize(sf::Vector2f(31.7, 31.7));
    rect.setPosition(750-24, 425-32);
    rect.setFillColor(sf::Color::Blue);
    sprite.setTextureRect(sf::IntRect(0, 0, 31.7, 31.7));
}

void Hero::Update() {
    sprite.setPosition(rect.getPosition());
}

void Hero::UpdateMovement() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        rect.move(0, -movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 31.7, 31.7*3, 31.7, 31.7));
        direction = 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        rect.move(0, movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 31.7, 0, 31.7, 31.7));
        direction = 2;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        rect.move(-movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 31.7, 31.7, 31.7, 31.7));
        direction = 3;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        rect.move(movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 31.7, 31.7*2, 31.7, 31.7));
        direction = 4;
    }

    counterWalking++;
    if (counterWalking == 2)
        counterWalking = 0;
}
