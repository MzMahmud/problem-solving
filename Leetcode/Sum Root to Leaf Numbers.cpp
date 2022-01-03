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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        sumNumbers(root, 0, sum);
        return sum;
    }
    
    void sumNumbers(TreeNode* root, int number, int &sum) {
        if(root == nullptr) return;
        number = number * 10 + root->val; 
        if(root->left == nullptr && root->right == nullptr) {
            sum += number;
            return;
        }
        sumNumbers(root->left, number, sum);
        sumNumbers(root->right, number, sum);
    }
};
