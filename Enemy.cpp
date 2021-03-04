//
// Created by erosp on 22/10/2020.
//

#include "Enemy.h"

Enemy::Enemy() {
    setHp(15);
    setMaxhp(15);
    setMovementSpeed(2);
    setAttackDamage(2);

    rect.setSize(sf::Vector2f(31.7, 31.7));
    rect.setPosition(75, 42);
    rect.setFillColor(sf::Color::Blue);
    sprite.setTextureRect(sf::IntRect(0, 31.7*2, 31.7, 31.7));
}

void Enemy::UpdateMovement(bool testing, sf::Keyboard::Key key) {
    sprite.setPosition(rect.getPosition());
    text.setPosition(rect.getPosition().x - rect.getSize().x/2 - 5, rect.getPosition().y - rect.getSize().y/2 - 5);
    if (direction == up && Character::Walkable(up)){ //up
        rect.move(0, -movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 31.7, 31.7*3, 31.7, 31.7));
    }

    else if (direction == down && Character::Walkable(down)){ //down
        rect.move(0, movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 31.7, 0, 31.7, 31.7));
    }

    else if (direction == left && Character::Walkable(left)){ //left
        rect.move(-movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 31.7, 31.7, 31.7, 31.7));
    }

    else if (direction == right && Character::Walkable(right)){ //right
        rect.move(movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 31.7, 31.7*2, 31.7, 31.7));
    }

    counterWalking++;
    if (counterWalking == 2)
        counterWalking = 0;

    counter++;
    if (counter >= movementLength) {
        direction = static_cast<Direction>(generateRandom(20));
        counter = 0;
    }
}