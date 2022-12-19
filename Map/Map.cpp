//
// Created by danit on 10.12.2022.
//

#include "Map.h"
#include "../Exceptions.h"

/// Constructor
Map::Map(sf::Image &mapSketch) {
    if (mapSketch.getSize().y != SCREEN_HEIGHT / CELL_SIZE && mapSketch.getSize().x < SCREEN_WIDTH / CELL_SIZE)
        throw mapSketchError();

    empty.loadFromFile("Sprites/empty.png");
    ground.loadFromFile("Sprites/ground.png");
    wall.loadFromFile("Sprites/wall.png");
    for (unsigned int i = 0; i < mapSketch.getSize().x; i++) {
        std::vector<Cell> temp;
        for (unsigned int j = 0; j < mapSketch.getSize().y; j++) {
            if (mapSketch.getPixel(i, j) == sf::Color(255, 255, 255))
                temp.emplace_back(empty, i * CELL_SIZE, j * CELL_SIZE, Cell::Empty);
            else if (mapSketch.getPixel(i, j) == sf::Color(255, 0, 0))
                temp.emplace_back(ground, i * CELL_SIZE, j * CELL_SIZE, Cell::Ground);
            else if(mapSketch.getPixel(i, j) == sf::Color(100, 0, 0))
                temp.emplace_back(wall, i * CELL_SIZE, j * CELL_SIZE, Cell::Ground);
        }
        this->map.emplace_back(temp);
    }
    if (Cell::getCellNum() != (mapSketch.getSize().x * mapSketch.getSize().y))
        throw mapConversionError();

}

/// Functions
const std::vector<std::vector<Cell>> &Map::getMap() const {
    return map;
}

void Map::render(sf::RenderTarget &target, int pos_x) {
//    for (auto &i: this->map)
//        for (auto &j: i)
//            j.render(target);
    pos_x /= CELL_SIZE;
    for(int i = std::max<int>(pos_x - 20, 0); i < std::min<int>(pos_x + 20, int(this->map.size())); i++)
        for(auto & j : this->map[i])
            j.render(target);

}
