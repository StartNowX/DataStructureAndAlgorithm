/**
 * 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

返回删除后的链表的头节点。
*/

#include <iostream>


//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    // O(n)
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val) {
            return head->next;
        }

        ListNode* pre = head;
        ListNode* cur = head->next;

        while (cur != NULL && cur->val != val) {
            pre = cur;
            cur = cur->next;
        }

        pre->next = cur->next;

        return head;
    }

    // O(1)
    ListNode* deleteNodeEfficient(ListNode* head, int val) {}
};

int main(int argc, char* argv[]) { return 0; }