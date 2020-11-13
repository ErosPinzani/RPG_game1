#include <iostream>
#include <SFMl/Graphics.hpp>
#include <memory>

int main() {
    sf::VideoMode mode = sf::VideoMode::getDesktopMode();
    std::shared_ptr<sf::RenderWindow> window(
            new sf::RenderWindow(sf::VideoMode(1500, 850, mode.bitsPerPixel),
                                 "RPG_game"));
    window->setPosition(sf::Vector2i{(int) (mode.width - 1500) / 2,
                                     (int) (mode.height - 850) / 2});                // Center window
    window->setFramerateLimit(60);  // Set maximum framerate




    while (window->isOpen()) {

    }
    return 0;
}