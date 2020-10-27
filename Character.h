//
// Created by Eros on 21/10/2020.
//

#ifndef RPG_GAME_CHARACTER_H
#define RPG_GAME_CHARACTER_H
#include <string>

class Character {
public:
    Character(const std::string &type, float posX, float posY, int hp, int damage, int strength, int armor, int speed);

    virtual void move(float posX, float posY) = 0;

    virtual void attack() = 0;

    const std::string &getType() const;

    void setType(const std::string &type);

    float getPosX() const;

    void setPosX(float posX);

    float getPosY() const;

    void setPosY(float posY);

    int getHp() const;

    void setHp(int hp);

    int getDamage() const;

    void setDamage(int damage);

    int getStrength() const;

    void setStrength(int strength);

    int getArmor() const;

    void setArmor(int armor);

    int getSpeed() const;

    void setSpeed(int speed);

protected:
    std::string type;
    float posX;
    float posY;
    int hp;
    int damage;
    int strength;
    int armor;
    int speed;
};


#endif //RPG_GAME_CHARACTER_H
