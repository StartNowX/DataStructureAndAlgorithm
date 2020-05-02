/**
 * Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words,
one of the first string's permutations is the substring of the second string.

 
Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Input:s1= "ab" s2 = "eidboaoo"
Output: False

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * 超过时间限制，
     * 思想是：遍历s2，若s2的当前节点在s1中，则以当前点为滑动窗的起始点，然后向右滑动窗口，
     * 注意：若没有找到，s2要重置，且重置代码要在while循环外
     */
    bool checkInclusionTimeout(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        vector<bool> s1_flag_used(len1, false);
        std::string s1_bak = s1;

        for (int i = 0; i < len2; ++i) {
            int rindex_s2 = i;
            int s1_use_cnt = 0;

            while (s1.find(s2[rindex_s2]) != std::string::npos && rindex_s2 < len2) {
                int tmp_index = s1.find(s2[rindex_s2]);
                if (!s1_flag_used[tmp_index]) {
                    rindex_s2++;
                    s1_flag_used[tmp_index] = true;
                    // 将当前点置为0，规避下次find时还用该节点
                    s1[tmp_index] = '0';
                    s1_use_cnt++;
                } else {
                    break;
                }

                if (s1_use_cnt == len1) {
                    return true;
                }
            }
            // 不能再while中break前重置，因为如果下个位置的字符没有找到的话，是进不去while中的
            vector<bool> tmp_false(len1, false);
            s1_flag_used.swap(tmp_false);
            s1 = s1_bak;
        }
        return false;
    }

    // 滑动窗+hashmap
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        // 构造所有待查找元素的map，s1中可能重复出现某个字符
        for (auto c : s1) mp[c]++;

        int l = 0, r = 0;
        // 每次以r作为当前位置，然后向右构造滑动窗
        while (r < s2.size()) {
            char c = s2[r++];
            // 当前字符使用过，便减一
            mp[c]--;

            // 构造滑动窗口，mp[c]<0,表示没有找到当前的字符
            // 没找到的话，则把s2的左边点继续向右滑动
            while (l < r && mp[c] < 0) {
                // 相当于没有找到的话，就把滑动窗左边的起始点右移，同时将该位置对应的字符出现的次数再加一，因为没有用到
                mp[s2[l++]]++;
            }
            if (r - l == s1.size()) return true;
        }

        return false;
    }
};

int main(int argc, char* argv[]) {
    Solution sln;
    std::string s1 = "ab";         //"adc";
    std::string s2 = "eidboaooo";  //"dcda";
    std::cout << "res = " << std::boolalpha << sln.checkInclusion(s1, s2) << std::endl;
    return 0;
}