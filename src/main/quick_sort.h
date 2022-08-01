#ifndef KIP_ALGS_MERGE_SORT_H_
#define KIP_ALGS_MERGE_SORT_H_

#include <vector>
#include <random>

namespace algs {
namespace {
    
    int64_t get_rand(int64_t size) {
        std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> range(1, size - 1);
        return range(rng);
    }

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

    template <typename T>
    [[nodiscard]] std::vector<T> quick_sort_impl(typename std::vector<T>::iterator start,
                                                 typename std::vector<T>::iterator end) {
        auto dist = std::distance(start, end);
        if (dist == 1) {
            return std::vector<T>{*start};
        }
        auto pivot_index = get_rand(dist);
        return merge(quick_sort_impl<T>(start, start + pivot_index),
                     quick_sort_impl<T>(start + pivot_index, end));
    }
}

    template <typename T>
    [[nodiscard]] std::vector<T> quick_sort(std::vector<T>& vec) {
        if (vec.size() < 2) {
            return vec;
        }
        return quick_sort_impl<T>(vec.begin(), vec.end());
    }

}

#endif // KIP_ALGS_MERGE_SORT_H_
