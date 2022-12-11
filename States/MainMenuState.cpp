//
// Created by danit on 24.10.2022.
//

#include "MainMenuState.h"

/// Init functions

void MainMenuState::initFonts() {
    if (!this->font.loadFromFile("Fonts/alagard.ttf")) {
        std::cout << "ERROR::MainMenuState::initFonts";
    }

    std::cout << "initFonts" << "\n";
}

void MainMenuState::initButtons() {
    this->buttons["GAME_STATE"] = std::make_shared<Button>(100, 100, 150, 50,
                                             this->font, "New Game",
                                             sf::Color(0, 51, 102),
                                             sf::Color(26, 140, 255),
                                             sf::Color(128, 191, 255));

    this->buttons["EXIT_STATE"] = std::make_shared<Button>(100, 160, 150, 50,
                                             this->font, "Quit Game",
                                             sf::Color(0, 51, 102),
                                             sf::Color(26, 140, 255),
                                             sf::Color(128, 191, 255));
}

/// Constructor / Destructor
MainMenuState::MainMenuState(sf::RenderWindow &window, std::stack<std::shared_ptr<State>> &states)
        : State(window, states) {
    std::cout << "MainMenuState Constructor\n";

    this->initFonts();
    this->initButtons();

    this->background.setSize(this->getWindowSize());
    this->background.setFillColor(sf::Color(38, 38, 38, 255));
}

MainMenuState::~MainMenuState() {
//    for (auto const &button: this->buttons) {
//        delete button.second;
//    }
    std::cout << "MainMenuState Destructor\n";
}

std::shared_ptr<State> MainMenuState::clone() const {
    return std::make_shared<MainMenuState>(*this);
}

/// Functions

void MainMenuState::updateButtons() {
    for (auto const &button: this->buttons) {
        button.second->update(static_cast<sf::Vector2f>(this->getMousePosWindow()));
    }

    if (this->buttons["GAME_STATE"]->isPressed()) {
        this->getStates().push(std::make_shared<GameState>(this->getWindow(), this->getStates()));
    }

    if (this->buttons["EXIT_STATE"]->isPressed()) {
        this->setQuit(true);
    }

}

void MainMenuState::update(const float dt) {
    if (dt == 0) {
    }

    this->updateMousePositions();
    this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget &target) {
    for (auto const &button: this->buttons) {
        button.second->render(target);
    }
}


void MainMenuState::render(sf::RenderTarget &target) {

    target.draw(this->background);
    this->renderButtons(target);
}











