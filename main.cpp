#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Random.h"
#include "Hero.h"
#include "Enemy.h"
#include "AoeBullet.h"
#include "StBullet.h"
#include "MeleeWeapon.h"
#include "TextDisplay.h"
#include "RenderMap.h"
#include "Map.h"

using namespace std;

int main()
{
    //variables
    int counter;
    int counter2;
    int HeroChoice;
    sf::Clock clock;
    sf::Clock clock2;
    sf::Clock clock3;
    sf::Clock clock4;
    int n = 24; //enemy number
    std::vector<std::vector<int>> enemyPos = std::vector<std::vector<int>> ({
            std::vector<int>({501, 453}), std::vector<int>({501, 453}),
            std::vector<int>({391, 678}), std::vector<int>({391, 678}),
            std::vector<int>({1056, 718}), std::vector<int>({1056, 718}),
            std::vector<int>({916, 968}), std::vector<int>({916, 968}),
            std::vector<int>({236, 908}), std::vector<int>({236, 908}),
            std::vector<int>({106, 388}), std::vector<int>({106, 388}),
            std::vector<int>({1456, 968}), std::vector<int>({1456, 968}),
            std::vector<int>({2316, 718}), std::vector<int>({2316, 718}),
            std::vector<int>({1561, 633}), std::vector<int>({1561, 633}),
            std::vector<int>({526, 53}), std::vector<int>({526, 53}),
            std::vector<int>({766, 358}), std::vector<int>({766, 358}),
            std::vector<int>({1351, 518}), std::vector<int>({1351, 518}),
    });

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

    //Hero texture
    sf::Texture textureHero;
    if(!textureHero.loadFromFile(R"(Resources\Rpg.textureHero.png)"))
        return EXIT_FAILURE;

    //enemy texture
    sf::Texture textureEnemy;
    if(!textureEnemy.loadFromFile(R"(Resources\UnHero.png)"))
        return EXIT_FAILURE;

    //Bullet texture
    sf::Texture textureAoeBullet;
    if(!textureAoeBullet.loadFromFile(R"(Resources\Projectiles_preview_rev_1.png)"))
        return EXIT_FAILURE;

    //blood texture
    sf::Texture textureBlood;
    if(!textureBlood.loadFromFile(R"(Resources/Blood.png)"))
        return EXIT_FAILURE;

    //Hero object
    class Hero Hero1;
    Hero1.sprite.setTexture(textureHero);

    //melee weapon object
    class MeleeWeapon MeleeWeapon1;

    //Bullet vector array
    vector<AoeBullet>::const_iterator iter;
    vector<AoeBullet> AoeBulletArray;

    vector<StBullet>::const_iterator iter2;
    vector<StBullet> StBulletArray;

    //Bullet object
    class AoeBullet AoeBullet1;
    AoeBullet1.sprite.setTexture(textureAoeBullet);

    class StBullet StBullet1;
    StBullet1.sprite.setTexture(textureAoeBullet);

    //enemy vector array
    vector<Enemy>::const_iterator iter4;
    vector<Enemy> enemyArray;

    //enemy object
    class Enemy Enemy1;
    Enemy1.sprite.setTexture(textureEnemy);
    Enemy1.text.setFont(font);
    Enemy1.text.setCharacterSize(12);
    Enemy1.text.setFillColor(sf::Color::Red);

    //blood vector array
    vector<Enemy>::const_iterator iter5;
    vector<Enemy> bloodArray;

    //blood object
    class Enemy Blood1;
    Blood1.isBlood = true;
    Blood1.sprite.setTexture(textureBlood);
    Blood1.sprite.setTextureRect(sf::IntRect(0, 0, 70, 53));
    //bloodArray.push_back(Blood1);

    //text vector array
    vector<TextDisplay>::const_iterator iter8;
    vector<TextDisplay> textDisplayArray;

    //text object
    class TextDisplay TextDisplay1;
    TextDisplay1.text.setFont(font);

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

        //cout << Hero1.rect.getPosition().x <<"   "<<Hero1.rect.getPosition().y<< endl ;

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

        //enemy collision with player
        if (elapsed2.asSeconds() >= 0.5) {
            clock2.restart();
            counter = 0;
            for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {
                if (Hero1.rect.getGlobalBounds().intersects(enemyArray[counter].rect.getGlobalBounds())) {

                    //text display
                    TextDisplay1.text.setString(to_string(enemyArray[counter].attackDamage));
                    TextDisplay1.text.setPosition(Hero1.rect.getPosition().x + Hero1.rect.getSize().x / 2,Hero1.rect.getPosition().y - Hero1.rect.getSize().y / 2);
                    textDisplayArray.push_back(TextDisplay1);

                    Hero1.hp -= enemyArray[counter].attackDamage;
                }
                counter++;
            }
        }
        //cout << Hero1.hp << endl;

        //enemy aggro AI
        counter = 0;
        for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {
            if (enemyArray[counter].aggro) {
                if (elapsed4.asSeconds() >= 0.05) {
                    clock4.restart();
                    int tempRand = generateRandom(3);
                    if (tempRand == 1) {

                        //hero to up
                        if ((Hero1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x) && (abs(Hero1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y) <= 40)) {
                            enemyArray[counter].direction = 1;
                        }
                        //hero to down
                        if ((Hero1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x) && (abs(Hero1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y) <= 40)) {
                            enemyArray[counter].direction = 2;
                        }
                        //hero to right
                        if ((Hero1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x) && (abs(Hero1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y) <= 40)) {
                            enemyArray[counter].direction = 3;
                        }
                        //hero to left
                        if ((Hero1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x) && (abs(Hero1.rect.getPosition().y - enemyArray[counter].rect.getPosition().y) <= 40)) {
                            enemyArray[counter].direction = 4;
                        }
                    }

                    //enemy chases Hero
                    else if (tempRand == 2) {
                        if (Hero1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y)
                            enemyArray[counter].direction = 1;
                        else if (Hero1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y)
                            enemyArray[counter].direction = 2;
                        else if (Hero1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x)
                            enemyArray[counter].direction = 3;
                        else if (Hero1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x)
                            enemyArray[counter].direction = 4;
                    }

                    else {
                        if (Hero1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x)
                            enemyArray[counter].direction = 3;
                        else if (Hero1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x)
                            enemyArray[counter].direction = 4;
                        else if (Hero1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y)
                            enemyArray[counter].direction = 1;
                        else if (Hero1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y)
                            enemyArray[counter].direction = 2;
                    }
                }
            }
            counter++;
        }

        //AoeBullet collisions
        counter = 0;
        for (iter = AoeBulletArray.begin(); iter != AoeBulletArray.end(); iter++) {
            counter2 = 0;
            for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {
                if (AoeBulletArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds())){
                    AoeBulletArray[counter].destroy = true;

                    //text display
                    TextDisplay1.text.setString(to_string(AoeBulletArray[counter].attackDamage));
                    TextDisplay1.text.setPosition(enemyArray[counter2].rect.getPosition().x + enemyArray[counter2].rect.getSize().x / 2,enemyArray[counter2].rect.getPosition().y - enemyArray[counter2].rect.getSize().y / 2);
                    textDisplayArray.push_back(TextDisplay1);

                    enemyArray[counter2].hp -= AoeBulletArray[counter].attackDamage;
                    if (enemyArray[counter2].hp <= 0)
                        enemyArray[counter2].alive = false;

                    //aggro
                    enemyArray[counter2].aggro = true;
                }
                counter2++;
            }
            counter++;
        }

        if (elapsed3.asSeconds() >= 0.5) {
            clock3.restart();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                //enemy collision with melee weapon
                counter = 0;
                for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {
                    if (MeleeWeapon1.rect.getGlobalBounds().intersects(enemyArray[counter].rect.getGlobalBounds())) {

                        //text display
                        TextDisplay1.text.setString(to_string(MeleeWeapon1.attackDamage));
                        TextDisplay1.text.setPosition(
                                enemyArray[counter].rect.getPosition().x + enemyArray[counter].rect.getSize().x / 2,
                                enemyArray[counter].rect.getPosition().y - enemyArray[counter].rect.getSize().y / 2);
                        textDisplayArray.push_back(TextDisplay1);

                        enemyArray[counter].hp -= MeleeWeapon1.attackDamage;
                        if (enemyArray[counter].hp <= 0)
                            enemyArray[counter].alive = false;
                    }
                    counter++;
                }
            }
        }

        //delete dead enemy
        counter = 0;
        for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {
            if (!enemyArray[counter].alive) {

                //create enemy blood stain
                Blood1.sprite.setPosition(enemyArray[counter].rect.getPosition());
                bloodArray.push_back(Blood1);

                enemyArray.erase(iter4);
                break;
            }
            counter++;
        }

        //delete AoeBullet
        counter = 0;
        for (iter = AoeBulletArray.begin(); iter != AoeBulletArray.end(); iter++) {
            if (AoeBulletArray[counter].destroy) {
                AoeBulletArray.erase(iter);
                break;
            }
            counter++;
        }

        //delete text
        counter = 0;
        for (iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++) {
            if (textDisplayArray[counter].destroy) {
                textDisplayArray.erase(iter8);
                break;
            }
            counter++;
        }


        //spawn new enemies
        while(n > 0){
            Enemy1.rect.setPosition(enemyPos[n-1][0], enemyPos[n-1][1]);
            enemyArray.push_back(Enemy1);
            n--;
        }

        //fire Bullet (left click)
        if (elapsed1.asSeconds() >= 0.1) {
            clock.restart();
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                AoeBullet1.rect.setPosition(Hero1.rect.getPosition().x + Hero1.rect.getSize().x/2 - AoeBullet1.rect.getSize().x/2, Hero1.rect.getPosition().y + Hero1.rect.getSize().y/2 - AoeBullet1.rect.getSize().y/2);
                AoeBullet1.direction = Hero1.direction;
                AoeBulletArray.push_back(AoeBullet1);
            }
        }

        //draw blood
        counter = 0;
        for (iter5 = bloodArray.begin(); iter5 != bloodArray.end(); iter5++) {
            window.draw(bloodArray[counter].sprite);
            counter++;
        }

        //draw AoeBullet
        counter = 0;
        for (iter = AoeBulletArray.begin(); iter != AoeBulletArray.end(); iter++) {
            AoeBulletArray[counter].Update(); //update AoeBullet
            window.draw(AoeBulletArray[counter].sprite);
            counter++;
        }

        //draw enemies
        counter = 0;
        for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {
            enemyArray[counter].UpdateMovement();
            window.draw(enemyArray[counter].sprite);
            counter++;
        }

        //draw enemy's hp
        counter = 0;
        for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {
            enemyArray[counter].text.setString("HP " + to_string(enemyArray[counter].hp) + "/" + to_string(enemyArray[counter].maxhp));
            window.draw(enemyArray[counter].text);
            counter++;
        }

        //update MeleeWeapon
        MeleeWeapon1.Update();

        //draw melee weapon
        window.draw(MeleeWeapon1.rect);

        //update Hero
        Hero1.UpdateMovement();

        //hero view
        window.setView(view1);
        view1.setCenter(Hero1.rect.getPosition());

        //draw hero
        window.draw(Hero1.sprite);

        //draw text
        counter = 0;
        for (iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++) {
            textDisplayArray[counter].Update();
            window.draw(textDisplayArray[counter].text);
            counter++;
        }

        //hero HP text
        textHP.setString("HP " + to_string(Hero1.hp) + "/" + to_string(Hero1.maxhp));
        window.draw(textHP);
        textHP.setPosition(Hero1.rect.getPosition().x - window.getSize().x/2, Hero1.rect.getPosition().y - window.getSize().y/2);

        //update the window
        window.display();
    }


    return 0;
}