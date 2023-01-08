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
    // O(1) space, O(n) time, One pass, Modifies Linked List
    // - slow and fast to find middle
    // - while traversing the slow pointer reverse the list
    // - when you reach the middle left traverses reversed linked list, right goes to end forward
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr) {
            return true;
        }
        ListNode *slow = head;        
        ListNode *fast = head;
        ListNode *prev = nullptr;        
        while(fast != nullptr and fast->next != nullptr) {
            // ordering is very important
            // think and modify value accordingly
            fast = fast->next->next;
            ListNode *slow_next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = slow_next;
        }
        ListNode *left = prev;
        ListNode *right = fast == nullptr ? slow : slow->next;
        while(left != nullptr and right != nullptr) {
            if(left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return left == nullptr and right == nullptr;
    }
};
