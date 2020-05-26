/**
 * 给定两个大小为 m 和 n 的正序（从小到大）数组 nums1
 和 nums2。请你找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m +
 n))。你可以假设 nums1 和 nums2 不会同时为空。

    hard
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total_len = nums1.size() + nums2.size();
        if (total_len % 2 == 1) {
            return GetKthEleInVector(nums1, nums2, (total_len + 1) / 2);
        } else {
            return (GetKthEleInVector(nums1, nums2, total_len / 2) +
                    GetKthEleInVector(nums1, nums2, total_len / 2 + 1)) /
                   2.0;
        }
    }

    double GetKthEleInVector(const vector<int>& nums1, const vector<int>& nums2, int k) {
        /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
         * 这里的 "/" 表示整除
         * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
         * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
         * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
         * 这样 pivot 本身最大也只能是第 k-1 小的元素
         * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的
         * nums1 数组 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部
         * "删除"，剩下的作为新的 nums2 数组 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k
         * 的值，减去删除的数的个数
         */
        nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;
        while (true) {
            // 边界
            if (index1 == m) {
                return nums2[index2 + k - 1];
            }

            if (index2 == n) {
                return nums1[index1 + k - 1];
            }

            if (k == 1) {
                return std::min(nums1[index1], nums2[index2]);
            }

            // 正常情况
            int new_index1 = std::min(index1 + k / 2 - 1, m - 1);
            int new_index2 = std::min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[new_index1];
            int pivot2 = nums2[new_index2];
            if (pivot1 <= pivot2) {
                k -= new_index1 - index1 + 1;
                index1 = new_index1 + 1;
            } else {
                k -= new_index2 - index2 + 1;
                index2 = new_index2 + 1;
            }
        }
    }

   public:
    /**
     * O(m+n)
     */
    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int merge_len = m + n;
        vector<int> merge_vec(merge_len, 0);
        int index = 0, num1_idx = 0, num2_idx = 0;
        while (num1_idx < m && num2_idx < n && index < merge_len) {
            if (nums1[num1_idx] < nums2[num2_idx]) {
                merge_vec[index++] = nums1[num1_idx];
                num1_idx++;
            } else {
                merge_vec[index++] = nums2[num2_idx];
                num2_idx++;
            }
        }

        while (num1_idx < m) {
            merge_vec[index++] = nums1[num1_idx++];
        }
        while (num2_idx < n) {
            merge_vec[index++] = nums2[num2_idx++];
        }

        double median = 0;
        if (merge_len % 2 == 0) {
            median = (double)(merge_vec[merge_len / 2] + merge_vec[(merge_len / 2) - 1]) / 2.0;
        } else {
            median = (double)(merge_vec[merge_len / 2]);
        }

        return median;
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums1{1, 2};
    vector<int> nums2{3, 4};

    Solution sln;
    auto res = sln.findMedianSortedArrays(nums1, nums2);
    std::cout << "res = " << res << std::endl;

    return 0;
}