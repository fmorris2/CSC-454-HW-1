//
// Created by freddy on 9/4/17.
//
#include <iostream>
#include "GameData.h"

GameData::GameData() {}

void GameData::cleanup() {
    if(!rooms.empty()) {
        for(Room* room : rooms) {
            delete(room);
        }
        rooms.clear();
        rooms.resize(0);
    }

    if(!creatures.empty()) {
        for(Creature* creature : creatures) {
            delete(creature);
        }
        creatures.clear();
        creatures.resize(0);
    }
}

Creature* GameData::find_creature(int id) {
    for(Creature* creature : creatures) {
        if(creature->get_id() == id) {
            return creature;
        }
    }

    return NULL;
}

int GameData::find_creature_index(int creature_id) {
    for(int i = 0; i < creatures.size(); i++) {
        if(creatures[i]->get_id() == creature_id) {
            return i;
        }
    }

    return -1;
}

std::vector<Creature*> GameData::get_creatures_in_room(int room) {
    std::vector<Creature*> creatures_in_room;
    for(Creature* creature : creatures) {
        if(creature->location == room) {
            creatures_in_room.push_back(creature);
        }
    }

    return creatures_in_room;
}
