function pseudoPalindromicPaths (root: TreeNode | null): number {
    const digitOccurrences: number[] = Array.from({length: 10}, () => 0);
    let paths = 0;
    function dfs(root: TreeNode | null) {
        if (root == null) return;
        digitOccurrences[root.val]++;
        if (root.left == root.right) {
            paths += +isPseudoPalindromic(digitOccurrences);
        }
        dfs(root.left);
        dfs(root.right);
        digitOccurrences[root.val]--;
    }
    dfs(root);
    return paths;
}

function isPseudoPalindromic(digitOccurrences: number[]) {
    const oddCount = digitOccurrences.reduce((s, n) => s + n % 2, 0);
    return oddCount < 2;
}
