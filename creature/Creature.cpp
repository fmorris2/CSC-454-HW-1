//
// Created by freddy on 9/2/17.
//

#include <iostream>
#include "Creature.h"
#include "../core/GameData.h"
#include "../room/Room.h"

const int FORCED_ACTION_TIMES = 3;

Creature::Creature() {}

Creature::Creature(int id, int location) {
    this->id = id;
    this->location = location;
}

void Creature::look(Room* room) {
    std::cout << "\nRoom " << location << std::endl;
    room->print_state();
    room->print_neighbors();
    room->print_creatures();
}

void Creature::move(Room* current, Room* destination, int direction) {
    if(destination == 0) {
        std::cout << "There is no room to the " << destination->get_direction_name((Room::Direction)direction)
                  << " that creature " << id << " can move to." << std::endl;
    } else if (destination->is_full()){
        std::cout << "Creature " << id << " cannot move to room " << destination->get_id() << " because it is full." << std::endl;
        perform_angry_action();
    } else {
        current->remove_creature(this);
        set_location(destination->get_id());
        destination->add_creature(this);
        std::cout << "Creature " << id << " moves " << destination->get_direction_name((Room::Direction)direction) << " to room " << location << std::endl;
    }
}

void Creature::escape_room(Room *current) {
    std::vector<int> available_rooms = current->get_available_neighbors();
    while(available_rooms.size() > 0) {
        int random_index = rand() % available_rooms.size();
        Room *destination = GameData::get_room(available_rooms[random_index]);
        if(destination->is_full()) {
            available_rooms.erase(available_rooms.begin() + random_index);
        } else {
            current->remove_creature(this);
            destination->add_creature(this);
            location = destination->get_id();
            std::cout << "Creature " << id << " escapes to room " << location << std::endl;
            if(destination->get_state() == get_incompatible_room_state()) {
                fix_room(destination);
            }
            break;
        }
    }

    if(available_rooms.size() == 0) {
        drill_hole();
    }
}

void Creature::drill_hole() {
    std::cout << "Creature " << id << " drills a hole in the ceiling and crawls out through the roof." << std::endl;
    Room* room = GameData::get_room(location);
    room->remove_creature(this);
    room->handle_consequence_of_drill_hole();
}

void Creature::start_action(bool is_happy_action) {
    if(location != GameData::pc->get_location()) {
        return;
    }

    int times = forced_action ? FORCED_ACTION_TIMES : 1;
    for(int i = 0; i < times; i++) {
        if(is_happy_action) {
            perform_happy_action();
        }
        else {
            perform_angry_action();
        }
    }
    forced_action = false;
}

void Creature::fix_room(Room* room) {}

//Getters & Setters
int Creature::get_id() {
    return id;
}

int Creature::get_location() {
    return location;
}

void Creature::set_forced_action(bool forced_action) {
    this->forced_action = forced_action;
}

void Creature::set_location(int location) {
    this->location = location;
}

Creature::~Creature() {}