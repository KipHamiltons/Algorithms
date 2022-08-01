#ifndef KIP_ALGS_UTILS_H_
#define KIP_ALGS_UTILS_H_

#include <vector>

namespace algs::utils {

    template <typename T>
    std::vector<T> merge(const std::vector<T>& first, const std::vector<T> second) {
        auto first_iter = first.begin();
        auto second_iter = second.begin();
        std::vector<T> result{};
        result.reserve(first.size() + second.size());
        while (first_iter != first.end() && second_iter != second.end()) {
            if (*first_iter < *second_iter) {
                result.push_back(*first_iter);
                first_iter++;
            } else {
                result.push_back(*second_iter);
                second_iter++;
            }
        }
        if (first_iter == first.end()) {
            result.insert(result.end(), second_iter, second.end());
        } else if (second_iter == second.end()) {
            result.insert(result.end(), first_iter, first.end());
        } 
        return result;
    }
}

#endif // KIP_ALGS_UTILS_H_

