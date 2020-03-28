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
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        insert_elem(nums,root);
        
        int i = 0;
        int j = nums.size() - 1;
        
        while(i < j){
            int sum = nums[i] + nums[j];
            if(sum == k)
                return true;
            else if(sum > k)
                j--;
            else
                i++;
        }
        return false;        
    }
    
    void insert_elem(vector<int> &elems,TreeNode* root){
        if(!root)
            return;
        insert_elem(elems,root->left);
        elems.push_back(root->val);
        insert_elem(elems,root->right);
    }
};
