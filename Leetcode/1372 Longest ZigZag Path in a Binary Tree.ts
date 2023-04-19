function longestZigZag(root: TreeNode | null): number {
    let maxLen = 0;
    function dfs(root: TreeNode | null) {
        if (root === null) {
            return {left: -1, right: -1};
        }
        const left = dfs(root.left);
        const right = dfs(root.right);
        const fromRoot = {
            left: 1 + left.right,
            right: 1 + right.left,
        }
        maxLen = Math.max(maxLen, fromRoot.left, fromRoot.right);
        return fromRoot;
    }
    dfs(root);
    return maxLen;
}
