function printTree(root: TreeNode | null): string[][] {
    if (root == null) return [];
    const h = treeHeight(root);
    const m = h  + 1;
    const n = (1 << (h + 1)) - 1;
    const tree = Array.from({length: m}, () => Array.from({length: n}, () => ""));
    function dfs(root: TreeNode | null, r: number, c: number) {
        if (root == null) return;
        tree[r][c] = `${root.val}`;
        const diff = 1 << (h - r - 1);
        dfs(root.left, r + 1, c - diff);
        dfs(root.right, r + 1, c + diff);
    } 
    dfs(root, 0, (n - 1) / 2);
    return tree;   
}

function treeHeight(root: TreeNode | null): number {
    if (root == null) return -1;
    return 1 + Math.max(treeHeight(root.left), treeHeight(root.right));
}
