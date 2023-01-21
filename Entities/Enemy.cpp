//
// Created by danit on 14.01.2023.
//

#include "Enemy.h"

void Enemy::input(float dt) {
    if(this->getVelocity().x == 0)
        walkDir *= -1.f;
    if(this->getDead() == 0)
        this->updateVelocity(walkDir, 0.f, dt);
}

Enemy::Enemy(sf::Vector2f pos) {
    std::cout << "Enemy Constructor\n";

    this->texture.loadFromFile("Sprites/enemy1.png");
    this->setTexture(texture);
    this->setMaxVelocity(3.f);
    this->walkDir = -1.f;

    std::cout << pos.x <<  " " << pos.y << "\n";
    this->setPosition(pos.x, pos.y);
}

Enemy::~Enemy() {
    std::cout << "Enemy destructor";
}
