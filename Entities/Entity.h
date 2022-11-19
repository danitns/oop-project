//
// Created by danit on 01.11.2022.
//

#ifndef OOP_ENTITY_H
#define OOP_ENTITY_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>


class Entity {
private:
    /// Variables
    sf::RectangleShape shape;
    float movementSpeed;

public:
    /// Constructor / Destructor
    Entity();

    virtual ~Entity();

    /// Functions
    virtual void move(float dt, float x, float y);

    virtual void update(const float &dt);

    virtual void render(sf::RenderTarget *target);
};


#endif //OOP_ENTITY_H
