//
// Created by Leon Wong on 29/Oct.
//
#include "Ingredient.h"
#include<iostream>
#include<stdio.h>

inline std::string Ingredient::who_am_i() const {
    std::string ret = "Ingredient@";
    std::stringstream ss;
    ss << this;
    ret += ss.str();
    return ret;
}

Ingredient::Ingredient(const std::string name) {
    this->properties = new std::map<std::string, std::string>();
    (*this->properties)["name"] = name;
    this->reference_count = new int(1);
};

Ingredient::Ingredient(const Ingredient& RHS){
    this->properties = RHS.properties;
    this->reference_count = RHS.reference_count;
    (*this->reference_count) += 1;
}

Ingredient::~Ingredient() {
    *this->reference_count -= 1;
    if (*this->reference_count == 0) {
        delete this->properties;
        delete this->reference_count;
    }
};

std::string Ingredient::get_name() {
    if (!(this->properties->count("name"))) {
        return std::string("");
    }
    else
        return this->properties->at("name");
}

const std::string Ingredient::get_custom_property(const std::string& property_name) const {
    if (!(this->properties->count(property_name))) {
        return std::string("");
    }
    else
        return this->properties->at(property_name);
}

bool Ingredient::add_custom_property(const std::string& property_name, const std::string& property_value) {
    this->deRefCounting();
    if ((this->properties->count(property_name))){
        return false;
    }
    else {
        (*this->properties)[property_name] = property_value;
    }
    return true;
}

bool Ingredient::modify_property(const std::string& property_name, const std::string& property_value) {
    this->deRefCounting();
    if (!(this->properties->count(property_name))) {
        return false;
    }
    else {
        (*this->properties)[property_name] = property_value;
    }
    return true;
}

std::string& Ingredient::operator[](const std::string &property) {
    this->deRefCounting();
    return (*this->properties)[property];
}

const std::string& Ingredient::operator[](const std::string &property) const {
    return (*this->properties)[property];
}

void Ingredient::deRefCounting() {
    if (*this->reference_count == 1)
        return;
    else {
        *this->reference_count -= 1;
        this->properties = new std::map<std::string, std::string>(*this->properties);
        this->reference_count = new int(1);
    }
}