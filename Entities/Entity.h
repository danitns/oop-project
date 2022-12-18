//
// Created by danit on 01.11.2022.
//

#ifndef OOP_ENTITY_H
#define OOP_ENTITY_H

#include "../Map/Cell.h"
#include "../Entities/AnimationComponent.h"

class Entity {
private:
    /// Variables
    sf::Sprite sprite;
    sf::FloatRect hitbox;

    sf::Vector2f velocity;
    float maxVelocity;
    float acceleration;
    float deceleration;
    float gravityForce;
    float jumpForce;

    bool dead = false;

    std::shared_ptr<AnimationComponent> animation;

    ///Functions
    virtual void input(float dt) = 0;

    virtual void die(float dt) = 0;

public:
    /// Constructor / Destructor
    Entity();

    virtual ~Entity();

    /// Functions
    void setTexture(sf::Texture &texture);

    virtual void setPosition(float x, float y);

    sf::Vector2f getPosition();

    sf::FloatRect getGlobalBounds() const;

    virtual void updateVelocity(float dir_x, float dir_y, float dt);

    void move();

    void windowCollision(const sf::Image &mapSketch, float dt);

    void cellCollision(sf::FloatRect wall);

    bool onGround() const;

    virtual void update(float dt);

    virtual void render(sf::RenderTarget &target);
};


#endif //OOP_ENTITY_H
