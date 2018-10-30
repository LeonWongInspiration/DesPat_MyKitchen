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

void Cooker::on()
{
    current->on(this);
}

void Cooker::off()
{
    current->off(this);
}

Pot::Pot()
{
    name="锅";
    cout << "寻找可用的锅..." << endl;
}

Pot::~Pot()
{
    
}

KitchenKnife::KitchenKnife()
{
    name="刀";
    cout << "找到可用的刀" << endl;
}

KitchenKnife::~KitchenKnife()
{
    
}

Oven::Oven()
{
    name="烤箱";
    cout << "找到可用的烤箱" << endl;
}

Oven::~Oven()
{
    
}


