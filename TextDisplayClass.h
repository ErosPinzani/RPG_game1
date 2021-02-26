//
// Created by erosp on 01/12/2020.
//

#ifndef RPG_GAME_TEXTDISPLAY_H
#define RPG_GAME_TEXTDISPLAY_H

#include "SFML/Graphics.hpp"

class TextDisplayClass {
public:
    sf::RectangleShape rect;
    sf::Sprite sprite;
    sf::Text text;
    std::string myString;
    int counter = 0;
    int lifeTime = 100;
    int movementSpeed = 1;
    bool destroy = false;

    TextDisplayClass();
    void Update();
};


#endif //RPG_GAME_TEXTDISPLAY_H
