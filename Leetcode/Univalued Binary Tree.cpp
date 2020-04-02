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
    unordered_set<int> vals;
    bool isUnivalTree(TreeNode* root) {
        vals.clear();
        pre_order(root);
        return vals.size() < 2;
    }
    
    void pre_order(TreeNode* root) {
        if(!root)
            return;
        vals.insert(root->val);
        pre_order(root->left);
        pre_order(root->right);
    }
};
