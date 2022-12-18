//
// Created by danit on 01.12.2022.
//

#include "Player.h"

void Player::input(float dt) {
    if (this->getDead() == 0) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            this->updateVelocity(-1.f, 0.f, dt);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            this->updateVelocity(1.f, 0.f, dt);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->onGround())
            this->updateVelocity(0.f, -1.f, dt);
    }

}

void Player::die(float dt) {
    if (!this->dead) {
        this->updateVelocity(0.f, float(-1.6), dt);
        this->dead = 1;
    } else
        this->dead = 2;
}

/// Constructor
Player::Player() {
    std::cout << "Player Constructor\n";

    this->texture.loadFromFile("Sprites/marioSprite.png");
    this->setTexture(texture);

    this->dead = 0;

    this->setPosition(100.f, 400.f);
}

int Player::getDead() const {
    return dead;
}


