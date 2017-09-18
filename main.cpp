//
// Created by freddy on 9/3/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "core/GameInitializer.h"
#include "core/Game.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>

int main() {
    srand (time(NULL));
    GameInitializer game_initializer;
    GameData game_data;
    if(game_initializer.handle_init_input(&game_data)) {
        Game game(&game_data);
        game.cycle();
        game_data.cleanup();
        return EXIT_SUCCESS;
    }

    std::cout << "Failed to initialize game." << std::endl;
    game_data.cleanup();
    return EXIT_FAILURE;
}
