/**
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a
multiple of k then left-out nodes in the end should remain as it is.

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

#include <iostream>
#include <utility>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) {
            return NULL;
        }

        if (k == 1) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        while (head) {
            ListNode* tail = prev;
            // 遍历当前组的链表节点，如果长度等于k的话，最终tail为当前组最后一个节点
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                // 说明当前组的长度少于k了
                if (!tail) {
                    return dummy->next;
                }
            }

            ListNode* tmp_next = tail->next;
            std::pair<ListNode*, ListNode*> result = reverse_sub_link(head, tail);
            head = result.first;
            tail = result.second;

            prev->next = head;
            tail->next = tmp_next;

            // head每次走k步，直接等于当前组的末尾节点的next，prev等于当前组的尾结点（原head前加入一个dummy能够使得第一个组和后面所有组统一起来）
            prev = tail;
            head = tail->next;
        }

        return dummy->next;
    }

   private:
    std::pair<ListNode*, ListNode*> reverse_sub_link(ListNode* head, ListNode* tail) {
        // 遍历一组链表内部，并进行翻转
        ListNode* prev = tail->next;
        ListNode* p_head = head;
        while (prev != tail) {
            ListNode* next = p_head->next;
            p_head->next = prev;
            prev = p_head;
            p_head = next;
        }
        return {tail, head};
    }
};

int main(int argc, char* argv[]) { return 0; }