//
// Created by freddy on 9/17/17.
//

#include "CommandHandler.h"
#include "../creature/Creature.h"
#include "../room/Room.h"
#include <iostream>
#include <string>
#include <stdlib.h>

CommandHandler::CommandHandler(GameData *game_data) {
    this->game_data = game_data;
}

CommandHandler::CommandHandler() {}

void CommandHandler::handle(std::vector<std::string> tokens) {
    if(tokens.size() == 0)
        return;

    std::string command = tokens[0];
    Creature* target = game_data->pc;
    if(tokens.size() > 1) { //there is a target
        command = tokens[1];
        target = game_data->find_creature(std::stoi(tokens[0]));
    }

    execute_command(command, target);
}

void CommandHandler::execute_command(std::string command, Creature *target_creature) {
    Room *target_creature_room = game_data->get_room(target_creature->get_location());
    if (command.compare("look") == 0) {
        target_creature->look(target_creature_room);
    } else if (command.compare("clean") == 0) {
        target_creature->set_forced_action(true);
        target_creature_room->clean(target_creature);
    } else if (command.compare("dirty") == 0) {
        target_creature->set_forced_action(true);
        target_creature_room->dirty(target_creature);
    } else if (command.compare("north") == 0) {
        target_creature->move(target_creature_room, game_data->get_room(target_creature_room->get_north()),
                              Room::NORTH);
    } else if (command.compare("south") == 0) {
        target_creature->move(target_creature_room, game_data->get_room(target_creature_room->get_south()),
                              Room::SOUTH);
    } else if (command.compare("east") == 0) {
        target_creature->move(target_creature_room, game_data->get_room(target_creature_room->get_east()), Room::EAST);
    } else if (command.compare("west") == 0) {
        target_creature->move(target_creature_room, game_data->get_room(target_creature_room->get_west()), Room::WEST);
    }
    target_creature->set_forced_action(false);
}