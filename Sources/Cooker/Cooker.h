#ifndef Cooker_h
#define Cooker_h
#include <iostream>
#include <stdio.h>
#include <list>
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
class Pot :public Cooker
{
public:
    Pot();
    ~Pot();
};

/**
 * @brief A basic KitchenKnife class containing some requirements of KitchenKnife.
 *
 */
class KitchenKnife :public Cooker
{
public:
    KitchenKnife();
    ~KitchenKnife();
};

/**
 * @brief A basic Oven class containing some requirements of Oven.
 *
 */
class Oven :public Cooker
{
public:
    Oven();
    ~Oven();
};

#endif
