//
// Created by danit on 13.12.2022.
//1

#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(sf::Sprite &sprite) : sprite(sprite) {
    animationSpeed = 5;
    flipped = false;
    currentFrame = 0;
    animationIterator = 0;
}

void AnimationComponent::setFlipped(bool flipped_) {
    this->flipped = flipped_;
}

void AnimationComponent::idle() {
    if (!flipped)
        this->sprite.setTextureRect(sf::IntRect(0.f, 0.f, CELL_SIZE, CELL_SIZE));
    else
        this->sprite.setTextureRect(sf::IntRect(CELL_SIZE, 0.f, -CELL_SIZE, CELL_SIZE));
}

void AnimationComponent::walk() {
    if (!flipped)
        this->sprite.setTextureRect(sf::IntRect(currentFrame * CELL_SIZE, CELL_SIZE, CELL_SIZE, CELL_SIZE));
    else
        this->sprite.setTextureRect(sf::IntRect((1 + currentFrame) * CELL_SIZE, CELL_SIZE, -CELL_SIZE, CELL_SIZE));
}

void AnimationComponent::jump() {
    if (!flipped)
        this->sprite.setTextureRect(sf::IntRect(0.f, 2 * CELL_SIZE, CELL_SIZE, CELL_SIZE));
    else
        this->sprite.setTextureRect(sf::IntRect(CELL_SIZE, 2 * CELL_SIZE, -CELL_SIZE, CELL_SIZE));
}

void AnimationComponent::die() {
    if (!flipped)
        this->sprite.setTextureRect(sf::IntRect(CELL_SIZE, 2 * CELL_SIZE, CELL_SIZE, CELL_SIZE));
    else
        this->sprite.setTextureRect(sf::IntRect(2 * CELL_SIZE, 2 * CELL_SIZE, -CELL_SIZE, CELL_SIZE));
}

void AnimationComponent::update() {
    if (animationIterator < animationSpeed) {
        animationIterator++;
    } else {
        animationIterator = 0;
        currentFrame = (1 + currentFrame) % 3;
    }
}




