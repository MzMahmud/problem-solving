function findFrequentTreeSum(root: TreeNode | null): number[] {
    const freqencies = new Map<number, number>();
    let maxFreq = 0;
    function dfs(root: TreeNode | null): number {
        if (root === null) {
            return 0;
        }
        const subTreeSum = dfs(root.left) + root.val + dfs(root.right);
        freqencies.set(subTreeSum, (freqencies.get(subTreeSum) ?? 0) + 1);
        maxFreq = Math.max(maxFreq, freqencies.get(subTreeSum) as number);
        return subTreeSum;
    }
    dfs(root);
    const maxFreqItems: number[] = [];
    for (const [item, freq] of freqencies) {
        if (freq == maxFreq) {
            maxFreqItems.push(item);
        }
    }
    return maxFreqItems;
}
