//
// Created by danit on 14.01.2023.
//

#ifndef OOP_ENEMY_H
#define OOP_ENEMY_H

#include "Entity.h"

class Enemy:
        public Entity{
private:
    sf::Texture texture;
    float walkDir;

    void input(float dt) override;

public:
    explicit Enemy(sf::Vector2f pos);

    ~Enemy() override;
};


#endif //OOP_ENEMY_H
