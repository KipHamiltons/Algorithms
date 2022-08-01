#ifndef KIP_ALGS_MERGE_SORT_H_
#define KIP_ALGS_MERGE_SORT_H_

#include <vector>

namespace algs {
namespace {
    template <typename T>
    [[nodiscard]] std::vector<T> merge_sort_impl(typename std::vector<T>::iterator start,
                                     typename std::vector<T>::iterator end) {
        auto dist = std::distance(start, end);
        std::vector<T> first;
        std::vector<T> second;
        switch (dist) {
            case 1:
                return std::vector<T>{*start};
            default:
                first = merge_sort_impl<T>(start, start + (dist / 2));
                second = merge_sort_impl<T>(start + (dist / 2), end);
                break;
        }
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

    template <typename T>
    [[nodiscard]] std::vector<T> merge_sort(std::vector<T>& vec) {
        if (vec.size() < 2) {
            return vec;
        }
        return merge_sort_impl<T>(vec.begin(), vec.end());
    }

}

#endif // KIP_ALGS_MERGE_SORT_H_
