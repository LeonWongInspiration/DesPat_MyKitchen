//
// Created by Leon Wong on 29/Oct.
//

#ifndef DESPAT_MYKITCHEN_INGREDIENT_H
#define DESPAT_MYKITCHEN_INGREDIENT_H

#include "../Object.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <map>

/**
 * Ingredient base class definition.
 */
class Ingredient: public Object {
public:
	/**
	* @brief construct a kind of ingredient with given name.
	*
	* @param (const std::string)name: Name of the Ingredient.
	*/
	Ingredient(const std::string name);

	/**
	 * @brief Copy construct with Copy-on-Write.
	 *
	 * @param RHS Copy construct param.
	 */
	Ingredient(const Ingredient& RHS);

	/**
	 * @brief Destruct this Ingredient, with Copy-on-Write.
	 */
	~Ingredient();

    /**
     * @brief Return the basic info of this object: name and address.
     *
     * @return (string) A string about this object and its address.
     */
    inline virtual std::string who_am_i() const override;

	/**
     * @brief Return the name of this ingredient.
     *
     */
	std::string get_name();
    
    /**
     * @brief Return the property of this ingredient.
     *
     * @param (string) property_name:property_name is the key.
     * @return (string) Return acquired property of this ingredient.
     */
    const std::string get_custom_property(const std::string& property_name) const;
    
    /**
     * @brief Add a new record to properties.
     *
     * @param (string) property_name:property_name is the key.
     * @param (const string&) property_value:property_value is the value.
     * @return (bool):True if add the record successfully.
     */
    bool add_custom_property(const std::string& property_name, const std::string& property_value);
    
    /**
     * @brief Change the state.
     *
     * @param (string) property_name:the new state.
     * @param (string) property_value: The new value of the property.
     * @return (bool):True if change the state successfully.
     */
    bool modify_property(const std::string& property_name, const std::string& property_value);

    /**
     * @brief Acquire a property and (maybe) modify it.
     *
     * @param property Name of the acquired property.
     * @return (string&) value of that property.
     */
    std::string& operator[](const std::string& property);

    /**
     * @brief Acquire a property and (maybe) modify it.
     *
     * @param property Name of the acquired property.
     * @return (string&) value of that property.
     */
    const std::string& operator[](const std::string& property) const;

    /**
     * @brief Decide whether an Ingredient is identical to another one.
     *
     * @param LHS
     * @param RHS
     * @return True if identical, false otherwise.
     */
    friend bool operator==(const Ingredient& LHS, const Ingredient& RHS){
        if (LHS.properties == RHS.properties)
            return true;
        if (LHS.properties->size() != RHS.properties->size())
            return false;
        auto iter = LHS.properties->begin();
        while (iter != LHS.properties->end()) {
            if (iter->second != (*RHS.properties)[iter->first])
                return false;
            ++iter;
        }
        return true;
    }

private:
    /**
     * The properties of the Ingredient.
     */
    std::map<std::string, std::string>* properties;

    /**
     * Reference counting.
     */
    int *reference_count;

    /**
     * @brief Cancel the sharing of the map and create a new one for this Ingredient.
     */
    void deRefCounting();
};


#endif //DESPAT_MYKITCHEN_INGREDIENT_H





