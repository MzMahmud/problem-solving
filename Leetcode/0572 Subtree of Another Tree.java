/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        if (root == null || subRoot == null) {
            return root == subRoot;
        }
        boolean isSameTreeFromHere = false;
        if (root.val == subRoot.val) {
            isSameTreeFromHere = isSameTree(root.left, subRoot.left)
                                 && isSameTree(root.right, subRoot.right);
        }
        return isSameTreeFromHere
               || isSubtree(root.left, subRoot)
               || isSubtree(root.right, subRoot);
    }

    private boolean isSameTree(TreeNode root1, TreeNode root2) {
        if (root1 == null || root2 == null) {
            return root1 == root2;
        }
        if (root1.val != root2.val) {
            return false;
        }
        return isSubtree(root1.left, root2.left)
               && isSubtree(root1.right, root2.right);
    }
}