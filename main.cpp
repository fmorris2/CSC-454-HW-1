//
// Created by freddy on 9/3/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "core/GameInitializer.h"
#include "core/Game.h"

using namespace std;

int main() {
    GameInitializer game_initializer;
    if(game_initializer.handle_init_input()) {
        Game game;
        game.cycle();
        return EXIT_SUCCESS;
    }

    cout << "Failed to initialize game." << endl;
    return EXIT_FAILURE;
}
