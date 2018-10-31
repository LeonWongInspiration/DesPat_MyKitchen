//
// Created by Leon Wong on 29/Oct.
//
#include "Ingredient.h"
#include<iostream>
#include<stdio.h>

using namespace std;

inline string Ingredient::who_am_i() const {
    string ret = "Ingredient@";
    stringstream ss;
    ss << this;
    ret += ss.str();
    return ret;
}

Ingredient::Ingredient() {};

Ingredient::Ingredient(string n){
	Ingredient.name = n;
}

Ingredient::~Ingredient() {};

string Ingredient::get_name(const Ingredient* i) {
	return i->name;
}

bool Ingredient::can_be_cooked(const Ingredient* i) { return 1; }
bool Ingredient::can_be_cut(const Ingredient* i) { return 1; }
bool Ingredient::can_be_fried(const Ingredient* i) { return 1; }
bool Ingredient::can_be_steamed(const Ingredient* i) { return 1; }

Ingredient* Ingredient::get_ingredient(Ingredient& i, double w) {
	Ingredient* p = new Ingredient(i);
	p->weight =w;
	i.weight -= w;
	return p;
}

Vegetable::Vegetable() {};
Vegetable::Vegetable(string n) {
	Vegetable.name = n;
}
Vegetable::~Vegetable() {};

Meat::Meat() {};
Meat::Meat(string n) {
	Meat.name = n;
}
Meat::~Meat() {};

Fruit::Fruit() {};
Fruit::Fruit(string n) {
	Fruit.name = n;
}
Fruit::~Fruit() {};

Flavour::Flavour() {};
Flavour::Flavour(string n) {
	Flavour.name = n;
}
Flavour::~Flavour() {};


