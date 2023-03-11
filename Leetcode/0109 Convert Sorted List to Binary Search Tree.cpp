class Solution {
public:
    // O(n log n) time, O(log n) space
    // does not modify the list 
    TreeNode* sortedListToBST(ListNode* head, ListNode* end=nullptr) {
        if(head == end) {
            return nullptr;
        }
        if(head->next == end) {
            return new TreeNode(head->val);
        }
        ListNode *slow = head, *fast = head;
        while (fast != end and fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head, slow);
        root->right = sortedListToBST(slow->next, end);
        return root;
    }
};