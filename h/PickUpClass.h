//
// Created by Francesco on 22/10/2020.
//

#ifndef RPG_GAME_PICKUP_H
#define RPG_GAME_PICKUP_H

#include <SFML/Graphics.hpp>
using namespace std;

class PickUpClass {
public:
    sf::RectangleShape rect;
    sf::Sprite sprite;
    sf::Text text;

    bool isCoin = true;
    int coinValue = 5;
    bool destroy = false;
    int counterWalking = 0;

    void Update();

    PickUpClass();
};


#endif //RPG_GAME_PICKUP_H
