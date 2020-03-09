#ifndef SORT_H_
#define SORT_H_

#include <vector>

class Sorts {
   public:
    /**
     * 稳定排序，
     * 时间复杂度：最好O(n), 最坏O(n^2)
     */
    void BubbleSort(std::vector<int>& data);

    /**
     * 稳定排序
     * 时间复杂度：正序时，最好O(n)，逆序时，最坏O(n^2)
     * */
    void InsertSort(std::vector<int>& data);

    /**
     * 折半插入排序，稳定排序
     * 只是用折半查找去找到每次的插入点，时间复杂度O(n^2)
     */
    void BinaryInsertSort(std::vector<int>& data);

    /**
     * 不稳定排序
     * 希尔排序的时间复杂度较为复杂，有的增量序列的时间复杂度至今未分析出来
     * 应用场景：1. 待排序序列按关键字“基本有序”； 2. 直接插入算法简单，当增量很小时，效率也高
     */
    void ShellSort(std::vector<int>& data);

   private:
    inline void SwapTwoNums(int& a, int& b) {
        int tmp = b;
        b = a;
        a = tmp;
    }
};

#endif
