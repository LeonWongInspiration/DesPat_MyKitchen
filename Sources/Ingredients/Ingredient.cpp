//
// Created by Leon Wong on 29/Oct.
//

#include "Ingredient.h"

inline std::string Ingredient::who_am_i() const {
    std::string ret = "Ingredient@";
    std::stringstream ss;
    ss << this;
    ret += ss.str();
    return ret;
}