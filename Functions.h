//
// Created by erosp on 27/02/2021.
//

#ifndef MAIN_CPP_FUNCTIONS_H
#define MAIN_CPP_FUNCTIONS_H

#include "Hero.h"
#include "PickUpClass.h"
#include "Enemy.h"
#include "TextDisplayClass.h"
#include "AoeBullet.h"
#include "Chest.h"
// Add a short alias for std::shared_ptr to the current environment
template <class T> using sptr = std::shared_ptr<T>;





void item_collision(Hero &Hero, vector<sptr<PickUpClass>> &pickUpArray);
void enemy_collision_player(Hero &Hero, vector<sptr<Enemy>> &enemyArray, TextDisplayClass &TextDisplay, vector<sptr<TextDisplayClass>> &textDisplayArray, sf::Clock &clock);
void aoe_collision(vector<sptr<AoeBullet>> &AoeBulletArray, vector<sptr<Enemy>> &enemyArray, vector<sptr<Chest>> &chestArray, TextDisplayClass &TextDisplay, vector<sptr<TextDisplayClass>> &textDisplayArray);
void aggro(vector<sptr<Enemy>> &enemyArray, Hero &Hero, sf::Clock &clock);
void delete_enemy(vector<sptr<Enemy>> &enemyArray, PickUpClass &PickUp, vector<sptr<PickUpClass>> &pickUpArray, Enemy &Blood, vector<sptr<Enemy>> &bloodArray);
void delete_AoeBullet(vector<sptr<AoeBullet>> &AoeBulletArray);
void delete_text(vector<sptr<TextDisplayClass>> &textDisplayArray);
void delete_chest(vector<sptr<Chest>> &chestArray, Chest &OpenChest, vector<sptr<Chest>> &openChestArray, PickUpClass &PickUp, vector<sptr<PickUpClass>> &pickUpArray);
void delete_PickUp_items(vector<sptr<PickUpClass>> &pickUpArray);
void draw(vector<sptr<Enemy>> &bloodArray, vector<sptr<Chest>> &chestArray, vector<sptr<Chest>> &openChestArray, vector<sptr<PickUpClass>> &pickUpArray, vector<sptr<AoeBullet>> &AoeBulletArray, vector<sptr<Enemy>> &enemyArray, vector<sptr<TextDisplayClass>> &textDisplayArray, Hero &Hero, sf::RenderWindow &window);


void item_collision(Hero &Hero, vector<sptr<PickUpClass>> &pickUpArray){
    vector<sptr<PickUpClass>>::const_iterator iter;
    int counter = 0;
    for (iter = pickUpArray.begin(); iter != pickUpArray.end(); iter++) {
        if (Hero.rect.getGlobalBounds().intersects(pickUpArray[counter]->rect.getGlobalBounds())) {
            if (pickUpArray[counter]->isCoin)
                Hero.coins += pickUpArray[counter]->coinValue;
            pickUpArray[counter]->destroy = true;
        }
        counter++;
    }
}

void enemy_collision_player(Hero &Hero, vector<sptr<Enemy>> &enemyArray, TextDisplayClass &TextDisplay, vector<sptr<TextDisplayClass>> &textDisplayArray, sf::Clock &clock){
    vector<sptr<Enemy>>::const_iterator iter;
    sf::Time elapsed = clock.getElapsedTime();

    if (elapsed.asSeconds() >= 0.5) {
        clock.restart();
        int counter = 0;
        for (iter = enemyArray.begin(); iter != enemyArray.end(); iter++) {
            if (Hero.rect.getGlobalBounds().intersects(enemyArray[counter]->rect.getGlobalBounds())) {

                //text display
                TextDisplay.text.setString(to_string(enemyArray[counter]->attackDamage));
                TextDisplay.text.setPosition(Hero.rect.getPosition().x + Hero.rect.getSize().x / 2,Hero.rect.getPosition().y - Hero.rect.getSize().y / 2);
                textDisplayArray.push_back(std::make_shared<TextDisplayClass>(TextDisplay));

                Hero.hp -= enemyArray[counter]->attackDamage;
            }
            counter++;
        }
    }
}


