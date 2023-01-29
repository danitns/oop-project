//
// Created by danit on 26.01.2023.
//

#ifndef OOP_ENEMYTEMPLATE_H
#define OOP_ENEMYTEMPLATE_H

#include "Entity.h"

template <typename T>
class EnemyTemplate:
        public Entity {
public:
    enum enemyType {mushroom, turtle};

private:
    T walkDir;
    enemyType eType;
    sf::Texture texture;


    void input(float dt) override {
        if(this->getVelocity().x == 0)
            walkDir *= -1.f;
        if(this->getDead() == 0)
            this->updateVelocity(walkDir, 0.f, dt);
    };

public:
    EnemyTemplate(sf::Vector2f pos, float maxVelocity, float acceleration, float deceleration, T walkDir, enemyType eType) :
        Entity(maxVelocity, acceleration, deceleration), walkDir(walkDir), eType(eType) {

        if(this->eType == mushroom)
            this->texture.loadFromFile("Sprites/enemy1.png");
        else if(this->eType == turtle)
            this->texture.loadFromFile("Sprites/enemyTurtle.png");

        this->setTexture(texture);
        this->setPosition(pos.x, pos.y);
    }

    ~EnemyTemplate() override = default;

    [[maybe_unused]] void setWalkDir(T walkDir_){
        this->walkDir = walkDir_;
    }
};

template class EnemyTemplate<float>;
template class EnemyTemplate<double>;

#endif //OOP_ENEMYTEMPLATE_H
