//
// Created by joseph on 11/29/24.
//

#ifndef QUICKSORT_RANDOM_PIVOT_H
#define QUICKSORT_RANDOM_PIVOT_H
#include <cstdlib>


template<class T>
void quicksort_random_pivot(T data[], int first, int last) {
    int lower = first + 1;
    int upper = last;

    std::swap(data[first], data[random() % (last - first + 1) + first]);

    T bound = data[first];
    while (lower <= upper) {
        while (bound > data[lower])
            lower++;
        while (bound < data[upper])
            upper--;
        if (lower < upper)
            std::swap(data[lower++], data[upper--]);
        else
            lower++;
    }
    std::swap(data[upper], data[first]);
    if (first < upper - 1)
        quicksort_random_pivot(data, first, upper - 1);
    if (upper + 1 < last)
        quicksort_random_pivot(data, upper + 1, last);
}

template<class T>
void quicksort_random_pivot(T data[], const int n) {
    int i, max;
    if (n < 2)
        return;
    for (i = 1, max = 0; i < n; i++) // find the largest
        if (data[max] < data[i]) // element and put it
            max = i; // at the end of data[];
    std::swap(data[n - 1], data[max]); // largest el is now in its
    quicksort_random_pivot(data, 0, n - 2); // final position;
}


#endif //QUICKSORT_RANDOM_PIVOT_H
