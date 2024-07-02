function rob(root: TreeNode | null): number {
    function dfs(root: TreeNode | null): [number, number] {
        if (root == null) return [0, 0];
        const left = dfs(root.left), right = dfs(root.right);
        const dontTake = Math.max(...left) + Math.max(...right);
        const take = root.val + left[0] + right[0];
        return [dontTake, take];
    }
    return Math.max(...dfs(root));
}
