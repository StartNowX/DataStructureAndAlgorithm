# DataStructureAndAlgorithm


## LeetCode问题跟踪
`困难`难度的题目，暂未做


## 1. DP问题
该分类直接按照[知乎DP问题分类](https://zhuanlan.zhihu.com/p/126546914)的顺序，在对应的题目下列入个人认为的关键点

#### 线性DP
1. 单串，[300-最长升序子序列LIS](./LeetCode/P300_longest_increasing_subseq.cc)
    * 注意，这里只要求是升序的子序列，而不是连续的，即`[2,5,3]`这样的增序子序列是`[2,3]`
    * 数组dp，其中dp[i]表示当前节点对应的最长升序子序列的长度。因此，最终整个序列的最长升序子序列长度是**dp数组中的最大值**
    * dp通项为\\( dp[i] = max(dp[i], dp[j] + 1), i > j 且 num[i] > nums[j] \\)

2. 双串，[1143-最长公共子串](./LeetCode/P1143_longest_common_subsequence.cc)
    * tips：用一个二维数组表示两个字符串对应的子串的公共子串的长度的查找表table
    * 边界条件
        * 二维数组的行和列分别比输入的两个字符串长度各增加1，用于处理空串，即table左上角肯定为0，表示输入为空字符串的时候的公共子序列的长度
        * 鉴于上一条，起始搜索下标都是从1开始，比较时用的是i-1和j-1
3. [120-三角形的最短路径和](./LeetCode/P120_min_path_triangle.cc)
    * tip: 三角形的每行的行号即该行的列数，那么用dp数组表示到当前行的对应元素的最小路径，因此只需要一个一维数组即可，整个三角形的最短路径，即最后一行dp的所有元素的最小值
    * 假设dp为二维数组，dp[i][j]的元素只来源于dp[i-1][j]和dp[i-1][j-1]两方面（不考虑边缘条件），这样可以将空间优化为n，用两个变量cur和pre分别存储dp[i-1][j]和dp[i-1][j-1]，并不断更新两个
    * 边界条件：每列最左的元素，只来源dp[i-1][0]（即cur），每列最右边的元素，只来源于dp[i-1][col-1]（即pre）
    * cur每次都等于dp[c](c为列数)，即上一行的个数，然后更新当前行的dp[c]，下一行使用时，cur又变成当前行的dp[c]
4. [53-最大子序列和](./LeetCode/P53_max_sub_array.cc)
    * 利用dp算法很容易，空间复杂度O(n)
    * 用`联机算法`能够实现O(1)的空间负责度
5. [152-乘积最大子数组](./LeetCode/P152_max_product_subarray.cc)
    * 这里是乘积，和上一题的区别是，这里当出现负数时，前面的最大值将变成最小值，最小值将变成最大值。
6. 887，`鸡蛋掉落`（困难，暂未做）
7. 354，`俄罗斯套娃`（困难，暂未做）
8. 打家劫舍系列
    * 198，[98-打家劫舍1](./LeetCode/P198_robber_house.cc)，主要注意不能相邻，所以dp通项为`dp[i] = max(dp[i-2] + num[i], dp[i-1])`
    * 213，[213-打家劫舍2](./LeetCode/P213_robber_house2.cc)，在1的基础上增加了最后一户和倒数第一户是相邻的，可以分解为不考虑第一户的打家劫舍1和不考虑最后一户的打家劫舍1，最后求两者之间的最大值
    * 面试题46，[46-将数字转为字符串](./LeetCode/PE46_translation_num_to_string.cc)
9. 股票系列
    * 120，[121-买卖股票的最佳时机](./LeetCode/P121_best_to_operator_stock.cc)
    * 121，[122-买卖股票的最佳时机](./LeetCode/P122_best_to_operator_stock2.cc)
        * 该题用贪心算法似乎更容易
    * 123，`困难，暂未做`
    * 188，`困难，暂未做`
10. 字符串匹配系列
    * 72，`困难，暂未做`
    * 44，`困难，暂未做`
    * 10，`困难，暂未做`


#### 区间DP
1. 516，[516-最长回文子序列](./LeetCode/P516_longest_palindromic_subseq.cc)
    * 注意和题目5区分，这里是子序列，不是子串
2. 1039，[1039-多边形的最小三角形剖分值](./LeetCode/P1039_min_score_polygon.cc)
    * 对比96题的卡特兰数
3. `困难，暂未做`
    * 730
    * 664
    * 312

#### 背包DP
1. 416，[416-分割等和子集](./LeetCode/P416_partition_equal_subset_sum.cc)
    * 将问题转换为01背包问题
2. 494，[494-目标和](./LeetCode/P494_target_sum.cc)
    * 递归方法
    * 01背包问题，动态规划，同时还可以动态规划时进行状态空间压缩
2. 322，[322-零钱兑换](./LeetCode/P322_coin_change.cc)
    * 完全背包，注意DP数组表示组成金额i所需要的最小硬币数
3. 518，[518-零钱兑换2](./LeetCode/P518_coin_change.cc)
    * 完全背包，求方案数


#### 树形DP
1. `困难，暂未做`
    * 124，
2. 543，[543-Diameter of Binary Tree](./LeetCode/P543_diameter_of_bt.cc)
    * 递归调用
3. 377，[377-House robber3](./LeetCode/P377_robber_house3.cc)
    * 树形DP的参考


#### 计数型DP
1. [62-不同路径](./LeetCode/P62_unique_paths.cc)
    * 可以将空间复杂度优化到O(n)
2. [63-不同路径2](./LeetCode/P63_unique_path_2.cc)
    * 多了一个障碍物信息
3. [96-不同的二叉搜索树](./LeetCode/P96_different_binary_search_tree.cc)
    * 卡特兰数
4. [279-最少完美平方数](./LeetCode/P279_perfect_squares.cc)

#### 其他
1. [837-新21点游戏](./LeetCode/P837_new21games.cc)


## 滑动窗系列
1. 3，[3-最长无重复子串](./LeetCode/P3_longest_substr_without_repeating.cc)
2. 209, [209-长度最小的子数组](./LeetCode/P209_min_seq_sum_len.cc)
    * 注意和第3题中在计算滑动窗长度时的区别
    * [python版本](./LeetCode/P209_min_seq_sum_len.py)
        * 用了List, `from typing import List`
3. 567, [567-字符串的排列](./LeetCode/P567_permutation_in_string.cc)
    * [python版本](./LeetCode/P567_permutation_in_string.py)
        * 用了defaultdict, `from collections import defaultdict`
4. `困难系列`
    * 30， 串联所有单词的子串
    * 76，最小覆盖子串
    * 159， 至多包含两个不同字符的最长子串
    * 239，滑动窗口最大值
    * 632， 最小区间
    * 727，最小窗口子序列

## 贪心算法
1. 55, [55-跳跃游戏](./LeetCode/P55_jump_game.cc)
    * [python版本](./LeetCode/P55_jump_game.py)
2. 45, [45-跳跃游戏2](./LeetCode/P45_jump_game2.cc)
    * [python版本](./LeetCode/P45_jump_game2.py)
    * 注意，用dp的话会超时

## 前缀和
1. 560，[560-子数组和等于k的个数](./LeetCode/P560_subarray_sum_equals_k.cc)，[python版本](./LeetCode/P560_subarray_sum_equals_k.py)
2. 974，[974-和能被K整除的子数组个数](./LeetCode/P974_subarray_sums_divisible_by_K.cc)

## DFS
1. 100, [100-相同二叉树](./LeetCode/P100_same_tree.cc)
2. 100, [101-对称二叉树](./LeetCode/P101_symmetric_tree.cc)
3. 108, [108-将排序数组转为二叉搜索树](./LeetCode/P108_convert_sorted_array_bst.cc)
4. 110, [110-平衡二叉树](./LeetCode/P110_balanced_binary_tree.cc)
5. 111, [111-二叉树最小高度](./LeetCode/P111_minimum_depth_binary_tree.cc)
6. 112, [112-路径和](./LeetCode/P112_path_sum.cc)

## 其他
1. 9，[9-回文数字](./LeetCode/P9_palindrome_number.cc)

## 每日一题
#### May
1. 2020-05-01: [21-合并两个有序的链表](./LeetCode/P21_merge_two_sorted_lists.cc)，[python版本](./LeetCode/P21_merge_two_sorted_list.py)
2. 2020-05-02: [3-最长无重复子串](./LeetCode/P3_longest_substr_without_repeating.cc)，[python版本](./LeetCode/P3_longest_substr_without_repeating.py)
3. 2020-05-03: [53-最大子序列和]((./LeetCode/P53_max_sub_array.cc))， [python版本]((./LeetCode/P53_max_sub_array.py)
4. 2020-05-04: [45-跳跃游戏2](./LeetCode/P45_jump_game2.cc)，[python版本](./LeetCode/P45_jump_game2.py)
5. 2020-05-05: [98-验证二叉搜索树](./LeetCode/P98_validate_bst.cc)，[python版本](./LeetCode/P98_validate_bst.py)
6. 2020-05-06: [983-最低票价](./LeetCode/P983_min_cost_for_tickets.cc)，[python版本](./LeetCode/P983_min_cost_for_tickets.py)
7. 2020-05-07: [572-另一个树的子树](./LeetCode/P572_Subtree_of_another_tree.cc)，[python版本](./LeetCode/P572_Subtree_of_another_tree.py)
8. 2020-05-08: [221-最大方形](./LeetCode/P221_maximal_square.cc)，[python版本](./LeetCode/P221_maximal_square.py)
9. 2020-05-09: [9-求平方根](./LeetCode/P69_sqrt.cc)
10. 2020-05-10: [263-最近公共祖先](./LeetCode/P236_lowest_common_ancestor_of_a_binary_tree.cc)，[python版本](./LeetCode/P236_lowest_common_ancestor_of_a_binary_tree.py)
11. 2020-05-11: [50-求幂](./LeetCode/P50_power.cc)，[python版本](./LeetCode/P50_power.py)
12. 2020-05-15: [560-子数组和等于k的个数](./LeetCode/P560_subarray_sum_equals_k.cc)，[python版本](./LeetCode/P560_subarray_sum_equals_k.py)
13. 2020-05-16: [25-按k组翻转链表](./LeetCode/P25_reverse_nodes_in_k-group.cc)
14. 2020-05-17: [210-课程表2](./LeetCode/P210_course_schedule2.cc)，[python版本](./LeetCode/P210_course_schedule2.py)
15. 2020-05-18: [152-最大子数组乘积](./LeetCode/P152_max_product_subarray.cc)，[python版本](./LeetCode/P152_max_product_subarray.py)
16. 2020-05-19: [152-最大子数组乘积](./LeetCode/P680_valid_palindrome2.cc)
17. 2020-05-22: [150-用前序遍历和后续遍历构造二叉树](./LeetCode/P105_construct_btree_with_preorder_inorder.cc)
19. 2020-05-24: [4-找排序数组中的中位数](./LeetCode/P4_find_median_in_sorted_array.cc)
19. 2020-05-26: [287-找重复数](./LeetCode/P287_find_duplicate_num.cc)
20. 2020-05-27: [974-和能被K整除的子数组个数](./LeetCode/P974_subarray_sums_divisible_by_K.cc)
    * 和560思想一样
21. 2020-05-28: [394-字符串解码](./LeetCode/P394_decode_string.cc)
22. 2020-05-29: [198-打家劫舍](./LeetCode/P198_robber_house.cc)
23. 2020-05-31: [101-对称二叉树](./LeetCode/P101_symmetric_tree.cc)

#### June
1. 2020-06-01: [1431-孩子可以分到的最大糖果数](./LeetCode/P1431_kids_with_the_greatest_number_of_candies.cc)
2. 2020-06-02: [64-不用乘除和控制语句实现加和](./LeetCode/PE64_sum_without_multi_division.cc)
3. 2020-06-03: [837-新21点游戏](./LeetCode/P837_new21games.cc)
4. 2020-06-04: [238-数组除自身元素外的乘积](./LeetCode/P238_product_of_array_except_self.cc)
5. 2020-06-05: [29-顺时针打印矩阵](./LeetCode/PE29_spiral_matrix.cc)
6. 2020-06-07: [128-最长连续序列](./LeetCode/P128_longest_consecutive_seq.cc)
7. 2020-06-09: [46-将数字转为字符串](./LeetCode/PE46_translation_num_to_string.cc)
8. 2020-06-10: [9-回文数](./LeetCode/P9_palindrome_number.cc)
9. 2020-06-11: [11-每日温度](./LeetCode/P739_daily_temperatures.cc)