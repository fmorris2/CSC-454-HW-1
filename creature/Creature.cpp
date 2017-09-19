//
// Created by freddy on 9/2/17.
//

#include <iostream>
#include "Creature.h"

const std::string CREATURE_TYPES[] = {"PC", "ANIMAL", "HUMAN"};

Creature::Creature() {}

Creature::Creature(int id, int location) {
    this->id = id;
    this->location = location;
}

int Creature::get_id() {
    return id;
}

std::string Creature::get_type() {
    return CREATURE_TYPES[(int)type];
}

std::string Creature::get_happy_action() {
    return happy_action;
}

std::string Creature::get_angry_action() {
    return angry_action;
}

Creature::~Creature() {}