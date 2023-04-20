class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        deque<pair<TreeNode*, int>> queue {{root, 0}};
        int maxWidth = 0;
        while (not queue.empty()) {
            int width = (long long) queue.back().second - queue.front().second + 1;
            maxWidth = max(maxWidth, width);
            int size = queue.size();
            for (int i = 0;i < size; i++) {
                auto [node, index] = queue.front();
                queue.pop_front();
                long long leftIndex = (long long) 2 * index;
                if (node->left != nullptr) {
                    queue.push_back({node->left, leftIndex});
                }
                if (node->right != nullptr) {
                    queue.push_back({node->right, leftIndex + 1});
                }
            } 
        }
        return maxWidth;
    }
};
