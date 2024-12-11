#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <random>
#include <iostream>
// Handles player name input and logic
class Player {
private:
    sf::Text instructionText;
    sf::Text nameText;
    sf::Text displayName;
    std::string userInput;
    bool nameEntered = false;

public:
    Player(const sf::Font& font) 
        : instructionText("Enter your name:", font, 24), 
          nameText("", font, 24), 
          displayName("", font, 30) {
        instructionText.setPosition(50, 250);
        instructionText.setFillColor(sf::Color::White);

        nameText.setPosition(50, 300);
        nameText.setFillColor(sf::Color::Green);

        displayName.setPosition(50, 100);
        displayName.setFillColor(sf::Color::Yellow);
    }

    void handleEvent(const sf::Event& event) {
        if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode == '\b') {
                if (!userInput.empty()) userInput.pop_back();
            } else if (event.text.unicode == '\r') {
                nameEntered = true;
                displayName.setString("Hello, " + userInput + "!");
            } else if (event.text.unicode < 128) {
                userInput += static_cast<char>(event.text.unicode);
            }
            nameText.setString(userInput);
        }
    }

    bool isNameEntered() const {
        return nameEntered;
    }

    void draw(sf::RenderWindow& window) {
        if (!nameEntered) {
            window.draw(instructionText);
            window.draw(nameText);
        } else {
            window.draw(displayName);
        }
    }
};