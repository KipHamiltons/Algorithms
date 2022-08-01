#include "insertion_sort.h"

#include <iostream>
#include <array>


int main() {

    std::array<int, 10> input{-10, 10, 20, -15, 2, 5, 1, -1, -56, 3};
    
    algs::insertion_sort(input.begin(), input.end());

    for (auto&& i : input) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
