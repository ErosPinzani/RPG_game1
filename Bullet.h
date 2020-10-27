//
// Created by Francesco on 22/10/2020.
//

#ifndef RPG_GAME_BULLET_H
#define RPG_GAME_BULLET_H
#include <string>

class Bullet {
public:
    Bullet(const std::string &type, float posX, float posY, float range, int speed, int power, bool hit);

    void move(float posX,float posY);

    const std::string &getType() const;

    void setType(const std::string &type);

    float getPosX() const;

    void setPosX(float posX);

    float getPosY() const;

    void setPosY(float posY);

    float getRange() const;

    void setRange(float range);

    int getSpeed() const;

    void setSpeed(int speed);

    int getPower() const;

    void setPower(int power);

    bool isHit() const;

    void setHit(bool hit);

private:
    std::string type;
    float posX;
    float posY;
    float range;
    int speed;
    int power;
    bool hit;
};


#endif //RPG_GAME_BULLET_H
