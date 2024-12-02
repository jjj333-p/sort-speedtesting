//
// Created by joseph on 11/29/24.
//

#ifndef QUICKSORT9_11_H
#define QUICKSORT9_11_H

template<class T>
void quicksort9_11(T data[], int first, int last) {
    int lower = first + 1, upper = last;
    std::swap(data[first], data[(first + last) / 2]);
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
        quicksort9_11(data, first, upper - 1);
    if (upper + 1 < last)
        quicksort9_11(data, upper + 1, last);
}

template<class T>
void quicksort9_11(T data[], const int n) {
    int i, max;
    if (n < 2)
        return;
    for (i = 1, max = 0; i < n; i++) // find the largest
        if (data[max] < data[i])    // element and put it
            max = i;                // at the end of data[];
    std::swap(data[n - 1], data[max]);   // largest el is now in its
    quicksort9_11(data, 0, n - 2);      // final position;
}


#endif //QUICKSORT9_11_H
