//
// Created by Leon Wong on 29/Oct.
//

#ifndef DESPAT_MYKITCHEN_INGREDIENT_H
#define DESPAT_MYKITCHEN_INGREDIENT_H

#include "Object.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

class Ingredient: public Object {
public:
	/**
	* @brief construct a kind of ingredient.
	*
	*/
	Ingredient();
	Ingredient(string n);
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
	string get_name();
    
    /**
     * @brief Return the property of this ingredient.
     *
     * @param (string) property_name:property_name is the key.
     * @return (string) property_name:Return property of this ingredient.
     */
    string get_custom_property(string property_name);
    
    /**
     * @brief Add a new record to properties.
     *
     * @param (string) property_name:property_name is the key.
     * @param (string) property_value:property_value is the value.
     * @return (bool):True if add the record sucessfully.
     */
    bool add_custom_property(string property_name,string property_value);
    
    /**
     * @brief Change the state.
     *
     * @param (string) str:the new state.
     * @return (bool):True if change the state sucessfully.
     */
    bool change_state(string str);
    
	/**
	* @brief Return the state of this ingredient.
	*
	*/
	bool can_be_cut();
	bool can_be_fried();
	bool can_be_cooked();
	bool can_be_steamed();
    
    /**
     * The properties of the Ingredient.
     */
    map<string,string>properties;

protected:
    // TODO: set some properties for ingredients
	string state = "1111";
};

class Vegetable :public Ingredient {
public:
	Vegetable();
	Vegetable(string n);
	~Vegetable();
};

class Fruit :public Ingredient {
public:
	Fruit();
	Fruit(string n);
	~Fruit();
};

class Meat :public Ingredient {
public:
	Meat();
	Meat(string n);
	~Meat();
};

class Flavour :public Ingredient {
public:
	Flavour();
	Flavour(string n);
	~Flavour();

protected:
	const string state = "0011";
};

#endif //DESPAT_MYKITCHEN_INGREDIENT_H





