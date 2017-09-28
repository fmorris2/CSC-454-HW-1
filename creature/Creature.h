//
// Created by freddy on 9/2/17.
//

#ifndef CSC_454_HW_1_CREATURE_H
#define CSC_454_HW_1_CREATURE_H

#include <string>

class Room;
class Creature {
public:
    Creature(int id, int location);
    Creature();

    void look(Room* room);
    void move(Room* current, Room* destination, int direction);
    void escape_room(Room* current);
    void start_action(bool is_happy_action);
    void drill_hole();

    virtual std::string get_type() = 0;
    virtual int get_incompatible_room_state() = 0;
    virtual void fix_room(Room* room);

    //Getters & Setters
    int get_id();
    int get_location();

    void set_location(int location);
    void set_forced_action(bool forced_action);

    virtual ~Creature();
protected:
    int id;
    int location;
    bool forced_action;
    virtual void perform_angry_action() = 0;
    virtual void perform_happy_action() = 0;
};

#endif //CSC_454_HW_1_CREATURE_H
