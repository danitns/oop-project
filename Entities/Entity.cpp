//
// Created by danit on 01.11.2022.
//

#include "Entity.h"

/// Constructor / Destructor
Entity::Entity() {
    this->dead = 0;

    this->velocity = sf::Vector2f(0.f, -1.f);
    this->maxVelocity = 8.f;
    this->acceleration = 25.f;
    this->deceleration = 16.f;
    this->jumpForce = 1500.f;
    this->gravityForce = 100.f;
    this->animation = std::make_shared<AnimationComponent>(this->sprite);
}

Entity::Entity(float maxVelocity, float acceleration, float deceleration) : maxVelocity(maxVelocity),
    acceleration(acceleration), deceleration(deceleration) {
    this->dead = 0;
    this->velocity = sf::Vector2f(0.f, -1.f);
    this->jumpForce = 1500.f;
    this->gravityForce = 100.f;
    this->animation = std::make_shared<AnimationComponent>(this->sprite);
}


/// Functions
void Entity::setTexture(sf::Texture &texture) {
    this->sprite.setTexture(texture);
}

void Entity::setPosition(const float x, const float y) {
    this->sprite.setPosition(sf::Vector2f(x, y));
}

void Entity::die(float dt) {
    if (!dead) {
        this->updateVelocity(0.f, -0.9f, dt);
        this->dead = 1;
    } else
        this->dead = 2;
}

int Entity::getDead() const {
    return dead;
}

sf::Vector2f Entity::getPosition() {
    return this->sprite.getPosition();
}

sf::FloatRect Entity::getGlobalBounds() const {
    return this->sprite.getGlobalBounds();
}

const sf::Vector2f &Entity::getVelocity() const {
    return velocity;
}

void Entity::updateVelocity(const float dir_x, const float dir_y, const float dt) {
    this->velocity.x += this->acceleration * dir_x * dt;
    this->velocity.y += this->jumpForce * dir_y * dt;
}

void Entity::move() {
    this->sprite.move(this->velocity);
}

void Entity::windowCollision(const sf::Image& mapSketch, const float dt) {
    this->hitbox = this->sprite.getGlobalBounds();
    this->hitbox.left += velocity.x;
    this->hitbox.top += velocity.y;
    /// Right collision
    if(this->hitbox.left >= static_cast<float>(mapSketch.getSize().x * CELL_SIZE) - this->hitbox.getSize().x)
    {
        this->velocity.x = 0.f;
        this->sprite.setPosition(static_cast<float>(mapSketch.getSize().x * CELL_SIZE) - this->hitbox.getSize().x, this->sprite.getPosition().y);
    }
    /// Left collision
    if(this->hitbox.left <= 0.f)
    {
        this->velocity.x = 0.f;
        this->sprite.setPosition(0.f, this->sprite.getPosition().y);
    }
    /// Bottom collision
    if(this->hitbox.top >= static_cast<float>(mapSketch.getSize().y * CELL_SIZE) - this->hitbox.getSize().y)
    {
        this->die(dt);
        this->velocity.x = 0.f;
    }

}

bool Entity::rightCollision(sf::FloatRect wall) {
    if(sprite.getGlobalBounds().left < wall.left
       && sprite.getGlobalBounds().left + sprite.getGlobalBounds().width < wall.left + wall.width
       && sprite.getGlobalBounds().top < wall.top + wall.height
       && sprite.getGlobalBounds().top + sprite.getGlobalBounds().height > wall.top)
        return true;
    return false;
}

bool Entity::leftCollision(sf::FloatRect wall) {
    if(sprite.getGlobalBounds().left > wall.left
       && sprite.getGlobalBounds().left + sprite.getGlobalBounds().width > wall.left + wall.width
       && sprite.getGlobalBounds().top < wall.top + wall.height
       && sprite.getGlobalBounds().top + sprite.getGlobalBounds().height > wall.top)
        return true;
    return false;
}

