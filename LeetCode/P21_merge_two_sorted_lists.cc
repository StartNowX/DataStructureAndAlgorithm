/**
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

 **/

 // 同SwordOffer中Q25_merge_sorted_listnode.cc

 #include <iostream>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        }
        ListNode *root = new ListNode(0);
        ListNode *p_node = root;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val > l2->val) {
                ListNode *tmp = new ListNode(l2->val);
                p_node->next = tmp;

                l2 = l2->next;
            } else {
                ListNode *tmp = new ListNode(l1->val);
                p_node->next = tmp;

                l1 = l1->next;
            }
            p_node = p_node->next;
        }
        if (l1) p_node->next = l1;
        if (l2) p_node->next = l2;

        return root->next;
    }
};

int main(int argc, char* argv[]) {return 0;}