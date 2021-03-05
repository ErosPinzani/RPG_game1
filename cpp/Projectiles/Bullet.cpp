//
// Created by Francesco on 22/10/2020.
//

#include "../../h/Projectiles/Bullet.h"
#include "../../h/Map.h"

void Bullet::Update() {
    Bullet::Walkable(direction);
    if (direction == up) //up
        rect.move(0, -movementSpeed);
    if (direction == down) //down
        rect.move(0, movementSpeed);
    if (direction == left) //left
        rect.move(-movementSpeed, 0);
    if (direction == right) //right
        rect.move(movementSpeed, 0);

    //lifetime
    counterLifetime++;
    if (counterLifetime >= lifetime)
        destroy = true;

    //sprite
    sprite.setPosition(rect.getPosition());
}

void Bullet::Walkable (int direction) {
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
    if (Map::getInstance()->vectorM1[pos] == 1)
        destroy = true;
}

//getters
int Bullet::getAttackDamage() {return Bullet::attackDamage;}

//setters
void Bullet::setMovementSpeed(int movementSpeed) {Bullet::movementSpeed = movementSpeed;}
void Bullet::setAttackDamage(int attackDamage) {Bullet::attackDamage = attackDamage;}