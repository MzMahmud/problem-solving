// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            ListNode *to_go = curr->next;
            curr->next      = prev;
            prev            = curr;
            curr            = to_go;
        }
        return head = prev;
    }

    ListNode *reverseListRecurrsive(ListNode *head) {
        if (head == nullptr or head->next == nullptr)
            return head;
        ListNode *second_elem = head->next;
        ListNode *new_head    = reverseListRecurrsive(second_elem);
        head->next            = nullptr;
        second_elem->next     = head;
        return new_head;
    }
};
