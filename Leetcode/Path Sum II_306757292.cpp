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
    vector<vector<int>> all;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        pathSum(root,sum,path);
        return all;
    }
    
    void pathSum(TreeNode* root, int sum,vector<int> path) {
        if(!root)   return;
        
        if(isLeaf(root) && (root->val == sum)){
            path.push_back(root->val);
            all.push_back(path);
            return;
        }
        
        path.push_back(root->val);
        pathSum(root->left,sum - root->val,path);
        pathSum(root->right,sum - root->val,path);
    }
    
    bool isLeaf(TreeNode *root){
        return !(root->left || root->right);
    }
};
