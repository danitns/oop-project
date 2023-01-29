//
// Created by danit on 22.01.2023.
//

#include "PausedState.h"

void PausedState::initButtons() {
    this->buttons["PREV_GAME_STATE"] = std::make_shared<Button>(150, 50, this->getWindow().getSize().x / 2, 400,
                                                                this->getFont(), "Resume",
                                                                sf::Color(0, 51, 102),
                                                                sf::Color(26, 140, 255),
                                                                sf::Color(128, 191, 255));

//    this->buttons["NEW_GAME_STATE"] = std::make_shared<Button>(150, 50, this->getWindow().getSize().x / 2, 400,
//                                                           this->getFont(), "New Game",
//                                                           sf::Color(0, 51, 102),
//                                                           sf::Color(26, 140, 255),
//                                                           sf::Color(128, 191, 255));
//
//    this->buttons["EXIT_STATE"] = std::make_shared<Button>(150, 50, this->getWindow().getSize().x / 2, 500,
//                                                           this->getFont(), "Quit Game",
//                                                           sf::Color(0, 51, 102),
//                                                           sf::Color(26, 140, 255),
//                                                           sf::Color(128, 191, 255));
}

PausedState::PausedState(sf::RenderWindow &window, std::stack<std::shared_ptr<State>> &states) : State(window, states) {
    this->initButtons();
    this->getWindow().setView(this->getWindow().getDefaultView());

    this->text.setFont(getFont());
    this->text.setFillColor(sf::Color(255, 255, 255));
    this->text.setString("The game is paused");
    this->text.setCharacterSize(75);
    this->text.setPosition(float(this->getWindow().getSize().x) / 2 - this->text.getGlobalBounds().width / 2, 200.f);

    this->background.setSize(this->getWindowSize());
    this->background.setFillColor(sf::Color(49, 118, 255));
}


void PausedState::updateButtons() {
    for (auto const &button: this->buttons) {
        button.second->update(this->getMousePosWindow<float>());
    }

    if (this->buttons["PREV_GAME_STATE"]->isPressed())
        this->setQuit(true);

//    if (this->buttons["PREV_GAME_STATE"]->isPressed()) {
//        //this->getStates().push(std::make_shared<GameState>(this->getWindow(), this->getStates()));
//        this->getStates().top()->setQuit(true);
//        this->getStates().top()->setQuit(true);
//    }
//
//    if (this->buttons["EXIT_STATE"]->isPressed()) {
//        this->setQuit(true);
//        this->getStates().top()->setQuit(true);
//    }
}

void PausedState::update(float dt) {
    if (dt == 0) {
    }

    this->updateButtons();
}

void PausedState::renderButtons(sf::RenderTarget &target) {
    for (auto const &button: this->buttons) {
        button.second->render(target);
    }
}

void PausedState::render(sf::RenderTarget &target) {
    target.draw(this->background);
    this->renderButtons(target);
    target.draw(this->text);
}
