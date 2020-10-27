//
// Created by erosp on 22/10/2020.
//

#ifndef RPG_GAME_OBSTACLE_H
#define RPG_GAME_OBSTACLE_H


class Obstacle {
public:
    Obstacle(float posX, float posY, int hp);

    virtual ~Obstacle();

    void drop();

    float getPosX() const;

    void setPosX(float posX);

    float getPosY() const;

    void setPosY(float posY);

    int getHp() const;

    void setHp(int hp);

private:
    float posX;
    float posY;
    int hp;
};


#endif //RPG_GAME_OBSTACLE_H
