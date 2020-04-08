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
        if (!head or !head->next)
            return head;

        // find middle
        ListNode *fast, *slow, *prev;
        prev = NULL;
        fast = slow = head;
        while (fast and fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // cuts the list in hlaf
        prev->next = NULL;
        // head....prev->slow...... to
        // head....prev (and) slow.....

        // recurrsively sort left and right
        ListNode *left = sortList(head);
        ListNode *right = sortList(slow);

        // marge
        ListNode *i = left;
        ListNode *j = right;

        ListNode dummy_head(0);
        ListNode *curr = NULL;

        prev = &dummy_head;
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

        if (i != NULL)
            prev->next = i;
        if (j != NULL)
            prev->next = j;

        return dummy_head.next;
    }
};