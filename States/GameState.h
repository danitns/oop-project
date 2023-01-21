//
// Created by danit on 24.10.2022.
//

#ifndef OOP_GAMESTATE_H
#define OOP_GAMESTATE_H

#include "State.h"
#include "../Map/Map.h"
#include "../Entities/Player.h"

class GameState :
        public State {
private:
    /// Variables
    Player player;

    sf::View view;

    int viewChange = 0;
    bool stopGame = false;

    sf::Text gameOverText;

    sf::Sprite background;
    sf::Texture backgroundTexture;
    sf::Image mapSketch;
    std::shared_ptr<Map> map;

public:
    /// Constructor / Destructor
    GameState(sf::RenderWindow &window, std::stack<std::shared_ptr<State>> &states);

    ~GameState() override;

    std::shared_ptr<State> clone() const override;

    //friend std::ostream& operator<<(std::ostream& os, const GameState& gameState);

    /// Functions
    void updatePlayerMovement(float dt);

    void updateEnemies(float dt);

    void update(float dt) override;

    void render(sf::RenderTarget &target) override;


};


#endif //OOP_GAMESTATE_H
