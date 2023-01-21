//
// Created by danit on 01.12.2022.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H


#include "Entity.h"

class Player: public Entity {
private:
    /// Variables
    sf::Texture texture;

    /// Functions
    void input(float dt) override;
public:
    /// Constructor
    Player();

//    void die(float dt) override;
};

#endif //OOP_PLAYER_H
