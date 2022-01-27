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
        if(head == nullptr) {
            return nullptr;
        }
        ListNode *head_next = removeElements(head->next, val);
        if(head->val == val) {
            delete head;
            head = head_next;
        } else {
            head->next = head_next;        
        }
        return head;
    }
};
