//
// Created by freddy on 9/3/17.
//

#include "GameData.h"
#include <string>
#ifndef CSC_454_HW_1_GAMEINITIALIZER_H
#define CSC_454_HW_1_GAMEINITIALIZER_H

class GameInitializer {
public:
    bool handle_init_input(GameData* data);
private:
    bool create_rooms(GameData* data, int size);
    bool get_room_details_from_user(GameData* data);
    bool create_creatures(GameData* data, int size);
    bool get_creature_details_from_user(GameData* data);
    int get_upper_bounded_value_from_user(int MAX_VAL, std::string name_of_value);
    void ensure_max_val(int max_value, int* value_to_check);

};
#endif //CSC_454_HW_1_GAMEINITIALIZER_H
