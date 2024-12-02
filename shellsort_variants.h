//
// Created by joseph on 11/29/24.
//

#ifndef SHELLSORT_VARIANTS_H

#define SHELLSORT_VARIANTS_H
#include <vector>
#include <cmath>

//from the textbook
template<class T>
void Shellsort_9_8(T data[], int n) {
    int i, h;
    int increments[20];

    // Create an appropriate number of increments h
    for (h = 1, i = 0; h < n; i++) {
        // Calculate h_t+2 to decide whether to stop
        if (3 * (3 * h + 1) + 1 >= n) break; // Stop if h_t+2 >= n

        increments[i] = h;
        h = 3 * h + 1;
    }

    // Loop on the number of different increments h
    for (i--; i >= 0; i--) {
        h = increments[i];

        // Loop on the number of subarrays h-sorted in ith pass
        for (int hCnt = h; hCnt < 2 * h; hCnt++) {
            // Insertion sort for subarray containing every hth element
            for (int j = hCnt; j < n;) {
                // array data
                T tmp = data[j];
                int k = j;
                while (k - h >= 0 && tmp < data[k - h]) {
                    data[k] = data[k - h];
                    k -= h;
                }
                data[k] = tmp;
                j += h;
            }
        }
    }
}

//h=2k−1h=2k−1
template<class T>
void Shellsort_b(T data[], int n) {
    int i, j, k, hCnt, h;
    std::vector<int> increments;

    // Generate gap sequence: h = 2^k - 1
    for (int k = 1; (h = (1 << k) - 1) < n; k++) {
        increments.push_back(h);
    }

    // Loop through the gaps in reverse order
    for (auto it = increments.rbegin(); it != increments.rend(); ++it) {
        h = *it;

        // Perform h-sorting using insertion sort
        for (hCnt = h; hCnt < n; hCnt++) {
            T tmp = data[hCnt];
            for (j = hCnt; j >= h && data[j - h] > tmp; j -= h) {
                data[j] = data[j - h];
            }
            data[j] = tmp;
        }
    }
}

// h1=1,h=2k+1h1=1,h=2k+1
template<class T>
void Shellsort_c(T data[], int n) {
    if (n <= 1) return; // Early exit for edge cases

    int i, j, hCnt, h;
    std::vector<int> increments;

    // Generate gap sequence: h = 2k + 1 for k >= 0
    for (int k = 0, h = 1; h < n; ++k, h = 2 * k + 1) {
        increments.push_back(h);
    }

    // Loop through the gaps in reverse order
    for (auto it = increments.rbegin(); it != increments.rend(); ++it) {
        h = *it;

        // Perform h-sorting using insertion sort
        for (hCnt = h; hCnt < n; ++hCnt) {
            T tmp = data[hCnt];
            for (j = hCnt; j >= h && data[j - h] > tmp; j -= h) {
                data[j] = data[j - h];
            }
            data[j] = tmp;
        }
    }
}


//Fibonacci sequence
template<class T>
void Shellsort_d(T data[], int n) {
    int i, j, k, hCnt, h;
    std::vector<int> increments;

    // Generate Fibonacci sequence up to n
    int a = 1, b = 1; // F(2) = 1, F(3) = 1
    while (a < n) {
        increments.push_back(a);
        int next = a + b;
        a = b;
        b = next;
    }

    // Loop through the gaps in reverse order
    for (auto it = increments.rbegin(); it != increments.rend(); ++it) {
        h = *it;

        // Perform h-sorting using insertion sort
        for (hCnt = h; hCnt < n; hCnt++) {
            T tmp = data[hCnt];
            for (j = hCnt; j >= h && data[j - h] > tmp; j -= h) {
                data[j] = data[j - h];
            }
            data[j] = tmp;
        }
    }
}

// h1=n/2,hi=⌊0.75⋅hi+1⌋h1=n/2,hi=⌊0.75⋅hi+1⌋
template<class T>
void Shellsort_e(T data[], int n) {
    int i, j, k, hCnt, h;
    std::vector<int> increments;
    // Generate gap sequence: h1 = n/2, hi = floor(0.75 * hi+1)
    h = n / 2;
    while (h > 0) {
        increments.push_back(h);
        h = static_cast<int>(std::floor(0.75 * h));
    }

    // Loop through the gaps in reverse order
    for (auto it = increments.rbegin(); it != increments.rend(); ++it) {
        h = *it;

        // Perform h-sorting using insertion sort
        for (hCnt = h; hCnt < n; hCnt++) {
            T tmp = data[hCnt];
            for (j = hCnt; j >= h && data[j - h] > tmp; j -= h) {
                data[j] = data[j - h];
            }
            data[j] = tmp;
        }
    }
}


#endif //SHELLSORT_VARIANTS_H
