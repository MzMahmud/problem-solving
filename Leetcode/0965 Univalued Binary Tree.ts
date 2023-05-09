function isUnivalTree(root: TreeNode | null, value: number | null = null): boolean {
    if (root === null) {
        return true;
    }
    if (value === null) {
        value = root.val;
    }
    return root.val === value 
        && isUnivalTree(root.left, value)
        && isUnivalTree(root.right, value); 
}
