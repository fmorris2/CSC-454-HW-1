//
// Created by freddy on 9/2/17.
//

#include "Npc.h"
#include "../CreatureType.cpp"
#include <string>

Npc::Npc(int id, int location) : Creature(id, location) {
    type = (int)CreatureType::NPC;
    happy_action = "smile";
    angry_action = "grumble";
}
