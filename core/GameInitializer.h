//
// Created by freddy on 9/3/17.
//

#include "GameData.h"
#ifndef CSC_454_HW_1_GAMEINITIALIZER_H
#define CSC_454_HW_1_GAMEINITIALIZER_H

class GameInitializer {
public:
    bool handle_init_input(GameData* data);
private:
    bool create_rooms(GameData* data);
    int get_num_rooms_from_user();
    bool create_creatures(GameData* data);
    int get_num_creatures_from_user();
    void ensure_max_val(int max_value, int* value_to_check);

};
#endif //CSC_454_HW_1_GAMEINITIALIZER_H
