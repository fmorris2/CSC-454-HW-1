//
// Created by freddy on 9/2/17.
//

#ifndef CSC_454_HW_1_CREATURE_H
#define CSC_454_HW_1_CREATURE_H

#include <string>

class Creature {
public:
    Creature(int id, int location);
    Creature();
    virtual ~Creature();
    int get_id();
    int location;
    bool forced_action;
    std::string get_type();
protected:
    int id;
    int type;
};

#endif //CSC_454_HW_1_CREATURE_H
