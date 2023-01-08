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
    int getDecimalValue(ListNode* head) {
        int value = 0;
        getDecimalValue(value,head);
        return value;
    }
    void getDecimalValue(int &value,ListNode* head){
        if(!head) return;
        value = (value << 1) + head->val;
        getDecimalValue(value,head->next);
    }
};
