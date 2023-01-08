/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    // one pass
    // - move first to nth node from the beginning
    // - move start second from head and move until first->next reaches end
    // - this takes second to nth position from back. delete slow now
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *first;
        first = head;
        while(n--) {
            first = first->next;
        }
        ListNode dummy_head(0, head);
        ListNode *second = &dummy_head;
        while(first != nullptr) {
            first = first->next;
            second = second->next;
        }
        ListNode *to_delete = second->next;
        second->next = second->next->next;
        if(to_delete != nullptr) {
            delete to_delete;            
        }
        return dummy_head.next;
    }
};
