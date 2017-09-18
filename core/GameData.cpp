//
// Created by freddy on 9/4/17.
//
#include <iostream>
#include "GameData.h"

GameData::GameData() {
    num_rooms = -1;
    num_creatures = 1;
}

void GameData::cleanup() {
    if(!rooms.empty()) {
        rooms.clear();
        rooms.resize(0);
    }

    if(!creatures.empty()) {
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

std::vector<Creature*> GameData::get_creatures_in_room(int room) {
    std::vector<Creature*> creatures_in_room;
    for(Creature* creature : creatures) {
        if(creature->location == room) {
            creatures_in_room.push_back(creature);
        }
    }

    return creatures_in_room;
}
