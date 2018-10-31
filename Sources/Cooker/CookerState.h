#pragma once
#ifndef CookerState_h
#define CookerState_h

#include <iostream>
#include <stdio.h>
using namespace std;

class Cooker;

class State
{
public:
    virtual void on(Cooker* c)
    {
        cout << "already ON\n" << endl;
    }
    virtual void off(Cooker* c)
    {
        cout << "already OFF\n" << endl;
    }
};

class ON :public State
{
public:
    ON();
    ~ON();
    void off(Cooker* c);
    
};

class OFF :public State
{
public:
    OFF();
    ~OFF();
    void on(Cooker* c);
};
#endif
