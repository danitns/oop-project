//
// Created by danit on 22.01.2023.
//

#ifndef OOP_PAUSEDSTATE_H
#define OOP_PAUSEDSTATE_H


#include "MainMenuState.h"

class PausedState :
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
    PausedState(sf::RenderWindow &window, std::stack<std::shared_ptr<State>> &states);

    ~PausedState() override = default;

    [[maybe_unused]] std::shared_ptr<State> clone() const override;

    /// Functions
    void updateButtons();

    void update(float dt) override;

    void renderButtons(sf::RenderTarget &target);

    void render(sf::RenderTarget &target) override;
};


#endif //OOP_PAUSEDSTATE_H
