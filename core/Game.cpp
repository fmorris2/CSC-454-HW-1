//
// Created by freddy on 9/3/17.
//

#include "Game.h"
#include <string>
#include <iostream>

const std::string EXIT_VALUE = "exit";

void Game::cycle() {
    std::string user_input;
    do {
        user_input = get_user_input();
        process_user_input(user_input);
    } while (user_input.compare(EXIT_VALUE) != 0);

}

void Game::process_user_input(string command) {

}

std::string Game::get_user_input() {
    std::string command;
    std::cout << "Enter a command: ";
    std::cin >> command;
    return command;
}


