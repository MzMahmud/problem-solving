function pruneTree(root: TreeNode | null): TreeNode | null {
    return dfs(root)? root : null;
}

function dfs(root: TreeNode | null): boolean {
    if (root === null) {
        return false;
    }
    const leftHasOne = dfs(root.left);
    if (!leftHasOne) {
        root.left = null;
    }
    const rightHasOne = dfs(root.right);
    if (!rightHasOne) {
        root.right = null;
    }
    return root.val === 1 || leftHasOne || rightHasOne;
}
