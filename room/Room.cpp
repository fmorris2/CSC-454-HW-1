//
// Created by freddy on 9/2/17.
//

#include "Room.h"
#include "../creature/Creature.h"
#include <iostream>
#include <algorithm>

const int MAX_CREATURES = 10;

Room::Room(int id, int state, int north, int south, int east, int west) {
    this->id = id;
    this->state = (State)state;
    neighbors[NORTH] = north;
    neighbors[SOUTH] = south;
    neighbors[EAST] = east;
    neighbors[WEST] = west;
}

Room::Room() {}

void Room::clean(Creature *creature_doing_cleaning) {
    if(state != CLEAN) {
        std::cout << "Creature " << creature_doing_cleaning->get_id() << " cleans room " << id << std::endl;
        State old_state = state;
        state = state == DIRTY ? HALF_DIRTY : CLEAN;
        handle_consequences_of_state_change(old_state, state);
    }
}

void Room::dirty(Creature *creature_doing_dirtying) {
    if(state != DIRTY) {
        std::cout << "Creature " << creature_doing_dirtying->get_id() << " dirties room " << id << std::endl;
        State old_state = state;
        state = state == CLEAN ? HALF_DIRTY : DIRTY;
        handle_consequences_of_state_change(old_state, state);
    }
}

void Room::handle_consequences_of_state_change(State old_state, State new_state) {
    for(Creature* creature : creatures) {
        State incompatible_state = (State)creature->get_incompatible_room_state();
        if(old_state == incompatible_state || (old_state == HALF_DIRTY && new_state != incompatible_state)) {
            creature->start_action(true);
        }
        else {
            creature->start_action(false);
            if(new_state == incompatible_state) {
                creature->escape_room(this);
            }
        }
    }
}

void Room::handle_consequence_of_drill_hole() {
    for(Creature* creature : creatures) {
        creature->start_action(false);
    }
}

bool Room::is_full() {
    return creatures.size() >= MAX_CREATURES;
}

void Room::print_creatures() {
    std::cout << "Occupants: (" << creatures.size() << ")" << std::endl;
    for(Creature *creature : creatures) {
        std::cout << "\t" << creature->get_type() << " " << creature->get_id() << std::endl;
    }
}

Creature* Room::find_creature(int id) {
    for(Creature* creature : creatures) {
        if(creature->get_id() == id) {
            return creature;
        }
    }

    return 0;
}

void Room::cleanup_resources() {
    for(Creature* creature : creatures) {
        delete(creature);
    }
    creatures.clear();
    creatures.resize(0);
}

std::vector<int> Room::get_available_neighbors() {
    std::vector<int> rooms;
    for(int i : neighbors) {
        if(i != -1) {
            rooms.push_back(i);
        }
    }

    return rooms;
}

void Room::add_creature(Creature *creature) {
    creatures.push_back(creature);
}

void Room::remove_creature(Creature *creature) {
    auto index = std::find(creatures.begin(), creatures.end(), creature);
    creatures.erase(index);
}

int Room::get_north() {
    return neighbors[NORTH];
}

int Room::get_south() {
    return neighbors[SOUTH];
}

int Room::get_west() {
    return neighbors[WEST];
}

int Room::get_east() {
    return neighbors[EAST];
}

int Room::get_id() {
    return id;
}

Room::State Room::get_state() {
    return state;
}

void Room::set_state(State state) {
    if(state < 0) {
        state = (State)0;
    } else if(state > 2) {
        state = (State)2;
    }
    this->state = state;
}

void Room::print_neighbors() {
    std::cout << "Neighbors: " << std::endl;
    for(int dir_index = NORTH; dir_index != LAST_DIRECTION; dir_index++) {
        Direction direction = static_cast<Direction>(dir_index);
        if(neighbors[direction] >= 0) {
            std::cout << "\t" << get_direction_name(direction) << ": " << neighbors[direction] << std::endl;
        }
    }
}

std::string Room::get_direction_name(Direction direction) {
    switch(direction) {
        case NORTH:
            return "North";
        case SOUTH:
            return "South";
        case EAST:
            return "East";
        case WEST:
            return "West";
        default:
            return "Doesn't exist";
    }
}

std::string Room::get_state_name(State state) {
    switch(state) {
        case HALF_DIRTY:
            return "Half Dirty";
        case DIRTY:
            return "Dirty";
        case CLEAN:
            return "Clean";
        default:
            return "Doesn't exist";
    }
}

void Room::print_state() {
    std::cout << "State: " << get_state_name(state) << std::endl;
}
