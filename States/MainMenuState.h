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

    sf::Text text;

    std::map<std::string, std::shared_ptr<Button>> buttons;

    /// Init functions
    void initButtons();

public:
    /// Constructor / Destructor
    MainMenuState(sf::RenderWindow &window, std::stack<std::shared_ptr<State>> &states);

    ~MainMenuState() override = default;


    /// Functions
    void updateButtons();

    void update(float dt) override;

    void renderButtons(sf::RenderTarget &target);

    void render(sf::RenderTarget &target) override;

};


#endif //OOP_MAINMENUSTATE_H
