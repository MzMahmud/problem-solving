/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int find_length(ListNode *head) {
        int length = 0;
        while(head != nullptr) {
            head = head->next;
            ++length;
        }
        return length;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int length_a = find_length(headA);
        int length_b = find_length(headB);
        if(length_a < length_b) {
            swap(length_a, length_b);
            swap(headA, headB);
        }
        while(length_a != length_b) {
            headA = headA->next;
            --length_a;
        }
        while(headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
