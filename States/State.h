//
// Created by danit on 22.10.2022.
//

#ifndef OOP_STATE_H
#define OOP_STATE_H

#include "../Entities/Entity.h"
#include "../Button.h"

class State {
private:
    /// Variables
    std::stack<State *> &states;
    sf::RenderWindow &window;
    bool quit;
    int escapeCooldown;

    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;

public:
    /// Constructors / Destructors
    State(sf::RenderWindow &window, std::stack<State *> &states);

    virtual ~State();

    friend std::ostream &operator<<(std::ostream &os, const State &state);

    /// Functions
    [[nodiscard]] sf::Vector2f getWindowSize() const;

    [[nodiscard]] const bool &getQuit() const;

    [[nodiscard]] const sf::Vector2i &getMousePosWindow() const;

    [[nodiscard]] std::stack<State *> &getStates() const;

    [[nodiscard]] sf::RenderWindow &getWindow() const;

    void setQuit(bool quit_);

    virtual void endState() = 0;

    virtual void updateMousePositions();

    virtual void update(const float &dt) = 0;

    virtual void render(sf::RenderTarget *target) = 0;

};


#endif //OOP_STATE_H
