//
// Created by erosp on 22/10/2020.
//

#ifndef RPG_GAME_OBSTACLE_H
#define RPG_GAME_OBSTACLE_H

#include <SFML/Graphics.hpp>
using namespace std;

class Chest {
public:
    sf::RectangleShape rect;
    sf::Sprite sprite;
    sf::Text text;

    bool alive = true;
    int hp = 5;

    Chest();
    void Update();
};


#endif //RPG_GAME_OBSTACLE_H
