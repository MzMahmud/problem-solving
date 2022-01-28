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
    void flatten(TreeNode* root) {
        flatten_and_get_head_tail(root);
    }
    
    pair<TreeNode*,TreeNode*> flatten_and_get_head_tail(TreeNode* root) {
        if(root == nullptr) {
            return {nullptr, nullptr};
        }
        if(root->left == nullptr and root->right == nullptr) {
            return {root, root};
        }
        auto [left_head, left_tail] = flatten_and_get_head_tail(root->left);
        auto [right_head, right_tail] = flatten_and_get_head_tail(root->right);
        TreeNode *tail; 
        if(root->left == nullptr) {
            root->right = right_head;
            tail = right_tail;
        }else if(root->right == nullptr) {
            root->right = left_head;
            tail = left_tail;
        } else {
            root->right = left_head;
            left_tail->right = right_head;   
            tail = right_tail;
        }
        root->left = nullptr;
        return {root, tail};
    }
};
