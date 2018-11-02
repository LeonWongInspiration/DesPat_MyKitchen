#include <iostream>
#include "../Sources/Ingredients/Ingredient.h"

using namespace std;

int main(int argc, const char * argv[]) {

    Ingredient i1("Apple");
    Ingredient i2("Banana");

    cout << i1.get_name() << endl;
    cout << i2.get_name() << endl;

    i1.add_custom_property("Weight", "50g");
    i2.add_custom_property("Color", "Yellow");

    cout << i1["Weight"] << endl;
    cout << i1.get_custom_property("Weight") << endl;

    Ingredient i3(i2);

    cout << i3.get_custom_property("Color") << endl;

    cout << (i2 == i3) << endl;

    i2["Color"] = "Green";
    cout << i2.get_custom_property("Color") << endl;

    cout << i3.get_custom_property("Color") << endl;
    cout << (i2 == i3) << endl;

    Ingredient i4("Apple");
    i4.add_custom_property("Weight", "50g");
    cout << (i1 == i4) << endl;

    return 0;
}
