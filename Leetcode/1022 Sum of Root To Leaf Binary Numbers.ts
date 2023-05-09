function sumRootToLeaf(root: TreeNode | null): number {
    let sum = 0;
    function dfs(root: TreeNode | null, value: number) {
        if (root === null) {
             return;
        }
        value = (value << 1) | root.val;
        if (root.left === null && root.right === null) {
            sum += value;
            return;
        }
        dfs(root.left, value);
        dfs(root.right, value);
    }
    dfs(root, 0);
    return sum;
}
