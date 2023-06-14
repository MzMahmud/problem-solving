function getMinimumDifference(root: TreeNode | null): number {
    let prevNode: TreeNode | null = null, minDiff = Infinity;
    function dfs(root: TreeNode | null) {
        if (root === null) {
            return;
        }
        dfs(root.left);
        if (prevNode != null) {
            minDiff = Math.min(minDiff, root.val - prevNode.val);
        }
        prevNode = root;
        dfs(root.right);
    }
    dfs(root);
    return minDiff;
}
