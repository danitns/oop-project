//
// Created by danit on 04.11.2022.
//

#include "Button.h"

/// Constructor/Destructor
Button::Button(float width, float height, float x, float y, const sf::Font &font, const std::string &text,
               const sf::Color &idleColor, const sf::Color &hoverColor, const sf::Color &pressedColor)
        : font(font), idleColor(idleColor), hoverColor(hoverColor), pressedColor(pressedColor) {
    this->buttonState = IDLE;

    this->shape.setSize(sf::Vector2f(width, height));
    this->shape.setOrigin(width / 2, height / 2);

    this->shape.setPosition(sf::Vector2f(x, y));
    this->shape.setFillColor(idleColor);
    this->text.setFont(this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(12);
    this->text.setPosition(
            this->shape.getPosition().x - this->text.getGlobalBounds().width / 2,
            this->shape.getPosition().y - this->text.getGlobalBounds().height / 2
    );

    this->shape.setFillColor(this->idleColor);
}

/// Getters
bool Button::isPressed() const {
    return this->buttonState == PRESSED;
}

/// Functions
void Button::update(sf::Vector2f mousePos) {
    /// Idle
    this->buttonState = IDLE;
    this->shape.setFillColor(this->idleColor);

    /// Hover
    if (this->shape.getGlobalBounds().contains(mousePos)) {
        this->buttonState = HOVER;
        this->shape.setFillColor(this->hoverColor);

        /// Pressed
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->buttonState = PRESSED;
            this->shape.setFillColor(this->pressedColor);
        }
    }
}

void Button::render(sf::RenderTarget &target) {
    target.draw(this->shape);
    target.draw(this->text);
}






