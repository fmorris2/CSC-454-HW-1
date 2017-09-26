//
// Created by freddy on 9/4/17.
//

#include "../creature/Creature.h"
#include "../creature/pc/PlayerCharacter.h"
#include "../room/Room.h"
#include <vector>
#ifndef CSC_454_HW_1_GAMEDATA_H
#define CSC_454_HW_1_GAMEDATA_H
class GameData {
public:
    static PlayerCharacter* pc;

    GameData();
    static void cleanup();

    static Creature* find_creature(int id);
    static Room* get_room(int index);
    static void add_room(Room* room);
private:
    static std::vector<Room*> rooms;
};
#endif //CSC_454_HW_1_GAMEDATA_H
