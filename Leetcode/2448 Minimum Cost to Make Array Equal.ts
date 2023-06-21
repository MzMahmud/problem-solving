function minCost(nums: number[], costs: number[]) {
    const n = nums.length;
    const numCosts =
        Array.from({ length: n }, (_, i) => [nums[i], costs[i]])
             .sort((a, b) => a[0] - b[0]);

    const prefixCost = new Array<number>(n).fill(0);
    prefixCost[0] = numCosts[0][1];
    for (let i = 1; i < n; i++) {
        prefixCost[i] = numCosts[i][1] + prefixCost[i - 1];
    }
    let totalCost = 0;
    for (let i = 1; i < n; i++) {
        totalCost += numCosts[i][1] * (numCosts[i][0] - numCosts[0][0]);
    }
    let minCost = totalCost;
    for (let i = 1; i < n; ++i) {
        const gap = numCosts[i][0] - numCosts[i - 1][0];
        totalCost += prefixCost[i - 1] * gap;
        totalCost -= (prefixCost[n - 1] - prefixCost[i - 1]) * gap;
        minCost = Math.min(minCost, totalCost);
    }
    return minCost;
}
