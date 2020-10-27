//
// Created by erosp on 22/10/2020.
//

#include "Obstacle.h"

float Obstacle::getPosX() const {
    return posX;
}

void Obstacle::setPosX(float posX) {
    Obstacle::posX = posX;
}

float Obstacle::getPosY() const {
    return posY;
}

void Obstacle::setPosY(float posY) {
    Obstacle::posY = posY;
}

int Obstacle::getHp() const {
    return hp;
}

void Obstacle::setHp(int hp) {
    Obstacle::hp = hp;
}

void Obstacle::drop() {

}

Obstacle::Obstacle(float posX, float posY, int hp) : posX(posX), posY(posY), hp(hp) {}
