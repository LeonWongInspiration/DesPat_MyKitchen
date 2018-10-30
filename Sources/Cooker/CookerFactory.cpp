#include "CookerFactory.h"
#include "Cooker.h"

CookerFactory::CookerFactory()
{
    
}

CookerFactory::~CookerFactory()
{
    
}

PotFactory::PotFactory()
{
    
}

PotFactory::~PotFactory()
{
    
}

Cooker* PotFactory::CreateCooker()
{
    return new Pot();
}

KitchenKnifeFactory::KitchenKnifeFactory()
{
    
}

KitchenKnifeFactory::~KitchenKnifeFactory()
{
    
}

Cooker* KitchenKnifeFactory::CreateCooker()
{
    return new KitchenKnife();
}

OvenFactory::OvenFactory()
{
    
}

OvenFactory::~OvenFactory()
{
    
}

Cooker* OvenFactory::CreateCooker()
{
    return new Oven();
}
