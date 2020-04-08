/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return sort(head);        
    }
    
    ListNode *sort(ListNode *head, ListNode *end = NULL) {
        if (!head)
            return head;

        if (head->next == end) {
            head->next = NULL;
            return head;
        }

        // find middle
        ListNode *mid = middle_node(head, end);

        // recurrsively sort left and right
        ListNode *left = sort(head, mid);
        ListNode *right = sort(mid, end);

        // marge
        ListNode *i = left;
        ListNode *j = right;

        ListNode dummy_head(0);
        ListNode *prev = &dummy_head;
        ListNode *curr = NULL;

        while (i and j) {
            if (i->val < j->val) {
                curr = i;
                i = i->next;
            } else {
                curr = j;
                j = j->next;
            }
            prev->next = curr;
            prev = curr;
        }

        if (i) prev->next = i;
        
        if (j) prev->next = j;

        return dummy_head.next;
    }
    
    ListNode *middle_node(ListNode *head, ListNode *end = NULL) {
        ListNode *fast, *slow;
        fast = slow = head;
        while (fast != end and fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};