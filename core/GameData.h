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
    std::vector<Room*> rooms;
    std::vector<Creature*> creatures;
    PlayerCharacter* pc;

    GameData();
    void cleanup();

    std::vector<Creature*> get_creatures_in_room(int room);
    Creature* find_creature(int id);
    int find_creature_index(int creature_id);
};
#endif //CSC_454_HW_1_GAMEDATA_H
