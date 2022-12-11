//
// Created by danit on 22.10.2022.
//

#include "State.h"

/// Constructor / Destructor

State::State(sf::RenderWindow &window, std::stack<std::shared_ptr<State>> &states): states{states}, window{window} {
    std::cout << "State Constructor\n";

    //this->mousePosScreen = sf::Vector2i(0, 0);
    this->mousePosWindow = sf::Vector2i(0, 0);
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
    return sf::Vector2f(this->window.getSize());
}

void State::setQuit(bool quit_) {
    this->quit = quit_;
}

const bool &State::getQuit() const {
    return this->quit;
}

const sf::Vector2i &State::getMousePosWindow() const {
    return mousePosWindow;
}

std::stack<std::shared_ptr<State>> &State::getStates() const {
    return states;
}

sf::RenderWindow &State::getWindow() const {
    return window;
}

void State::updateMousePositions() {
    //this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(this->window);
}













