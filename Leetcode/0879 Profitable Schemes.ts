const MOD = 1_000_000_007;

function profitableSchemes(n: number, minProfit: number, groups: number[], profits: number[]): number {
    const cache = new Array<number[][]>(profits.length);
    for (let i = 0; i < cache.length; i++) {
        cache[i] = new Array<number[]>(n + 1);
        for (let j = 0; j < cache[i].length; j++) {
            cache[i][j] = new Array<number>(minProfit + 1).fill(-1);
        }
    }
    function ways(i: number, groupSize: number, profit: number) {
        if (i === profits.length) {
            return profit >= minProfit ? 1 : 0;
        }
        if (cache[i][groupSize][profit] !== -1) {
            return cache[i][groupSize][profit];
        }
        let totalWays = ways(i + 1, groupSize, profit);
        if (groupSize + groups[i] <= n) {
            totalWays += ways(i + 1, groupSize + groups[i], Math.min(minProfit, profit + profits[i]));
        }
        return cache[i][groupSize][profit] = totalWays % MOD;
    }
    return ways(0, 0, 0);
}
