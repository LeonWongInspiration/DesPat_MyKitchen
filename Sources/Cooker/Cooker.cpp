#include "Cooker.h"
#include "CookerState.h"
#include <iostream>
#include <stdio.h>
using namespace std;

Cooker::Cooker()
{
    current = new OFF();
}

void Cooker::setCurrent(State *s)
{
    current = s;
}

/**
 *@brief Change to the "ON"state
 *
 */
void Cooker::on()
{
    current->on(this);
}

/**
 *@brief Change to the "OFF"state.
 *
 */
void Cooker::off()
{
    current->off(this);
}

/**
 *@brief Find food in Refrigerator.
 *
 *@param (string)rp:rp tells cooker what you needs.
 *@param (string)rg:cooker tells rg what is needed.
 &@return (bool):True if the food can be found in refrigerator,false otherwise.
 */
bool Cooker::search(list<string> rp, list<string> rg)
{
    /**
     * can be find.
     */
    bool flag = false;
    /**
     * Traversing rp.
     */
    for (list<string>::iterator i = rp.begin(); i != rp.end(); i++)
    {
        /**
         * Traversing rg.
         */
        for (list<string>::iterator j = rg.begin(); j!=rg.end(); j++)
        {
            if (*i==*j)
            {
                flag = true;
            }
        }
        if (flag == false)
            return false;
        else
            flag = false;
    }
    return true;
}

/**
 *@brief Cook the food.
 *
 */
bool Cooker::cook()
{
    if(name=="Pot")
    {
        cout<<"煮"<<endl;
        return true;
    }
    else
        return false;
}

/**
 *@brief Fry the food.
 *
 */
bool Cooker::fry()
{
    if(name=="Pot")
    {
        cout<<"炸"<<endl;
        return true;
    }
    else
        return false;
}

/**
 *@brief Steam the food.
 *
 */
bool Cooker::steam()
{
    if(name=="Pot")
    {
        cout<<"蒸"<<endl;
        return true;
    }
    else
        return false;
}

/**
 *@brief Roast the food.
 *
 */
bool Cooker::roast()
{
    if(name=="Oven")
    {
        cout<<"烤"<<endl;
        return true;
    }
    else
        return false;
}

/**
 *@brief Cut the food.
 *
 */
bool Cooker::cut()
{
    if(name=="KitchenKnife")
    {
        cout<<"切"<<endl;
        return true;
    }
    else
        return false;
}
Pot::Pot()
{
    name="Pot";
    cout << "找到可用的锅" << endl;
}

Pot::~Pot()
{
    
}

KitchenKnife::KitchenKnife()
{
    name="KitchenKnife";
    cout << "找到可用的刀" << endl;
}

KitchenKnife::~KitchenKnife()
{
    
}

Oven::Oven()
{
    name="Oven";
    cout << "找到可用的烤箱" << endl;
}

Oven::~Oven()
{
    
}



