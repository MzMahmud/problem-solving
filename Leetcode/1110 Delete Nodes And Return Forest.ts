function delNodes(root: TreeNode | null, toDelete: number[]): Array<TreeNode | null> {
    const toDeleteSet = new Set<number>(toDelete);
    const forest: (TreeNode | null) [] = [];
    function dfs(root: TreeNode | null) {
        if (root === null) {
            return null;
        }
        root.left = dfs(root.left); 
        root.right = dfs(root.right);
        if (!toDeleteSet.has(root.val)) {
            return root;
        }
        if (root.left !== null) {
            forest.push(root.left);
        }
        if (root.right !== null) {
            forest.push(root.right);
        }
        return null;
    }
    const newRoot = dfs(root);
    if (newRoot !== null) {
        forest.push(newRoot);
    }
    return forest;
}
