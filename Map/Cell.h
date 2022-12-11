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
const unsigned int CELL_SIZE = 40;

class Cell {
public:
    enum cellType{Ground, Pipe, Empty, Wall};

    /// Constructor
    explicit Cell(const sf::Texture& texture , float pos_x, float pos_y, cellType type_ = Empty);

    ///Functions
    sf::FloatRect getGlobalBounds() const;
    cellType getType() const;

    void setPosition(float x, float y);

    void render(sf::RenderTarget& target);

private:
    /// Variables
    sf::Sprite sprite;
    cellType type;
};


#endif //OOP_CELL_H
