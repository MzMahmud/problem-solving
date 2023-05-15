function replaceValueInTree(root: TreeNode | null): TreeNode | null {
    const levelSum = new Map<number, number>();
    function calculateLevelSum(root: TreeNode | null, depth: number) {
        if (root === null) return;
        levelSum.set(depth, (levelSum.get(depth) ?? 0) + root.val);
        calculateLevelSum(root.left, depth + 1);
        calculateLevelSum(root.right, depth + 1);
    }
    calculateLevelSum(root, 0);
    function updateWithCousinSum(root: TreeNode | null, depth: number, siblingSum: number) {
        if (root === null) return;
        root.val = levelSum.get(depth) as number - siblingSum;
        const nextSiblingSum = (root.left ? root.left.val : 0) + (root.right ? root.right.val : 0);
        updateWithCousinSum(root.left, depth + 1, nextSiblingSum);
        updateWithCousinSum(root.right, depth + 1, nextSiblingSum);
    }
    updateWithCousinSum(root, 0, levelSum.get(0) as number);
    return root;
}
