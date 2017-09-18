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
    PlayerCharacter* find_pc();
private:
    GameData* game_data;
    void execute_command(std::string command, Creature* target);
    void look(Creature* target);
    void clean(Creature* target);
    void dirty(Creature* target);
    void print_creatures(std::vector<Creature*> creatures);
    void handle_room_state_change(Room* room, bool clean);
    void creature_escape_room(Creature* creature);
    void creature_fix_room(Creature* creature);
    void creature_drill_hole(Creature* creature);
    void angry_action(Creature* creature);
    void happy_action(Creature* creature);
    bool creature_can_be_in_room(Creature* creature, Room* room);
    void move(Creature* creature, int room, std::string direction);
};

#endif //CSC_454_HW_1_COMMANDPARSER_H
