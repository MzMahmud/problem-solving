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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        //if(!(l1 || l2))
        //    return new ListNode(0);

        ListNode *sumL;
        ListNode *peviousDigit = NULL;
        int carry = 0;

        while(l1 || l2){
            
            int digitSum = carry + (l1? l1->val : 0) + (l2? l2->val : 0);

            int nextDigit = digitSum % 10;
            carry         = digitSum / 10;

            ListNode *currentDigit = new ListNode(nextDigit);

            if(peviousDigit)
                peviousDigit->next = currentDigit;
            else
                sumL = currentDigit;

            peviousDigit = currentDigit;

            l1 = l1? l1->next : l1;
            l2 = l2? l2->next : l2;
        }

        if(carry)
            peviousDigit->next = new ListNode(carry);

        return sumL;        
    }
};
