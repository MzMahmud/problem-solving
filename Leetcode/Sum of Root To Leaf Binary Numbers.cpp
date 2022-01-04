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
private:
    inline bool is_leaf(TreeNode* root) {
        return root->left == nullptr
               && root->right == nullptr;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        sumRootToLeaf(root, 0, sum);
        return sum;
    }
    
    void sumRootToLeaf(TreeNode* root, int number_from_root, int &sum) {
        if(root == nullptr) return;
        int current_number = (number_from_root << 1) + root->val;
        if(is_leaf(root)) {
            sum += current_number;
            return;
        }
        sumRootToLeaf(root->left,  current_number, sum);
        sumRootToLeaf(root->right, current_number, sum);
    }
    
    
};
