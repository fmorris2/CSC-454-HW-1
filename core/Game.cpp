//
// Created by freddy on 9/3/17.
//

#include "Game.h"
#include "../utils/StringUtils.h"
#include <string>
#include <iostream>

const int MAX_RESPECT = 80, MIN_RESPECT = 0;
const std::string EXIT_VALUE = "exit";
const char COMMAND_DELIMITER = ':';

Game::Game(GameData *game_data) {
    this->command_handler = CommandHandler(game_data);
    this->game_data = game_data;
}

void Game::cycle() {
    std::vector<std::string> user_input_tokens;
    do {
        user_input_tokens = get_user_input_tokens();
        command_handler.handle(user_input_tokens);
    } while (user_input_tokens[0].compare(EXIT_VALUE) != 0 && !is_victorious() && !is_defeated());
}

bool Game::is_victorious() {
    if(game_data->pc->respect > MAX_RESPECT) {
        std::cout << "You are victorious!" << std::endl;
        return true;
    }

    return false;
}

bool Game::is_defeated() {
    if(game_data->pc->respect <= MIN_RESPECT) {
        std::cout << "You have been defeated." << std::endl;
        return true;
    }

    return false;
}

std::vector<std::string> Game::get_user_input_tokens() {
    std::string command;
    std::cout << "Enter a command: ";
    std::cin >> command;
    std::vector<std::string> tokens = StringUtils::split(command, COMMAND_DELIMITER);
    return tokens;
}


