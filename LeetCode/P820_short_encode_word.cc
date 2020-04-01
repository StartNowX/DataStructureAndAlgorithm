/**
 * Given a list of words, we may encode it by writing a reference string S and a list of indexes A. For example, if the
list of words is ["time", "me", "bell"], we can write it as S = "time#bell#" and indexes = [0, 2, 5]. Then for each
index, we will recover the word by reading from the reference string from that index until we reach a "#" character.

What is the length of the shortest reference string S possible that encodes the given words?

    Input: words = ["time", "me", "bell"]
    Output: 10
    Explanation: S = "time#bell#" and indexes = [0, 2, 5].

*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class TrieNode {
   private:
    TrieNode* children[26];

   public:
    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = NULL;
        }
        count = 0;
    }
    TrieNode* get(char c) {
        if (children[c - 'a'] == NULL) {
            children[c - 'a'] = new TrieNode();
            // 当前节点count++，表明不是叶子结点了
            count++;
        }

        return children[c - 'a'];
    }

   public:
    // count可以理解为当前节点是否有子节点
    int count;
};

class Solution {
   public:
    // method1: 存储后缀
    int minimumLengthEncoding111(vector<string>& words) {
        if (0 == words.size()) {
            return 0;
        }

        unordered_set<string> good(words.begin(), words.end());
        for (auto& word : words) {
            // 遍历word的所有后缀，如果存在good中，就删除；由于good是所有单词的set，所以遍历时，只是word的后几位在set中，并不会删除掉
            for (int k = 1; k < word.size(); ++k) {
                good.erase(word.substr(k));
            }
        }

        int ans = 0;
        for (auto& w : good) {
            ans += (w.length() + 1);
        }

        return ans;
    }

    // method2: 字典树
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode* trie = new TrieNode();
        // 将TrieNode和给定的words中的单词对应起来，因为TrieNode中有标志位
        unordered_map<TrieNode*, int> nodes;

        // 遍历所有单词，每个单词以逆序的方式构造Trie
        for (int i = 0; i < (int)words.size(); ++i) {
            std::string word = words[i];
            TrieNode* cur = trie;
            // 对每个单词的每个字母以逆序的方式插入Trie中，每个单词一个TrieNode
            for (int j = word.length() - 1; j >= 0; j--) {
                cur = cur->get(word[j]);
            }
            nodes[cur] = i;
        }

        int ans = 0;
        for (auto& node : nodes) {
            // count为0的节点，表明该单词是编码的一部分，即没有和其他单词相同的后缀
            if (node.first->count == 0) {
                ans += (words[node.second].length() + 1);
            }
        }

        return ans;
    }
};

int main(int argc, char* argv[]) {
    vector<string> words{"time", "me", "ell", "bell", "e"};

    Solution sln;
    auto res = sln.minimumLengthEncoding(words);

    std::cout << "res = " << res << std::endl;


    return 0;
}