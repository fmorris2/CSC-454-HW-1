//
// Created by freddy on 9/4/17.
//
#include <iostream>
#include "GameData.h"

GameData::GameData() {
    creatures = NULL;
    rooms = NULL;
    num_rooms = -1;
    num_creatures = -1;
}

void GameData::cleanup() {
    if(creatures != NULL) {
        delete (creatures);
    }

    if(rooms != NULL) {
        delete (rooms);
    }
}
