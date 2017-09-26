//
// Created by freddy on 9/2/17.
//

#include "PlayerCharacter.h"
#include "../../room/Room.h"
#include "../CreatureType.cpp"

PlayerCharacter::PlayerCharacter(int id, int location) : Creature(id, location) {}

void PlayerCharacter::perform_happy_action() {

}

void PlayerCharacter::perform_angry_action() {

}

int PlayerCharacter::get_incompatible_room_state() {
    return Room::State::LAST_STATE;
}

std::string PlayerCharacter::get_type()
{
    return "PC";
}
