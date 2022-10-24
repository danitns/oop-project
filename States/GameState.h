//
// Created by danit on 24.10.2022.
//

#ifndef OOP_GAMESTATE_H
#define OOP_GAMESTATE_H

#include "State.h"

class GameState :
        public State {
private:

public:
    /// Constructor / Destructor
    explicit GameState(sf::RenderWindow *window);

    virtual ~GameState();

    /// Functions
    void endState();

    void update(const float &dt);

    void render(sf::RenderTarget *target = nullptr);


};


#endif //OOP_GAMESTATE_H
