function insertIntoMaxTree(root: TreeNode | null, val: number): TreeNode | null {
    if (root === null) {
        return new TreeNode(val);
    }
    if (val > root.val) {
        return new TreeNode(val, root, null);
    }
    root.right = insertIntoMaxTree(root.right, val);
    return root;
}
