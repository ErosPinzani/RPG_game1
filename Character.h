//
// Created by Eros on 21/10/2020.
//

#ifndef RPG_GAME_CHARACTER_H
#define RPG_GAME_CHARACTER_H

#include <SFML/Graphics.hpp>
using namespace std;

class Character {
public:
    sf::RectangleShape rect;
    sf::Sprite sprite;
    sf::Text text;
    int hp;
    float movementSpeed;
    int attackDamage;
    int counterWalking = 0;
    int direction = 0; //1 - up, 2 - down, 3 - left, 4 - right

    virtual void UpdateMovement();
    bool Walkable(int direction);

};


#endif //RPG_GAME_CHARACTER_H
