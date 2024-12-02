#include <iostream>
#include <chrono>
#include "quicksort9.11.h"
#include "quicksort_median_pivot.h"
#include "quicksort_random_pivot.h"
#include "shellsort_variants.h"

int main() {
    for (int run = 0; run < 5; run++) {
        std::cout << "Run " << run + 1 << std::endl;

        std::cout << "Generating array of 20 integers to test against...\n\t[ ";
        auto *qs_911_arr20 = new long int[20];
        auto *qs_rand_arr20 = new long int[20];
        auto *qs_median_pivot_arr20 = new long int[20];
        auto *ss_98_arr20 = new long int[20];
        auto *ss_b_arr20 = new long int[20];
        auto *ss_c_arr20 = new long int[20];
        auto *ss_d_arr20 = new long int[20];
        auto *ss_e_arr20 = new long int[20];
        for (long int i = 0, j = 0; i < 20; i++) {
            j = random() % 500000;
            std::cout << j << ", ";
            qs_911_arr20[i] = j;
            qs_rand_arr20[i] = j;
            qs_median_pivot_arr20[i] = j;
            ss_98_arr20[i] = j;
            ss_b_arr20[i] = j;
            ss_c_arr20[i] = j;
            ss_d_arr20[i] = j;
            ss_e_arr20[i] = j;
        }
        std::cout << "]\n";

        std::cout << "Generating array of 10k integers to test against... [ ";
        auto *qs_911_arr10k = new long int[10000];
        auto *qs_rand_arr10k = new long int[10000];
        auto *qs_median_pivot_arr10k = new long int[10000];
        auto *ss_98_arr10k = new long int[10000];
        auto *ss_b_arr10k = new long int[10000];
        auto *ss_c_arr10k = new long int[10000];
        auto *ss_d_arr10k = new long int[10000];
        auto *ss_e_arr10k = new long int[10000];
        for (long int i = 0, j = 0; i < 10000; i++) {
            j = random() % 500000;
            if (i < 5) std::cout << j << ", ";
            qs_911_arr10k[i] = j;
            qs_rand_arr10k[i] = j;
            qs_median_pivot_arr10k[i] = j;
            ss_98_arr10k[i] = j;
            ss_b_arr10k[i] = j;
            ss_c_arr10k[i] = j;
            ss_d_arr10k[i] = j;
            ss_e_arr10k[i] = j;
        }
        std::cout << "...]\n";

        std::cout << "Generating array of 50k integers to test against... [ ";
        auto *qs_911_arr50k = new long int[50000];
        auto *qs_rand_arr50k = new long int[50000];
        auto *qs_median_pivot_arr50k = new long int[50000];
        auto *ss_98_arr50k = new long int[50000];
        for (long int i = 0, j = 0; i < 50000; i++) {
            j = random() % 50000;
            if (i < 5) std::cout << j << ", ";
            qs_911_arr50k[i] = j;
            qs_rand_arr50k[i] = j;
            qs_median_pivot_arr50k[i] = j;
            ss_98_arr50k[i] = j;
        }
        std::cout << "...]\n";

        std::cout << "Generating array of 150k integers to test against... [ ";
        auto *qs_911_arr150k = new long int[150000];
        auto *qs_rand_arr150k = new long int[150000];
        auto *qs_median_pivot_arr150k = new long int[150000];
        auto *ss_98_arr150k = new long int[150000];
        for (long int i = 0, j = 0; i < 150000; i++) {
            j = random() % 500000;
            if (i < 5) std::cout << j << ", ";
            qs_911_arr150k[i] = j;
            qs_rand_arr150k[i] = j;
            qs_median_pivot_arr150k[i] = j;
            ss_98_arr150k[i] = j;
        }
        std::cout << "...]\n";

        std::cout << "Generating array of 200k integers to test against... [ ";
        auto *qs_911_arr200k = new long int[200000];
        auto *qs_rand_arr200k = new long int[200000];
        auto *qs_median_pivot_arr200k = new long int[200000];
        auto *ss_98_arr200k = new long int[200000];
        for (long int i = 0, j = 0; i < 200000; i++) {
            j = random() % 500000;
            if (i < 5) std::cout << j << ", ";
            qs_911_arr200k[i] = j;
            qs_rand_arr200k[i] = j;
            qs_median_pivot_arr200k[i] = j;
            ss_98_arr200k[i] = j;
        }
        std::cout << "...]\n";

        std::cout << std::endl;

        //fig 9.11 ---------------------------------------------------------------------------------------------------
        std::cout << "Sorting arrays with quicksort implementation from the textbook...\n";
        //20 item array
        const auto start_quicksort_9_11_20 = std::chrono::high_resolution_clock::now();
        quicksort9_11(qs_911_arr20, 20);
        const auto end_quicksort_9_11_20 = std::chrono::high_resolution_clock::now();
        std::cout << "\t• Sorted 20 item test array in "
                << std::chrono::duration_cast<std::chrono::microseconds>(
                    end_quicksort_9_11_20 - start_quicksort_9_11_20).
                count()
                << " microseconds, with result\n\t\t[ ";
        for (int i = 0; i < 20; i++) {
            std::cout << qs_911_arr20[i] << ", ";
        }
        std::cout << "]\n";
        //10k item array
        const auto start_quicksort_9_11_10k = std::chrono::high_resolution_clock::now();
        quicksort9_11(qs_911_arr10k, 10000);
        const auto end_quicksort_9_11_10k = std::chrono::high_resolution_clock::now();
        std::cout << "\t• Sorted 10k item array in "
                << std::chrono::duration_cast<std::chrono::microseconds>(
                    end_quicksort_9_11_10k - start_quicksort_9_11_10k).
                count()
                << " microseconds.\n";
        // 50k item array
        const auto start_quicksort_9_11_50k = std::chrono::high_resolution_clock::now();
        quicksort9_11(qs_911_arr50k, 50000);
        const auto end_quicksort_9_11_50k = std::chrono::high_resolution_clock::now();
        std::cout << "\t• Sorted 50k item array in "
                << std::chrono::duration_cast<std::chrono::microseconds>(
                    end_quicksort_9_11_50k - start_quicksort_9_11_50k).count()
                << " microseconds.\n";
        // 150k item array
        const auto start_quicksort_9_11_150k = std::chrono::high_resolution_clock::now();
        quicksort9_11(qs_911_arr150k, 150000);
        const auto end_quicksort_9_11_150k = std::chrono::high_resolution_clock::now();
        std::cout << "\t• Sorted 150k item array in "
                << std::chrono::duration_cast<std::chrono::microseconds>(
                    end_quicksort_9_11_150k - start_quicksort_9_11_150k).count()
                << " microseconds.\n";
        // 200k item array
        const auto start_quicksort_9_11_200k = std::chrono::high_resolution_clock::now();
        quicksort9_11(qs_911_arr200k, 200000);
        const auto end_quicksort_9_11_200k = std::chrono::high_resolution_clock::now();
        std::cout << "\t• Sorted 200k item array in "
                << std::chrono::duration_cast<std::chrono::microseconds>(
                    end_quicksort_9_11_200k - start_quicksort_9_11_200k).count()
                << " microseconds.\n";

        //quicksort modified to use a random pivot value -------------------------------------------------------------
        // 20 item array with quicksort_random_pivot
        std::cout << "\nSorting arrays with quicksort modified to use a random pivot\n";
        const auto start_quicksort_random_pivot_20 = std::chrono::high_resolution_clock::now();
        quicksort_random_pivot(qs_rand_arr20, 20);
        const auto end_quicksort_random_pivot_20 = std::chrono::high_resolution_clock::now();
        std::cout << "\t• Sorted 20 item test array in "
                << std::chrono::duration_cast<std::chrono::microseconds>(
                    end_quicksort_random_pivot_20 - start_quicksort_random_pivot_20).count()
                << " microseconds, with result\n\t\t[ ";
        for (int i = 0; i < 20; i++) {
            std::cout << qs_rand_arr20[i] << ", ";
        }
        std::cout << "]\n";
        // 10k item array with quicksort_random_pivot
        const auto start_quicksort_random_pivot_10k = std::chrono::high_resolution_clock::now();
        quicksort_random_pivot(qs_rand_arr10k, 10000);
        const auto end_quicksort_random_pivot_10k = std::chrono::high_resolution_clock::now();
        std::cout << "\t• Sorted 10k item array in "
                << std::chrono::duration_cast<std::chrono::microseconds>(
                    end_quicksort_random_pivot_10k - start_quicksort_random_pivot_10k).count()
                << " microseconds.\n";
        // 50k item array with quicksort_random_pivot
        const auto start_quicksort_random_pivot_50k = std::chrono::high_resolution_clock::now();
        quicksort_random_pivot(qs_rand_arr50k, 50000);
        const auto end_quicksort_random_pivot_50k = std::chrono::high_resolution_clock::now();
        std::cout << "\t• Sorted 50k item array in "
                << std::chrono::duration_cast<std::chrono::microseconds>(
                    end_quicksort_random_pivot_50k - start_quicksort_random_pivot_50k).count()
                << " microseconds.\n";
        // 150k item array with quicksort_random_pivot
        const auto start_quicksort_random_pivot_150k = std::chrono::high_resolution_clock::now();
        quicksort_random_pivot(qs_rand_arr150k, 150000);
        const auto end_quicksort_random_pivot_150k = std::chrono::high_resolution_clock::now();
        std::cout << "\t• Sorted 150k item array in "
                << std::chrono::duration_cast<std::chrono::microseconds>(
                    end_quicksort_random_pivot_150k - start_quicksort_random_pivot_150k).count()
                << " microseconds.\n";
        // 200k item array with quicksort_random_pivot
        const auto start_quicksort_random_pivot_200k = std::chrono::high_resolution_clock::now();
        quicksort_random_pivot(qs_rand_arr200k, 200000);
        const auto end_quicksort_random_pivot_200k = std::chrono::high_resolution_clock::now();
        std::cout << "\t• Sorted 200k item array in "
                << std::chrono::duration_cast<std::chrono::microseconds>(
                    end_quicksort_random_pivot_200k - start_quicksort_random_pivot_200k).count()
                << " microseconds.\n";

        //quicksort modified to use a median pivot value ---------------------------------------------------------------
        std::cout << "\nSorting arrays with quicksort modified to use a median pivot\n";
        // 20 item array with quicksort_median_pivot
        const auto start_quicksort_median_pivot_20 = std::chrono::high_resolution_clock::now();
        quicksort_median_pivot(qs_median_pivot_arr20, 20);
        const auto end_quicksort_median_pivot_20 = std::chrono::high_resolution_clock::now();
        std::cout << "\t• Sorted 20 item test array in "
                << std::chrono::duration_cast<std::chrono::microseconds>(
                    end_quicksort_median_pivot_20 - start_quicksort_median_pivot_20).count()
                << " microseconds, with result\n\t\t[ ";
        for (int i = 0; i < 20; i++) {
            std::cout << qs_median_pivot_arr20[i] << ", ";
        }
        std::cout << "]\n";
        // 10k item array with quicksort_median_pivot
        const auto start_quicksort_median_pivot_10k = std::chrono::high_resolution_clock::now();
        quicksort_median_pivot(qs_median_pivot_arr10k, 10000);
        const auto end_quicksort_median_pivot_10k = std::chrono::high_resolution_clock::now();
        std::cout << "\t• Sorted 10k item array in "
                << std::chrono::duration_cast<std::chrono::microseconds>(
                    end_quicksort_median_pivot_10k - start_quicksort_median_pivot_10k).count()
                << " microseconds.\n";
        // 50k item array with quicksort_median_pivot
        const auto start_quicksort_median_pivot_50k = std::chrono::high_resolution_clock::now();
        quicksort_median_pivot(qs_median_pivot_arr50k, 50000);
        const auto end_quicksort_median_pivot_50k = std::chrono::high_resolution_clock::now();
        std::cout << "\t• Sorted 50k item array in "
                << std::chrono::duration_cast<std::chrono::microseconds>(
                    end_quicksort_median_pivot_50k - start_quicksort_median_pivot_50k).count()
                << " microseconds.\n";
        // 150k item array with quicksort_median_pivot
        const auto start_quicksort_median_pivot_150k = std::chrono::high_resolution_clock::now();
        quicksort_median_pivot(qs_median_pivot_arr150k, 150000);
        const auto end_quicksort_median_pivot_150k = std::chrono::high_resolution_clock::now();
        std::cout << "\t• Sorted 150k item array in "
                << std::chrono::duration_cast<std::chrono::microseconds>(
                    end_quicksort_median_pivot_150k - start_quicksort_median_pivot_150k).count()
                << " microseconds.\n";
        // 200k item array with quicksort_median_pivot
        const auto start_quicksort_median_pivot_200k = std::chrono::high_resolution_clock::now();
        quicksort_median_pivot(qs_median_pivot_arr200k, 200000);
        const auto end_quicksort_median_pivot_200k = std::chrono::high_resolution_clock::now();
        std::cout << "\t• Sorted 200k item array in "
                << std::chrono::duration_cast<std::chrono::microseconds>(
                    end_quicksort_median_pivot_200k - start_quicksort_median_pivot_200k).count()
                << " microseconds.\n";

        //shellsort implementation from the textbook
        std::cout << "\nSorting arrays with the shellsort implementation from the textbook...\n";
        // 20 item array with Shellsort_9_8
        const auto start_shellsort_9_8_20 = std::chrono::high_resolution_clock::now();
        Shellsort_9_8(ss_98_arr20, 20);
        const auto end_shellsort_9_8_20 = std::chrono::high_resolution_clock::now();
        std::cout << "\t• Sorted 20 item test array in "
                << std::chrono::duration_cast<std::chrono::microseconds>(
                    end_shellsort_9_8_20 - start_shellsort_9_8_20).count()
                << " microseconds, with result\n\t\t[ ";
        for (int i = 0; i < 20; i++) {
            std::cout << ss_98_arr20[i] << ", ";
        }
        std::cout << "]\n";
        // 10k item array with Shellsort_9_8
        const auto start_shellsort_9_8_10k = std::chrono::high_resolution_clock::now();
        Shellsort_9_8(ss_98_arr10k, 10000);
        const auto end_shellsort_9_8_10k = std::chrono::high_resolution_clock::now();
        std::cout << "\t• Sorted 10k item array in "
                << std::chrono::duration_cast<std::chrono::microseconds>(
                    end_shellsort_9_8_10k - start_shellsort_9_8_10k).count()
                << " microseconds.\n";
        // 50k item array with Shellsort_9_8
        const auto start_shellsort_9_8_50k = std::chrono::high_resolution_clock::now();
        Shellsort_9_8(ss_98_arr50k, 50000);
        const auto end_shellsort_9_8_50k = std::chrono::high_resolution_clock::now();
        std::cout << "\t• Sorted 50k item array in "
                << std::chrono::duration_cast<std::chrono::microseconds>(
                    end_shellsort_9_8_50k - start_shellsort_9_8_50k).count()
                << " microseconds.\n";
        // 150k item array with Shellsort_9_8
        const auto start_shellsort_9_8_150k = std::chrono::high_resolution_clock::now();
        Shellsort_9_8(ss_98_arr150k, 150000);
        const auto end_shellsort_9_8_150k = std::chrono::high_resolution_clock::now();
        std::cout << "\t• Sorted 150k item array in "
                << std::chrono::duration_cast<std::chrono::microseconds>(
                    end_shellsort_9_8_150k - start_shellsort_9_8_150k).count()
                << " microseconds.\n";
        // 200k item array with Shellsort_9_8
        const auto start_shellsort_9_8_200k = std::chrono::high_resolution_clock::now();
        Shellsort_9_8(ss_98_arr200k, 200000);
        const auto end_shellsort_9_8_200k = std::chrono::high_resolution_clock::now();
        std::cout << "\t• Sorted 200k item array in "
                << std::chrono::duration_cast<std::chrono::microseconds>(
                    end_shellsort_9_8_200k - start_shellsort_9_8_200k).count()
                << " microseconds.\n";

        //pretty formatting
        std::cout << std::endl;
        for (int _dash = 0; _dash < 150; _dash++) {
            std::cout << '-';
        }
        std::cout << std::endl;
    }


    std::cout << "Done.\n";
}
