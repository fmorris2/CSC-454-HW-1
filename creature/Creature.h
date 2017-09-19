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

    int get_id();
    int location;
    bool forced_action;
    std::string get_type();
    std::string get_happy_action();
    std::string get_angry_action();

    virtual ~Creature();
protected:
    int id;
    int type;
    std::string happy_action, angry_action;
};

#endif //CSC_454_HW_1_CREATURE_H
