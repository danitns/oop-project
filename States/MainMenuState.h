//
// Created by danit on 24.10.2022.
//

#ifndef OOP_MAINMENUSTATE_H
#define OOP_MAINMENUSTATE_H

#include "GameState.h"

class MainMenuState :
        public State {
private:
    /// Variables
    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, Button *> buttons;

    /// Init functions
    void initFonts();

    void initButtons();

public:
    /// Constructor / Destructor
    MainMenuState(sf::RenderWindow *window, std::stack<State *> *states);

    ~MainMenuState() override;

    /// Functions
    void endState() override;

    void updateButtons();

    void update(const float &dt) override;

    void renderButtons(sf::RenderTarget *target);

    void render(sf::RenderTarget *target) override;

};


#endif //OOP_MAINMENUSTATE_H
