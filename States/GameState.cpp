//
// Created by danit on 24.10.2022.
//

#include "GameState.h"

/// Constructor / Destructor
GameState::GameState(sf::RenderWindow &window, std::stack<std::shared_ptr<State>> &states)
        : State(window, states) {
    std::cout << "GameState Constructor\n";
    this->stopGame = false;

    this->view = this->getWindow().getDefaultView();
    this->view.move(0.f, -600.f);
    this->getWindow().setView(this->view);

    this->gameOverText.setString("Game Over");
    this->gameOverText.setFont(this->getFont());
    this->gameOverText.setCharacterSize(50);
    this->gameOverText.setOrigin(this->gameOverText.getGlobalBounds().width / 2,
                                 this->gameOverText.getGlobalBounds().height / 2);
    this->gameOverText.setPosition(float(this->getWindow().getSize().x) / 2, float(this->getWindow().getSize().y) / 2);

    this->backgroundTexture.loadFromFile("Sprites/gameStateBackground.png");
    this->background.setTexture(backgroundTexture);
    this->background.setPosition(-200.f, -600.f);

    try {
        this->mapSketch.loadFromFile("Sprites/map1.png");

        this->map = std::make_shared<Map>(mapSketch);
    } catch (const gameError &error) {
        std::cout << error.what() << '\n';
    }
}

GameState::~GameState() {
    Cell::setCellNum(0);
    /// Reset view
    this->getWindow().setView(this->getWindow().getDefaultView());
}

std::shared_ptr<State> GameState::clone() const {
    return std::make_shared<GameState>(*this);
}

/// Functions
void GameState::updatePlayerMovement(float dt) {
    /// Keyboard input & deceleration
    this->player.update(dt);

    /// Window collision
    this->player.windowCollision(this->mapSketch, dt);
    if (this->player.getDead() == 2)
        this->stopGame = true;

    /// Map collision
    for (const auto &i: this->map->getMap())
        for (const auto &j: i)
            if (j.getType() == Cell::Ground)
                this->player.cellCollision(j.getGlobalBounds());

    /// Apply velocity
    this->player.move();

}

void GameState::update(const float dt) {
    if (!this->stopGame) {
        this->view.setCenter(std::min<float>(std::max<float>(this->player.getPosition().x, 400.f), float(this->mapSketch.getSize().x) * CELL_SIZE - 400.f), 300.f);
        this->getWindow().setView(view);


        if (viewChange < 600) {
            this->view.move(0.f, 10.f);
            viewChange += 10;
        }

        this->updateMousePositions();

        this->updatePlayerMovement(dt);
    } else
        this->gameOverText.setPosition(this->view.getCenter());

}

void GameState::render(sf::RenderTarget &target) {
    target.draw(this->background);
    this->map->render(target);
    if (this->stopGame) {
        target.draw(this->gameOverText);
    }
    this->player.render(target);


}








