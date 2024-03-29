//
// Created by danit on 22.10.2022.
//

#ifndef OOP_STATE_H
#define OOP_STATE_H

#include "../Exceptions.h"
#include "../Entities/Entity.h"
#include "../Button.h"

class State {
private:
    /// Variables
    std::stack<std::shared_ptr<State>> &states;
    sf::RenderWindow &window;
    bool quit;
    int escapeCooldown;

    sf::Font font;

protected:
    State(const State &other) = default;

public:
    /// Constructors / Destructors
    State(sf::RenderWindow &window, std::stack<std::shared_ptr<State>> &states);

    virtual ~State() = default;

    friend std::ostream &operator<<(std::ostream &os, const State &state);



    /// Functions
    [[nodiscard]] sf::Vector2f getWindowSize() const;

    [[nodiscard]] const bool &getQuit() const;

    template<typename T>
    sf::Vector2<T> getMousePosWindow() const {
        return sf::Vector2<T>(sf::Mouse::getPosition(this->window).x, sf::Mouse::getPosition(this->window).y);
    }

    [[nodiscard]] std::stack<std::shared_ptr<State>> &getStates() const;

    [[nodiscard]] sf::RenderWindow &getWindow() const;

    const sf::Font &getFont() const;

    void setQuit(bool quit_);

    virtual void update(float dt) = 0;

    virtual void render(sf::RenderTarget &target) = 0;

    virtual int getType();
};

#endif //OOP_STATE_H
