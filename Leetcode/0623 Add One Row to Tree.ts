function addOneRow(root: TreeNode | null, val: number, depth: number): TreeNode | null {
    if (depth == 1) {
        return new TreeNode(val, root, null);
    }
    let q: TreeNode[] = [root!];
    let currDepth = 1;
    while(q.length > 0) {
        ++currDepth;
        if (currDepth == depth) {
            for (const node of q) {
                node.left = new TreeNode(val, node.left, null);
                node.right = new TreeNode(val, null, node.right); 
            }
            break;
        }
        const newQ: TreeNode[] = [];
        for (const node of q) {
            if (node.left != null) newQ.push(node.left);
            if (node.right != null) newQ.push(node.right);
        }
        q = newQ;
    }
    return root;
}
