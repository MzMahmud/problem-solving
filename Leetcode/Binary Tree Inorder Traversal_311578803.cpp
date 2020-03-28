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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        inorderTraversal(root,traversal);
        return traversal;
    }
    
    void inorderTraversal(TreeNode* root,vector<int> &traversal){
        if(!root) return;
        
        inorderTraversal(root->left,traversal);
        
        traversal.push_back(root->val);
        
        inorderTraversal(root->right,traversal);
    }
};
