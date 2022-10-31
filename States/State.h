//
// Created by danit on 22.10.2022.
//

#ifndef OOP_STATE_H
#define OOP_STATE_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>

class State {
private:
    /// Variables
    sf::RenderWindow *window;
    bool quit;
    int escapeCooldown;

public:
    /// Constructors / Destructors
    State(sf::RenderWindow *window);

    virtual ~State();

    friend std::ostream& operator<<(std::ostream& os, const State& state);

    /// Functions
    sf::Vector2f getWindowSize() const;

    const bool &getQuit() const;

    virtual void checkForQuit();

    virtual void endState() = 0;

    virtual void update(const float &dt) = 0;

    virtual void render(sf::RenderTarget *target = nullptr) = 0;

};


#endif //OOP_STATE_H
