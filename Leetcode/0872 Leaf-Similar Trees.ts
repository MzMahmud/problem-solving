function leafSimilar(root1: TreeNode | null, root2: TreeNode | null): boolean {
    const leaves1 = getLeaves(root1, []);
    const leaves2 = getLeaves(root2, []);
    if (leaves1.length !== leaves2.length) {
        return false;
    }
    for (let i = 0; i < leaves1.length; i++) {
        if (leaves1[i] !== leaves2[i]) {
            return false;
        }
    }
    return true;
}

function getLeaves(root: TreeNode | null, leaves: number[]) {
    if (root !== null) {
        if (root.left === null && root.right === null) {
            leaves.push(root.val);
        }
        getLeaves(root.left, leaves);
        getLeaves(root.right, leaves);
    }
    return leaves;
}
