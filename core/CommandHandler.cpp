//
// Created by freddy on 9/17/17.
//

#include "CommandHandler.h"
#include "../room/RoomState.cpp"
#include "../creature/npc/Npc.h"
#include "../creature/animal/Animal.h"
#include "../creature/Creature.h"
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
    Creature* target = find_pc();
    if(tokens.size() > 1) { //there is a target
        command = tokens[1];
        target = game_data->find_creature(std::stoi(tokens[0]));
    }

    execute_command(command, target);
}

void CommandHandler::execute_command(std::string command, Creature *target) {
    target->forced_action = true;
    Room* room = game_data->rooms[target->location];
    if(command.compare("look") == 0) {
        look(target);
    }
    else if(command.compare("clean") == 0) {
        clean(target);
    }
    else if(command.compare("dirty") == 0) {
        dirty(target);
    }
    else if(command.compare("north") == 0) {
        move(target, room->get_north(), "north");
    }
    else if(command.compare("south") == 0) {
        move(target, room->get_south(), "south");
    }
    else if(command.compare("east") == 0) {
        move(target, room->get_east(), "east");
    }
    else if(command.compare("west") == 0) {
        move(target, room->get_west(), "west");
    }
    target->forced_action = false;
}

void CommandHandler::move(Creature *creature, int room, std::string direction) {
    if (room < 0) {
        std::cout << "There is no room to the " << direction << " that creature " << creature->get_id()
                  << " can move to." << std::endl;
    } else {
        Room *destination = game_data->rooms[room];
        std::vector<Creature*> creatures_in_dest = game_data->get_creatures_in_room(room);
        if(creatures_in_dest.size() == 10) {
            std::cout << "Creature " << creature->get_id() << " cannot move to room " << room << " because it is full." << std::endl;
            if(!dynamic_cast<PlayerCharacter*>(creature)) {
                angry_action(creature);
            }
        } else {
            creature->location = room;
            std::cout << "Creature " << creature->get_id() << " moves " << direction << " to room " << room << std::endl;
        }
    }
}

void CommandHandler::clean(Creature *target) {
    Room* room = game_data->rooms[target->location];
    if(room->get_state() != (int)RoomState::CLEAN) {
        std::cout << "Creature " << target->get_id() << " cleans room " << room->get_id() << std::endl;
        room->set_state(room->get_state() + 1);
        handle_room_state_change(room, true);
    }
}

void CommandHandler::dirty(Creature *target) {
    Room* room = game_data->rooms[target->location];
    if(room->get_state() != (int)RoomState::DIRTY) {
        std::cout << "Creature " << target->get_id() << " dirties room " << room->get_id() << std::endl;
        room->set_state(room->get_state() - 1);
        handle_room_state_change(room, false);
    }
}

void CommandHandler::handle_room_state_change(Room *room, bool clean) {
    std::vector<Creature*> creatures = game_data->get_creatures_in_room(room->get_id());
    for(Creature* creature : creatures) {
        if(dynamic_cast<PlayerCharacter*>(creature)) {
            continue;
        }
        else if((clean && dynamic_cast<Animal *>(creature))
                || (!clean && dynamic_cast<Npc *>(creature))) {
                happy_action(creature);
        }
        else {
            angry_action(creature);
            if(!creature_can_be_in_room(creature, room)) {
                creature_escape_room(creature);
            }
        }
        creature->forced_action = false;
    }
}

void CommandHandler::creature_escape_room(Creature *creature) {
    Room* current_room = game_data->rooms[creature->location];
    std::vector<int> available_rooms;
    int rooms[] = {current_room->get_north(), current_room->get_east(), current_room->get_south(), current_room->get_west()};
    for(int room : rooms) {
        if (room != -1) {
            available_rooms.push_back(room);
        }
    }
    while(true) {
        if(available_rooms.size() == 0) {
            creature_drill_hole(creature);
            break;
        }
        int random_index = rand() % available_rooms.size();
        Room *destination = game_data->rooms[available_rooms[random_index]];
        if(game_data->get_creatures_in_room(destination->get_id()).size() == 10) {
            available_rooms.erase(available_rooms.begin() + random_index);
        } else {
            creature->location = destination->get_id();
            std::cout << "Creature " << creature->get_id() << " escapes to room " << destination->get_id() << std::endl;
            if(!creature_can_be_in_room(creature, destination)) {
                creature_fix_room(creature);
            }
            break;
        }
    }
}

void CommandHandler::creature_fix_room(Creature *creature) {
    if(dynamic_cast<Animal*>(creature)) {
        clean(creature);
    } else {
        dirty(creature);
    }
}

void CommandHandler::creature_drill_hole(Creature *creature) {
    std::cout << "Creature " << creature->get_id() << " drills a hole in the ceiling and crawls out through the roof." << std::endl;
    int room = creature->location;
    game_data->creatures.erase(game_data->creatures.begin() + creature->get_id());
    std::vector<Creature*> creatures_in_room = game_data->get_creatures_in_room(room);
    for(Creature* c : creatures_in_room) {
        if(!dynamic_cast<PlayerCharacter*>(c)) {
            angry_action(c);
        }
    }
}

void CommandHandler::happy_action(Creature *creature) {
    std::string action = "smile";
    if(dynamic_cast<Animal*>(creature)) {
        action = "lick face";
    }

    int times = creature->forced_action ? 3 : 1;
    for(int i = 0; i < times; i++) {
        std::cout << "Creature " << creature->get_id() << ": " << action << std::endl;
        PlayerCharacter* pc = find_pc();
        find_pc()->respect += 1;
        std::cout << "Respect is now " << pc->respect << std::endl;
    }
 }

void CommandHandler::angry_action(Creature *creature) {
    std::string action = "grumble";
    if(dynamic_cast<Animal*>(creature)) {
        action = "growl";
    }

    int times = creature->forced_action ? 3 : 1;
    for(int i = 0; i < times; i++) {
        std::cout << "Creature " << creature->get_id() << ": " << action << std::endl;
        PlayerCharacter* pc = find_pc();
        pc->respect -= 1;
        std::cout << "Respect is now " << pc->respect << std::endl;
    }
}

bool CommandHandler::creature_can_be_in_room(Creature *creature, Room *room) {
    if(dynamic_cast<Npc*>(creature)) {
        return room->get_state() != RoomState::CLEAN;
    } else if(dynamic_cast<Animal*>(creature)) {
        return room->get_state() != RoomState::DIRTY;
    }

    return true;
}

void CommandHandler::look(Creature *target) {
    std::cout << "\nRoom " << target->location << std::endl;
    Room* room = game_data->rooms[target->location];
    room->print_state();
    room->print_neighbors();
    print_creatures(game_data->get_creatures_in_room(room->get_id()));
}

void CommandHandler::print_creatures(std::vector<Creature*> creatures) {
    std::cout << "Occupants: " << std::endl;
    for(Creature *creature : creatures) {
        std::cout << "\t" << creature->get_type() << " " << creature->get_id() << std::endl;
    }
}

PlayerCharacter* CommandHandler::find_pc() {
    for(Creature* creature : game_data->creatures) {
        if(dynamic_cast<PlayerCharacter*>(creature)) {
            return (PlayerCharacter*)creature;
        }
    }
}