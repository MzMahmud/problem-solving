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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* marged = new ListNode(0);
        ListNode* prev   = marged;
        
        while(l1 || l2){
            ListNode *newNode;
            if(!l1){
                newNode = l2;
                l2 = l2->next;
            }
            else if(!l2) {
                newNode = l1;
                l1 = l1->next;
            }else{
                if(l1->val < l2->val){
                    newNode = l1;
                    l1 = l1->next;
                }else{
                    newNode = l2;
                    l2 = l2->next; 
                }
            }
            
            prev->next = newNode;
            prev       = newNode;
        }
        return marged->next;
    }
};
