//
// Created by danit on 21.10.2022.
//

#include "Game.h"

/// Init functions
void Game::initWindow() {
    this->window.create(sf::VideoMode(800, 600), "C++ SFML Game");
    this->window.setVerticalSyncEnabled(true);
    this->window.setFramerateLimit(60);
}

void Game::initStates() {
    this->states.push(new GameState(&this->window));
    this->states.push(new MainMenuState(&this->window));
}


/// Constructor / Destructor
Game::Game() {
    this->dt = 0.f;
    this->initWindow();
    this->initStates();
}

Game::~Game() {
    while (!this->states.empty()) {
        delete this->states.top();
        this->states.pop();
    }

}

Game &Game::operator=(const Game &other) {
    dtClock = other.dtClock;
    event = other.event;
    dt = other.dt;
    states = other.states;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Game &game) {
    os << "dt: " << game.dt;
    return os;
}

/// Functions

void Game::updateDt() {
    /// dt = the time it takes to render one frame
    this->dt = this->dtClock.restart().asSeconds();

    //std::cout << dt << "\n";
}


void Game::updateEvents() {
    while (this->window.pollEvent(this->event)) {
        if (this->event.type == sf::Event::Closed)
            this->window.close();
    }
}


void Game::update() {
    this->updateEvents();

    if (!this->states.empty()) {
        this->states.top()->update(this->dt);

        if (this->states.top()->getQuit()) {
            this->states.top()->endState();
            delete this->states.top();
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
        this->states.top()->render(&this->window);

    window.display();
}

void Game::run() {
    while (this->window.isOpen()) {
        this->updateDt();
        this->update();
        this->render();
    }
}






