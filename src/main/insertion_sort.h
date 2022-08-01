#ifndef KIP_ALGS_INSERTION_SORT_H_
#define KIP_ALGS_INSERTION_SORT_H_

#include <iterator>

namespace algs {

    template <typename Iterator>
    void insertion_sort(Iterator start, Iterator end) {
       
        for (Iterator sorted = start; sorted != end; sorted++) {
            for (Iterator inserting = sorted; inserting != start; --inserting) {
                if (*inserting < *std::prev(inserting)) {
                    std::swap(*inserting, *std::prev(inserting));
                }
            }
        }
    }
}

#endif // KIP_ALGS_INSERTION_SORT_H_

