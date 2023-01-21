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

    int dead = 0;

    std::shared_ptr<AnimationComponent> animation;

    ///Functions
    virtual void input(float dt) = 0;

public:
    /// Constructor / Destructor
    Entity();

    virtual ~Entity();

    /// Functions
    void setTexture(sf::Texture &texture);

    virtual void setPosition(float x, float y);

    void setMaxVelocity(float maxVelocity_);

    void die(float dt);

    int getDead() const;

    sf::Vector2f getPosition();

    sf::FloatRect getGlobalBounds() const;

    const sf::Vector2f &getVelocity() const;

    virtual void updateVelocity(float dir_x, float dir_y, float dt);

    void move();

    void windowCollision(const sf::Image &mapSketch, float dt);

    bool rightCollision(sf::FloatRect wall);

    bool leftCollision(sf::FloatRect wall);

    bool topCollision(sf::FloatRect wall);

    bool bottomCollision(sf::FloatRect wall);

    void cellCollision(sf::FloatRect wall);

    bool entityCollision(sf::FloatRect hitBox, float dt);

    bool onGround() const;

    virtual void update(float dt);

    virtual void render(sf::RenderTarget &target);
};


#endif //OOP_ENTITY_H
