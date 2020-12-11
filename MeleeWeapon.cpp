//
// Created by Francesco on 22/10/2020.
//

#include "MeleeWeapon.h"

MeleeWeapon::MeleeWeapon() {
    rect.setSize(sf::Vector2f(48*3, 64*3));
    //rect.setPosition(750-72, 425-96);
    rect.setFillColor(sf::Color::Blue);
    //sprite.setTextureRect(sf::IntRect(0, 0, 48, 64));
}

void MeleeWeapon::Update() {
    sprite.setPosition(rect.getPosition());
}