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
class Solution {
    private int maximumPathSum = Integer.MIN_VALUE;

    public int maxPathSum(TreeNode root) {
        getMaxPathSumEndingAtRoot(root);
        return maximumPathSum;
    }

    public int getMaxPathSumEndingAtRoot(TreeNode root) {
        if(root == null) {
            return 0;
        }
        int leftPathSum = Math.max(0, getMaxPathSumEndingAtRoot(root.left));
        int rightPathSum = Math.max(0, getMaxPathSumEndingAtRoot(root.right));
        maximumPathSum = Math.max(
            maximumPathSum,
            leftPathSum + root.val + rightPathSum
        );
        return Math.max(root.val + leftPathSum, root.val + rightPathSum);
    }
}
