//
// Created by danit on 21.10.2022.
//

#ifndef OOP_GAME_H
#define OOP_GAME_H

#include <ostream>
#include "States/MainMenuState.h"

class Game {
private:
    /// Variables
    sf::RenderWindow window;
    sf::Event event{};

    sf::Clock dtClock;
    float dt;

    std::stack<std::shared_ptr<State>> states;

    /// Init functions
    void initWindow();

    void initStates();

public:
    /// Constructors / Destructors:
    Game();

    Game(const Game &other) = delete;

    Game &operator=(Game other) = delete;

    ~Game();

    static Game &get_game();

    /// Functions
    void updateDt();

    void updateEvents();

    void update();

    void render();

    void run();
};


#endif //OOP_GAME_H
