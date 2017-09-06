//
// Created by freddy on 9/3/17.
//
#include "GameInitializer.h"
#include <iostream>

const int MAX_ROOMS = 100, MAX_CREATURES = 100;

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
        data->rooms = new Room[size];
        return true;
    }

    std::cout << "# of rooms must be 0 < n <= " << MAX_ROOMS << std::endl;
    return false;
}

bool GameInitializer::create_creatures(GameData *data, int size) {
    if(size > 0) {
        data->creatures = new Creature[size];
        return true;
    }

    std::cout << "# of creatures must be 0 < n <= " << MAX_CREATURES << std::endl;
    return false;
}

void GameInitializer::ensure_max_val(int max_value, int *value_to_check) {
    if(*value_to_check > max_value)
        *value_to_check = max_value;
}

