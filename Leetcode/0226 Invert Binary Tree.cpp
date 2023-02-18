class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root != nullptr) {
            auto rootLeft = root->left;
            root->left = invertTree(root->right);
            root->right = invertTree(rootLeft);
        }
        return root;
    }
};