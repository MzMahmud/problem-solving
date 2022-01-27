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
public:
    ListNode *removeElements(ListNode *head, int val) {
        while(head != nullptr and head->val == val) {
            ListNode *to_delete = head;
            head = head->next;
            delete to_delete;
        }
        ListNode *prev = nullptr, *curr = head;
        while(curr != nullptr) {
            if(curr->val == val) {
                ListNode *to_delete = curr;
                curr = prev->next = curr->next;
                delete to_delete;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
    
    ListNode *removeElementsRecurrsive(ListNode *head, int val) {
        if(head == nullptr) {
            return nullptr;
        }
        ListNode *head_next = removeElementsRecurrsive(head->next, val);
        if(head->val == val) {
            delete head;
            head = head_next;
        } else {
            head->next = head_next;        
        }
        return head;
    }
};
