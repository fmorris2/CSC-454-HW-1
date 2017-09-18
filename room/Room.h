//
// Created by freddy on 9/2/17.
//

#ifndef CSC_454_HW_1_ROOM_H
#define CSC_454_HW_1_ROOM_H

class Room {
public:
    const int MAX_CREATURES = 10;
    Room(int id, int state, int north, int south, int east, int west);
    Room();
    void set_state(int state);
    int get_state();
    int get_north();
    int get_south();
    int get_east();
    int get_west();
    int get_id();
    void print_neighbors();
    void print_state();
private:
    int north, south, east, west, state, id;
};

#endif //CSC_454_HW_1_ROOM_H
