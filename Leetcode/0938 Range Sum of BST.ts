function rangeSumBST(root: TreeNode | null, low: number, high: number): number {
    if (root === null || low > high) {
        return 0;
    }
    let rangeSum = low <= root.val && root.val <= high? root.val : 0;
    if (root.val >= low) {
        rangeSum += rangeSumBST(root.left, low, Math.min(high, root.val));
    }
    if (root.val <= high) {
        rangeSum += rangeSumBST(root.right, Math.max(root.val, low), high);
    }
    return rangeSum;
}
