//
// Created by freddy on 9/2/17.
//

#include "Animal.h"
#include "../CreatureType.cpp"
#include <string>

Animal::Animal(int id, int location) : Creature(id, location) {
    type = (int)CreatureType::ANIMAL;
    happy_action = "lick face";
    angry_action = "growl";
}