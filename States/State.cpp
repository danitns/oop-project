//
// Created by danit on 22.10.2022.
//

#include "State.h"

/// Constructor / Destructor

State::State(sf::RenderWindow *window) {
    this->window = window;
    this->quit = false;
    this->escapeCooldown = 0;
}

State::~State() {

}

/// Functions
sf::Vector2f State::getWindowSize() const {
    return sf::Vector2f(this->window->getSize());
}


void State::checkForQuit() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && escapeCooldown == 10)
    {
        this->quit = true;
        this->escapeCooldown = 0;
    }
    if(escapeCooldown < 10)
        escapeCooldown++;
}

const bool &State::getQuit() const {
    return this->quit;
}

