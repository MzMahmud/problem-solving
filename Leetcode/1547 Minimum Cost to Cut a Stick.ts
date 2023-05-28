function minCost(n: number, cuts: number[]): number {
    const cache = new Map<string, number>();
    function dfs(left: number, right: number): number {
        const key = `${left}-${right}`;
        if (cache.has(key)) {
            return cache.get(key) as number;
        }
        let minCost = Infinity;
        for (const cut of cuts) {
            if (left < cut && cut < right) {
                const cost = right - left + dfs(left, cut) + dfs(cut, right);
                minCost = Math.min(minCost, cost);
            }
        }
        minCost = minCost === Infinity ? 0 : minCost;
        cache.set(key, minCost);
        return minCost;
    }
    return dfs(0, n);
}
