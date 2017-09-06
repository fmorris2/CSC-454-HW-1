//
// Created by freddy on 9/4/17.
//

#include "../creature/Creature.h"
#include "../room/Room.h"
#ifndef CSC_454_HW_1_GAMEDATA_H
#define CSC_454_HW_1_GAMEDATA_H
class GameData {
public:
    Room* rooms;
    Creature* creatures;
    GameData();
    void cleanup();
};
#endif //CSC_454_HW_1_GAMEDATA_H
