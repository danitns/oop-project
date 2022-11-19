//
// Created by danit on 21.10.2022.
//

#include "Game.h"

/// Init functions
void Game::initWindow() {
    this->window.create(sf::VideoMode(800, 600), "C++ SFML Game");
    this->window.setVerticalSyncEnabled(true);
    this->window.setFramerateLimit(60);
    //this->window.setKeyRepeatEnabled(false);
}

void Game::initStates() {
    this->states.push(new MainMenuState(this->window, this->states));
}


/// Constructor / Destructor
Game::Game() {
    this->dt = 0.f;
    this->initWindow();
    this->initStates();
}

Game::Game(const Game &other): event{other.event}, dtClock{other.dtClock}, dt{other.dt} {
    /// ???? Deep copy pt states
    this->states = *new std::stack<State *>;
    std::stack<State *> copy(other.states);
    std::stack<State *> reverse_order;
    while(!copy.empty()) {
        reverse_order.push(copy.top());
        copy.pop();
    }
    while(!reverse_order.empty()) {
        states.push(reverse_order.top());
        reverse_order.pop();
    }
}

Game &Game::operator=(const Game &other) {
    dtClock = other.dtClock;
    event = other.event;
    dt = other.dt;
    Game copy(other);
    std::swap(this->states, copy.states);
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Game &game) {
    os << "dt: " << game.dt;
    return os;
}

Game::~Game() {
    while (!this->states.empty()) {
        delete this->states.top();
        this->states.pop();
    }

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
        if (this->event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
            this->states.top()->setQuit(true);
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











