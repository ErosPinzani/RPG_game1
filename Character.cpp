//
// Created by erosp on 21/10/2020.
//

#include "Character.h"
#include "Map.h"

void Character::UpdateMovement() {
    sprite.setPosition(rect.getPosition());

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

bool Character::Walkable() {
    int x = rect.getPosition().x / 50;
    int y = rect.getPosition().y / 50;
    int pos = x + y * 48;
    Map::getInstance()->vectorM1;


}
