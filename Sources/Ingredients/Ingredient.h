//
// Created by Leon Wong on 29/Oct.
//

#ifndef DESPAT_MYKITCHEN_INGREDIENT_H
#define DESPAT_MYKITCHEN_INGREDIENT_H

#include "../Object.h"
#include <iostream>
#include <string>
#include <sstream>

class Ingredient: public Object {
public:
    /**
     * @brief Return the basic info of this object: name and address.
     *
     * @return (string) A string about this object and its address.
     */
    inline virtual std::string who_am_i() const;


};

#endif //DESPAT_MYKITCHEN_INGREDIENT_H
