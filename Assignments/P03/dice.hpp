#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <random>
#include <iostream>

class Dice {
private:
    std::vector<sf::Texture> textures;
    sf::Sprite sprite;
    int currentIndex = 0;
    std::mt19937 randomGenerator;
    sf::Vector2f position; // specific position of the dice on the grid

public:
    Dice(const std::string& imagePath) : randomGenerator(std::random_device{}()) {
        for (int i = 0; i < 6; ++i) {
            sf::Texture texture;
            if (!texture.loadFromFile(imagePath + std::to_string(i + 1) + ".png")) {
                std::cerr << "Error loading die image\n";
                exit(-1);
            }
            textures.push_back(texture);
        }
        sprite.setTexture(textures[0]);
        sprite.setPosition(1000, 1000);

        sprite.setScale(0.4f, 0.4f);  // Make the dice smaller
    }

    void setRandomTexture() {
        sprite.setTexture(textures[randomGenerator() % 6]);
    }

    void setPosition(float x, float y) {
        position = sf::Vector2f(x,y);
        sprite.setPosition(position);
    }

    void setNextTexture() {
        currentIndex = (currentIndex + 1) % 6;
        sprite.setTexture(textures[currentIndex]);
    }

    sf::Sprite& getSprite() {
        return sprite;
    }

    sf::Vector2f getPostion() const {
        return position;
    }
};
