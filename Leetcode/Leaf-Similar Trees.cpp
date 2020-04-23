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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> l1,l2;
        store_leaves(root1,l1);
        store_leaves(root2,l2);
        if(l1.size() != l2.size())
            return false;
        
        for(int i = 0;i < l1.size();++i)
            if(l1[i] != l2[i])
                return false;
        return true;
    }
    
    void store_leaves(TreeNode* root,vector<int> &leaves){
        if(!root) return;
        
        if(!root->left and !root->right)
            leaves.push_back(root->val);
    
        store_leaves(root->left,leaves);
        store_leaves(root->right,leaves);
    }
};