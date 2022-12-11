//
// Created by danit on 08.12.2022.
//

#include "Cell.h"

/// Constructor
Cell::Cell(const sf::Texture &texture, float pos_x, float pos_y, Cell::cellType type_): type(type_)  {
    this->sprite.setTexture(texture);
    this->sprite.setPosition(sf::Vector2f(pos_x, pos_y));
}

/// Functions
sf::FloatRect Cell::getGlobalBounds() const{
    return this->sprite.getGlobalBounds();
}

Cell::cellType Cell::getType() const {
    return type;
}

void Cell::setPosition(float x, float y) {
    this->sprite.setPosition(x, y);
}

void Cell::render(sf::RenderTarget &target) {
    target.draw(this->sprite);
}