void aoe_collision(vector<sptr<AoeBullet>> &AoeBulletArray, vector<sptr<Enemy>> &enemyArray, vector<sptr<Chest>> &chestArray, TextDisplayClass &TextDisplay, vector<sptr<TextDisplayClass>> &textDisplayArray){
    vector<sptr<AoeBullet>>::const_iterator iter;
    vector<sptr<Enemy>>::const_iterator iter1;
    vector<sptr<Chest>>::const_iterator iter2;
    int counter = 0;
    for (iter = AoeBulletArray.begin(); iter != AoeBulletArray.end(); iter++) {
        int counter2 = 0;
        int counter3 = 0;
        for (iter1 = enemyArray.begin(); iter1 !=enemyArray.end(); iter1++) {
            if (AoeBulletArray[counter]->rect.getGlobalBounds().intersects(enemyArray[counter2]->rect.getGlobalBounds())){
                AoeBulletArray[counter]->destroy = true;

                //text display
                TextDisplay.text.setString(to_string(AoeBulletArray[counter]->attackDamage));
                TextDisplay.text.setPosition(enemyArray[counter2]->rect.getPosition().x + enemyArray[counter2]->rect.getSize().x / 2,enemyArray[counter2]->rect.getPosition().y - enemyArray[counter2]->rect.getSize().y / 2);
                textDisplayArray.push_back(std::make_shared<TextDisplayClass>(TextDisplay));

                enemyArray[counter2]->hp -= AoeBulletArray[counter]->attackDamage;
                if (enemyArray[counter2]->hp <= 0)
                    enemyArray[counter2]->alive = false;

                //aggro
                enemyArray[counter2]->aggro = true;
            }
            counter2++;
        }

        //chest collision
        for (iter2 = chestArray.begin(); iter2 != chestArray.end(); iter2++) {
            if (AoeBulletArray[counter]->rect.getGlobalBounds().intersects(chestArray[counter3]->rect.getGlobalBounds())) {
                AoeBulletArray[counter]->destroy = true;
                chestArray[counter3]->hp -= AoeBulletArray[counter]->attackDamage;
                if (chestArray[counter3]->hp <= 0)
                    chestArray[counter3]->alive = false;
            }
            counter3++;
        }
        counter++;
    }
}

