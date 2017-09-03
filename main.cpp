//
// Created by freddy on 9/3/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "core/GameInitializer.h"
#include "core/Game.h"

int main() {
    GameInitializer game_initializer;
    if(game_initializer.handle_init_input()) {
        Game game;
        game.cycle();
        return EXIT_SUCCESS;
    }

    std::cout << "Failed to initialize game." << std::endl;
    return EXIT_FAILURE;
}
