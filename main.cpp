#include <iostream>
#include <SFMl/Graphics.hpp>

#include "Character.h"
#include "Hero.h"
#include "Enemy.h"

int main() {
    sf::Window window;
    sf::VideoMode mode = sf::VideoMode::getDesktopMode();
    window.create(sf::VideoMode(1500, 850), "RPG_game");

    class Hero Hero1;
    class Enemy Enemy1;

    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    window.setPosition(sf::Vector2i{(int) (mode.width - 1500) / 2,
                                     (int) (mode.height - 850) / 2});                // Center window
    window.setFramerateLimit(60);  // Set maximum framerate


    return 0;
}