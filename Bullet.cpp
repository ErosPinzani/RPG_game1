//
// Created by Francesco on 22/10/2020.
//

#include "Bullet.h"
#include "Map.h"

void Bullet::Update() {
    Bullet::Walkable(direction);
    if (direction == 1) //up
        rect.move(0, -movementSpeed);
    if (direction == 2) //down
        rect.move(0, movementSpeed);
    if (direction == 3) //left
        rect.move(-movementSpeed, 0);
    if (direction == 4) //right
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
    if (Map::getInstance()->vectorM1[pos] == 1)
        destroy = true;
}