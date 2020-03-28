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
    stack<int> s;
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        kthSmallest(root,k,ans);
        return ans;
    }
    void kthSmallest(TreeNode* root, int k,int &ans){
        if(root->left)
            kthSmallest(root->left,k,ans);
        
        s.push(root->val);
        if(s.size() == k){
            ans = s.top();
            return;
        }
        
        if(root->right)
            kthSmallest(root->right,k,ans);
    }
};
