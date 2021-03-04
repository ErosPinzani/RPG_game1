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

    //getters
    int getAttackDamage();

    bool destroy = false;
    int counterLifetime = 0;

    enum Direction {
        up,
        down,
        left,
        right
    };
    Direction direction;

    virtual void Update();
    void Walkable(int direction);


protected:
    int movementSpeed;
    int attackDamage;
    int lifetime = 100;

    //setters
    void setMovementSpeed(int movementSpeed);
    void setAttackDamage(int attackDamage);

};


#endif //RPG_GAME_BULLET_H