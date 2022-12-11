//
// Created by danit on 10.12.2022.
//

#include "Map.h"

/// Constructor
Map::Map(sf::Image& mapSketch) {
    empty.loadFromFile("Sprites/empty.png");
    ground.loadFromFile("Sprites/ground.png");
    for(unsigned int i = 0; i < mapSketch.getSize().x; i++)
    {
        std::vector<Cell> temp;
        for(unsigned int j = 0; j < mapSketch.getSize().y; j++)
        {
            if(mapSketch.getPixel(i, j) == sf::Color(255,255,255))
                temp.emplace_back(empty, i * CELL_SIZE, j * CELL_SIZE, Cell::Empty);
            else if(mapSketch.getPixel(i, j) == sf::Color(255,0,0))
                temp.emplace_back(ground, i * CELL_SIZE, j * CELL_SIZE, Cell::Ground);
        }
        this->map.emplace_back(temp);
    }

}

/// Functions
const std::vector<std::vector<Cell>> &Map::getMap() const {
    return map;
}

void Map::render(sf::RenderTarget &target) {
    for(auto & i : this->map)
        for(auto & j : i)
            j.render(target);
}