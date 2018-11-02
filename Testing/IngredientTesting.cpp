#include <iostream>
#include "Ingredient.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    //map
    Ingredient* food=new Vegetable("caraway");
    
    cout<<food->get_name()<<endl;
    
    if(food->can_be_cooked()==1)
        cout<<"can be cooked"<<endl;
    if(food->can_be_steamed()==1)
        cout<<"can be steamed"<<endl;
    if(food->can_be_fried()==1)
        cout<<"can be fried"<<endl;
    if(food->can_be_cut()==1)
        cout<<"can be cut"<<endl;
    
    food->change_state("1010");
    food->change_state("11111");
    food->change_state("absd");
    
    food->add_custom_property("weight", "1斤");
    cout<<food->get_custom_property("weight")<<endl;
    food->add_custom_property("weight", "1斤");
    
    return 0;
}
