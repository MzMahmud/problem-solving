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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q)
            return root;
        
        TreeNode *l = (p->val < q->val) ? p : q;
        TreeNode *r = (p->val > q->val) ? p : q;
        
        if(l->val < root->val && root->val < r->val)
            return root;
        
        return (l->val < root->val) ? 
                lowestCommonAncestor(root->left ,p ,q) : 
                lowestCommonAncestor(root->right,p ,q);
    }
};
