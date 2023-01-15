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
    record HeightInfo(boolean isBalanced, int height) {}
    
    public boolean isBalanced(TreeNode root) {
        return getHeightInfo(root, 0).isBalanced;        
    }

    public HeightInfo getHeightInfo(TreeNode root, int depth) {
        if(root == null) {
            return new HeightInfo(true, depth);
        }
        var leftHeightInfo = getHeightInfo(root.left, depth + 1);
        var rightHeightInfo = getHeightInfo(root.right, depth + 1);

        boolean rootIsBalanced = 
            leftHeightInfo.isBalanced 
            && rightHeightInfo.isBalanced 
            && Math.abs(leftHeightInfo.height - rightHeightInfo.height) < 2;
            
        int height = Math.max(leftHeightInfo.height, rightHeightInfo.height);
      
        return new HeightInfo(rootIsBalanced, height);
    }
}
