//
// Created by danit on 08.12.2022.
//

#ifndef OOP_CELL_H
#define OOP_CELL_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>
#include <memory>

const unsigned int SCREEN_HEIGHT = 600;
const unsigned int SCREEN_WIDTH = 800;
const int CELL_SIZE = 40;

class Cell {
public:
    enum cellType {
        Ground, Pipe, Empty, Wall
    };
    const static sf::Color WALL_COLOR;
    /// Constructor
    Cell(const sf::Texture &texture, float pos_x, float pos_y, cellType type_ = Empty);

    Cell(const sf::Texture &texture, const sf::IntRect &textureRect, float pos_x, float pos_y, cellType type_ = Empty);

    ///Functions
    sf::FloatRect getGlobalBounds() const;

    cellType getType() const;

    static unsigned int getCellNum();

    static void setCellNum(unsigned int cellNum);

    void setPosition(float x, float y);

    void render(sf::RenderTarget &target);

private:
    /// Variables
    sf::Sprite sprite;
    cellType type;
    static unsigned int cellNum;
};


#endif //OOP_CELL_H
