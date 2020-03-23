/**
 * Given a non-empty, singly linked list with head node head, return a middle node of linked list.If there are two
middle nodes, return the second middle node.

Input: [1,2,3,4,5]
Output: Node 3 from this list (Serialization: [3,4,5])
    The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
    Note that we returned a ListNode object ans, such that:
    ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.

Input: [1,2,3,4,5,6]
Output: Node 4 from this list (Serialization: [4,5,6])
    Since the list has two middle nodes with values 3 and 4, we return the second one.

Notes:
The number of nodes in the given list will be between 1 and 100.
 */

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    // 单指针方法
    // O(N), 空间复杂度O(1)
    ListNode* middleNode(ListNode* head) {
        ListNode* res = head;

        int len = 0;
        while (NULL != head->next) {
            head = head->next;
            len++;
        }
        len++;

        // the second one
        int mid = len / 2 + 1;
        int cnt = 1;
        while (cnt < mid) {
            res = res->next;
            cnt++;
        }
        return res;
    }

    // 快慢指针, 慢指针一次走一步，快指针一次走两步，快指针到尾后，慢指针肯定在中间
    // O(n), 空间复杂度O(1)
    ListNode* middleNodeDoublePointer(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (NULL != fast && NULL != fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
