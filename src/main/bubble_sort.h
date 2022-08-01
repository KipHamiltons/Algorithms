#ifndef KIP_ALGS_BUBBLE_SORT_H_
#define KIP_ALGS_BUBBLE_SORT_H_

namespace algs {
    template <typename Iterator>
    void bubble_sort(Iterator start, Iterator end) {
        bool clean_pass = false;
        while (!clean_pass) {
            clean_pass = true;
            Iterator current = start;
            while (std::next(current) != end) {
                if (*std::next(current) < *current) {
                    std::swap(*current, *std::next(current));
                    clean_pass = false;
                }
                current++;
            }
        }
    }
}

#endif // KIP_ALGS_BUBBLE_SORT_H_

