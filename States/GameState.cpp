//
// Created by danit on 24.10.2022.
//

#include "GameState.h"

/// Constructor / Destructor
GameState::GameState(sf::RenderWindow *window)
        : State(window) {

}

GameState::~GameState() {

}

/// Functions

void GameState::endState() {
    std::cout << "Ending GameState" << "\n";
}


void GameState::update(const float &dt) {
    this->checkForQuit();
    std::cout << dt << "\n";

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        std::cout << "a is pressed\n";
}

void GameState::render(sf::RenderTarget *target) {
    std::cout << target << "\n";
}

