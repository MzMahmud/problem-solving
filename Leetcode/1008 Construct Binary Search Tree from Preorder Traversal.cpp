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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return bst(i,INT_MAX,preorder);
    }
    
    TreeNode* bst(int &i,int parent_val,const vector<int>& preorder) {
        if(i >= preorder.size() or preorder[i] > parent_val)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[i]);
        ++i;
        
        root->left  = bst(i,root->val,preorder);
        root->right = bst(i,parent_val,preorder);
        
        return root;
    }
};