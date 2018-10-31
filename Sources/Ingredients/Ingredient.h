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
	string get_name(const Ingredient* i);

	/**
	* @brief Return the state of this ingredient.
	*
	*/
	bool can_be_cut(const Ingredient* i);
	bool can_be_fried(const Ingredient* i);
	bool can_be_cooked(const Ingredient* i);
	bool can_be_steamed(const Ingredient* i);

	/**
	* @brief Return a new object that is a definite food.
	*
	*/
	Ingredient* get_ingredient(Ingredient& i, double w);


protected:
    string name;
    double weight;
    // TODO: set some properties for ingredients
	char state = '11111111';
};

class Vegetable :public Ingredient {
	Vegetable();
	Vegetable(string n);
	~Vegetable();
};

class Fruit :public Ingredient {
	Fruit();
	Fruit(string n);
	~Fruit();
};

class Meat :public Ingredient {
	Meat();
	Meat(string n);
	~Meat();
};

class Flavour :public Ingredient {
	Flavour();
	Flavour(string n);
	~Flavour();

protected:
	const char state = '00001111';
};

#endif //DESPAT_MYKITCHEN_INGREDIENT_H





