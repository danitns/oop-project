//
// Created by danit on 24.10.2022.
//

#include "GameState.h"

/// Constructor / Destructor
GameState::GameState(sf::RenderWindow &window, std::stack<State *> &states)
        : State(window, states) {

}

GameState::~GameState() {
    std::cout << "GameState Destructor\n";
}

/// Functions

void GameState::endState() {
    std::cout << "Ending GameState\n";
}


void GameState::update(const float &dt) {
    this->updateMousePositions();
    this->player.update(dt);
}

void GameState::render(sf::RenderTarget *target) {

    this->player.render(target);
}


