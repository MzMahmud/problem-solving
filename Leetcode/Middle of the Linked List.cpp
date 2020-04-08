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
    // time: O(N) ; space: O(N)
    // ListNode* middleNode(ListNode* head) {
    //     vector<ListNode*> nodes;
    //     while(head){
    //         nodes.push_back(head);
    //         head = head->next;
    //     }
    //     return nodes[nodes.size()>>1];
    // }
    
    // time: O(N) ; space: O(1)
    ListNode* middleNode(ListNode* head) {
        ListNode *fast,*slow;
        fast = slow = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next; 
        }
        return slow;
    }
};