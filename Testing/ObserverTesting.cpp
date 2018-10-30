//
//  main.cpp
//  Created by yameng on 2018/10/30.
//

#include "../Sources/StoveRecipe/Stove.h"
#include "../Sources/StoveRecipe/Recipe.h"

void CreateRecipe(int id, list<int>tList, Stove *pStove){
    Recipe* pRecipe = new Recipe(id);
    pRecipe->SetTime(tList);
    pStove->Attach(pRecipe);
    pStove->Notify();
    pRecipe->Start();
    cout << endl;
    cout << "菜谱" << id << "已做完。" << endl;
    pStove->Detach(pRecipe);
    delete pRecipe;
}

int main(int argc, const char * argv[]) {
    Stove *pStove = new Stove();
    char op = 'y';
    int id = 1;
    list<int>timeList;
    cout << "欢迎来到厨房" << endl;
    while(op != 'n'){
        cout << "是否创建菜谱？(y/n): ";
        cin >> op;
        while(op != 'y' && op != 'n'){
            cout << "输入错误，请输入(y/n): ";
            cin >> op;
        }
        if(op == 'y'){
            cout << "创建菜谱" << id << endl;
            cout << "输入每个步骤的时间，例如：" << endl;
            cout << "2 3 1 5 2" << endl;
            do{
                int t;
                cin >> t;
                timeList.push_back(t);
            }while (cin.get() != '\n');
            thread t(CreateRecipe, id, timeList, pStove);
            t.detach();
            timeList.clear();
        }
        id++;
    }
    while(pStove->GetSize() != 0);
    cout << "程序结束。" << endl;
    delete pStove;
    return 0;
}
