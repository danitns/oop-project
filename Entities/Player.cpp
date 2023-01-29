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

/// Constructor
Player::Player() {
    this->texture.loadFromFile("Sprites/marioSprite.png");
    this->setTexture(texture);

    this->setPosition(100.f, 400.f);
}


