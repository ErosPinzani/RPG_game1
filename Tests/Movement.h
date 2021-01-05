//
// Created by erosp on 05/01/2021.
//

#ifndef MAIN_CPP_MOVEMENT_H
#define MAIN_CPP_MOVEMENT_H

#include "gtest/gtest.h"
#include "../Hero.h"

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
}

#endif //MAIN_CPP_MOVEMENT_H
