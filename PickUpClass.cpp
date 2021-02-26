//
// Created by Francesco on 22/10/2020.
//

#include "PickUpClass.h"

PickUpClass::PickUpClass() {
    rect.setSize(sf::Vector2f(20, 20));
    rect.setPosition(0, 0);
    rect.setFillColor(sf::Color::Yellow);
}

void PickUpClass::Update() {
    sprite.setPosition(rect.getPosition());

    sprite.setTextureRect(sf::IntRect(counterWalking * 20.6, 0, 20.6, 20));

    counterWalking++;
    if (counterWalking == 9)
        counterWalking = 0;
}
