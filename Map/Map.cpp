//
// Created by danit on 10.12.2022.
//

#include <cmath>
#include "Map.h"
#include "../Exceptions.h"

/// Constructor
Map::Map(sf::Image &mapSketch) {
    if (mapSketch.getSize().y != SCREEN_HEIGHT / CELL_SIZE && mapSketch.getSize().x < SCREEN_WIDTH / CELL_SIZE)
        throw mapSketchError();

    empty.loadFromFile("Sprites/empty.png");
    ground.loadFromFile("Sprites/ground.png");
    wall.loadFromFile("Sprites/wall.png");
    pipe.loadFromFile("Sprites/pipe.png");
    for (unsigned int i = 0; i < mapSketch.getSize().x; i++) {
        std::vector<Cell> temp;
        for (unsigned int j = 0; j < mapSketch.getSize().y / 2; j++) {
            if (mapSketch.getPixel(i, j) == sf::Color::White)
                temp.emplace_back(empty, i * CELL_SIZE, j * CELL_SIZE, Cell::Empty);
            else if (mapSketch.getPixel(i, j) == sf::Color::Red)
                temp.emplace_back(ground, i * CELL_SIZE, j * CELL_SIZE, Cell::Ground);
            else if(mapSketch.getPixel(i, j) == Cell::WALL_COLOR)
                temp.emplace_back(wall, i * CELL_SIZE, j * CELL_SIZE, Cell::Wall);
            else if(mapSketch.getPixel(i, j) == sf::Color::Green)
            {
                if(mapSketch.getPixel(i-1, j) != sf::Color::Green) {
                    if(mapSketch.getPixel(i, j-1) != sf::Color::Green)
                        temp.emplace_back(pipe, sf::IntRect(0, 0, CELL_SIZE, CELL_SIZE),
                                          i * CELL_SIZE, j * CELL_SIZE, Cell::Pipe);
                    else
                        temp.emplace_back(pipe, sf::IntRect(0, CELL_SIZE, CELL_SIZE, CELL_SIZE),
                                          i * CELL_SIZE, j * CELL_SIZE, Cell::Pipe);
                }
                else {
                    if(mapSketch.getPixel(i, j-1) != sf::Color::Green)
                        temp.emplace_back(pipe, sf::IntRect(CELL_SIZE, 0, CELL_SIZE, CELL_SIZE),
                                          i * CELL_SIZE, j * CELL_SIZE, Cell::Pipe);
                    else
                        temp.emplace_back(pipe, sf::IntRect(CELL_SIZE, CELL_SIZE, CELL_SIZE, CELL_SIZE),
                                          i * CELL_SIZE, j * CELL_SIZE, Cell::Pipe);
                }
            }


        }
        this->map.emplace_back(temp);
    }
    if (Cell::getCellNum() != (mapSketch.getSize().x * mapSketch.getSize().y / 2))
        throw mapConversionError();

    for (unsigned int i = 0; i < mapSketch.getSize().x; i++) {
        for (unsigned int j = mapSketch.getSize().y / 2 + 1; j < mapSketch.getSize().y; j++) {
            if (mapSketch.getPixel(i, j) == sf::Color::Red)
            {
                this->enemies.push_back(std::make_shared<Enemy>(sf::Vector2f(float(i) * CELL_SIZE, (float(j) - float(mapSketch.getSize().y) / 2) * CELL_SIZE)));
            }
        }
    }

}

/// Functions
const std::vector<std::vector<Cell>> &Map::getMap() const {
    return map;
}

const std::vector<std::shared_ptr<Enemy>> &Map::getEnemies() const {
    return enemies;
}

void Map::render(sf::RenderTarget &target, int pos_x) {
//    for (auto &i: this->map)
//        for (auto &j: i)
//            j.render(target);
    pos_x /= CELL_SIZE;
    for(int i = std::max(pos_x - 20, 0); i < std::min(pos_x + 20, int(this->map.size())); i++)
        for(auto & j : this->map[i])
            j.render(target);

//    for(const auto& i: enemies)
//    {
//        i->render(target);
//    }
}


