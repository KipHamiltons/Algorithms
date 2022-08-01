#include <iostream>
#include <array>
#include "bubble_sort.h"

int main() {

    std::array<int, 10> input{ -1, -3, 5, 4, 9, 5, 3, 10, -10, 11};

    algs::bubble_sort(input.begin(), input.end());
    
    for (int i : input) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

