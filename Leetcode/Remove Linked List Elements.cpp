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
        if(head->val == val) {
            ListNode *new_head = removeElements(head->next, val);
            delete head;
            return new_head;
        }
        head->next = removeElements(head->next, val);
        return head;
    }
};
