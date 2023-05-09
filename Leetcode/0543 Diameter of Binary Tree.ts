function diameterOfBinaryTree(root: TreeNode | null): number {
    let diameter = 0;
    function dfs(root: TreeNode | null): number {
        if (root === null) return 0;
        const left = dfs(root.left), right = dfs(root.right);
        diameter = Math.max(diameter, left + right);
        return 1 + Math.max(left, right);
    }
    dfs(root);
    return diameter;
}
