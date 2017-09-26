//
// Created by freddy on 9/2/17.
//

#include "Npc.h"
#include "../CreatureType.cpp"
#include "../../room/Room.h"
#include "../../core/GameData.h"
#include <string>
#include <iostream>

Npc::Npc(int id, int location) : Creature(id, location) {}

void Npc::perform_happy_action() {
    std::cout << "Creature " << id << ": smiles - ";
    GameData::pc->respect += 1;
    std::cout << "Respect is now " << GameData::pc->respect << std::endl;
}

void Npc::perform_angry_action() {
    std::cout << "Creature " << id << ": grumbles - ";
    GameData::pc->respect -= 1;
    std::cout << "Respect is now " << GameData::pc->respect << std::endl;
}

void Npc::fix_room(Room* room) {
    room->dirty(this);
}

int Npc::get_incompatible_room_state() {
    return Room::State::CLEAN;
}

std::string Npc::get_type()
{
    return "Npc";
}
