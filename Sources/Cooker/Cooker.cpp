#include "Cooker.h"
#include "CookerState.h"
#include <iostream>
#include <stdio.h>
using namespace std;

Cooker::Cooker()
{
    current = new OFF();
    cout << "begin" << endl;
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
 *@param (FoodList)rp:rp tells cooker what you needs.
 *@param (FoodList)rg:cooker tells rg what is needed.
 &@return (bool):True if the food can be found in refrigerator,false otherwise.
 */
bool Cooker::search(FoodList rp, FoodList rg)
{
    FoodList::iterator j;
    /**
     * can be find.
     */
    bool flag = false;
    /**
     * Traversing rp.
     */
    for (FoodList::iterator i = rp.begin(); i != rp.end(); i++)
    {
        /**
         * Traversing rg.
         */
        for (FoodList::iterator j = rg.begin(); j!=rg.end(); j++)
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

Pot::Pot()
{
    cout << "找到可用的锅" << endl;
}

Pot::~Pot()
{
    
}

/**
 *@brief Cooke the food.
 *
 */
void Pot::cook()
{
    cout << "煮" << endl;
}

/**
 *@brief Fry the food.
 *
 */
void Pot::fry()
{
    cout << "炸" << endl;
}

/**
 *@brief Steam the food.
 *
 */
void Pot::steam()
{
    cout << "蒸" << endl;
}

KitchenKnife::KitchenKnife()
{
    cout << "找到可用的刀" << endl;
}

KitchenKnife::~KitchenKnife()
{
    
}

/**
 *@brief Cut the food.
 *
 */
void KitchenKnife::cut()
{
    cout << "切" << endl;
}

Oven::Oven()
{
    cout << "找到可用的烤箱" << endl;
}

Oven::~Oven()
{
    
}

/**
 *@brief Roast the food.
 *
 */
void Oven::roast()
{
    cout << "切" << endl;
}


