function maxUncrossedLines(a: number[], b: number[]): number {
    const cache = new Array<number[]>(a.length);
    for (let i = 0; i < cache.length; i++) {
        cache[i] = new Array<number>(b.length).fill(-1);
    }
    function dfs(i: number, j: number): number {
        if (i === a.length || j === b.length) {
            return 0;
        }
        if (cache[i][j] !== -1) {
            return cache[i][j];
        }
        if (a[i] === b[j]) {
            return cache[i][j] = 1 + dfs(i + 1, j + 1);
        }
        return cache[i][j] = Math.max(dfs(i + 1, j), dfs(i, j + 1));
    }
    return dfs(0, 0);
}
