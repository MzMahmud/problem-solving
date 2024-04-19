function isEvenOddTree(root: TreeNode | null): boolean {
    if (root == null) return true;
    let q: TreeNode[] = [root];
    let isEvenLevel = true;
    while (q.length > 0) {
        const newQ: TreeNode[] = [];
        let prev: number | null = null;
        for (const node of q) {
            if ((node.val % 2 === 0) === isEvenLevel) return false;
            if (prev != null) {
                const diff = prev - node.val;
                if (diff === 0 || (diff > 0) === isEvenLevel) return false;
            }
            prev = node.val;
            if (node.left != null) newQ.push(node.left);
            if (node.right != null) newQ.push(node.right);
        }
        q = newQ;
        isEvenLevel = !isEvenLevel;
    }
    return true;
}
