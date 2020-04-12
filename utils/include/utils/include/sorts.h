#ifndef SORT_H_
#define SORT_H_

#include <vector>

class Sorts {
   public:
    /**
     * 选择排序，
     * 稳定排序，时间复杂度O(n^2)，数据量少的时候再用，不用额外的空间
     */
    void SelectSort(std::vector<int>& data);

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

    /**
     * 稳定排序，
     * 时间复杂度：最好O(n), 最坏O(n^2)
     */
    void BubbleSort(std::vector<int>& data);

    /**
     * 快速排序，和冒泡排序一样，都是通过交换元素实现的
     * 不稳定排序（中轴和元素交换时，可能会导致元素的顺序发生变化）
     * 时间复杂度：O(nlogn)，最慢O(n^2), 最快O(n)
     */
    void QuickSort(std::vector<int>& data);


    /**
     * 归并排序，
     * 稳定排序, 时间复杂度：O(nlogn)，但一般很少用其进行内部排序（因为需要额外空间？）
     */
    void MergeSort(std::vector<int>& data);

    /**
     * 堆排序
     * 不稳定排序，时间复杂度最坏为O(nlogn)
     *
     * 关于堆的介绍：https://mp.weixin.qq.com/s/7GeO8jjg1QUG_ofJznOsCQ
     */
    void HeapSort(std::vector<int>& data);

    /**
     * 基数排序
     * 稳定排序，时间复杂度最坏为O(n*k)，最好O(n*k)，空间复杂度O(n+k)
     * 用于整数排序，桶的个数为10，用于字符串排序，桶的个数为26
     */
    void RadixSort(std::vector<int>& data);

   private:
    inline void SwapTwoNums(int& a, int& b) {
        int tmp = b;
        b = a;
        a = tmp;
    }

    // 快排相关
    int Partition(std::vector<int>& data, int low, int high);
    void Qsort(std::vector<int>& data, int low, int high);

    // 归并排序相关
    void MSort(std::vector<int>& data, int low, int high);
    void Merge(std::vector<int>& data, int low, int mid, int high);

    // 堆排序相关
    void HeapMaxModify(std::vector<int>& data, int start, int end);

    // 基数排序相关
    int MaxBits(std::vector<int>& data);
};

#endif
