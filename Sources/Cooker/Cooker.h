#ifndef Cooker_h
#define Cooker_h
#include <iostream>
#include <stdio.h>
using namespace std;

class Food;
class Refrigerator;
class Menu;

/**
 * @brief Cooker.
 *
 */
class Cooker
{
    class State *current;
public:
    Cooker();
    void setCurrent(State *s);
    
    /**
     *@brief Change to the "ON"state.
     *
     */
    void on();
    
    /**
     *@brief Change to the "OFF"state.
     *
     */
    void off();
    
    /**
     *@brief Get Messagers from Menu,including time.
     *
     */
    void getMenu(Menu* m);
    
    /**
     *@brief Send Messagers to Refrigerator.
     *
     */
    void sendMessager(Refrigerator* r);
    
    /**
     * The name of the Cooker.
     */
    string name;
    
    /**
     * Count Down.
     */
    int time;
};

/**
 * @brief Pot.
 *
 */
class Pot :public Cooker
{
public:
    Pot();
    ~Pot();
    /**
     *@brief Cook the food.
     *
     */
    void cook(Food f);
    
    /**
     *@brief Fry the food.
     *
     */
    void fry(Food f);
    
    /**
     *@brief Steam the food.
     *
     */
    void steam(Food f);
};

/**
 * @brief KitchenKnife.
 *
 */
class KitchenKnife :public Cooker
{
public:
    KitchenKnife();
    ~KitchenKnife();
    
    /**
     *@brief cut the food.
     *
     */
    void cut(Food f);
};

/**
 * @brief Oven.
 *
 */
class Oven :public Cooker
{
public:
    Oven();
    ~Oven();
    /**
     *@brief roast the food.
     *
     */
    void roast(Food f);
};

#endif /* Cooker_hpp */
