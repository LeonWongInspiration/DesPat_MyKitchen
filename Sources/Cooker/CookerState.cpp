#include "CookerState.h"
#include "Cooker.h"
#include "CookerState.h"
#include <iostream>
#include <stdio.h>
using namespace std;

ON::ON()
{
}

ON::~ON()
{
}

/**
 *@brief The cooker is from ON to OFF.
 *
 *@param (Cooker*)c:The pointer points to the cooker you are using.
 */
void ON::off(Cooker* c)
{
    cout<<"进行中..."<<endl;
    cout<<"完成"<<endl;
    c->setCurrent(new OFF());
    delete this;
}

OFF::OFF()
{
}

OFF::~OFF()
{
}

/**
 *@brief The cooker is ready.
 *
 *@param (Cooker*)c:The pointer points to the cooker you are using.
 */
void OFF::on(Cooker* c)
{
    cout << "准备就绪..." << endl;
    c->setCurrent(new ON());
    delete this;
}
