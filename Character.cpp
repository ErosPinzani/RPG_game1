//
// Created by erosp on 21/10/2020.
//

#include "Character.h"
#include "Map.h"

void Character::UpdateMovement(bool testing, sf::Keyboard::Key key) {
    sprite.setPosition(rect.getPosition());

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) && Character::Walkable(up))
    || (testing && key == sf::Keyboard::W  && Character::Walkable(up))){
        rect.move(0, -movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 31.7, 31.7*3, 31.7, 31.7));
        setDirection(up);
    }

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Character::Walkable(down))
        || (testing && key == sf::Keyboard::S  && Character::Walkable(down))){
        rect.move(0, movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 31.7, 0, 31.7, 31.7));
        setDirection(down);
    }

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) && Character::Walkable(left))
        || (testing && key == sf::Keyboard::A  && Character::Walkable(left))){
        rect.move(-movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 31.7, 31.7, 31.7, 31.7));
        setDirection(left);
    }

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) && Character::Walkable(right))
        || (testing && key == sf::Keyboard::D  && Character::Walkable(right))){
        rect.move(movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 31.7, 31.7*2, 31.7, 31.7));
        setDirection(right);
    }

    counterWalking++;
    if (counterWalking == 2)
        counterWalking = 0;
}

bool Character::Walkable (int direction) {
    int x =  rect.getPosition().x;
    int y = rect.getPosition().y;
    if (direction == up){
        x = x / 50;
        y = (y - movementSpeed) / 50;
    }
    if (direction == down){
        x = (x + sprite.getTextureRect().width) / 50;
        y = (y + sprite.getTextureRect().height + movementSpeed) / 50;
    }
    if (direction == left){
        x = (x - movementSpeed) / 50;
        y = y / 50;
    }
    if (direction == right){
        x = (x + sprite.getTextureRect().width + movementSpeed) / 50;
        y = (y + sprite.getTextureRect().height) / 50;
    }
    int pos = (y * 48) + x ;
    if (Map::getInstance()->vectorM1[pos] == 0)
        return true;
    return false;
}

// getters
int Character::getMaxhp() {return Character::maxhp;}
int Character::getAttackDamage() {return Character::attackDamage;}
int Character::getDirection() {return Character::direction;}

// setters
void Character::setHp(int hp) {Character::hp = hp;}
void Character::setMaxhp(int maxhp) {Character::maxhp = maxhp;}
void Character::setMovementSpeed(float movementSpeeed) {Character::movementSpeed = movementSpeeed;}
void Character::setAttackDamage(int attackDamage) {Character::attackDamage = attackDamage;}
void Character::setDirection(Character::Direction direction) {Character::direction = direction;}
