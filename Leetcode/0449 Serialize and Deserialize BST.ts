function serialize(root: TreeNode | null): string {
    const values = preorder(root, []);
    return values.join(",");
}

function deserialize(data: string): TreeNode | null {
    if (data === '') {
        return null;
    }
    const preorderVals = data.split(","); 
    let i = 0;
    function constructBst(lo: number, hi: number): TreeNode | null {
        let value = 0;
        const reachedEnd = i >= preorderVals.length || (value = Number(preorderVals[i])) <= lo || value > hi;
        if (reachedEnd) {
            return null;
        }
        const root = new TreeNode(value);
        i++;
        root.left = constructBst(lo, root.val);
        root.right = constructBst(root.val, hi);
        return root;
    }
    return constructBst(-Infinity, Infinity);
}

function preorder(root: TreeNode | null, preorderValues: number[]) {
    if (root !== null) {
        preorderValues.push(root.val);
        preorder(root.left, preorderValues);
        preorder(root.right, preorderValues);
    }
    return preorderValues;
}
