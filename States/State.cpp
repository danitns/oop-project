//
// Created by danit on 22.10.2022.
//

#include "State.h"

/// Constructor / Destructor

State::State(sf::RenderWindow *window, std::stack<State *> *states) {
    this->mousePosScreen = sf::Vector2i(0, 0);
    this->mousePosWindow = sf::Vector2i(0, 0);
    this->window = window;
    this->states = states;
    this->quit = false;
    this->escapeCooldown = 0;
}

State::~State() {
    std::cout << "State Destructor\n";
}

std::ostream &operator<<(std::ostream &os, const State &state) {
    os << "quit: " << state.quit << ", escapeCooldown:" << state.escapeCooldown << "\n";
    return os;
}

/// Functions

sf::Vector2f State::getWindowSize() const {
    return sf::Vector2f(this->window->getSize());
}

void State::setQuit(bool quit) {
    this->quit = quit;
}

const bool &State::getQuit() const {
    return this->quit;
}

const sf::Vector2i &State::getMousePosWindow() const {
    return mousePosWindow;
}

std::stack<State *> *State::getStates() const {
    return states;
}

sf::RenderWindow *State::getWindow() const {
    return window;
}

void State::updateMousePositions() {
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
}










