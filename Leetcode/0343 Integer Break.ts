function integerBreak(n: number): number {
    const cache = [new Array<number>(n + 1).fill(-1), new Array<number>(n + 1).fill(-1)];
    function dfs(n: number, isSingleAllowed: number) {
        if (n < 1) return 0;
        if (n === 1) return 1;
        if (cache[isSingleAllowed][n] !== -1) {
            return cache[isSingleAllowed][n];
        }
        let maxProd = 0;
        for (let i = 1; i < n; i++) {
            maxProd = Math.max(maxProd, i * dfs(n - i, 1));
        }
        if (isSingleAllowed) maxProd = Math.max(n, maxProd);
        cache[isSingleAllowed][n] = maxProd;
        return maxProd;
    }
    return dfs(n, 0);
}
