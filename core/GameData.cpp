//
// Created by freddy on 9/4/17.
//
#include <iostream>
#include "GameData.h"

PlayerCharacter* GameData::pc;
std::vector<Room*> GameData::rooms;

GameData::GameData() {}

void GameData::cleanup() {
    if(!rooms.empty()) {
        for(Room* room : rooms) {
            room->cleanup_resources();
            delete(room);
        }
        rooms.clear();
        rooms.resize(0);
    }
}

Room* GameData::get_room(int index) {
    if(index >= 0 && index < rooms.size()) {
        return rooms[index];
    }

    return 0;
}

void GameData::add_room(Room *room) {
    rooms.push_back(room);
}

Creature* GameData::find_creature(int id) {
    for(Room* room : rooms) {
        Creature* creature = room->find_creature(id);
        if(creature != 0) {
            return creature;
        }
    }

    return 0;
}
