//
// Created by danit on 01.12.2022.
//

#include "Player.h"

/// Constructor
Player::Player() {
    std::cout << "Player Constructor\n";

    this->texture.loadFromFile("Sprites/marioIdle.png");
    this->setTexture(texture);

    this->setPosition(300.f, 200.f);
}


