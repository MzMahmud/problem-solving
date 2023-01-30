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
    int maxLevelSum(TreeNode *root) {
        queue<TreeNode *> q;
        if (root != nullptr) {
            q.emplace(root);
        }
        int level = 1, max_level_sum, max_sum_level = 0;
        while (!q.empty()) {
            int n_nodes_in_level = q.size();
            int level_sum = 0;
            for (int i = 0; i < n_nodes_in_level; ++i) {
                auto node = q.front();
                q.pop();
                level_sum += node->val;
                if (node->left != nullptr) {
                    q.emplace(node->left);
                }
                if (node->right != nullptr) {
                    q.emplace(node->right);
                }
            }
            if (max_sum_level == 0 || level_sum > max_level_sum) {
                max_level_sum = level_sum;
                max_sum_level = level;
            }
            ++level;
        }
        return max_sum_level;
    }
};