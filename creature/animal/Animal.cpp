//
// Created by freddy on 9/2/17.
//

#include "Animal.h"
#include "../CreatureType.cpp"
#include "../../core/GameData.h"
#include "../../room/Room.h"
#include <string>
#include <iostream>

Animal::Animal(int id, int location) : Creature(id, location) {}

void Animal::perform_happy_action() {
    std::cout << "Creature " << id << ": licks face - ";
    GameData::pc->respect += 1;
    std::cout << "Respect is now " << GameData::pc->respect << std::endl;
}

void Animal::perform_angry_action() {
    std::cout << "Creature " << id << ": growls - ";
    GameData::pc->respect -= 1;
    std::cout << "Respect is now " << GameData::pc->respect << std::endl;
}

void Animal::fix_room(Room* room) {
    room->clean(this);
}

int Animal::get_incompatible_room_state() {
    return Room::State::DIRTY;
}

std::string Animal::get_type()
{
    return "Animal";
}