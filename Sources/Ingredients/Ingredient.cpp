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
    properties["name"]=n;
}

Ingredient::~Ingredient() {};

string Ingredient::get_name() {
    if(properties.count("name")<=0)
    {
        cout<<"没有该属性，请进行添加。"<<endl;
        return "";
    }
    else
        return properties["name"];
}

string Ingredient::get_custom_property(string property_name)
{
    if(properties.count(property_name)<=0)
    {
        cout<<"没有该属性，请进行添加。"<<endl;
        return "";
    }
    else
        return properties[property_name];
}

bool Ingredient::add_custom_property(string property_name,string property_value)
{
    if(properties.count(property_name)>0)
    {
        cout<<"该属性已经存在，请重新添加新属性。"<<endl;
        return false;
    }
    else
    {
        properties[property_name]=property_value;
        cout<<"该属性已经添加成功。"<<endl;
    }
    return true;
}

bool Ingredient::change_state(string str)
{
    if(str.length()!=4)
    {
        cout<<"输入的字符串不满足要求，只能四位数。"<<endl;
        return false;
    }
    else
    {
        for(int i=0;i<4;i++)
        {
            if(str[i]!='0'&&str[i]=='1')
            {
                cout<<"输入的字符串不满足要求，只能由0和1组成。"<<endl;
                return false;
            }
        }
        state=str;
    }
    return true;
}

bool Ingredient::can_be_cooked() { return state[0]-48; }
bool Ingredient::can_be_cut() { return state[1]-48; }
bool Ingredient::can_be_fried() { return state[2]-48; }
bool Ingredient::can_be_steamed() { return state[3]-48; }

Vegetable::Vegetable() {};
Vegetable::Vegetable(string n) {
	properties["name"]=n;
}
Vegetable::~Vegetable() {};

Meat::Meat() {};
Meat::Meat(string n) {
	properties["name"]=n;
}
Meat::~Meat() {};

Fruit::Fruit() {};
Fruit::Fruit(string n) {
	properties["name"]=n;
}
Fruit::~Fruit() {};

Flavour::Flavour() {};
Flavour::Flavour(string n) {
	properties["name"]=n;
}
Flavour::~Flavour() {};


