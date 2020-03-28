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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return head;
        
        ListNode *i,*j;
        i = head,j = head->next;
        while(j){
            if(i->val != j->val){
                i->next = j;
                i = j;
            }
            j = j->next;
        }
        
        i->next = j;
        return head;
    }
};
