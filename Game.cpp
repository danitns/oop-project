//
// Created by danit on 21.10.2022.
//

#include "Game.h"
#include "States/PausedState.h"

/// Init functions
void Game::initWindow() {
    this->window.create(sf::VideoMode(800, 600), "C++/SFML Mario");
    this->window.setVerticalSyncEnabled(true);
    this->window.setFramerateLimit(60);
}

void Game::initStates() {
    this->states.push(std::make_shared<MainMenuState>(this->window, this->states));
}


/// Constructor / Destructor
Game::Game() {
    this->dt = 0.f;
    this->initWindow();
    this->initStates();
}

Game::~Game() {
    while (!this->states.empty()) {
        this->states.pop();
    }
}

/// Functions

void Game::updateDt() {
    /// dt = the time it takes to render one frame
    this->dt = this->dtClock.restart().asSeconds();
}


void Game::updateEvents() {
    while (this->window.pollEvent(this->event)) {
        if (this->event.type == sf::Event::Closed)
            this->window.close();
        if (this->event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            this->states.top()->setQuit(true);
        if (this->event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P && this->states.top()->getType() == 1)
                this->states.push(std::make_shared<PausedState>(this->window, this->states));
    }
}


void Game::update() {
    this->updateEvents();

    if (!this->states.empty()) {
        this->states.top()->update(this->dt);

        if (this->states.top()->getQuit()) {
            this->states.pop();
        }
    }
        /// Aplication end
    else {
        this->window.close();
    }
}

void Game::render() {
    window.clear();

    if (!this->states.empty())
        this->states.top()->render(this->window);
    window.display();
}

void Game::run() {
    while (this->window.isOpen()) {
        this->updateDt();
        this->update();
        this->render();
    }
}

Game &Game::get_game() {
    static Game game;
    return game;
}













