function makeArrayIncreasing(arr1: number[], arr2: number[]) {
    arr2.sort((a, b) => a - b);
    const cache = new Map<string, number>();
    function dfs(i: number, prev: number): number {
        if (i === arr1.length) {
            return 0;
        }
        const key = `${i},${prev}`;
        if (cache.has(key)) {
            return cache.get(key) as number;
        }
        let cost = Infinity;
        if (arr1[i] > prev) {
            cost = dfs(i + 1, arr1[i]);
        }
        const j = firstGreaterIndex(prev, arr2);
        if (j < arr2.length) {
            cost = Math.min(cost, 1 + dfs(i + 1, arr2[j]));
        }
        cache.set(key, cost);
        return cost;
    }
    const minCost = dfs(0, -Infinity);
    return minCost === Infinity ? -1 : minCost;
}

function firstGreaterIndex(value: number, nums: number[]) {
    let lo = 0, hi = nums.length;
    while (lo < hi) {
        const mid = Math.floor((lo + hi) / 2);
        if (nums[mid] <= value) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    return lo;
}
