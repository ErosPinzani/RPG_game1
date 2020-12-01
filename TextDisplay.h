//
// Created by erosp on 01/12/2020.
//

#ifndef RPG_GAME_TEXTDISPLAY_H
#define RPG_GAME_TEXTDISPLAY_H


#include "Character.h"

class TextDisplay: public Character {
public:
    string myString;
    int counter = 0;
    int lifeTime = 100;
    bool destroy = false;

    TextDisplay();
    void Update();
};


#endif //RPG_GAME_TEXTDISPLAY_H
