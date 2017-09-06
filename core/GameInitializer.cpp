//
// Created by freddy on 9/3/17.
//
#include "GameInitializer.h"
#include <iostream>

const int MAX_ROOMS = 100, MAX_CREATURES = 100;

bool GameInitializer::handle_init_input(GameData* data) {
    return create_rooms(data)
            && create_creatures(data);
}

int GameInitializer::get_num_rooms_from_user() {
    int num_rooms = -1;
    std::cout << "Enter # rooms: ";
    std::cin >> num_rooms;
    ensure_max_val(MAX_ROOMS, &num_rooms);
    return num_rooms;
}

bool GameInitializer::create_rooms(GameData *data) {
    int num_rooms = get_num_rooms_from_user();
    if(num_rooms > 0) {
        data->rooms = new Room[num_rooms];
        return true;
    }

    std::cout << "# of rooms must be 0 < n <= " << MAX_ROOMS << std::endl;
    return false;
}

int GameInitializer::get_num_creatures_from_user() {
    int num_creatures = -1;
    std::cout << "Enter # creatures: ";
    std::cin >> num_creatures;
    ensure_max_val(MAX_CREATURES, &num_creatures);
    return num_creatures;
}

bool GameInitializer::create_creatures(GameData *data) {
    int num_creatures = get_num_creatures_from_user();
    if(num_creatures > 0) {
        data->creatures = new Creature[num_creatures];
        return true;
    }

    std::cout << "# of creatures must be 0 < n <= " << MAX_CREATURES << std::endl;
    return false;
}

void GameInitializer::ensure_max_val(int max_value, int *value_to_check) {
    if(*value_to_check > max_value)
        *value_to_check = max_value;
}

