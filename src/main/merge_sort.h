#ifndef KIP_ALGS_MERGE_SORT_H_
#define KIP_ALGS_MERGE_SORT_H_

#include <vector>
#include "utils.h"

namespace algs {
namespace {
    template <typename T>
    [[nodiscard]] std::vector<T> merge_sort_impl(typename std::vector<T>::iterator start,
                                     typename std::vector<T>::iterator end) {
        auto dist = std::distance(start, end);
        std::vector<T> first;
        std::vector<T> second;
        if (dist == 1) {
            return std::vector<T>{*start};
        }
        return utils::merge(merge_sort_impl<T>(start, start + (dist / 2)),
                            merge_sort_impl<T>(start + (dist / 2), end));
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

