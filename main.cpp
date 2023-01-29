#include "Game.h"

// #include <chrono>
// #include <thread>

int main() {
    auto &game = Game::get_game();
    game.run();
    return 0;
}
