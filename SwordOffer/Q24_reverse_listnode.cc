/**
 * 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
 *
 * 输入: 1->2->3->4->5->NULL
 * 输出: 5->4->3->2->1->NULL
 */


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
    ListNode* reverseList(ListNode* head) {
        ListNode* p_reverse_node = NULL;
        ListNode* last_node = NULL;
        ListNode* cur_node = head;
        ListNode* next_node = NULL;

        while (cur_node != NULL) {
            next_node = cur_node->next;
            if (next_node == NULL) {
                p_reverse_node = cur_node;
            }

            cur_node->next = last_node;

            last_node = cur_node;
            cur_node = next_node;
        }

        return p_reverse_node;
    }
};

int main(int argc, char* argv[]) { return 0; }