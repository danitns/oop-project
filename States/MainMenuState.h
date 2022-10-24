//
// Created by danit on 24.10.2022.
//

#ifndef OOP_MAINMENUSTATE_H
#define OOP_MAINMENUSTATE_H

#include "GameState.h"

class MainMenuState :
        public State{
private:
    sf::RectangleShape background;

public:
    /// Constructor / Destructor
    explicit MainMenuState(sf::RenderWindow *window);

    virtual ~MainMenuState();

    /// Functions
    void endState();

    void update(const float &dt);

    void render(sf::RenderTarget *target = nullptr);

};


#endif //OOP_MAINMENUSTATE_H
