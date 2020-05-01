/**
 * 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
 *
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 */

  // 同LeetCode中Q21_merge_sorted_lists.cc

#include <iostream>

using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        }

        ListNode* merged_listnode = new ListNode(0);
        ListNode* p_head = merged_listnode;

        while (l1 != NULL && l2 != NULL) {
            if (l1->val >= l2->val) {
                // 不需要频繁的new的
                // ListNode* tmp = new ListNode(l2->val);
                // p_head->next = tmp;
                p_head->next = l2;
                l2 = l2->next;
            } else {
                p_head->next = l1;
                l1 = l1->next;
            }
            // 这里要更新p_head的
            p_head = p_head->next;
        }

        /*
        while (l1 != NULL) {
            p_head->next = l1;
            l1 = l1->next;

            p_head = p_head->next;
        }

        while (l2 != NULL) {
            p_head->next = l2;
            l2 = l2->next;

            p_head = p_head->next;
        }*/
        // 上面两个while loop可以用如下一个替换，因为l1和l2只可能有一个非空
        p_head->next = (l1) ? l1 : l2;

        return merged_listnode->next;
    }
};

int main(int argc, char* argv[]) { return 0; }