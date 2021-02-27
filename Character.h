//
// Created by Eros on 21/10/2020.
//

#ifndef RPG_GAME_CHARACTER_H
#define RPG_GAME_CHARACTER_H

#include <SFML/Graphics.hpp>
using namespace std;

class Character {
public:
    sf::RectangleShape rect;
    sf::Sprite sprite;
    sf::Text text;

    // getters
    int getHp();
    int getMaxhp();
    float getMovementSpeed();
    int getAttackDamage();
    int getCounterWalking();
    int getDirection();

    virtual void UpdateMovement(bool testing = false, sf::Keyboard::Key key = sf::Keyboard::D);
    bool Walkable(int direction);

    int hp;
    int maxhp;
    float movementSpeed;
    int attackDamage;
    int counterWalking = 0;
    int U = 1;
    int D = 2;
    int L = 3;
    int R = 4;
    int direction = 0; //1 - up, 2 - down, 3 - left, 4 - right
    //std::string direction;

protected:

    // setters
    void setHp(int hp);
    void setMaxhp(int maxhp);
    void setMovementSpeed(float movementSpeeed);
    void setAttackDamage(int attackDamage);
    void setCounterWalking(int counterWalking);
    void setDirection(int direction);

};


#endif //RPG_GAME_CHARACTER_H
