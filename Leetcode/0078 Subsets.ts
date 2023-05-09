function subsets(nums: number[]): number[][] {
    const allSubsets: number[][] = [];
    function dfs(i: number, subset: number[]) {
        if (i === nums.length) {
            allSubsets.push(subset.map(n => n));
            return;
        }
        dfs(i + 1, subset);
        subset.push(nums[i]);
        dfs(i + 1, subset);
        subset.pop();
    }
    dfs(0, []);
    return allSubsets;
}
