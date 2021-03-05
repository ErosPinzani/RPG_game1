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
    int getMaxhp();
    int getAttackDamage();
    int getDirection();

    virtual void UpdateMovement(bool testing = false, sf::Keyboard::Key key = sf::Keyboard::D);
    bool Walkable(int direction);

    int hp;
    int counterWalking = 0;
    enum Direction {
        up,
        down,
        left,
        right
    };
    Direction direction;

protected:
    int attackDamage;
    int maxhp;
    float movementSpeed;

    // setters
    void setHp(int hp);
    void setMaxhp(int maxhp);
    void setMovementSpeed(float movementSpeeed);
    void setAttackDamage(int attackDamage);
    void setDirection(Direction direction);

};


#endif //RPG_GAME_CHARACTER_H
