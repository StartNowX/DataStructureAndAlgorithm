/**
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse
order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

(5) (5) -> (0, 1)

  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 */

#include <iostream>
#include <vector>

#include "utils/include/list.h"

using namespace std;

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode vHead(0), *p = &vHead;

        int flag = 0;
        while (l1 || l2 || flag) {
            int tmp = 0;
            if (l1 != nullptr) tmp += l1->val;
            if (l2 != nullptr) tmp += l2->val;
            tmp += flag;

            flag = tmp / 10;
            tmp %= 10;

            // 当两个链表长度不一致的时候
            ListNode* next = l1 ? l1 : l2;
            if (nullptr == next) {
                next = new ListNode(tmp);
            }
            next->val = tmp;

            p->next = next;
            p = next;

            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        return vHead.next;
    }
    // 需要考量两个数的长度
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, const List& list) {
        // 反转list
        ListNode* revert_l1;
        ListNode* revert_l2;
        // revert_l1 = revertLinkedList(l1);
        // revert_l2 = revertLinkedList(l2);
        revert_l1 = l1;
        revert_l2 = l2;

        int sum = 0;
        int remain = 0;
        ListNode* res = new ListNode(0);
        ListNode* res_tmp = res;

        while (revert_l1 != NULL && revert_l2 != NULL) {
            sum = revert_l1->val + revert_l2->val + remain;
            ListNode* tmp = new ListNode(sum % 10);
            remain = sum / 10;

            res_tmp->next = tmp;
            res_tmp = tmp;

            revert_l1 = revert_l1->next;
            revert_l2 = revert_l2->next;
        }

        while (revert_l1 != NULL) {
            sum = revert_l1->val + remain;
            ListNode* tmp = new ListNode(sum % 10);
            remain = sum / 10;

            res_tmp->next = tmp;
            res_tmp = tmp;

            revert_l1 = revert_l1->next;
        }
        while (revert_l2 != NULL) {
            sum = revert_l2->val + remain;
            ListNode* tmp = new ListNode(sum % 10);
            remain = sum / 10;

            res_tmp->next = tmp;
            res_tmp = tmp;

            revert_l2 = revert_l2->next;
        }

        if (0 != remain) {
            ListNode* tmp = new ListNode(remain);

            res_tmp->next = tmp;
            res_tmp = tmp;
        }

        return res->next;
    }

    ListNode* revertLinkedList(ListNode* list) {
        ListNode* tmp = list;
        vector<int> tmp_value;

        int index = 0;
        while (tmp != NULL) {
            tmp_value.push_back(tmp->val);
            tmp = tmp->next;
            // std::cout << "tmp_val: " << tmp_value[index++] << " ";
        }
        std::cout << std::endl;

        ListNode* revert_list = new ListNode(tmp_value[tmp_value.size() - 1]);
        ListNode* rever_tmp = revert_list;
        for (int i = tmp_value.size() - 2; i >= 0; --i) {
            ListNode* L = new ListNode(tmp_value[i]);

            rever_tmp->next = L;
            rever_tmp = L;
        }
        return revert_list;
    }
};

int main(int argc, char* argv[]) {
    // (2 -> 4 -> 3) + (5 -> 6 -> 4) {1} {9, 9}
    std::vector<int> list_vec1{0};     //{2, 4, 3};
    std::vector<int> list_vec2{7, 3};  //{5, 6, 4};

    List list;
    ListNode* L1;
    ListNode* L2;
    L1 = list.Create(list_vec1);
    L2 = list.Create(list_vec2);

    // list.PrintList(L1);
    // list.PrintList(L2);

    Solution sln;
    auto res = sln.addTwoNumbers(L1, L2, list);

    list.PrintList(res);
    return 0;
}