//
// Created by freddy on 9/17/17.
//

#ifndef CSC_454_HW_1_STRINGUTILS_H
#define CSC_454_HW_1_STRINGUTILS_H
#include <string>
#include <vector>

namespace StringUtils {

    template<typename Out>
    void split(const std::string &s, char delim, Out result);
    std::vector<std::string> split(const std::string &s, char delim);
}

#endif //CSC_454_HW_1_STRINGUTILS_H
