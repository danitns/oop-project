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


    if(this->player.getDead() == 0)
    {
        /// Map collision
        for (const auto &i: this->map->getMap())
            for (const auto &j: i)
                if (j.getType() == Cell::Ground || j.getType() == Cell::Wall || j.getType() == Cell::Pipe)
                    this->player.cellCollision(j.getGlobalBounds());

        /// Enemy collision
        for(const auto &i: this->map->getEnemies())
            if(i->getDead() == 0)
                if(this->player.entityCollision(i->getGlobalBounds(), dt))
                    i->die(dt);
    }


    /// Apply velocity
    this->player.move();

    if(this->player.getPosition().x > float(this->mapSketch.getSize().x * CELL_SIZE) - 150.f)
    {
        this->gameOverText.setString("Level Completed!");
        this->gameOverText.setOrigin(this->gameOverText.getGlobalBounds().width / 2,
                                     this->gameOverText.getGlobalBounds().height / 2);
        this->stopGame = true;
    }

}

void GameState::updateEnemies(float dt) {
    for (const auto &e: this->map->getEnemies())
        if (e->getPosition().x > this->view.getCenter().x - (this->view.getSize().x / 2 + 50) &&
            e->getPosition().x < this->view.getCenter().x + (this->view.getSize().x / 2 + 50) && e->getDead() < 2) {

            e->update(dt);

            /// Window collision
            e->windowCollision(this->mapSketch, dt);

            /// Map collision
            if(e->getDead() == 0)
                for (const auto &i: this->map->getMap())
                    for (const auto &j: i)
                        if (j.getType() == Cell::Ground || j.getType() == Cell::Wall || j.getType() == Cell::Pipe)
                            e->cellCollision(j.getGlobalBounds());

            /// Apply velocity
            e->move();
        }

}

void GameState::update(const float dt) {
    if (!this->stopGame) {

        if (viewChange < 600) {
            this->view.move(0.f, 10.f);
            viewChange += 10;
        } else {
//            this->view.setCenter(std::min<float>(
//                    std::max<float>(this->player.getPosition().x + this->player.getGlobalBounds().width, 400.f),
//                    float(this->mapSketch.getSize().x) * CELL_SIZE - 400.f), 300.f);
            this->view.setCenter(
                    std::clamp(this->player.getPosition().x, 400.f,
                               float(this->mapSketch.getSize().x) * CELL_SIZE - 400.f),
                    300.f);
        }
        this->getWindow().setView(view);
        this->updateMousePositions();

        this->updatePlayerMovement(dt);
        this->updateEnemies(dt);
    } else
        this->gameOverText.setPosition(this->view.getCenter());

}

void GameState::render(sf::RenderTarget &target) {
    target.draw(this->background);
    this->map->render(target, int(this->player.getPosition().x));
    if (this->stopGame) {
        target.draw(this->gameOverText);
    }
    for (const auto &e: this->map->getEnemies())
        if (e->getPosition().x > this->view.getCenter().x - (this->view.getSize().x / 2 + 50) &&
            e->getPosition().x < this->view.getCenter().x + (this->view.getSize().x / 2 + 50) && (e->getDead() == 0  || e->getDead() == 1))
                e->render(target);
    this->player.render(target);
}










