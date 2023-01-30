class Solution {
    public int maxLevelSum(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        if (root != null) {
            queue.add(root);
        }
        int level = 1;
        int maxLevelSum = 0, maxSumLevel = 0;
        while (!queue.isEmpty()) {
            int nNodesInLevel = queue.size();
            int levelSum = 0;
            for (int i = 0; i < nNodesInLevel; ++i) {
                var node = queue.poll();
                levelSum += node.val;
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
            if (maxSumLevel == 0 || levelSum > maxLevelSum) {
                maxLevelSum = levelSum;
                maxSumLevel = level;
            }
            ++level;
        }
        return maxSumLevel;
    }
}

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */