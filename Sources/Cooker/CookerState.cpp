#include "CookerState.h"
#include "Cooker.h"
#include "CookerState.h"
#include <unistd.h>
#include <iostream>
#include <stdio.h>
using namespace std;

ON::ON()
{
}

ON::~ON()
{
}

void ON::off(Cooker* c)
{
    cout<<"进行中..."<<endl;
    sleep(c->time);
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

void OFF::on(Cooker* c)
{
    cout << "准备就绪..." << endl;
    c->setCurrent(new ON());
    delete this;
}
