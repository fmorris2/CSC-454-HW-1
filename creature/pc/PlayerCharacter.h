//
// Created by freddy on 9/2/17.
//

#ifndef CSC_454_HW_1_PLAYERCHARACTER_H
#define CSC_454_HW_1_PLAYERCHARACTER_H

#include "../Creature.h"

class PlayerCharacter: public Creature {
public:
    PlayerCharacter(int id, int location);
    int respect = 40;
    void perform_happy_action();
    void perform_angry_action();
    int get_incompatible_room_state();
    std::string get_type();
};

#endif //CSC_454_HW_1_PLAYERCHARACTER_H
