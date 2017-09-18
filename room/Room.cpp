//
// Created by freddy on 9/2/17.
//

#include "../core/GameData.h"
#include "../creature/Creature.h"
#include "Room.h"
#include "RoomState.cpp"
#include <iostream>
#include <string>

const std::string STATES[] = {"DIRTY", "HALF_DIRTY", "CLEAN"};

Room::Room(int id, int state, int north, int south, int east, int west) {
    this->id = id;
    this->state = state;
    this->north = north;
    this->south = south;
    this->east = east;
    this->west = west;
}

Room::Room() {

}

int Room::get_north() {
    return north;
}

int Room::get_south() {
    return south;
}

int Room::get_west() {
    return west;
}

int Room::get_east() {
    return east;
}

int Room::get_id() {
    return id;
}

int Room::get_state() {
    return state;
}

void Room::set_state(int state) {
    if(state < 0) {
        state = 0;
    } else if(state > 2) {
        state = 2;
    }
    this->state = state;
}

void Room::print_neighbors() {
    std::cout << "Neighbors: " << std::endl;
    std::string dirs[] = {"North", "South", "East", "West"};
    int neighbors[] = {north, south, east, west};
    for(int i = 0; i < 4; i++) {
        if(neighbors[i] >= 0) {
            std::cout << "\t" << dirs[i] << ": " << neighbors[i] << std::endl;
        }
    }
}

void Room::print_state() {
    std::cout << "State: " << STATES[state] << std::endl;
}
