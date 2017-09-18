//
// Created by freddy on 9/2/17.
//

#include "Animal.h"
#include "../CreatureType.cpp"

Animal::Animal(int id, int location) : Creature(id, location) {
    type = (int)CreatureType::ANIMAL;
}
