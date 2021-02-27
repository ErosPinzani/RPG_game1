#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

#include "Random.h"
#include "Hero.h"
#include "Enemy.h"
#include "AoeBullet.h"
#include "StBullet.h"
#include "MeleeWeapon.h"
#include "TextDisplayClass.h"
#include "RenderMap.h"
#include "Map.h"
#include "PickUpClass.h"
#include "Chest.h"

using namespace std;
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


int main(){
    //variables
    int counter;
    int counter2;
    int counter3;
    int HeroChoice;
    sf::Clock clock;
    sf::Clock clock2;
    sf::Clock clock3;
    sf::Clock clock4;
    int n = 24; //enemy number
    int k = 5; //chest number

    //create window
    sf::RenderWindow window(sf::VideoMode(1500, 850), "RPG Game");
    window.setFramerateLimit(60);

    //view
    sf::View view1(sf::FloatRect(200, 200, 300, 200));
    view1.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
    view1.setCenter(sf::Vector2f(view1.getSize().x/2, view1.getSize().y/2));
    window.setView(view1);

    //set icon
    sf::Image icon;
    if(!icon.loadFromFile( R"(Resources\role-playing-game.png)"))
        return EXIT_FAILURE;
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //text font
    sf::Font font;
    if(!font.loadFromFile( R"(Resources\SuperLegendBoy-4w8Y.ttf)"))
        return EXIT_FAILURE;

    //hero HP text
    sf::Text textHP("HP ", font, 20);
    textHP.setFillColor(sf::Color::Green);

    //coin text
    sf::Text coinText("COIN ", font, 20);
    coinText.setFillColor(sf::Color::Yellow);

    //Hero texture
    sf::Texture textureHero;
    if(!textureHero.loadFromFile(R"(Resources\Rpg.textureHero.png)"))
        return EXIT_FAILURE;

    //enemy texture
    sf::Texture textureEnemy;
    if(!textureEnemy.loadFromFile(R"(Resources\UnHero.png)"))
        return EXIT_FAILURE;

    //coin texture
    sf::Texture textureCoin;
    if(!textureCoin.loadFromFile(R"(Resources/Coin.png)"))
        return EXIT_FAILURE;

    //Bullet texture
    sf::Texture textureAoeBullet;
    if(!textureAoeBullet.loadFromFile(R"(Resources\Projectiles_preview_rev_1.png)"))
        return EXIT_FAILURE;

    //blood texture
    sf::Texture textureBlood;
    if(!textureBlood.loadFromFile(R"(Resources/Blood.png)"))
        return EXIT_FAILURE;

    //chest texture
    sf::Texture textureChest;
    if(!textureChest.loadFromFile(R"(Resources/Chest.png)"))
        return EXIT_FAILURE;

    //Hero object
    class Hero Hero1;
    Hero1.sprite.setTexture(textureHero);

    //melee weapon object
    class MeleeWeapon MeleeWeapon1;

    //Bullet vector array
    vector<sptr<AoeBullet>> AoeBulletArray;

    //vector<sptr<StBullet>>::const_iterator iter2;
    vector<sptr<StBullet>> StBulletArray;

    //Bullet object
    class AoeBullet AoeBullet1;
    AoeBullet1.sprite.setTexture(textureAoeBullet);

    class StBullet StBullet1;
    StBullet1.sprite.setTexture(textureAoeBullet);

    //enemy vector array
    vector<sptr<Enemy>> enemyArray;

    //enemy object
    class Enemy Enemy1;
    Enemy1.sprite.setTexture(textureEnemy);
    Enemy1.text.setFont(font);
    Enemy1.text.setCharacterSize(12);
    Enemy1.text.setFillColor(sf::Color::Red);

    //blood vector array
    vector<sptr<Enemy>> bloodArray;

    //blood object
    class Enemy Blood1;
    Blood1.sprite.setTexture(textureBlood);
    Blood1.sprite.setTextureRect(sf::IntRect(0, 0, 70, 53));

    //chest vector array
    vector<sptr<Chest>> chestArray;

    vector<sptr<Chest>> openChestArray;

    //chest object
    class Chest Chest1;
    Chest1.sprite.setTexture(textureChest);

    class Chest OpenChest1;
    OpenChest1.sprite.setTexture(textureChest);
    OpenChest1.sprite.setTextureRect(sf::IntRect(0, 45.75*3, 50, 47.67));

    //text vector array
    vector<sptr<TextDisplayClass>> textDisplayArray;

    //text object
    class TextDisplayClass TextDisplay1;
    TextDisplay1.text.setFont(font);

    //pickUp vector array
    vector<sptr<PickUpClass>> pickUpArray;

    //coin object
    class PickUpClass PickUp1;
    PickUp1.sprite.setTexture(textureCoin);

    //map
    class RenderMap RenderMap1;

    //start game loop
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event{};
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //clear screen
        window.clear();

        //render map
        Map::getInstance()->vectorM1;
        RenderMap1.generate(sf::Vector2u(50, 50), Map::getInstance()->vectorM1, RenderMap1.map_width, RenderMap1.map_height);
        window.draw(RenderMap1);

        //cin HeroChoice

        //clock
        sf::Time elapsed1 = clock.getElapsedTime();
        sf::Time elapsed2 = clock2.getElapsedTime();
        sf::Time elapsed3 = clock3.getElapsedTime();
        sf::Time elapsed4 = clock4.getElapsedTime();

        //player collides with PickUpClass items
        item_collision(Hero1, pickUpArray);

        //enemy collision with player
        enemy_collision_player(Hero1, enemyArray, TextDisplay1, textDisplayArray, clock2);

        //AoeBullet collisions
        aoe_collision(AoeBulletArray, enemyArray, chestArray, TextDisplay1, textDisplayArray);

        //enemy aggro AI
        aggro(enemyArray, Hero1, clock4);
/*
        //melee weapon
        if (elapsed3.asSeconds() >= 0.5) {
            clock3.restart();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                //enemy collision with melee weapon
                counter = 0;
                for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {
                    if (MeleeWeapon1.rect.getGlobalBounds().intersects(enemyArray[counter]->rect.getGlobalBounds())) {

                        //text display
                        TextDisplay1.text.setString(to_string(MeleeWeapon1.attackDamage));
                        TextDisplay1.text.setPosition(
                                enemyArray[counter]->rect.getPosition().x + enemyArray[counter]->rect.getSize().x / 2,
                                enemyArray[counter]->rect.getPosition().y - enemyArray[counter]->rect.getSize().y / 2);
                        textDisplayArray.push_back(std::make_shared<TextDisplayClass>(TextDisplay1));

                        enemyArray[counter]->hp -= MeleeWeapon1.attackDamage;
                        if (enemyArray[counter]->hp <= 0)
                            enemyArray[counter]->alive = false;
                    }
                    counter++;
                }
            }
        }
*/
        //delete dead enemy
        delete_enemy(enemyArray, PickUp1, pickUpArray, Blood1, bloodArray);

        //delete AoeBullet
        delete_AoeBullet(AoeBulletArray);

        //delete text
        delete_text(textDisplayArray);

        //delete chest
        delete_chest(chestArray, OpenChest1, openChestArray, PickUp1, pickUpArray);

        //delete PickUpClass items
        delete_PickUp_items(pickUpArray);

        //spawn new enemies
        while(n > 0){
            Enemy1.rect.setPosition(RenderMap::enemyPos[n-1][0], RenderMap::enemyPos[n-1][1]);
            enemyArray.push_back(std::make_shared<Enemy>(Enemy1));
            n--;
        }

        //spawn new chests
        while(k > 0){
            Chest1.rect.setPosition(RenderMap::chestPos[k-1][0], RenderMap::chestPos[k-1][1]);
            chestArray.push_back(std::make_shared<Chest>(Chest1));
            k--;
        }

        //fire Bullet (left click)
        if (elapsed1.asSeconds() >= 0.1) {
            clock.restart();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                AoeBullet1.rect.setPosition(Hero1.rect.getPosition().x + Hero1.rect.getSize().x/2 - AoeBullet1.rect.getSize().x/2, Hero1.rect.getPosition().y + Hero1.rect.getSize().y/2 - AoeBullet1.rect.getSize().y/2);
                AoeBullet1.direction = Hero1.direction;
                AoeBulletArray.push_back(std::make_shared<AoeBullet>(AoeBullet1));
            }
        }

        //draw
        draw(bloodArray, chestArray, openChestArray, pickUpArray, AoeBulletArray, enemyArray, textDisplayArray, Hero1, window);

        //update MeleeWeapon
        MeleeWeapon1.Update();

        //draw melee weapon
        //window.draw(MeleeWeapon1.rect);

        //update Hero
        Hero1.UpdateMovement();

        //hero view
        window.setView(view1);
        view1.setCenter(Hero1.rect.getPosition());

        //hero HP text
        textHP.setString("HP " + to_string(Hero1.hp) + "/" + to_string(Hero1.maxhp));
        window.draw(textHP);
        textHP.setPosition(Hero1.rect.getPosition().x - window.getSize().x/2, Hero1.rect.getPosition().y - window.getSize().y/2);

        //coin text
        coinText.setString("COIN " + to_string(Hero1.coins));
        window.draw(coinText);
        coinText.setPosition(Hero1.rect.getPosition().x - window.getSize().x/2, Hero1.rect.getPosition().y - window.getSize().y/2 + 25);

        //update the window
        window.display();
    }

    return 0;
}

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