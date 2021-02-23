//
// Created by erosp on 11/02/2021.
//

#ifndef ENEMY_CPP_COLLISIONS_H
#define ENEMY_CPP_COLLISIONS_H

#include "gtest/gtest.h"
#include "../Hero.h"
#include "../Enemy.h"
#include "../Map.h"
#include "../Chest.h"
#include "../AoeBullet.h"

TEST(Collision, WallCollision){
    Map::getInstance()->vectorM1 = std::vector<int> {
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,0,0,1,0,1,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,1,1,1,1,0,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,1,1,1,1,
    1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,
    1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,0,1,1,0,0,0,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,
    1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,0,0,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,
    1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
    };

    AoeBullet Bullet1;
    Bullet1.rect.setPosition(100, 100);

    Bullet1.direction = 3;
    ASSERT_EQ((int)Bullet1.rect.getPosition().x, 100);
    ASSERT_EQ((int)Bullet1.rect.getPosition().y, 100);
    Bullet1.Update();
    ASSERT_EQ((int)Bullet1.rect.getPosition().x, 100 - Bullet1.movementSpeed);
    ASSERT_EQ((int)Bullet1.rect.getPosition().y, 100);

    Bullet1.direction = 4;
    Bullet1.Update();
    ASSERT_EQ((int)Bullet1.rect.getPosition().x, 100);
    ASSERT_EQ((int)Bullet1.rect.getPosition().y, 100);

    Bullet1.direction = 2;
    Bullet1.Update();
    ASSERT_EQ((int)Bullet1.rect.getPosition().x, 100);
    ASSERT_EQ((int)Bullet1.rect.getPosition().y, 100 + Bullet1.movementSpeed);

    Bullet1.direction = 1;
    Bullet1.Update();
    ASSERT_EQ((int)Bullet1.rect.getPosition().x, 100);
    ASSERT_EQ((int)Bullet1.rect.getPosition().y, 100);

    for (int i = 0; i < 100; i++)
        Bullet1.Update();
    ASSERT_EQ((int)Bullet1.destroy, true);



    Map::getInstance()->vectorM1 = std::vector<int> {
            1,1,1,1,1,1,1,1,1,1,1,1,
            1,0,0,0,0,0,0,0,0,0,0,1,
            1,0,0,0,0,0,0,0,0,0,0,1,
            1,0,0,0,0,0,0,0,0,0,0,1,
            1,0,0,0,0,0,0,0,0,0,0,1,
            1,1,1,1,1,1,1,1,1,1,1,1
    };
    Bullet1.rect.setPosition(100, 100);
    Bullet1.destroy = false;

    Bullet1.direction = 3;
    ASSERT_EQ((int)Bullet1.rect.getPosition().x, 100);
    ASSERT_EQ((int)Bullet1.rect.getPosition().y, 100);
    Bullet1.Update();
    ASSERT_EQ((int)Bullet1.rect.getPosition().x, 100 - Bullet1.movementSpeed);
    ASSERT_EQ((int)Bullet1.rect.getPosition().y, 100);

    Bullet1.direction = 4;
    Bullet1.Update();
    ASSERT_EQ((int)Bullet1.rect.getPosition().x, 100);
    ASSERT_EQ((int)Bullet1.rect.getPosition().y, 100);

    Bullet1.direction = 2;
    Bullet1.Update();
    ASSERT_EQ((int)Bullet1.rect.getPosition().x, 100);
    ASSERT_EQ((int)Bullet1.rect.getPosition().y, 100 + Bullet1.movementSpeed);

    Bullet1.direction = 1;
    Bullet1.Update();
    ASSERT_EQ((int)Bullet1.rect.getPosition().x, 100);
    ASSERT_EQ((int)Bullet1.rect.getPosition().y, 100);

    for (int i = 0; i < 100; i++)
        Bullet1.Update();
    ASSERT_EQ((int)Bullet1.destroy, true);
}

TEST(Collision, EnemyCollision){
    AoeBullet Bullet1;
    Enemy Enemy1;

    Enemy1.rect.setPosition(50, 100);
    Bullet1.rect.setPosition(100, 100);

    int initHp = Enemy1.hp;
    Bullet1.attackDamage = 5;
    Bullet1.direction = 3;
    for (int i = 0; i < 5; i++) {
        std::cout<<Enemy1.hp<<endl;
        Bullet1.Update();
    }
    ASSERT_EQ((int)Bullet1.destroy, true);
    ASSERT_EQ(Enemy1.hp, initHp - Bullet1.attackDamage);
}

#endif //ENEMY_CPP_COLLISIONS_H
