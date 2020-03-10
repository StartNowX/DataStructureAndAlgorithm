#include <iostream>
#include <vector>

#include "utils/include/sorts.h"
#include "utils/include/utils.h"

using namespace std;

int main(int argc, const char** argv) {
    vector<int> input{8, 3, 2, 9, 0, 10, 3, 5};

    Utils<int> util_int;
    Sorts sort;

    if (false) {
        std::cout << "Insert Sort..." << std::endl;
        util_int.PrintVector(input);
        sort.InsertSort(input);
        util_int.PrintVector(input);
    }

    if (false) {
        std::cout << "Binary insert Sort..." << std::endl;
        util_int.PrintVector(input);
        sort.BinaryInsertSort(input);
        util_int.PrintVector(input);
    }

    if (false) {
        std::cout << "Shell Sort..." << std::endl;
        util_int.PrintVector(input);
        sort.ShellSort(input);
        util_int.PrintVector(input);
    }

    if (false) {
        std::cout << "Bubble Sort..." << std::endl;
        util_int.PrintVector(input);
        sort.BubbleSort(input);
        util_int.PrintVector(input);
    }

    if (false) {
        std::cout << "Quick Sort..." << std::endl;
        util_int.PrintVector(input);
        sort.QuickSort(input);
        util_int.PrintVector(input);
    }

    if (true) {
        std::cout << "Merge Sort..." << std::endl;
        util_int.PrintVector(input);
        sort.MergeSort(input);
        util_int.PrintVector(input);
    }


    return 0;
}