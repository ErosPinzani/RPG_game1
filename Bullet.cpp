//
// Created by Francesco on 22/10/2020.
//

#include "Bullet.h"

const std::string &Bullet::getType() const {
    return type;
}

void Bullet::setType(const std::string &type) {
    Bullet::type = type;
}

float Bullet::getPosX() const {
    return posX;
}

void Bullet::setPosX(float posX) {
    Bullet::posX = posX;
}

float Bullet::getPosY() const {
    return posY;
}

void Bullet::setPosY(float posY) {
    Bullet::posY = posY;
}

float Bullet::getRange() const {
    return range;
}

void Bullet::setRange(float range) {
    Bullet::range = range;
}

int Bullet::getSpeed() const {
    return speed;
}

void Bullet::setSpeed(int speed) {
    Bullet::speed = speed;
}

int Bullet::getPower() const {
    return power;
}

void Bullet::setPower(int power) {
    Bullet::power = power;
}

bool Bullet::isHit() const {
    return hit;
}

void Bullet::setHit(bool hit) {
    Bullet::hit = hit;
}

void Bullet::move(float posX, float posY) {

}

Bullet::Bullet(const std::string &type, float posX, float posY, float range, int speed, int power, bool hit) : type(
        type), posX(posX), posY(posY), range(range), speed(speed), power(power), hit(hit) {}

Bullet::~Bullet() {

}
