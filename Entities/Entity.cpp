//
// Created by danit on 01.11.2022.
//

#include "Entity.h"

/// Constructor / Destructor
Entity::Entity() {
    this->shape.setSize(sf::Vector2f(50.f, 50.f));
    this->movementSpeed = 100.f;
}

Entity::~Entity() {
    std::cout << "Entity Destructor\n";
}


/// Functions
void Entity::move(const float &dt, const float dir_x, const float dir_y) {
    this->shape.move(dir_x * this->movementSpeed * dt, dir_y * this->movementSpeed * dt);
}

void Entity::update(const float &dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->move(dt, -1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->move(dt, 1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->move(dt, 0.f, -1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->move(dt, 0.f, 1.f);
}

void Entity::render(sf::RenderTarget *target) {
    target->draw(this->shape);
}

