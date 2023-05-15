function deleteNode(root: TreeNode | null, key: number): TreeNode | null {
    if (root === null) {
        return null;
    }
    if (key < root.val) {
        root.left = deleteNode(root.left, key);
    } else if (key > root.val) {
        root.right = deleteNode(root.right, key);
    } else {
        if (root.right === null) return root.left;
        let nextVal!: number;
        for (let curr: TreeNode | null = root.right; curr !== null; curr = curr.left) {
            nextVal = curr.val;
        }
        root.val = nextVal;
        root.right = deleteNode(root.right, nextVal);
    }
    return root;
}
