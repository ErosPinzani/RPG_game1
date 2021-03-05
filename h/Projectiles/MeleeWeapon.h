//
// Created by Francesco on 22/10/2020.
//

#ifndef RPG_GAME_MELEEWEAPON_H
#define RPG_GAME_MELEEWEAPON_H

#include <SFML/Graphics.hpp>

class MeleeWeapon {
public:
    sf::RectangleShape rect;
    sf::Sprite sprite;

    float movementSpeed = 5;
    int attackDamage = 5;

    MeleeWeapon();
    void Update();
};


#endif //RPG_GAME_MELEEWEAPON_H