bool Entity::topCollision(sf::FloatRect wall) {
    if(sprite.getGlobalBounds().top > wall.top
       && sprite.getGlobalBounds().top + sprite.getGlobalBounds().height > wall.top + wall.height
       && sprite.getGlobalBounds().left < wall.left + wall.width
       && sprite.getGlobalBounds().left + sprite.getGlobalBounds().width > wall.left)
        return true;
    return false;
}

bool Entity::bottomCollision(sf::FloatRect wall) {
    if(sprite.getGlobalBounds().top < wall.top
       && sprite.getGlobalBounds().top + sprite.getGlobalBounds().height < wall.top + wall.height
       && sprite.getGlobalBounds().left < wall.left + wall.width
       && sprite.getGlobalBounds().left + sprite.getGlobalBounds().width > wall.left)
        return true;
    return false;
}

void Entity::cellCollision(sf::FloatRect wall) {
    this->hitbox = this->sprite.getGlobalBounds();
    this->hitbox.left += velocity.x;
    this->hitbox.top += velocity.y;
    if(this->hitbox.intersects(wall))
    {
        /// Right collision
        if(rightCollision(wall))
        {
            velocity.x = 0.f;
            sprite.setPosition(wall.left - sprite.getGlobalBounds().width, sprite.getGlobalBounds().top);
        }
        /// Left collision
        else if(leftCollision(wall))
        {
            velocity.x = 0.f;
            sprite.setPosition(wall.left + wall.width, sprite.getGlobalBounds().top);
        }
        /// Top collision
        else if(topCollision(wall))
        {
            velocity.y = 1.f;
            sprite.setPosition(sprite.getGlobalBounds().left, wall.top + wall.height);
        }
        /// Bottom collision
        else if(bottomCollision(wall))
        {
            velocity.y = 0;
            sprite.setPosition(sprite.getGlobalBounds().left, wall.top - sprite.getGlobalBounds().height);
        }
    }

}

bool Entity::entityCollision(sf::FloatRect hitBox, float dt) {
    this->hitbox = this->sprite.getGlobalBounds();
    this->hitbox.left += velocity.x;
    this->hitbox.top += velocity.y;
    if(this->hitbox.intersects(hitBox))
    {
        /// Right, left, top collision
        if(rightCollision(hitBox) || leftCollision(hitBox) || topCollision(hitBox))
        {
            velocity.x = 0.f;
            velocity.y = 0.f;
            die(dt);
            sprite.setPosition(hitBox.left - sprite.getGlobalBounds().width, sprite.getGlobalBounds().top);
        }
            /// Bottom collision
        else if(bottomCollision(hitBox))
        {
            velocity.y = -15.f;
            return true;
        }
    }
    return false;
}

bool Entity::onGround() const {
    return this->velocity.y == 0;
}

void Entity::update(const float dt) {
    this->input(dt);
    this->animation->update();
    if(this->velocity.x > 0.f)
    {
        //Max velocity check
        this->velocity.x = std::min<float>(this->velocity.x, this->maxVelocity);

        //Deceleration
        this->velocity.x -= deceleration * dt;
        if(this->velocity.x < 0.f)
            this->velocity.x = 0.f;
    }
    else if(this->velocity.x < 0.f)
    {
        //Max velocity check
        if(this->velocity.x < -this->maxVelocity)
            this->velocity.x = -this->maxVelocity;

        //Deceleration
        this->velocity.x += deceleration * dt;
        if(this->velocity.x > 0.f)
            this->velocity.x = 0.f;
    }

    this->velocity.y += this->gravityForce * dt;
}

void Entity::render(sf::RenderTarget &target) {
    if(this->velocity.x == 0.f)
        this->animation->idle();
    else {
        this->animation->walk();

        if(this->velocity.x > 0.f)
            this->animation->setFlipped(false);
        else
            this->animation->setFlipped(true);

    }
    if(!this->onGround())
        this->animation->jump();
    if(this->dead)
        this->animation->die();

    target.draw(this->sprite);
}

























