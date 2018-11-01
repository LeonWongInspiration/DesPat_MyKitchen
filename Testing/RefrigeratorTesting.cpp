#include <iostream>
#include "../Sources/Refrigerator/Refrigerator.h"

int main() {
    Refrigerator<int> ref;
    ref.push_back(1024, 1);
    ref.push_back(1234, 1);
    ref.push_back(1024, 1);

    ref.reorganize();


}