//
// Created by Leon Wong on 29/Oct.
//

#ifndef DESPAT_MYKITCHEN_OBJECT_H
#define DESPAT_MYKITCHEN_OBJECT_H

#include <iostream>
#include <string>
#include <sstream>

/**
 * @brief A basic Object class containing some requirements of objects.
 *
 * @author Leon Wong
 * @build 201810291440
 */
class Object {
public:
    /**
     * @brief Get the basic information from this Object.
     * @return (string): A string about this Object and its address.
     */
    inline virtual std::string who_am_i() const {
        std::string ret = "Object@";
        std::stringstream ss;
        ss << this;
        ret += ss.str();
        return ret;
    }

    /**
     * @brief Judge if this object is equal to another one with its address.
     * @param (Object *) obj: The object pointer you want to compare with this one.
     * @return (bool): True if the two objects are the same one, false otherwise.
     * @warning This function tells an object is equal to another one only with its address!
     */
    inline bool operator== (const Object *obj) const {
        return this == obj;
    }

    /**
     * @brief Judge if this object is equal to another one with its address.
     * @param (Object &) obj: The object reference you want to compare with this one.
     * @return (bool): True if the two objects are the same one, false otherwise.
     * @warning This function tells an object is equal to another one if and only if their addresses are identical!
     */
    inline bool operator== (const Object &obj) const {
        return this == &obj;
    }
};

#endif //DESPAT_MYKITCHEN_OBJECT_H
