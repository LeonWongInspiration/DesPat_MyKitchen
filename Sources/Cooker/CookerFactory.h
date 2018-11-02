#pragma once
#ifndef CookerFactory_h
#define CookerFactory_h

class Cooker;


/**
 * @brief CookerFactory produces Cooker.
 *
 */
class CookerFactory
{
public:
    CookerFactory();
    ~CookerFactory();
    virtual Cooker* CreateCooker() = 0;
};

/**
 * @brief PotFactory produces Pot.
 *
 */
class PotFactory :public CookerFactory
{
public:
    PotFactory();
    ~PotFactory();
    Cooker* CreateCooker();
};

/**
 * @brief KitchenKnifeFactory produces KitchenKnife.
 *
 */
class KitchenKnifeFactory :public CookerFactory
{
public:
    KitchenKnifeFactory();
    ~KitchenKnifeFactory();
    Cooker* CreateCooker();
};

/**
 * @brief OvenFactory produces Oven.
 *
 */
class OvenFactory :public CookerFactory
{
public:
    OvenFactory();
    ~OvenFactory();
    Cooker* CreateCooker();
};

#endif
