//
// Created by erosp on 05/01/2021.
//

#ifndef MAIN_CPP_MOVEMENT_H
#define MAIN_CPP_MOVEMENT_H

#include "gtest/gtest.h"
#include "../Hero.h"
#include "../Map.h"

TEST(Character, Movement) {
    Hero Hero1;

    ASSERT_EQ((int)Hero1.rect.getPosition().x, 200-24);
    ASSERT_EQ((int)Hero1.rect.getPosition().y, 200-32);

    ASSERT_EQ(Hero1.Walkable(4), true);
    Hero1.UpdateMovement(true);
    ASSERT_EQ((int)Hero1.rect.getPosition().x, 200-24 + Hero1.movementSpeed);
    ASSERT_EQ((int)Hero1.rect.getPosition().y, 200-32);

    ASSERT_EQ(Hero1.Walkable(3), true);
    Hero1.UpdateMovement(true, sf::Keyboard::A);
    ASSERT_EQ((int)Hero1.rect.getPosition().x, 200-24);
    ASSERT_EQ((int)Hero1.rect.getPosition().y, 200-32);

    ASSERT_EQ(Hero1.Walkable(2), true);
    Hero1.UpdateMovement(true, sf::Keyboard::S);
    ASSERT_EQ((int)Hero1.rect.getPosition().x, 200-24);
    ASSERT_EQ((int)Hero1.rect.getPosition().y, 200-32 + Hero1.movementSpeed);

    ASSERT_EQ(Hero1.Walkable(1), true);
    Hero1.UpdateMovement(true, sf::Keyboard::W);
    ASSERT_EQ((int)Hero1.rect.getPosition().x, 200-24);
    ASSERT_EQ((int)Hero1.rect.getPosition().y, 200-32);

    for (int i = 0; i < 100; i++)
        Hero1.UpdateMovement(true, sf::Keyboard::S);
    ASSERT_EQ((int)Hero1.rect.getPosition().y, 268);


    Map::getInstance()->vectorM1 = std::vector<int> {
            1,1,1,1,1,1,1,1,1,1,1,1,
            1,0,0,0,0,0,0,0,0,0,0,1,
            1,0,0,0,0,0,0,0,0,0,0,1,
            1,0,0,0,0,0,0,0,0,0,0,1,
            1,0,0,0,0,0,0,0,0,0,0,1,
            1,1,1,1,1,1,1,1,1,1,1,1
    };


    ASSERT_EQ((int)Hero1.rect.getPosition().x, 200-24);
    ASSERT_EQ((int)Hero1.rect.getPosition().y, 268);

    ASSERT_EQ(Hero1.Walkable(4), false);
    Hero1.UpdateMovement(true);
    ASSERT_EQ((int)Hero1.rect.getPosition().x, 176);
    ASSERT_EQ((int)Hero1.rect.getPosition().y, 268);

    ASSERT_EQ(Hero1.Walkable(3), false);
    Hero1.UpdateMovement(true, sf::Keyboard::A);
    ASSERT_EQ((int)Hero1.rect.getPosition().x, 176);
    ASSERT_EQ((int)Hero1.rect.getPosition().y, 268);

    ASSERT_EQ(Hero1.Walkable(2), true);
    Hero1.UpdateMovement(true, sf::Keyboard::S);
    ASSERT_EQ((int)Hero1.rect.getPosition().x, 176);
    ASSERT_EQ((int)Hero1.rect.getPosition().y, 273);

    ASSERT_EQ(Hero1.Walkable(1), false);
    Hero1.UpdateMovement(true, sf::Keyboard::W);
    ASSERT_EQ((int)Hero1.rect.getPosition().x, 176);
    ASSERT_EQ((int)Hero1.rect.getPosition().y, 273);

    for (int i = 0; i < 100; i++)
        Hero1.UpdateMovement(true, sf::Keyboard::S);
    ASSERT_EQ((int)Hero1.rect.getPosition().y, 773);
}

#endif //MAIN_CPP_MOVEMENT_H
