#ifndef Cooker_h
#define Cooker_h
#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;

//食材的类
class abc;

typedef abc Food;
typedef list<Food*> FoodList;

class Cooker
{
    class State *current;
public:
    Cooker();
    void setCurrent(State *s);
    void on();
    void off();
    bool search(FoodList rp,FoodList rg);
    
    bool cook();
    bool fry();
    bool steam();
    bool roast();
    bool cut();
    
    string name;
};

class Pot :public Cooker
{
public:
    Pot();
    ~Pot();
};

class KitchenKnife :public Cooker
{
public:
    KitchenKnife();
    ~KitchenKnife();
};

class Oven :public Cooker
{
public:
    Oven();
    ~Oven();
};

#endif
