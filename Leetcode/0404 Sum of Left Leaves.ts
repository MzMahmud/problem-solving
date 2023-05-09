function sumOfLeftLeaves(root: TreeNode | null): number {
    let sum = 0;
    function dfs(root: TreeNode | null, isLeftChild: boolean) {
        if (root === null) {
            return;
        }
        if (root.left === null && root.right === null && isLeftChild) {
            sum += root.val;
        }
        dfs(root.left, true);
        dfs(root.right, false);
    }
    dfs(root, false);
    return sum;
}
