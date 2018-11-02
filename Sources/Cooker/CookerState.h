#pragma once
#ifndef CookerState_h
#define CookerState_h

#include <iostream>
#include <stdio.h>
#include "Object.h"
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

class ON :public State,public Object
{
public:
    ON();
    ~ON();
    void off(Cooker* c);
    
    /**
     * @brief Return basic information about the class.
     *
     * @return (string) Name and address of this class.
     */
    virtual string who_am_i() const override {
        stringstream add;
        add << this;
        string ret = "ON@" + add.str();
        return ret;
    }
    
};

class OFF :public State,public Object
{
public:
    OFF();
    ~OFF();
    void on(Cooker* c);
    
    /**
     * @brief Return basic information about the class.
     *
     * @return (string) Name and address of this class.
     */
    virtual string who_am_i() const override {
        stringstream add;
        add << this;
        string ret = "OFF@" + add.str();
        return ret;}
};
#endif
