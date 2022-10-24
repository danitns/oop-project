//
// Created by danit on 24.10.2022.
//

#include "MainMenuState.h"

/// Constructor / Destructor
MainMenuState::MainMenuState(sf::RenderWindow *window)
        : State(window) {
    this->background.setSize(this->getWindowSize());
    this->background.setFillColor(sf::Color::Red);

}

MainMenuState::~MainMenuState() {

}

/// Functions

void MainMenuState::endState() {
    std::cout << "Ending MainMenuState" << "\n";
}


void MainMenuState::update(const float &dt) {
    this->checkForQuit();
    std::cout << dt << "\n";

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        std::cout << "a is pressed\n";
}

void MainMenuState::render(sf::RenderTarget *target) {
    std::cout << target << "\n";

    target->draw(this->background);
}

