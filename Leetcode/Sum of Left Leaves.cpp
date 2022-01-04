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
    enum Direction {LEFT, RIGHT, NONE};
    
    inline bool is_leaf(TreeNode* root) {
        return root->left == nullptr
               && root->right == nullptr;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        sumOfLeftLeaves(root, NONE, sum);
        return sum;
    }
    
    void sumOfLeftLeaves(TreeNode* root, Direction dir, int &sum) {
        if(root == nullptr) return;
        if(is_leaf(root) && dir == LEFT) {
            sum += root->val;
            return;
        }
        sumOfLeftLeaves(root->left,  LEFT,  sum);
        sumOfLeftLeaves(root->right, RIGHT, sum);
    }
};
