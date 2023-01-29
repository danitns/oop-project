//
// Created by danit on 10.12.2022.
//

#include <cmath>
#include "Map.h"
#include "../Exceptions.h"

void Map::initTextures() {
    empty.loadFromFile("Sprites/empty.png");
    ground.loadFromFile("Sprites/ground.png");
    wall.loadFromFile("Sprites/wall.png");
    pipe.loadFromFile("Sprites/pipe.png");
    cloud.loadFromFile("Sprites/cloud.png");
    endSign.loadFromFile("Sprites/endSign.png");
    bush.loadFromFile("Sprites/bush.png");
}

/// Constructor
Map::Map(sf::Image &mapSketch) {
    initTextures();
    if (mapSketch.getSize().y != SCREEN_HEIGHT / CELL_SIZE && mapSketch.getSize().x < SCREEN_WIDTH / CELL_SIZE)
        throw mapSketchError();

    for (unsigned int i = 0; i < mapSketch.getSize().x; i++) {
        std::vector<Cell> temp;
        for (unsigned int j = 0; j < mapSketch.getSize().y / 2; j++) {
            if (mapSketch.getPixel(i, j) == sf::Color::White)
                temp.emplace_back(empty, i * CELL_SIZE, j * CELL_SIZE, Cell::Empty);
            else if (mapSketch.getPixel(i, j) == sf::Color::Red)
                temp.emplace_back(ground, i * CELL_SIZE, j * CELL_SIZE, Cell::Ground);
            else if (mapSketch.getPixel(i, j) == Cell::WALL_COLOR)
                temp.emplace_back(wall, i * CELL_SIZE, j * CELL_SIZE, Cell::Wall);
            else if (mapSketch.getPixel(i, j) == sf::Color::Green) {
                if (mapSketch.getPixel(i - 1, j) != sf::Color::Green) {
                    if (mapSketch.getPixel(i, j - 1) != sf::Color::Green)
                        temp.emplace_back(pipe, sf::IntRect(0, 0, CELL_SIZE, CELL_SIZE),
                                          i * CELL_SIZE, j * CELL_SIZE, Cell::Pipe);
                    else
                        temp.emplace_back(pipe, sf::IntRect(0, CELL_SIZE, CELL_SIZE, CELL_SIZE),
                                          i * CELL_SIZE, j * CELL_SIZE, Cell::Pipe);
                } else {
                    if (mapSketch.getPixel(i, j - 1) != sf::Color::Green)
                        temp.emplace_back(pipe, sf::IntRect(CELL_SIZE, 0, CELL_SIZE, CELL_SIZE),
                                          i * CELL_SIZE, j * CELL_SIZE, Cell::Pipe);
                    else
                        temp.emplace_back(pipe, sf::IntRect(CELL_SIZE, CELL_SIZE, CELL_SIZE, CELL_SIZE),
                                          i * CELL_SIZE, j * CELL_SIZE, Cell::Pipe);
                }
            } else if (mapSketch.getPixel(i, j) == sf::Color::Blue) {
                if (mapSketch.getPixel(i - 1, j) != sf::Color::Blue) {
                    temp.emplace_back(cloud, sf::IntRect(0, 0, CELL_SIZE, CELL_SIZE),
                                      i * CELL_SIZE, j * CELL_SIZE, Cell::Cloud);
                } else
                    temp.emplace_back(cloud, sf::IntRect(CELL_SIZE, 0, CELL_SIZE, CELL_SIZE),
                                      i * CELL_SIZE, j * CELL_SIZE, Cell::Cloud);
            } else if (mapSketch.getPixel(i, j) == sf::Color::Yellow)
                temp.emplace_back(endSign, i * CELL_SIZE, j * CELL_SIZE, Cell::EndSign);
            else if (mapSketch.getPixel(i, j) == sf::Color::Black) {
                if (mapSketch.getPixel(i - 1, j) != sf::Color::Black) {
                    temp.emplace_back(bush, sf::IntRect(0, 0, CELL_SIZE, CELL_SIZE),
                                      i * CELL_SIZE, j * CELL_SIZE, Cell::Bush);
                } else
                    temp.emplace_back(bush, sf::IntRect(CELL_SIZE, 0, CELL_SIZE, CELL_SIZE),
                                      i * CELL_SIZE, j * CELL_SIZE, Cell::Bush);
            }
        }
        this->map.emplace_back(temp);

        /// Enemies
        for (unsigned int j = mapSketch.getSize().y / 2 + 1; j < mapSketch.getSize().y; j++) {
            if (mapSketch.getPixel(i, j) == sf::Color::Red) {
                this->enemies.push_back(EnemyFactory::enemyMushroom(
                        sf::Vector2f(float(i) * CELL_SIZE, (float(j) - float(mapSketch.getSize().y) / 2) * CELL_SIZE)));
            } else if (mapSketch.getPixel(i, j) == sf::Color::Green) {
                this->enemies.push_back(EnemyFactory::enemyTurtle(
                        sf::Vector2f(float(i) * CELL_SIZE, (float(j) - float(mapSketch.getSize().y) / 2) * CELL_SIZE)));
            }
        }
    }
    if (Cell::getCellNum() != (mapSketch.getSize().x * mapSketch.getSize().y / 2))
        throw mapConversionError();

}

/// Functions
const std::vector<std::vector<Cell>> &Map::getMap() const {
    return map;
}

const std::vector<std::shared_ptr<Entity>> &Map::getEnemies() const {
    return enemies;
}

void Map::render(sf::RenderTarget &target, int pos_x) {
    pos_x /= CELL_SIZE;
    for (int i = std::max(pos_x - 20, 0); i < std::min(pos_x + 20, int(this->map.size())); i++)
        for (auto &j: this->map[i])
            j.render(target);
}




