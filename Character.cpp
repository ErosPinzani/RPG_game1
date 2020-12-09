//
// Created by erosp on 21/10/2020.
//

#include "Character.h"
#include "Map.h"

void Character::UpdateMovement() {
    sprite.setPosition(rect.getPosition());

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && Character::Walkable(1)){
        rect.move(0, -movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 31.7, 31.7*3, 31.7, 31.7));
        direction = 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Character::Walkable(2)){
        rect.move(0, movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 31.7, 0, 31.7, 31.7));
        direction = 2;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && Character::Walkable(3)){
        rect.move(-movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 31.7, 31.7, 31.7, 31.7));
        direction = 3;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && Character::Walkable(4)){
        rect.move(movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 31.7, 31.7*2, 31.7, 31.7));
        direction = 4;
    }

    counterWalking++;
    if (counterWalking == 2)
        counterWalking = 0;
}

bool Character::Walkable (int direction) {
    int x =  rect.getPosition().x;
    int y = rect.getPosition().y;
    if (direction == 1){
        x = x / 50;
        y = (y - movementSpeed) / 50;
    }
    if (direction == 2){
        x = (x + sprite.getTextureRect().width) / 50;
        y = (y + sprite.getTextureRect().height + movementSpeed) / 50;
    }
    if (direction == 3){
        x = (x - movementSpeed) / 50;
        y = y / 50;
    }
    if (direction == 4){
        x = (x + sprite.getTextureRect().width + movementSpeed) / 50;
        y = (y + sprite.getTextureRect().height) / 50;
    }
    int pos = (y * 48) + x ;
    if (Map::getInstance()->vectorM1[pos] == 0)
        return true;
}