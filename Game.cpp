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
    this->states.push(std::make_shared<MainMenuState>(this->window, this->states));
}


/// Constructor / Destructor
Game::Game() {
    std::cout << "Game Constructor\n";

    this->dt = 0.f;
    this->initWindow();
    this->initStates();
}

[[maybe_unused]] Game::Game(const Game &other): event{other.event}, dtClock{other.dtClock}, dt{other.dt} {
    /// Deep copy pt states
    this->states = *new std::stack<std::shared_ptr<State>>;
    std::stack<std::shared_ptr<State>> copy(other.states);
    std::stack<std::shared_ptr<State>> reverse_order;
    while(!copy.empty()) {
        reverse_order.push(copy.top()->clone());
        copy.pop();
    }
    while(!reverse_order.empty()) {
        states.push(reverse_order.top()->clone());
        reverse_order.pop();
    }
}

Game &Game::operator=(Game other) {
    std::swap(this->states, other.states);
    std::swap(this->dtClock, other.dtClock);
    std::swap(this->event, other.event);
    std::swap(this->dt, other.dt);
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Game &game) {
    os << "dt: " << game.dt;
    return os;
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
    }
}


void Game::update() {
    this->updateEvents();

    if (!this->states.empty()) {
        this->states.top()->update(this->dt);

        if (this->states.top()->getQuit()) {
            //delete this->states.top();
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











