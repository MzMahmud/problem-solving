class Solution {
  public:
    TreeNode *bstToGst(TreeNode *root) {
        int greaterSum = 0;
        dfs(root, greaterSum);
        return root;
    }

    void dfs(TreeNode *root, int &greaterSum) {
        if (root == nullptr) {
            return;
        }
        dfs(root->right, greaterSum);
        greaterSum += root->val;
        root->val = greaterSum;
        dfs(root->left, greaterSum);
    }
};