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
};

#endif //CSC_454_HW_1_PLAYERCHARACTER_H
