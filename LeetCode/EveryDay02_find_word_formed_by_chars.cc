/**
 * You are given an array of strings words and a string chars.
 * A string is good if it can be formed by characters from chars (each character can only be used once).
 * Return the sum of lengths of all good strings in words.

    Input: words = ["cat","bt","hat","tree"], chars = "atach"
    Output: 6
    Explanation:
    The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.

 */

#include <iostream>
#include <string>

#include "utils/include/time_log.h"
#include "utils/include/utils.h"
using namespace std;

class Solution {
   public:
    int countCharacters(vector<string>& words, string chars) {
        int res = 0;
        bool flag = 0;
        for (auto& word : words) {
            flag = true;
            string tmp = chars;
            for (auto& c : word) {
                if (tmp.npos == tmp.find(c)) {
                    flag = false;
                    break;
                }
                // 每一个字符只能用一次
                tmp.replace(tmp.find(c), 1, "#");
            }


            if (flag) {
                res += word.length();
            }
        }

        return res;
    }
};

void Test() {
    std::string str = "abcdac";
    std::string b = "a";
    std::cout << "str.find('a') = " << str.find("a") << ", find b: " << str.find("c");
}

int main(int argc, char* argv[]) {
    // ["hello","world","leetcode"], chars = "welldonehoneyr"
    // {"cat", "bt", "hat", "tree"}  "atach"
    // "dyiclysmffuhibgfvapygkorkqllqlvokosagyelotobicwcmebnpznjbirzrzsrtzjxhsfpiwyfhzyonmuabtlwin","ndqeyhhcquplmznwslewjzuyfgklssvkqxmqjpwhrshycmvrb","ulrrbpspyudncdlbkxkrqpivfftrggemkpyjl","boygirdlggnh","xmqohbyqwagkjzpyawsydmdaattthmuvjbzwpyopyafphx","nulvimegcsiwvhwuiyednoxpugfeimnnyeoczuzxgxbqjvegcxeqnjbwnbvowastqhojepisusvsidhqmszbrnynkyop","hiefuovybkpgzygprmndrkyspoiyapdwkxebgsmodhzpx","juldqdzeskpffaoqcyyxiqqowsalqumddcufhouhrskozhlmobiwzxnhdkidr","lnnvsdcrvzfmrvurucrzlfyigcycffpiuoo","oxgaskztzroxuntiwlfyufddl","tfspedteabxatkaypitjfkhkkigdwdkctqbczcugripkgcyfezpuklfqfcsccboarbfbjfrkxp","qnagrpfzlyrouolqquytwnwnsqnmuzphne","eeilfdaookieawrrbvtnqfzcricvhpiv","sisvsjzyrbdsjcwwygdnxcjhzhsxhpceqz","yhouqhjevqxtecomahbwoptzlkyvjexhzcbccusbjjdgcfzlkoqwiwue","hwxxighzvceaplsycajkhynkhzkwkouszwaiuzqcleyflqrxgjsvlegvupzqijbornbfwpefhxekgpuvgiyeudhncv","cpwcjwgbcquirnsazumgjjcltitmeyfaudbnbqhflvecjsupjmgwfbjo","teyygdmmyadppuopvqdodaczob","qaeowuwqsqffvibrtxnjnzvzuuonrkwpysyxvkijemmpdmtnqxwekbpfzs","qqxpxpmemkldghbmbyxpkwgkaykaerhmwwjonrhcsubchs"
    // "usdruypficfbpfbivlrhutcgvyjenlxzeovdyjtgvvfdjzcmikjraspdfp"
    std::string chars = "usdruypficfbpfbivlrhutcgvyjenlxzeovdyjtgvvfdjzcmikjraspdfp";
    std::vector<string> worlds{
        "dyiclysmffuhibgfvapygkorkqllqlvokosagyelotobicwcmebnpznjbirzrzsrtzjxhsfpiwyfhzyonmuabtlwin",
        "ndqeyhhcquplmznwslewjzuyfgklssvkqxmqjpwhrshycmvrb",
        "ulrrbpspyudncdlbkxkrqpivfftrggemkpyjl",
        "boygirdlggnh",
        "xmqohbyqwagkjzpyawsydmdaattthmuvjbzwpyopyafphx",
        "nulvimegcsiwvhwuiyednoxpugfeimnnyeoczuzxgxbqjvegcxeqnjbwnbvowastqhojepisusvsidhqmszbrnynkyop",
        "hiefuovybkpgzygprmndrkyspoiyapdwkxebgsmodhzpx",
        "juldqdzeskpffaoqcyyxiqqowsalqumddcufhouhrskozhlmobiwzxnhdkidr",
        "lnnvsdcrvzfmrvurucrzlfyigcycffpiuoo",
        "oxgaskztzroxuntiwlfyufddl",
        "tfspedteabxatkaypitjfkhkkigdwdkctqbczcugripkgcyfezpuklfqfcsccboarbfbjfrkxp",
        "qnagrpfzlyrouolqquytwnwnsqnmuzphne",
        "eeilfdaookieawrrbvtnqfzcricvhpiv",
        "sisvsjzyrbdsjcwwygdnxcjhzhsxhpceqz",
        "yhouqhjevqxtecomahbwoptzlkyvjexhzcbccusbjjdgcfzlkoqwiwue",
        "hwxxighzvceaplsycajkhynkhzkwkouszwaiuzqcleyflqrxgjsvlegvupzqijbornbfwpefhxekgpuvgiyeudhncv",
        "cpwcjwgbcquirnsazumgjjcltitmeyfaudbnbqhflvecjsupjmgwfbjo",
        "teyygdmmyadppuopvqdodaczob",
        "qaeowuwqsqffvibrtxnjnzvzuuonrkwpysyxvkijemmpdmtnqxwekbpfzs",
        "qqxpxpmemkldghbmbyxpkwgkaykaerhmwwjonrhcsubchs"
        "usdruypficfbpfbivlrhutcgvyjenlxzeovdyjtgvvfdjzcmikjraspdfp"};

    Solution sln;
    int res;

    {
        TimeLog scope("countCharacters");
        res = sln.countCharacters(worlds, chars);
    }
    std::cout << "res = " << res << std::endl;

    { Test(); }

    return 0;
}