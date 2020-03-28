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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(0,nums.size() - 1,nums);
    }
    
    TreeNode* sortedArrayToBST(int left,int right,vector<int>& nums) {
        if(left > right)
            return NULL;
        
        int mid = (left + right) >> 1;
        
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left  = sortedArrayToBST(left   , mid - 1, nums);
        root->right = sortedArrayToBST(mid + 1, right  , nums);
        
        return root;
    }
};
