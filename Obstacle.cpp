//
// Created by erosp on 22/10/2020.
//

#include "Obstacle.h"

Obstacle::Obstacle() {
    hp=5;
    sprite.setTextureRect(sf::IntRect(0, 0, 47, 45));
    sprite.setPosition(100, 100);
    rect.setFillColor(sf::Color::Blue);
}

void Obstacle::Update() {

}
