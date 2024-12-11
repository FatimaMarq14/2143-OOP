#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Grid {
private:
    std::vector<sf::RectangleShape> cells;
    int rows, cols;
    float cellSize, cellSpacing, gridStartX, gridStartY;

public:
    float getGridStartX() const { return gridStartX; }
    float getGridStartY() const { return gridStartY; }
    float getCellSize() const { return cellSize; }
    float getCellSpacing() const { return cellSpacing; }
    int getCols() const { return cols; }  // Getter for columns

    Grid(int rows, int cols, float cellSize, float cellSpacing, float gridStartX, float gridStartY)
        : rows(rows), cols(cols), cellSize(cellSize), cellSpacing(cellSpacing), gridStartX(gridStartX), gridStartY(gridStartY) {
        createGrid();
    } // Allows flexability to change positions

    void createGrid() {
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
                cell.setFillColor(sf::Color::White);
                cell.setOutlineColor(sf::Color::Black);
                cell.setOutlineThickness(2.f);

                float x = gridStartX + col * (cellSize + cellSpacing);
                float y = gridStartY + row * (cellSize + cellSpacing);
                cell.setPosition(x, y);

                cells.push_back(cell);
            }
        }
    }

    void draw(sf::RenderWindow& window) {
        for (const auto& cell : cells) {
            window.draw(cell);
        }
    }

    void updatePosition(float newStartY) {
        gridStartY = newStartY;
        cells.clear(); // Clear the existing cells
        createGrid();  // Recreate grid with updated position
    }

    sf::Vector2f getCellPosition(int row, int col) const {
        // Calculate the top-left corner of the cell based on its row and col
        float cellX = gridStartX + col * (cellSize + cellSpacing);
        float cellY = gridStartY + row * (cellSize + cellSpacing);
        return sf::Vector2f(cellX, cellY);
    }

    int getClickedCellIndex(float mouseX, float mouseY) {
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                float cellX = gridStartX + col * (cellSize + cellSpacing);
                float cellY = gridStartY + row * (cellSize + cellSpacing);
                sf::FloatRect cellBounds(cellX, cellY, cellSize, cellSize);

                if (cellBounds.contains(mouseX, mouseY)) {
                    return row * cols + col;  // Return the index of the clicked cell
                }
            }
        }
        return -1;  // No cell clicked
    }

};