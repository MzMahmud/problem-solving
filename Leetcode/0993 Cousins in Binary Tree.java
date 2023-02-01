class Solution {
    private boolean areCousins;

    public boolean isCousins(TreeNode root, int x, int y) {
        areCousins = false;
        getDepth(root, x, y, 0);
        return areCousins;
    }

    public int getDepth(TreeNode root, int x, int y, int depth) {
        if (root == null) {
            return -1;
        }
        if (x == root.val || y == root.val) {
            return depth;
        }
        int immediateChildDepth = depth + 1;
        int depth1 = getDepth(root.left, x, y, immediateChildDepth);
        int depth2 = getDepth(root.right, x, y, immediateChildDepth);
        if (depth1 != -1 && depth2 != -1) {
            areCousins = depth1 == depth2 && depth1 != immediateChildDepth;
            return -1;
        }
        return Math.max(depth1, depth2);
    }
}