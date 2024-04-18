function smallestFromLeaf(root: TreeNode | null): string {
    let minString: number[] = [];
    const currString: number[] = [];
    function dfs(root: TreeNode | null) {
        if (root === null) {
            return;
        }
        currString.push(root.val);
        if (root.left === root.right) {
            if (minString.length == 0 || isReverseLess(currString, minString)) {
                minString = [...currString];
            }
        }
        dfs(root.left);
        dfs(root.right);
        currString.pop();
    }
    dfs(root);
    return minString == null ? "" : minString.reduceRight((s, c) => s + String.fromCharCode(97 + c), "");
}

function isReverseLess(a: number[], b: number[]) {
    for (let i = a.length - 1, j = b.length - 1; i >= 0 && j >= 0; i--, j--) {
        if (a[i] !== b[j]) {
            return a[i] < b[j];
        }
    }
    return a.length < b.length;
}
