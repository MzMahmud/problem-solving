/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // both null -> true
        if(!p && !q)
            return true;
        
        // one null other not ->false
        if(p && !q || !p && q)
            return false;
        
        // root not same -> false
        if(p->val != q->val)
            return false;
        
        return
           (isSameTree(p->left,q->left)  && isSameTree(p->right,q->right))
        ;//|| (isSameTree(p->left,q->right) && isSameTree(p->right,q->left));        
        
    }
};
