//
// Created by danit on 24.10.2022.
//

#ifndef OOP_GAMESTATE_H
#define OOP_GAMESTATE_H

#include "State.h"

class GameState :
        public State {
private:
    /// Variables
    Entity player;

public:
    /// Constructor / Destructor
    GameState(sf::RenderWindow *window, std::stack<State *> *states);

    ~GameState() override;

    //friend std::ostream& operator<<(std::ostream& os, const GameState& gameState);

    /// Functions
    void endState() override;

    void update(const float &dt) override;

    void render(sf::RenderTarget *target) override;


};


#endif //OOP_GAMESTATE_H
