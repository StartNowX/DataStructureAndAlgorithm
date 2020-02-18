/**
 * Given a non-empty array of digits representing a non-negative integer, plus one to the integer. 
 * The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit. 
 * You may assume the integer does not contain any leading zero, except the number 0 itself.
 * input = [1, 2, 3], output = [1, 2, 4]
 * input = [4, 3, 2, 1], output = [4, 3, 2, 2]
 * 
 * 主要是最后一位是否为0
*/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

// 转成数字的话，总会有整型溢出的问题
vector<int> PlusOne1(vector<int>& target_vec){
    
    long long ori_value = 0;

    int length = target_vec.size();
    for(int i = length; i > 0; i--){
        int tmp_index = length - i;
        ori_value += target_vec[tmp_index] * pow(10, i - 1);
    }
    // ori_value += 1;
    cout << "ori_value = " << ori_value << endl;

    vector<int> res_vec_inverse;
    while(0 != ori_value / 10) {
        res_vec_inverse.emplace_back(ori_value % 10);
        ori_value /= 10;
    }
    res_vec_inverse.emplace_back(ori_value);

    vector<int> res_vec;
    for (int i = res_vec_inverse.size(); i > 0; --i) {
        res_vec.emplace_back(res_vec_inverse[i - 1]);
    }
    
    return res_vec;
}

// LeetCode 黄凯剑的思路
vector<int> PlusOne2(vector<int>& digits){
    for (int i = digits.size() - 1; i >= 0; --i) {
        if( 9 != digits[i]){
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }

    // 全是9，跳出循环
    vector<int> res;
    res.emplace_back(1); // [9, 9] 变成[1, 0, 0] 
    for (vector<int>::iterator it = digits.begin(); it != digits.end(); ++it) {
        res.emplace_back(*it);
    }
};

// 分开讨论，LeetCode耗时较少的解法
vector<int> PlusOne3(vector<int>& digits) {
    // one single number which is 9
    if( 9 == digits[0] && 1 == digits.size()){
        digits[0] = 1;
        digits.emplace_back(0);
        return digits;
    }

    int len = digits.size();
    // 最后一个数不是9
    if(digits[len - 1] != 9) {
        digits[len - 1]++;
        return digits;
    }
    
    digits[len - 1] = 0;
    for(int i = len - 2; i >= 0; i--) {
        if(9 == digits[i]) {
            if(0 == i) {
                digits[i] = 1;
                digits.emplace_back(0);
            } else {
                digits[i] = 0;
            }
        } else {
            digits[i]++;
            return digits;
        }
    }
    return digits;
}



int main(int argc, char* argv[]) {
    // vector<int> target_vec{9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; //{4, 3, 2, 1};// {1, 2, 3};
    vector<int> target_vec{6, 1, 4, 5, 3, 9, 0, 1, 9, 5, 1, 8, 6, 7, 0, 5, 5, 4, 3};
    // vector<int> target_vec{0};

    int length = target_vec.size();

    vector<int> res;
    res = PlusOne3(target_vec);

    cout << "result: length = " << length << ", elements: ";
    for (vector<int>::iterator it = res.begin(); it != res.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}