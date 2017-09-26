//
// Created by freddy on 9/2/17.
//

#ifndef CSC_454_HW_1_NPC_H
#define CSC_454_HW_1_NPC_H

#include "../Creature.h"
class Npc: public Creature {
public:
    Npc(int id, int location);
    void perform_happy_action();
    void perform_angry_action();
    void fix_room(Room* room);
    int get_incompatible_room_state();
    std::string get_type();
};

#endif //CSC_454_HW_1_NPC_H
