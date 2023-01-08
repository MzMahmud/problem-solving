/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
    
    bool isValidBST(TreeNode* root, long long min_val, long long max_val) {
        if(root == nullptr) {
            return true;
        }
        long long val = root->val;
        if(val <= min_val || val >= max_val) {
            return false;
        }
        return isValidBST(root->left, min_val, val)
               && isValidBST(root->right, val, max_val);
    }
};
