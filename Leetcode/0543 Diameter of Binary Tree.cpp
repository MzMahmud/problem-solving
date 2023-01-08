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
    int diam;
	
	int height(TreeNode* root){
        if(!root)
            return 0;
        int left  = height(root->left);
        int right = height(root->right);
        
        int curr_diam = (left + right);
        if(curr_diam > diam)
            diam = curr_diam;
        
        return 1 + max(left,right);
    }
	
public:
    
	int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
		diam = -1;
		
        int left  = height(root->left);
        int right = height(root->right);
        
        int curr_diam = (left + right);
        if(curr_diam > diam)
            diam = curr_diam;
        
        return diam;
    }
};