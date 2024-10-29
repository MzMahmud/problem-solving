function maxMoves(grid: number[][]): number {
    const m = grid.length, n = grid[0].length;
    const cache = Array.from({ length: m }, () => Array.from({ length: n }, () => NaN));
    function dp(i: number, j: number): number {
        if (i < 0 || i >= m || j < 0 || j >= n) return 0;
        if (!isNaN(cache[i][j])) return cache[i][j];
        const nexts = [[i - 1, j + 1], [i, j + 1], [i + 1, j + 1]];
        let maxMove = 0;
        for (const [ni, nj] of nexts) {
            const num = grid[ni]?.[nj];
            if (num == null || num <= grid[i][j]) continue;
            maxMove = Math.max(maxMove, 1 + dp(ni, nj));
        }
        return cache[i][j] = maxMove;
    }
    let maxMove = 0;
    for (let i = 0; i < m; i++) {
        maxMove = Math.max(maxMove, dp(i, 0));
    }
    return maxMove;
}
