//
// Created by erosp on 21/10/2020.
//

#include "Character.h"
#include "Map.h"

void Character::UpdateMovement(bool testing, sf::Keyboard::Key key) {
    sprite.setPosition(rect.getPosition());

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::W) && Character::Walkable(U))
    || (testing && key == sf::Keyboard::W  && Character::Walkable(U))){
        rect.move(0, -movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 31.7, 31.7*3, 31.7, 31.7));
        direction = U;
    }

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Character::Walkable(D))
        || (testing && key == sf::Keyboard::S  && Character::Walkable(D))){
        rect.move(0, movementSpeed);
        sprite.setTextureRect(sf::IntRect(counterWalking * 31.7, 0, 31.7, 31.7));
        direction = D;
    }

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::A) && Character::Walkable(L))
        || (testing && key == sf::Keyboard::A  && Character::Walkable(L))){
        rect.move(-movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 31.7, 31.7, 31.7, 31.7));
        direction = L;
    }

    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::D) && Character::Walkable(R))
        || (testing && key == sf::Keyboard::D  && Character::Walkable(R))){
        rect.move(movementSpeed, 0);
        sprite.setTextureRect(sf::IntRect(counterWalking * 31.7, 31.7*2, 31.7, 31.7));
        direction = R;
    }

    counterWalking++;
    if (counterWalking == 2)
        counterWalking = 0;
}

bool Character::Walkable (int direction) {
    int x =  rect.getPosition().x;
    int y = rect.getPosition().y;
    if (direction == U){
        x = x / 50;
        y = (y - movementSpeed) / 50;
    }
    if (direction == D){
        x = (x + sprite.getTextureRect().width) / 50;
        y = (y + sprite.getTextureRect().height + movementSpeed) / 50;
    }
    if (direction == L){
        x = (x - movementSpeed) / 50;
        y = y / 50;
    }
    if (direction == R){
        x = (x + sprite.getTextureRect().width + movementSpeed) / 50;
        y = (y + sprite.getTextureRect().height) / 50;
    }
    int pos = (y * 48) + x ;
    if (Map::getInstance()->vectorM1[pos] == 0)
        return true;
    return false;
}

// getters
int Character::getHp() {return Character::hp;}
int Character::getMaxhp() {return Character::maxhp;}
float Character::getMovementSpeed() {return Character::movementSpeed;}
int Character::getAttackDamage() {return Character::attackDamage;}
int Character::getCounterWalking() {return Character::counterWalking;}
int Character::getDirection() {return Character::direction;}

// setters
void Character::setHp(int hp) {Character::hp = hp;}
void Character::setMaxhp(int maxhp) {Character::maxhp = maxhp;}
void Character::setMovementSpeed(float movementSpeeed) {Character::movementSpeed = movementSpeeed;}
void Character::setAttackDamage(int attackDamage) {Character::attackDamage = attackDamage;}
void Character::setCounterWalking(int counterWalking) {Character::counterWalking = counterWalking;}
void Character::setDirection(int direction) {Character::direction = direction;}