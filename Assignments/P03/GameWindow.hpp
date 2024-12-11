#pragma once

#include <SFML/Graphics.hpp>

class GameWindow {
private:
    sf::RenderWindow window;
public:
    // Constructor initializes window with given dimensions
    GameWindow() : window(sf::VideoMode(900, 800), "Knucklebone Game") {
        window.setFramerateLimit(60);
    }

    // Accessor method to get the render window
    sf::RenderWindow& getWindow() { return window; }
};