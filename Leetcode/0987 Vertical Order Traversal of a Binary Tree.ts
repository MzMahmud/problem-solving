function verticalTraversal(root: TreeNode | null): number[][] {
    if (root == null) return [];
    const valuesByCol = new Map<number, Map<number, number[]>>();
    let q: [TreeNode, number][] = [[root, 0]];
    let r = 0;
    while (q.length > 0) {
        const newQ: [TreeNode, number][] = [];
        for (const [node, c] of q) {
            if (!valuesByCol.has(c)) {
                valuesByCol.set(c, new Map());
            }
            const values = valuesByCol.get(c)!;
            if (!values.has(r)) {
                values.set(r, []);
            }
            values.get(r)!.push(node.val);
            if (node.left != null) {
                newQ.push([node.left, c - 1]);
            }
            if (node.right != null) {
                newQ.push([node.right, c + 1]);
            }
        }
        q = newQ;
        r++;
    }
    return [...valuesByCol.entries()]
        .sort(([a], [b]) => a - b)
        .map(([_, valuesByRow]) => {
            const values: number[] = [];
            for (const [_, vals] of valuesByRow) {
                vals.sort((a, b) => a - b);
                for (const val of vals) {
                    values.push(val);
                }
            }
            return values;
        });
}
