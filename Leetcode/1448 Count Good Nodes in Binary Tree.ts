function goodNodes(root: TreeNode | null, maxNodeInPath: number = -Infinity): number {
    if (root === null) {
        return 0;
    }
    maxNodeInPath = Math.max(maxNodeInPath, root.val)
    let nGoodNodes = root.val === maxNodeInPath? 1 : 0;
    nGoodNodes += goodNodes(root.left, maxNodeInPath);
    nGoodNodes += goodNodes(root.right, maxNodeInPath);
    return nGoodNodes;
}
