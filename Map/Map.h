//
// Created by danit on 10.12.2022.
//

#ifndef OOP_MAP_H
#define OOP_MAP_H
#include "Cell.h"

class Map {
private:
    /// Variables
    sf::Texture empty;
    sf::Texture ground;
    std::vector<std::vector<Cell>> map;

public:
    /// Constructor
    explicit Map(sf::Image& mapSketch);

    /// Functions
    const std::vector<std::vector<Cell>> &getMap() const;
    void render(sf::RenderTarget& target);
};


#endif //OOP_MAP_H
