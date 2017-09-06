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
    GameData game_data;
    if(game_initializer.handle_init_input(&game_data)) {
        Game game;
        game.cycle();
        game_data.cleanup();
        return EXIT_SUCCESS;
    }

    std::cout << "Failed to initialize game." << std::endl;
    game_data.cleanup();
    return EXIT_FAILURE;
}
