//
// Created by danit on 10.12.2022.
//

#ifndef OOP_MAP_H
#define OOP_MAP_H

#include "Cell.h"
#include "../Entities/Enemy.h"

class Map {
private:
    /// Variables
    sf::Texture empty;
    sf::Texture ground;
    sf::Texture wall;
    sf::Texture pipe;
    std::vector<std::vector<Cell>> map;
    std::vector<std::shared_ptr<Enemy>> enemies;

public:
    /// Constructor
    explicit Map(sf::Image &mapSketch);

    /// Functions
    const std::vector<std::vector<Cell>> &getMap() const;

    const std::vector<std::shared_ptr<Enemy>> &getEnemies() const;

    void render(sf::RenderTarget &target, int pos_x);
};


#endif //OOP_MAP_H
