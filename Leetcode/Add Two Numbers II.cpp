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
    stack<int> get_digits_right_to_left(ListNode* head) {
        stack<int> digits;
        while(head != nullptr) {
            digits.push(head->val);
            head = head->next;
        }
        return digits;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> digits1 = get_digits_right_to_left(l1);
        stack<int> digits2 = get_digits_right_to_left(l2);
        ListNode head; 
        int carry = 0;
        while(not digits1.empty() or not digits2.empty()) {
            int d1 = 0,d2 = 0;
            if(!digits1.empty()) {
                d1 = digits1.top();
                digits1.pop();
            }
            if(!digits2.empty()) {
                d2 = digits2.top();
                digits2.pop();
            }
            int sum = d1 + d2 + carry;
            carry = sum / 10;
            head.next = new ListNode(sum % 10, head.next);
        }
        if(carry != 0) {
            head.next = new ListNode(carry, head.next);
        }
        return head.next;
    }
};
