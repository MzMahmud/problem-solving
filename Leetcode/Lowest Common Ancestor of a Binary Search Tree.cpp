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
    // O(h) solution for BST
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) {
            return nullptr;
        }
        if(p->val < root->val and q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
    
        if(root->val < p->val and root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
    /*
    - O(n)
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
    }*/
};
