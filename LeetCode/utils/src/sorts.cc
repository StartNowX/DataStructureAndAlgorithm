#include "utils/include/sorts.h"
#include <iostream>
#include <vector>

void Sorts::InsertSort(std::vector<int>& data) {
    if (0 == data.size()) {
        return;
    }

    int len = data.size();
    int i, j;

    for (i = 0; i < len; ++i) {
        // 为data[i]找一个插入点
        int tmp = data[i];

        // 判断条件，当data[j-1]大于data[i]时，相对于找到插入点了，将tmp插入到data[j]
        // 注意：这里时将tmp与data[i]之前的所有元素比较，但是data[i]之前的所有元素之间时不会再互相比较的，因为已经是有序的了
        for (j = i; (j > 0) && (data[j - 1] > tmp); --j) {
            data[j] = data[j - 1];
        }
        data[j] = tmp;

        // // 为什么不能写成这种形式?
        if (false) {
            // 如果将data[j-1]>tmp放到循环内判断，则需要一个变量记录j应该插入的位置
            // 假如tmp大于序列前面的所有数，则插入位置就是当前位置，而这种循环的方式，在执行data[j]=tmp时，j始终等于0
            int final_j = i;
            for (j = i; j > 0; --j) {
                if (data[j - 1] > tmp) {
                    data[j] = data[j - 1];
                    final_j = j - 1;
                }
            }
            data[final_j] = tmp;
        }
    }
}

void Sorts::BinaryInsertSort(std::vector<int>& data) {
    if (0 == data.size()) {
        return;
    }

    int len = data.size();
    int high, low, mid, j;

    // i从2开始
    for (int i = 0; i < len; ++i) {
        int tmp = data[i];
        high = i;
        low = 0;
        while (low < high) {
            mid = (low + high) / 2;
            if (tmp > data[mid]) {
                low = mid + 1;
            } else if (tmp <= data[mid]) {
                high = mid - 1;
            }
        }
        // high作为插入点，[high, i]之间的数据都需要后移
        for (j = i; j > high && data[j - 1] > tmp; --j) {
            data[j] = data[j - 1];
        }
        data[j] = tmp;
    }
}

void Sorts::ShellSort(std::vector<int>& data) {
    if (0 == data.size()) {
        return;
    }

    int len = data.size();
    int j;
    for (int gap = len / 2; gap > 0; gap /= 2) {
        // 对各个组进行插入的时候，不是先对一个组排序完再对另一个组排序，而是交叉进行，因此这里是i++
        for (int i = gap; i < len; ++i) {
            int tmp = data[i];
            for (j = i; j > 0 && data[j - gap] > tmp; j -= gap) {
                data[j] = data[j - gap];
            }
            data[j] = tmp;
        }
    }

    // int j;
    // for (int i = 0; i < len; ++i) {
    //     int tmp = data[i];
    //     for (j = i; j > 0 && data[j - 1] > tmp; --j) {
    //         data[j] = data[j - 1];
    //     }
    //     data[j] = tmp;
    // }

    return;
}

void Sorts::BubbleSort(std::vector<int>& data) {
    if (0 == data.size()) {
        return;
    }

    int len = data.size();
    for (int i = 0; i < len - 1; ++i) {
        // j是从头开始便利，因为对每一轮i，只是将相邻两个元素比较大小并互换了
        for (int j = 0; j < len - 1 - i; ++j) {
            if (data[j] > data[j + 1]) {
                SwapTwoNums(data[j], data[j + 1]);
            }
        }
    }

    return;
}

void Sorts::QuickSort(std::vector<int>& data) {
    if (0 == data.size()) {
        return;
    }

    Qsort(data, 0, data.size() - 1);
}

int Sorts::Partition(std::vector<int>& data, int low, int high) {
    if (0 == data.size()) {
        return 0;
    }

    int privo_key = data[low];

    while (low < high) {
        while (low < high && data[high] >= privo_key) --high;  // 从后向前找比privo_key小的值
        data[low] = data[high];

        while (low < high && data[low] <= privo_key) ++low;  // 从前向后找比provo_key大的值
        data[high] = data[low];
    }
    data[low] = privo_key;
    return low;
}

void Sorts::Qsort(std::vector<int>& data, int low, int high) {
    if (low < high) {
        int privot_loc = Partition(data, low, high);
        Qsort(data, 0, privot_loc - 1);
        Qsort(data, privot_loc + 1, high);
    }
}


void Sorts::MergeSort(std::vector<int>& data) {
    if (0 == data.size()) {
        return;
    }

    int len = data.size();
    MSort(data, 0, len - 1);

    return;
}


void Sorts::MSort(std::vector<int>& data, int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        MSort(data, low, mid);
        MSort(data, mid + 1, high);

        Merge(data, low, mid, high);
    }
}

void Sorts::Merge(std::vector<int>& data, int low, int mid, int high) {
    int i, j, k;
    int num_l = mid - low + 1;
    int num_r = high - mid;

    // 拆分成左右两个子模块
    std::vector<int> data_l;
    std::vector<int> data_r;
    for (i = 0; i < num_l; ++i) {
        data_l.emplace_back(data[low + i]);
    }

    for (j = 0; j < num_r; ++j) {
        data_r.emplace_back(data[mid + j + 1]);
    }

    // 比较左边数组
    i = j = 0;
    k = low;
    while (i < num_l && j < num_r) {
        if (data_l[i] <= data_r[j]) {
            data[k++] = data_l[i++];
        } else {
            data[k++] = data_r[j++];
        }
    }

    // 将剩余元素归并
    while (i < num_l) data[k++] = data_l[i++];
    while (j < num_r) data[k++] = data_r[j++];
}
