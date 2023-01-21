//
// Created by danit on 08.12.2022.
//

#include "Cell.h"

unsigned int Cell::cellNum = 0;
const sf::Color Cell::WALL_COLOR = sf::Color(100, 0, 0);

/// Constructor
Cell::Cell(const sf::Texture &texture, float pos_x, float pos_y, Cell::cellType type_) : type(type_) {
    cellNum++;
    std::cout << cellNum << '\n';
    this->sprite.setTexture(texture);
    this->sprite.setPosition(sf::Vector2f(pos_x, pos_y));
}

Cell::Cell(const sf::Texture &texture, const sf::IntRect &textureRect, float pos_x, float pos_y, Cell::cellType type_): type(type_) {
    cellNum++;
    std::cout << cellNum << '\n';
    this->sprite.setTexture(texture);
    this->sprite.setTextureRect(textureRect);
    this->sprite.setPosition(sf::Vector2f(pos_x, pos_y));
}

/// Functions
sf::FloatRect Cell::getGlobalBounds() const {
    return this->sprite.getGlobalBounds();
}

Cell::cellType Cell::getType() const {
    return type;
}

unsigned int Cell::getCellNum() {
    return cellNum;
}

void Cell::setCellNum(unsigned int cellNum_) {
    Cell::cellNum = cellNum_;
}

void Cell::setPosition(float x, float y) {
    this->sprite.setPosition(x, y);
}

void Cell::render(sf::RenderTarget &target) {
    target.draw(this->sprite);
}
