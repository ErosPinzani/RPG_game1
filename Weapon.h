//
// Created by Francesco on 22/10/2020.
//

#ifndef RPG_GAME_WEAPON_H
#define RPG_GAME_WEAPON_H
#include <string>

class Weapon {
public:
    virtual void shoot() = 0;

    const std::string &getType() const;

    void setType(const std::string &type);

protected:
    std::string type;
};


#endif //RPG_GAME_WEAPON_H
