#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>

#include "player.hpp" // Include the Player header
#include "dice.hpp" // Include the Dice header
#include "grid.hpp" // Include the Grid Class
#include "GameWindow.hpp" // Include the GameWindow Class
#include "FontManager.hpp" // Include the FontManager Class
#include "Button.hpp" // Include the Button Class

// Manages the overall game
class Game {
private:
    enum GameState {
        Welcome,
        NameInput,
        Playing
    };
    GameState currentState = Welcome;
    GameWindow window;
    FontManager fontManager;
    Dice dice;
    Button button;
    Player player;
    Grid topGrid;  // First grid on top
    Grid bottomGrid;  // Second grid at the bottom

    bool rolling = false;
    sf::Clock clock;
    const float rollDuration = 2.0f;

    void processEvents() {
        sf::Event event;
        while (window.getWindow().pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.getWindow().close();
            }

            if (currentState == NameInput) {
                player.handleEvent(event);
                if (player.isNameEntered()) {
                    currentState = Playing;
                }
            } else if (currentState == Playing) {
                if (button.isClicked(event)) {
                    rolling = true;
                    clock.restart();
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                // Check if mouse click is on top grid or bottom grid
                if (topGrid.getClickedCellIndex(event.mouseButton.x, event.mouseButton.y) != -1) {
                    // If clicked on top grid, set dice to that cell
                    int cellIndex = topGrid.getClickedCellIndex(event.mouseButton.x, event.mouseButton.y);
                    updateDicePosition(cellIndex, topGrid);
                } else if (bottomGrid.getClickedCellIndex(event.mouseButton.x, event.mouseButton.y) != -1) {
                    // If clicked on bottom grid, set dice to that cell
                    int cellIndex = bottomGrid.getClickedCellIndex(event.mouseButton.x, event.mouseButton.y);
                    updateDicePosition(cellIndex, bottomGrid);
                }
            }
        }
    }

    void updateDicePosition(int cellIndex, Grid& grid) {
    int row = cellIndex / grid.getCols();  // Calculate the row of the clicked cell
    int col = cellIndex % grid.getCols();  // Calculate the column of the clicked cell

    // Set the dice position to the clicked cell
    float x = grid.getGridStartX() + col * (grid.getCellSize() + grid.getCellSpacing());
    float y = grid.getGridStartY() + row * (grid.getCellSize() + grid.getCellSpacing());

    dice.getSprite().setPosition(x, y);
}

    void update() {
        if (currentState == Playing && rolling) {
            if (clock.getElapsedTime().asSeconds() < rollDuration) {
                dice.setNextTexture();
            } else {
                dice.setRandomTexture();
                rolling = false;
            }
        }
    }

    void render() {
        auto& gameWindow = window.getWindow();
        gameWindow.clear(sf::Color::Black);

        if (currentState == Welcome) {
            renderWelcomeScreen(gameWindow);
        } else if (currentState == NameInput) {
            player.draw(gameWindow);
        } else if (currentState == Playing) {
            topGrid.draw(gameWindow); // Draw the first grid
            bottomGrid.draw(gameWindow); // Draw the second grid
            player.draw(gameWindow); // Display player's name
            button.draw(gameWindow); // Draw Roll button
            gameWindow.draw(dice.getSprite()); // Draw Dice
        }

        gameWindow.display();
    }

    void renderWelcomeScreen(sf::RenderWindow& gameWindow) {
        sf::Text welcomeText("Welcome to Knucklebones! \n Loading...", fontManager.getFont(), 40);
        welcomeText.setFillColor(sf::Color::White);
        welcomeText.setPosition(150, 250);
        gameWindow.draw(welcomeText);
    }

public:
    Game()
        : window(),
          fontManager("assets/fonts/Jaro-Regular.ttf"),
          dice("diceRoll/"),
          button(fontManager.getFont(), {150, 55}, {625, 520}, "Roll"),
          player(fontManager.getFont()),
          topGrid(3, 3, 80.f, 8.f, 200.f, 200.f),  // First grid with smaller cells
          bottomGrid(3, 3, 80.f, 8.f, 200.f, 500.f) {}  // Second grid, positioned below the first grid

    void run() {
        sf::Clock welcomeTimer;
        while (window.getWindow().isOpen()) {
            processEvents();

            if (currentState == Welcome && welcomeTimer.getElapsedTime().asSeconds() > 2.0f) {
                currentState = NameInput; // Mimic loading screen
            }

            update();
            render();
        }
    }
};

int main() {
    Game game;
    game.run();
    return 0;
}