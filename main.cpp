#include <iostream>
#include "EuropeanOption.h"

int main() {
    EuropeanOption calloption;
    std::cout << "CallOption Price " << calloption.Price();
    return 0;
}
