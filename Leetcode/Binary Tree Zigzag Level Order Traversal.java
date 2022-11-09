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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        if (root != null) {
            queue.add(root);
        }
        List<List<Integer>> zigzagLevels = new ArrayList<>();
        boolean doReverse = false;
        while (!queue.isEmpty()) {
            int nNodesInLevel = queue.size();
            LinkedList<Integer> level = new LinkedList<>();
            for (int i = 0; i < nNodesInLevel; ++i) {
                TreeNode treeNode = queue.poll();
                if (doReverse) {
                    level.addFirst(treeNode.val);
                } else {
                    level.addLast(treeNode.val);
                }
                if (treeNode.left != null) {
                    queue.add(treeNode.left);
                }
                if (treeNode.right != null) {
                    queue.add(treeNode.right);
                }
            }
            zigzagLevels.add(level);
            doReverse = !doReverse;
        }
        return zigzagLevels;
    }
}
