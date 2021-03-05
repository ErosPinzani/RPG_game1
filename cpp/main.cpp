#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

#include "../h/Functions.h"
#include "../h/Projectiles/StBullet.h"
#include "../h/Projectiles/MeleeWeapon.h"
#include "../h/RenderMap.h"
#include "../h/Map.h"


using namespace std;
// Add a short alias for std::shared_ptr to the current environment
template <class T> using sptr = std::shared_ptr<T>;




int main(){
    //variables
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
                AoeBullet1.direction = static_cast<Bullet::Direction>(Hero1.direction);
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
        textHP.setString("HP " + to_string(Hero1.hp) + "/" + to_string(Hero1.getMaxhp()));
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