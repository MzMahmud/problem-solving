function removeLeafNodes(root: TreeNode | null, target: number): TreeNode | null {
    if (isLeafWithTarget(root, target)) {
        return null;
    }
    root.left = removeLeafNodes(root.left, target);
    root.right = removeLeafNodes(root.right, target);
    return isLeafWithTarget(root, target) ? null : root;
}

function isLeafWithTarget(root: TreeNode | null, target: number) {
    return root === null || (root.left === null && root.right === null && root.val === target);
}
