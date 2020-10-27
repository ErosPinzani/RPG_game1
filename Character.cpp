//
// Created by erosp on 21/10/2020.
//

#include "Character.h"

const std::string &Character::getType() const {
    return type;
}

void Character::setType(const std::string &type) {
    Character::type = type;
}

float Character::getPosX() const {
    return posX;
}

void Character::setPosX(float posX) {
    Character::posX = posX;
}

float Character::getPosY() const {
    return posY;
}

void Character::setPosY(float posY) {
    Character::posY = posY;
}

int Character::getHp() const {
    return hp;
}

void Character::setHp(int hp) {
    Character::hp = hp;
}

int Character::getDamage() const {
    return damage;
}

void Character::setDamage(int damage) {
    Character::damage = damage;
}

int Character::getStrength() const {
    return strength;
}

void Character::setStrength(int strength) {
    Character::strength = strength;
}

int Character::getArmor() const {
    return armor;
}

void Character::setArmor(int armor) {
    Character::armor = armor;
}

int Character::getSpeed() const {
    return speed;
}

void Character::setSpeed(int speed) {
    Character::speed = speed;
}

Character::Character(const std::string &type, float posX, float posY, int hp, int damage, int strength, int armor,
                     int speed) : type(type), posX(posX), posY(posY), hp(hp), damage(damage), strength(strength),
                                  armor(armor), speed(speed) {}
