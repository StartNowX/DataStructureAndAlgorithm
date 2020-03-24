#pragma

#include <iostream>
#include <memory>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class List {
   public:
    ListNode* Create(const std::vector<int>& vec);

    void PrintList(ListNode* list) const;

    void DeleteList(ListNode* list);

   private:
    // ListNode* node_;
};
