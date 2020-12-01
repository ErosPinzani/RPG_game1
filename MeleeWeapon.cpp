//
// Created by Francesco on 22/10/2020.
//

#include "MeleeWeapon.h"

MeleeWeapon::MeleeWeapon() {
    rect.setSize(sf::Vector2f(48*3, 64*3));
    rect.setPosition(750-72, 425-96);
    rect.setFillColor(sf::Color::Transparent);
    //sprite.setTextureRect(sf::IntRect(0, 0, 48, 64));
}

void MeleeWeapon::Update() {
    sprite.setPosition(rect.getPosition());
}

void MeleeWeapon::UpdateMovement() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        rect.move(0, -movementSpeed);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        rect.move(0, movementSpeed);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        rect.move(-movementSpeed, 0);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        rect.move(movementSpeed, 0);
    }
}