#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class FontManager {
private:
    sf::Font font;
public:
    // Constructor that loads the font from the specified path
    FontManager(const std::string& fontPath) {
        if (!font.loadFromFile(fontPath)) {
            std::cerr << "Error loading font\n";
            exit(-1); // If font fails to load, terminate the program
        }
    }

    // Accessor method to get the loaded font
    sf::Font& getFont() { return font; }
};