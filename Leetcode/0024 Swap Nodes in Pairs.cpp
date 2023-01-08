// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *new_head              = head->next;
        ListNode *rest_of_the_list_head = head->next->next;
        head->next->next                = head;
        head->next                      = swapPairs(rest_of_the_list_head);
        return new_head;
    }
};