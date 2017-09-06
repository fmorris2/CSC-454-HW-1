//
// Created by freddy on 9/3/17.
//

#include <string>
#ifndef CSC_454_HW_1_GAME_H
#define CSC_454_HW_1_GAME_H

class Game {
public:
    void cycle();
private:
    std::string get_user_input();
    void process_user_input(std::string command);
};

#endif //CSC_454_HW_1_GAME_H
