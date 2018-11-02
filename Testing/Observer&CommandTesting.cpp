//
//  main.cpp
//  Created by yameng on 2018/10/30.
//

#include "../Sources/StoveRecipe/Stove.h"
#include "../Sources/StoveRecipe/Recipe.h"
#include "../Sources/StoveRecipe/Procedure.h"
#include <thread>


void SelectRecipe(int id, Stove *pStove) {
    Recipe* pRecipe = new Recipe(id);
    vector<Cooker *>cookerList;
    Command *pCook = new Cook();
    Command *pFry = new Fry();
    Command *pRoast = new Roast();
    Command *pSteam = new Steam();
    Command *pCut = new Cut();
    switch (id) {
        case 1:{
            pRecipe->SetCommand(pCut);
            cookerList.push_back(pCut->SetCooker());
            pRecipe->SetCommand(pCook);
            cookerList.push_back(pCook->SetCooker());
            pRecipe->SetCommand(pCut);
            cookerList.push_back(pCut->SetCooker());
            pRecipe->SetCommand(pFry);
            cookerList.push_back(pFry->SetCooker());
            break;
        }
        case 2:{
            pRecipe->SetCommand(pCut);
            cookerList.push_back(pCut->SetCooker());
            pRecipe->SetCommand(pSteam);
            cookerList.push_back(pSteam->SetCooker());
            pRecipe->SetCommand(pRoast);
            cookerList.push_back(pRoast->SetCooker());
            break;
        }
        default: break;
    }
    pStove->Attach(pRecipe);
    pStove->Notify();
    pRecipe->Start();
    cout << "菜谱" << id << "已做完。" << endl;
    pStove->Detach(pRecipe);
    delete pRecipe;
    delete pCook;
    delete pFry;
    delete pRoast;
    delete pSteam;
    delete pCut;
}

int main(int argc, const char * argv[]) {
    Stove *pStove = new Stove();
    int op = 0;
    int id = 0;
    cout << "欢迎来到厨房" << endl;
    do {
        cout << "1. 选择菜谱" << endl;
        cout << "2. 退出程序" << endl;
        cout << "请选择操作： " << endl;
        cin >> op;
        while(op != 1 && op != 2) {
            cout << "输入错误，请重新输入： ";
            cin >> op;
        }
        if (op == 1) {
            cout << "现在已有菜谱" << endl;
            cout << "1 / 2" << endl;
            cout << "请选择菜谱编号： " << endl;
            cin >> id;
            while(id != 1 && id != 2) {
                cout << "输入错误，请重新选择： ";
                cin >> id;
            }
            if(id == 1) {
                thread t (SelectRecipe, id, pStove);
                t.detach();
            }
            else {
                thread t (SelectRecipe, id, pStove);
                t.detach();
            }
        }
    } while (op != 2);
    while(pStove->GetSize() != 0);
    cout << "程序结束。" << endl;
    delete pStove;
    return 0;
}
