class Solution {
    private boolean areCousins;

    public boolean isCousins(TreeNode root, int x, int y) {
        areCousins = false;
        getDepth(root, x, y, 0);
        return areCousins;
    }

    private static final int NOT_FOUND = -1;

    public int getDepth(TreeNode root, int x, int y, int depth) {
        if (root == null) {
            return NOT_FOUND;
        }
        if (x == root.val || y == root.val) {
            return depth;
        }
        int immediateChildDepth = depth + 1;
        int depthFromLeft = getDepth(root.left, x, y, immediateChildDepth);
        int depthFromRight = getDepth(root.right, x, y, immediateChildDepth);

        if (depthFromLeft != NOT_FOUND && depthFromRight != NOT_FOUND) {
            areCousins = depthFromLeft == depthFromRight && depthFromLeft != immediateChildDepth;
            return NOT_FOUND;
        }

        return depthFromLeft == NOT_FOUND ? depthFromRight : depthFromLeft;
    }
}