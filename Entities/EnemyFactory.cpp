//
// Created by danit on 27.01.2023.
//

#include "EnemyFactory.h"

std::shared_ptr<EnemyTemplate<float>> EnemyFactory::enemyMushroom(sf::Vector2f pos) {
    return std::make_shared<EnemyTemplate<float>>(pos, 3.f, 25.f, 16.f, -1.f, EnemyTemplate<float>::enemyType::mushroom);
}

std::shared_ptr<EnemyTemplate<double>> EnemyFactory::enemyTurtle(sf::Vector2f pos) {
    return std::make_shared<EnemyTemplate<double>>(pos, 2.f, 20.f, 14.f, -1.f, EnemyTemplate<double>::enemyType::turtle);
}
