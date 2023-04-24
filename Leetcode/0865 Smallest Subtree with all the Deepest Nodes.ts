function subtreeWithAllDeepest(root: TreeNode | null): TreeNode | null {
    return dfs(root, 0).lca;
}

function dfs(root: TreeNode | null, depth: number): {depth: number, lca: TreeNode | null} {
    if (root === null || root.left === null && root.right === null) {
        return {depth: depth, lca: root};
    }
    const left = dfs(root.left, depth + 1);
    const right = dfs(root.right, depth + 1);
    if (root.right === null || left.depth > right.depth) {
        return left;
    }
    if (root.left === null || right.depth > left.depth) {
        return right;
    }
    return {depth: left.depth, lca: root};
}