void aggro(vector<sptr<Enemy>> &enemyArray, Hero &Hero, sf::Clock &clock){
    vector<sptr<Enemy>>::const_iterator iter;
    sf::Time elapsed = clock.getElapsedTime();
    int counter = 0;
    for (iter = enemyArray.begin(); iter != enemyArray.end(); iter++) {
        if (enemyArray[counter]->aggro) {
            if (elapsed.asSeconds() >= 0.05) {
                clock.restart();
                int tempRand = generateRandom(3);
                if (tempRand == 1) {

                    //hero to up
                    if ((Hero.rect.getPosition().x < enemyArray[counter]->rect.getPosition().x) && (abs(Hero.rect.getPosition().y - enemyArray[counter]->rect.getPosition().y) <= 40)) {
                        enemyArray[counter]->direction = 1;
                    }
                    //hero to down
                    if ((Hero.rect.getPosition().x < enemyArray[counter]->rect.getPosition().x) && (abs(Hero.rect.getPosition().y - enemyArray[counter]->rect.getPosition().y) <= 40)) {
                        enemyArray[counter]->direction = 2;
                    }
                    //hero to right
                    if ((Hero.rect.getPosition().x < enemyArray[counter]->rect.getPosition().x) && (abs(Hero.rect.getPosition().y - enemyArray[counter]->rect.getPosition().y) <= 40)) {
                        enemyArray[counter]->direction = 3;
                    }
                    //hero to left
                    if ((Hero.rect.getPosition().x < enemyArray[counter]->rect.getPosition().x) && (abs(Hero.rect.getPosition().y - enemyArray[counter]->rect.getPosition().y) <= 40)) {
                        enemyArray[counter]->direction = 4;
                    }
                }

                    //enemy chases Hero
                else if (tempRand == 2) {
                    if (Hero.rect.getPosition().y < enemyArray[counter]->rect.getPosition().y)
                        enemyArray[counter]->direction = 1;
                    else if (Hero.rect.getPosition().y > enemyArray[counter]->rect.getPosition().y)
                        enemyArray[counter]->direction = 2;
                    else if (Hero.rect.getPosition().x < enemyArray[counter]->rect.getPosition().x)
                        enemyArray[counter]->direction = 3;
                    else if (Hero.rect.getPosition().x > enemyArray[counter]->rect.getPosition().x)
                        enemyArray[counter]->direction = 4;
                }

                else {
                    if (Hero.rect.getPosition().x < enemyArray[counter]->rect.getPosition().x)
                        enemyArray[counter]->direction = 3;
                    else if (Hero.rect.getPosition().x > enemyArray[counter]->rect.getPosition().x)
                        enemyArray[counter]->direction = 4;
                    else if (Hero.rect.getPosition().y < enemyArray[counter]->rect.getPosition().y)
                        enemyArray[counter]->direction = 1;
                    else if (Hero.rect.getPosition().y > enemyArray[counter]->rect.getPosition().y)
                        enemyArray[counter]->direction = 2;
                }
            }
        }
        counter++;
    }
}

void delete_enemy(vector<sptr<Enemy>> &enemyArray, PickUpClass &PickUp, vector<sptr<PickUpClass>> &pickUpArray, Enemy &Blood, vector<sptr<Enemy>> &bloodArray){
    vector<sptr<Enemy>>::const_iterator iter;
    int counter = 0;
    for (iter = enemyArray.begin(); iter != enemyArray.end(); iter++) {
        if (!enemyArray[counter]->alive) {

            //drop coin
            if(generateRandom(3) == 1) {
                PickUp.rect.setPosition(enemyArray[counter]->rect.getPosition());
                pickUpArray.push_back(std::make_shared<PickUpClass>(PickUp));
            }

            //create enemy blood stain
            Blood.sprite.setPosition(enemyArray[counter]->rect.getPosition());
            bloodArray.push_back(std::make_shared<Enemy>(Blood));

            enemyArray.erase(iter);
            break;
        }
        counter++;
    }
}


void delete_AoeBullet(vector<sptr<AoeBullet>> &AoeBulletArray){
    vector<sptr<AoeBullet>>::const_iterator iter;
    int counter = 0;
    for (iter = AoeBulletArray.begin(); iter != AoeBulletArray.end(); iter++) {
        if (AoeBulletArray[counter]->destroy) {
            AoeBulletArray.erase(iter);
            break;
        }
        counter++;
    }
}

void delete_text(vector<sptr<TextDisplayClass>> &textDisplayArray){
    vector<sptr<TextDisplayClass>>::const_iterator iter;
    int counter = 0;
    for (iter = textDisplayArray.begin(); iter != textDisplayArray.end(); iter++) {
        if (textDisplayArray[counter]->destroy) {
            textDisplayArray.erase(iter);
            break;
        }
        counter++;
    }
}

void delete_chest(vector<sptr<Chest>> &chestArray, Chest &OpenChest, vector<sptr<Chest>> &openChestArray, PickUpClass &PickUp, vector<sptr<PickUpClass>> &pickUpArray){
    vector<sptr<Chest>>::const_iterator iter;
    int counter = 0;
    for (iter = chestArray.begin(); iter != chestArray.end(); iter++) {
        if (!chestArray[counter]->alive) {

            //open chest texture
            OpenChest.sprite.setPosition(chestArray[counter]->rect.getPosition());
            openChestArray.push_back(std::make_shared<Chest>(OpenChest));

            //drop coin
            if(generateRandom(1) == 1) {
                PickUp.rect.setPosition(chestArray[counter]->rect.getPosition());
                pickUpArray.push_back(std::make_shared<PickUpClass>(PickUp));
            }

            chestArray.erase(iter);
            break;
        }
        counter++;
    }
}

