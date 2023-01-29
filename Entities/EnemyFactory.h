//
// Created by danit on 27.01.2023.
//

#ifndef OOP_ENEMYFACTORY_H
#define OOP_ENEMYFACTORY_H
#include "EnemyTemplate.h"

class EnemyFactory {
public:
    static std::shared_ptr<EnemyTemplate<float>> enemyMushroom(sf::Vector2f pos);
    static std::shared_ptr<EnemyTemplate<double>> enemyTurtle(sf::Vector2f pos);
};


#endif //OOP_ENEMYFACTORY_H
