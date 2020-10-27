//
// Created by Francesco on 22/10/2020.
//

#ifndef RPG_GAME_POWERUP_H
#define RPG_GAME_POWERUP_H
#include <string>

class PowerUp {
public:
    PowerUp();

    virtual ~PowerUp();

    void addCoin();

    void heal();

private:
    enum type {coin, health};
};


#endif //RPG_GAME_POWERUP_H