void delete_PickUp_items(vector<sptr<PickUpClass>> &pickUpArray){
    vector<sptr<PickUpClass>>::const_iterator iter;
    int counter = 0;
    for (iter = pickUpArray.begin(); iter != pickUpArray.end(); iter++) {
        if (pickUpArray[counter]->destroy) {
            pickUpArray.erase(iter);
            break;
        }
        counter++;
    }
}

void draw(vector<sptr<Enemy>> &bloodArray, vector<sptr<Chest>> &chestArray, vector<sptr<Chest>> &openChestArray, vector<sptr<PickUpClass>> &pickUpArray, vector<sptr<AoeBullet>> &AoeBulletArray, vector<sptr<Enemy>> &enemyArray, vector<sptr<TextDisplayClass>> &textDisplayArray, Hero &Hero, sf::RenderWindow &window){
    int counter;
    vector<sptr<Enemy>>::const_iterator iter1;
    vector<sptr<Chest>>::const_iterator iter2;
    vector<sptr<Chest>>::const_iterator iter3;
    vector<sptr<PickUpClass>>::const_iterator iter4;
    vector<sptr<AoeBullet>>::const_iterator iter5;
    vector<sptr<Enemy>>::const_iterator iter6;
    vector<sptr<TextDisplayClass>>::const_iterator iter7;

    //draw blood
    counter= 0;
    for (iter1 = bloodArray.begin(); iter1 != bloodArray.end(); iter1++) {
        window.draw(bloodArray[counter]->sprite);
        counter++;
    }

    //draw chest
    counter = 0;
    for (iter2 = chestArray.begin(); iter2 != chestArray.end(); iter2++) {
        chestArray[counter]->Update();
        window.draw(chestArray[counter]->sprite);
        counter++;
    }

    //draw open chest
    counter = 0;
    for (iter3 = openChestArray.begin(); iter3 != openChestArray.end(); iter3++) {
        window.draw(openChestArray[counter]->sprite);
        counter++;
    }

    //draw PickUpClass items
    counter = 0;
    for (iter4 = pickUpArray.begin(); iter4 != pickUpArray.end(); iter4++) {
        pickUpArray[counter]->Update();
        window.draw(pickUpArray[counter]->sprite);
        counter++;
    }

    //draw AoeBullet
    counter = 0;
    for (iter5 = AoeBulletArray.begin(); iter5 != AoeBulletArray.end(); iter5++) {
        AoeBulletArray[counter]->Update(); //update AoeBullet
        window.draw(AoeBulletArray[counter]->sprite);
        counter++;
    }

    //draw enemies
    counter = 0;
    for (iter6 = enemyArray.begin(); iter6 != enemyArray.end(); iter6++) {
        enemyArray[counter]->UpdateMovement();
        window.draw(enemyArray[counter]->sprite);
        counter++;
    }

    //draw enemy's hp
    counter = 0;
    for (iter6 = enemyArray.begin(); iter6 != enemyArray.end(); iter6++) {
        enemyArray[counter]->text.setString("HP " + to_string(enemyArray[counter]->hp) + "/" + to_string(enemyArray[counter]->maxhp));
        window.draw(enemyArray[counter]->text);
        counter++;
    }

    //draw text
    counter = 0;
    for (iter7 = textDisplayArray.begin(); iter7 != textDisplayArray.end(); iter7++) {
        textDisplayArray[counter]->Update();
        window.draw(textDisplayArray[counter]->text);
        counter++;
    }

    //draw hero
    window.draw(Hero.sprite);
}


#endif //MAIN_CPP_FUNCTIONS_H
