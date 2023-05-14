function maxScore(nums: number[]): number {
    const cacheSize = 1 << nums.length;
    const cache = new Array<number>(cacheSize).fill(-1);
    function dfs(n: number, mask: number): number {
        if (2 * n === nums.length) {
            return 0;
        }
        if (cache[mask] !== -1) {
            return cache[mask];
        }
        let maxValue = 0;
        for (let i = 0; i < nums.length; i++) {
            for (let j = i + 1; j < nums.length; j++) {
                const indexTaken = (mask & (1 << i)) || (mask & (1 << j));
                if (indexTaken) {
                    continue;
                }
                const newMask = mask | (1 << i) | (1 << j);
                const value = (n + 1) * gcd(nums[i], nums[j]) + dfs(n + 1, newMask);
                maxValue = Math.max(maxValue, value);
            }
        }
        return cache[mask] = maxValue;
    }
    return dfs(0, 0);
}

function gcd(a: number, b: number): number {
    return b === 0 ? a : gcd(b, a % b);
}
