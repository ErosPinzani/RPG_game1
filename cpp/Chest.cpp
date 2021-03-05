//
// Created by erosp on 22/10/2020.
//

#include "../h/Chest.h"

Chest::Chest() {
    sprite.setTextureRect(sf::IntRect(0, 0, 47, 45));
    rect.setSize(sf::Vector2f(47, 45));
    rect.setPosition(100, 100);
    rect.setFillColor(sf::Color::Blue);

}

void Chest::Update() {
    sprite.setPosition(rect.getPosition());
}
