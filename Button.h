//
// Created by danit on 04.11.2022.
//

#ifndef OOP_BUTTON_H
#define OOP_BUTTON_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


class Button {
private:
    /// Variables
    enum button_states {
        IDLE = 0, HOVER, PRESSED
    };
    short unsigned buttonState;

    sf::RectangleShape shape;
    sf::Font font;
    sf::Text text;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color pressedColor;

public:
    /// Constructor / Destructor
    Button(float x, float y, float width, float height, const sf::Font &font, const std::string &text,
           const sf::Color &idleColor, const sf::Color &hoverColor, const sf::Color &pressedColor);

    virtual ~Button();

    /// Getters
    bool isPressed() const;

    /// Functions
    void update(sf::Vector2f mousePos);

    void render(sf::RenderTarget &target);
};


#endif //OOP_BUTTON_H
