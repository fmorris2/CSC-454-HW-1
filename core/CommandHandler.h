//
// Created by freddy on 9/17/17.
//

#include "GameData.h"
#include "../creature/pc/PlayerCharacter.h"
#include <vector>
#include <string>
#ifndef CSC_454_HW_1_COMMANDPARSER_H
#define CSC_454_HW_1_COMMANDPARSER_H

class CommandHandler {
public:
    CommandHandler(GameData* game_data);
    CommandHandler();
    void handle(std::vector<std::string>);
private:
    GameData* game_data;
    void execute_command(std::string command, Creature* target);
};

#endif //CSC_454_HW_1_COMMANDPARSER_H
