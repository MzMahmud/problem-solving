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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> all_paths;
        binaryTreePaths(root, "", all_paths);
        return all_paths;
    }
    
    void binaryTreePaths(TreeNode* root, string path_from_parent, vector<string> &all_paths) {
        if(root == nullptr) return;
        
        string path = path_from_parent.empty() 
                      ? to_string(root->val)
                      : path_from_parent + "->" + to_string(root->val);
        
        if(root->left == nullptr && root->right == nullptr) {
            all_paths.push_back(path);
            return;
        }
        
        binaryTreePaths(root->left, path, all_paths);
        binaryTreePaths(root->right, path, all_paths);
    }
};
