#include <iostream>
#include "Cooker.h"
#include "CookerFactory.h"
using namespace std;

class abc;//食材的类
typedef abc Food;
typedef list<Food*> FoodList;

FoodList rp;
FoodList rg;

int main(int argc, const char * argv[]) {    
    CookerFactory *pCookerFactory1 = new PotFactory();
    Cooker* pCooker1 = pCookerFactory1->CreateCooker();
    
    //需要检验食材是否存在
    if(pCooker1->search(rp, rg))
    {
        cout<<"食材足够"<<endl;
        if(pCooker1->cook())
        {
            pCooker1->on();
            pCooker1->off();
            delete pCooker1;
        }
        else
        {
            cout<<"选择工具错误"<<endl;
            delete pCooker1;
        }
    }
    else
    {
        cout<<"食材不足"<<endl;
        delete pCooker1;
    }
    
    return 0;
}
