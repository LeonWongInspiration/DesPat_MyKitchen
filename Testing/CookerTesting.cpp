#include <iostream>
#include "Cooker.h"
#include "CookerFactory.h"
using namespace std;

list<string> rp;
list<string> rg;

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
        }
        else
        {
            cout<<"选择工具错误"<<endl;
        }
    }
    else
    {
        cout<<"食材不足"<<endl;
    }
    
    return 0;
}
