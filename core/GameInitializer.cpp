//
// Created by freddy on 9/3/17.
//
#include "GameInitializer.h"
#include "../creature/CreatureFactory.cpp"
#include <iostream>

const int MAX_ROOMS = 100, MAX_CREATURES = 100;
const int NUM_ROOM_PARAMS = 5, NUM_CREATURE_PARAMS = 2;


bool GameInitializer::handle_init_input(GameData* data) {
    return create_rooms(data, get_upper_bounded_value_from_user(MAX_ROOMS, "rooms"))
            && create_creatures(data, get_upper_bounded_value_from_user(MAX_CREATURES, "creatures"));
}

int GameInitializer::get_upper_bounded_value_from_user(int MAX_VAL, std::string name_of_value) {
    int user_input = -1;
    std::cout << "Enter # " << name_of_value << ": ";
    std::cin >> user_input;
    ensure_max_val(MAX_VAL, &user_input);
    return user_input;
}

bool GameInitializer::create_rooms(GameData *data, int size) {
    if(size > 0) {
        data->num_rooms = size;
        get_room_details_from_user(data);
        return true;
    }

    std::cout << "# of rooms must be 0 < n <= " << MAX_ROOMS << std::endl;
    return false;
}

bool GameInitializer::get_room_details_from_user(GameData *data) {
    for(int room_num = 0; room_num < data->num_rooms; room_num++) {
        int params[NUM_ROOM_PARAMS];
        for(int param_num = 0; param_num < NUM_ROOM_PARAMS; param_num++) {
            std::cin >> params[param_num];
        }
        data->rooms.push_back(new Room(room_num, params[0], params[1], params[2], params[3], params[4]));
    }
}

bool GameInitializer::create_creatures(GameData *data, int size) {
    if(size > 0) {
        data->num_creatures = size;
        get_creature_details_from_user(data);
        return true;
    }

    std::cout << "# of creatures must be 0 < n <= " << MAX_CREATURES << std::endl;
    return false;
}

bool GameInitializer::get_creature_details_from_user(GameData *data) {
    for(int creature_num = 0; creature_num < data->num_creatures; creature_num++) {
        int params[NUM_CREATURE_PARAMS];
        for(int param_num = 0; param_num < NUM_CREATURE_PARAMS; param_num++) {
            std::cin >> params[param_num];
        }
        Creature* creature = CreatureFactory::create_creature(creature_num, params[0], params[1]);
        if(params[0] == (int)CreatureType::PC) {
            data->pc = (PlayerCharacter*)creature;
        }
        data->creatures.push_back(creature);
    }
}

void GameInitializer::ensure_max_val(int max_value, int *value_to_check) {
    if(*value_to_check > max_value)
        *value_to_check = max_value;
}