/**
 * 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
 *   输入：head = [1,3,2]
 *   输出：[2,3,1]

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


#include <iostream>
#include <vector>

#include "../utils/include/list.h"
#include "../utils/include/utils.h"

using namespace std;


class Solution {
   public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;

        if (head == NULL) {
            return res;
        }

        ListNode* p_node = head;
        while (p_node != NULL) {
            res.emplace_back(p_node->val);
            p_node = p_node->next;
        }

        vector<int> res_reverse;
        for (int i = static_cast<int>(res.size()) - 1; i >= 0; --i) {
            res_reverse.emplace_back(res[i]);
        }

        return res_reverse;
    }

    // 递归的方式
    vector<int> reversePrintRecursively(ListNode* head) {
        vector<int> res;

        RecursivePrint(head, res);

        return res;
    }

   private:
    void RecursivePrint(ListNode* head, vector<int>& eles) {
        if (head != NULL) {
            if (head->next != NULL) {
                RecursivePrint(head->next, eles);
                eles.emplace_back(head->val);
            } else {
                eles.emplace_back(head->val);
            }
        }
    }
};

int main(int argc, char* argv[]) {
    vector<int> eles{1, 3, 2};

    ListNode* p_node;

    List list_cls;
    p_node = list_cls.Create(eles);

    list_cls.PrintList(p_node);

    Solution sln;
    auto res = sln.reversePrintRecursively(p_node);

    Utils<int> util_int;
    util_int.PrintVector(res);

    return 0;
}