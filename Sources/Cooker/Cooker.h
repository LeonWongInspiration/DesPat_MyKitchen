#ifndef Cooker_h
#define Cooker_h
#include <iostream>
#include <stdio.h>
#include <list>
#include "Object.h"
using namespace std;

/**
 * @brief A basic Cooker class containing some requirements of cookers.
 *
 */
class Cooker
{
    class State *current;
public:
    Cooker();
    void setCurrent(State *s);
    void on();
    void off();
    bool search(list<string> rp,list<string> rg);
    
    bool cook();
    bool fry();
    bool steam();
    bool roast();
    bool cut();
    
    string name;
};

/**
 * @brief A basic Pot class containing some requirements of Pot.
 *
 */
class Pot :public Cooker,public Object
{
public:
    Pot();
    ~Pot();
    
    /**
     * @brief Return basic information about the class.
     *
     * @return (string) Name and address of this class.
     */
    virtual string who_am_i() const override {
        stringstream add;
        add << this;
        string ret = "Pot@" + add.str();
        return ret;
    }
    
};

/**
 * @brief A basic KitchenKnife class containing some requirements of KitchenKnife.
 *
 */
class KitchenKnife :public Cooker,public Object
{
public:
    KitchenKnife();
    ~KitchenKnife();
    
    /**
     * @brief Return basic information about the class.
     *
     * @return (string) Name and address of this class.
     */
    virtual string who_am_i() const override {
        stringstream add;
        add << this;
        string ret = "KitchenKnife@" + add.str();
        return ret;
    }
};

/**
 * @brief A basic Oven class containing some requirements of Oven.
 *
 */
class Oven :public Cooker,public Object
{
public:
    Oven();
    ~Oven();
    
    /**
     * @brief Return basic information about the class.
     *
     * @return (string) Name and address of this class.
     */
    virtual string who_am_i() const override {
        stringstream add;
        add << this;
        string ret = "Oven@" + add.str();
        return ret;}
};

#endif
