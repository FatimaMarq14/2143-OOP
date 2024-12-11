#pragma once

#include <SFML/Graphics.hpp>

class Button {
private:
    sf::RectangleShape shape;
    sf::Text buttonText;
public:
    // Constructor that initializes the button with size, position, and text
    Button(const sf::Font& font, const sf::Vector2f& size, const sf::Vector2f& position, const std::string& text)
        : shape(size) {
        shape.setPosition(position);
        shape.setFillColor(sf::Color::Green);

        buttonText.setFont(font);
        buttonText.setString(text);
        buttonText.setCharacterSize(24);
        buttonText.setFillColor(sf::Color::White);
        buttonText.setPosition(position.x + 20, position.y + 10);
    }

    // Method to check if the button is clicked (mouse press event inside the button bounds)
    bool isClicked(const sf::Event& event) {
        return event.type == sf::Event::MouseButtonPressed &&
               shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
    }

    // Method to draw the button and its text on the window
    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(buttonText);
    }
};