/**
 * 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。
 *
 * 给定一个链表: 1->2->3->4->5, 和 k = 2.
 * 返回链表 4->5.
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
    // 遍历两次链表
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* p_head = head;
        int len = 0;
        while (p_head != NULL) {
            ++len;
            p_head = p_head->next;
        }

        p_head = head;
        ListNode* kth_node = new ListNode(0);
        while (p_head != NULL) {
            if (len - k == 0) {
                kth_node->val = p_head->val;
                kth_node->next = p_head->next;
                break;
            }
            --len;
            p_head = p_head->next;
        }
        return kth_node;
    }

    // 双指针，两者之间相差k步，只需要遍历一次就可以找到倒数第k个位置
    ListNode* getKthFromEndOnce(ListNode* head, int k) {
        ListNode* slow_node = head;
        ListNode* fast_node = head;
        int index = 0;
        while (index++ < k) {
            // k的大小和链表的实际长度比较由调用者负责检查
            fast_node = fast_node->next;
        }

        while (fast_node != NULL) {
            fast_node = fast_node->next;
            slow_node = slow_node->next;
        }

        return slow_node;
    }
};

int main(int argc, char* argv[]) { return 0; }