#include "utils/include/list.h"

#include <memory>

ListNode* List::Create(const std::vector<int>& vec) {
    ListNode* head = new ListNode(0);
    ListNode* p = head;

    for (auto& n : vec) {
        ListNode* tmp = new ListNode(n);

        p->next = tmp;
        p = tmp;
    }
    head = head->next;
    p->next = NULL;

    return head;
}

void List::PrintList(ListNode* list) const {
    ListNode* p = list;
    while (p != NULL) {
        std::cout << p->val << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

void List::DeleteList(ListNode* list) {
    ListNode* p;
    while (p != NULL) {
        list = p->next;
        delete p;
    }
}
