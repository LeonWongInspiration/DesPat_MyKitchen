#include <iostream>
#include "../Sources/Refrigerator/Refrigerator.h"

int main() {
    Refrigerator<int> ref;
    ref.push_back(1024, 1);
    ref.push_back(1234, 1);
    ref.push_back(1024, 1);

    std::cout << ref.search(1024) << std::endl;
    std::cout << ref.search(1234) << std::endl;
    ref.reorganize();
    ref.remove(1024);
    std::cout << ref.search(1024) << std::endl;
}