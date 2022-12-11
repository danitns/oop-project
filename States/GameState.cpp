//
// Created by danit on 24.10.2022.
//

#include "GameState.h"

/// Constructor / Destructor
GameState::GameState(sf::RenderWindow &window, std::stack<std::shared_ptr<State>> &states)
        : State(window, states) {
    std::cout << "GameState Constructor\n";

    this->view = sf::View(sf::FloatRect
            (0.f, 0.f,
             static_cast<float>(SCREEN_WIDTH), static_cast<float>(SCREEN_HEIGHT)));

    this->background.setSize(sf::Vector2f (3 * this->getWindowSize().x, this->getWindowSize().y));
    this->background.setFillColor(sf::Color(49,118, 255));
    this->background.setPosition(-200.f, 0.f);

    this->mapSketch.loadFromFile("Sprites/map1.png");

    this->map = std::make_shared<Map>(mapSketch);
}

GameState::~GameState() {
    /// Reset view
    this->getWindow().setView(this->getWindow().getDefaultView());

    std::cout << "GameState Destructor\n";
}

std::shared_ptr<State> GameState::clone() const {
    return std::make_shared<GameState>(*this);
}

/// Functions
void GameState::updatePlayerMovement(float dt) {
    /// Player input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->player.updateVelocity(-1.f, 0.f, dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->player.updateVelocity(1.f, 0.f, dt);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && this->player.onGround())
        this->player.updateVelocity(0.f, -1.f, dt);

    /// Deceleration
    this->player.update(dt);

    /// Window collision
    this->player.windowCollision(this->mapSketch);

    /// Map collision
    for(const auto & i : this->map->getMap())
        for(const auto & j : i)
            if(j.getType() == Cell::Ground)
                this->player.cellCollision(j.getGlobalBounds());

    /// Apply velocity
    this->player.move();

}

void GameState::update(const float dt) {
    this->view.move(this->player.getVelocity().x, 0.f);
    this->getWindow().setView(view);

    this->updateMousePositions();
    this->updatePlayerMovement(dt);
}

void GameState::render(sf::RenderTarget &target) {
    target.draw(this->background);
    this->map->render(target);
    this->player.render(target);
}






