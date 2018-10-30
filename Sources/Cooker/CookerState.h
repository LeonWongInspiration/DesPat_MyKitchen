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
    /**
     *@brief The cooker is from ON to OFF.
     *
     *@param (Cooker*)c:The pointer points to the cooker you are using.
     */
    void off(Cooker* c);
    
    /**
     *@brief wait.
     *
     *@param (int)time:You need to wait a moment.
     */
    void count(int time);
};

class OFF :public State
{
public:
    OFF();
    ~OFF();
    /**
     *@brief The cooker is ready.
     *
     *@param (Cooker*)c:The pointer points to the cooker you are using.
     */
    void on(Cooker* c);
};
#endif
