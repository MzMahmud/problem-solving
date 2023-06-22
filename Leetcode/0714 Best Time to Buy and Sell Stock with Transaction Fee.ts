function maxProfit(prices: number[], fee: number): number {
    const cache = new Map<string, number>();
    function maximumProfit(i: number, bought: boolean): number {
        if (i === prices.length) {
            return 0;
        }
        const key = `${i},${bought ? 1 : 0}`;
        if (cache.has(key)) {
            return cache.get(key) as number;
        }
        let profit = -Infinity;
        if (bought) {
            profit = Math.max(
                maximumProfit(i + 1, bought),
                prices[i] - fee + maximumProfit(i + 1, false)
            );
        } else {
            profit = Math.max(
                maximumProfit(i + 1, bought),
                maximumProfit(i + 1, true) - prices[i]
            );
        }
        cache.set(key, profit);
        return profit;
    }
    return maximumProfit(0, false);
}
