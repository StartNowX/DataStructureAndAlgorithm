#include <iostream>
#include <vector>

#include "utils/include/sorts.h"
#include "utils/include/utils.h"
#include "utils/include/time_log.h"

using namespace std;

template <typename T>
void SortExample(Utils<T>& util_int, Sorts& sort, std::vector<int>& input) {
    util_int.PrintVector(input);
    if (false) {
        TimeLog log("SelectSort");
        sort.SelectSort(input);
    }


    if (false) {
        TimeLog log("InsertSort");
        sort.InsertSort(input);
    }

    if (false) {
        TimeLog log("BinaryInsertSort");
        sort.BinaryInsertSort(input);
    }

    if (false) {
        TimeLog log("ShellSort");
        sort.ShellSort(input);
    }

    if (false) {
        TimeLog log("BubbleSort");
        sort.BubbleSort(input);
    }

    if (false) {
        TimeLog log("QuickSort");
        sort.QuickSort(input);
    }

    if (false) {
        TimeLog log("MergeSort");
        sort.MergeSort(input);
    }

    if (true) {
        TimeLog log("HeapSort");
        sort.MergeSort(input);
    }
    util_int.PrintVector(input);
}

int main(int argc, const char** argv) {
    vector<int> input{8, 93, 22, 3, 11, 2, 9, 0, 25, 24, 10, 3, 5};  // 32, 1, 4};

    Utils<int> util_int;
    Sorts sort;
    SortExample(util_int, sort, input);

    return 0;
}