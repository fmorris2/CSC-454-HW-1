//
// Created by freddy on 9/2/17.
//

#include "PlayerCharacter.h"
#include "../CreatureType.cpp"

PlayerCharacter::PlayerCharacter(int id, int location) : Creature(id, location) {
    type = (int)CreatureType::PC;
}
