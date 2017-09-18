//
// Created by freddy on 9/16/17.
//
#include "Creature.h"
#include "CreatureType.cpp"
#include "pc/PlayerCharacter.h"
#include "animal/Animal.h"
#include "npc/Npc.h"
#include "CreatureFactory.h"

namespace CreatureFactory {
    Creature* create_creature(int id, int type, int location) {
        switch((CreatureType) type) {
            case PC:
                return new PlayerCharacter(id, location);
            case ANIMAL:
                return new Animal(id, location);
            case NPC:
                return new Npc(id, location);
        }
    }
}

