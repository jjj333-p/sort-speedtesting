//
// Created by joseph on 11/29/24.
//

#ifndef QUICKSORT_MEDIAN_PIVOT_H
#define QUICKSORT_MEDIAN_PIVOT_H
#include <fstream>

template<class T>
void quicksort_median_pivot(T data[], int first, int last) {
    if (first >= last) return;
    int lower = first + 1;
    int upper = last;

    // Step 1: Select the first, middle, and last elements
    int mid = (first + last) / 2;
    T a = data[first], b = data[mid], c = data[last];

    // Step 2: Find the median of the first, middle, and last elements
    if (a > b) std::swap(a, b); // a <= b
    if (b > c) std::swap(b, c); // b <= c
    if (a > b) std::swap(a, b); // a <= b <= c

    // Step 3: std::swap the median with the first element
    std::swap(data[first], b);

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
        quicksort_median_pivot(data, first, upper - 1);
    if (upper + 1 < last)
        quicksort_median_pivot(data, upper + 1, last);
}

template<class T>
void quicksort_median_pivot(T data[], const int n) {
    int i, max;
    if (n < 2)
        return;
    for (i = 1, max = 0; i < n; i++) // find the largest
        if (data[max] < data[i]) // element and put it
            max = i; // at the end of data[];
    std::swap(data[n - 1], data[max]); // largest el is now in its
    quicksort_median_pivot(data, 0, n - 2); // final position;
}


#endif //QUICKSORT_MEDIAN_PIVOT_H
