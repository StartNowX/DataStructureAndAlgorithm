#include "utils/include/string_match.h"

#include <iostream>

bool StringMatch::KMP(const std::string& match_str, const std::string& candidate_str) {
    next_table_.clear();
    // 生成next table
    MakeNext(candidate_str);

    int m_size = match_str.length();
    int sub_size = candidate_str.length();

    for (int i = 0, sub_i = 0; i < m_size; ++i) {
        // 关键部分
        while(sub_i > 0 && match_str[i] != candidate_str[sub_i]){
            sub_i = next_table_[sub_i - 1];
        }

        if(match_str[i] == candidate_str[sub_i]){
            sub_i++;
        }

        if(sub_i == sub_size){
            return true;
        }
    }
    return false;
}

void StringMatch::MakeNext(const std::string& candidate_str) {
    int len = candidate_str.length();
    std::vector<int> next(len, 0);

    int k = 0;
    for (int i = 1; i < len; ++i) {
        // 当k大于0时,说明前面的字符是有k个共有元素的,因此从共有部分开始匹配,
        // str[i-k]...str[i-1]与str[0]...str[k-1]是相同的,而现在str[i]candidate_str[k]不同,
        // 则不需要比对str[0]...str[k-1]这么长的串了
        while (k > 0 && candidate_str[i] != candidate_str[k]) {
            k = next[k - 1];
        }

        // 相等,则表示可以匹配的共有元素又多一个
        if (candidate_str[i] == next[k]) {
            k++;
        }

        // 更新当前字符的next table
        next[i] = k;
    }

    next_table_.swap(next);
}