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
    int index;
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        index = 0;
        kthSmallest(root,k,ans);
        return ans;
    }
    void kthSmallest(TreeNode* root, int k,int &ans){
        if(root->left)
            kthSmallest(root->left,k,ans);
        
        if(++index == k){
            ans = root->val;
            return;
        }
        
        if(root->right)
            kthSmallest(root->right,k,ans);
    }
};
