//
// Created by freddy on 9/3/17.
//

#include <string>
#include <vector>
#include "GameData.h"
#include "CommandHandler.h"
#ifndef CSC_454_HW_1_GAME_H
#define CSC_454_HW_1_GAME_H

class Game {
public:
    Game(GameData* game_data);
    void cycle();
private:
    std::vector<std::string> get_user_input_tokens();
    CommandHandler command_handler;
    GameData* game_data;
    bool is_victorious();
    bool is_defeated();
};

#endif //CSC_454_HW_1_GAME_H
