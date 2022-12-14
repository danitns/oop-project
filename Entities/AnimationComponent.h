//
// Created by danit on 13.12.2022.
//

#ifndef OOP_ANIMATIONCOMPONENT_H
#define OOP_ANIMATIONCOMPONENT_H


#include "../Map/Cell.h"

class AnimationComponent {
private:
    sf::Sprite& sprite;
    int animationSpeed;
    int animationIterator;
    int currentFrame;
    bool flipped;

public:
    explicit AnimationComponent(sf::Sprite& sprite);

    void setFlipped(bool flipped_);
    void idle();
    void walk();
    void jump();
    void update();

public:
};


#endif //OOP_ANIMATIONCOMPONENT_H
