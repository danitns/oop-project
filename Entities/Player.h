//
// Created by danit on 01.12.2022.
//

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H


#include "Entity.h"

class Player: public Entity {
private:
    sf::Texture texture;
public:
    /// Constructor
    Player();

};

#endif //OOP_PLAYER_H
