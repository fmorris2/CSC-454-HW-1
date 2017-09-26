//
// Created by freddy on 9/2/17.
//

#ifndef CSC_454_HW_1_ROOM_H
#define CSC_454_HW_1_ROOM_H

#include <vector>
#include <string>

class Creature;
class Room {
    static const int NUM_NEIGHBORS = 4;

public:
    Room(int id, int state, int north, int south, int east, int west);
    Room();

    enum Direction {
        NORTH,
        SOUTH,
        EAST,
        WEST,
        LAST_DIRECTION
    };

    enum State {
        DIRTY,
        HALF_DIRTY,
        CLEAN,
        LAST_STATE
    };

    void clean(Creature* creature_doing_cleaning);
    void dirty(Creature* creature_doing_dirtying);
    void handle_consequences_of_state_change(State old_state, State new_state);
    void handle_consequence_of_drill_hole();

    bool is_full();

    void print_neighbors();
    void print_state();
    void print_creatures();
    void cleanup_resources();

    Creature* find_creature(int id);
    std::string get_direction_name(Direction direction);
    std::vector<int> get_available_neighbors();

    //Getters
    State get_state();
    int get_north();
    int get_south();
    int get_east();
    int get_west();
    int get_id();

    //Setters
    void add_creature(Creature* creature);
    void remove_creature(Creature* creature);
    void set_state(State state);

private:
    int id;
    int neighbors[NUM_NEIGHBORS];
    State state;
    std::vector<Creature*> creatures;
    std::string get_state_name(State state);
};

#endif //CSC_454_HW_1_ROOM_H
