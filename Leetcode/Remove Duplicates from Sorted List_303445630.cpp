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
        
        ListNode *current = head;
        while(current && current->next){
            if(current->val == current->next->val){
                current->next = current->next->next;
                //delete current->next;
            }else{
                current = current->next;
            }
        }
        return head;
    }
};
