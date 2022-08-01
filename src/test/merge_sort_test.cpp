#include "merge_sort.h"
#include <vector>
#include <iostream>


int main() {

    std::vector<int> a { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10 };
    
    for (auto&& b : algs::merge_sort<int>(a)) {
        std::cout << b << " ";
    }
    std::cout << std::endl;
}
