//
// Created by Francesco on 22/10/2020.
//

#ifndef RPG_GAME_BULLET_H
#define RPG_GAME_BULLET_H

#include <SFML/Graphics.hpp>

class Bullet {
public:
    sf::RectangleShape rect;
    sf::Sprite sprite;

    int movementSpeed;
    int attackDamage;
    int direction = 0; //1 - up, 2 - down, 3 - left, 4 - right
    bool destroy = false;
    int counterLifetime = 0;
    int lifetime = 100;

    virtual void Update() = 0;
};


#endif //RPG_GAME_BULLET_H