const DIRS = [[0, -1], [0, 1], [1, 0], [-1, 0]];
const MOD = 1_000_000_007;

function countPaths(grid: number[][]): number {
    const n = grid.length, m = grid[0].length;
    const nPaths = new Array<number[]>(n);
    for (let i = 0; i < n; i++) {
        nPaths[i] = new Array<number>(m).fill(0);
    }
    function dfs(i: number, j: number): number {
        if (nPaths[i][j] !== 0) {
            return nPaths[i][j];
        }
        let nPath = 1;
        for (const [di, dj] of DIRS) {
            const nextI = i + di, nextJ = j + dj;
            const isValidPath =
                0 <= nextI && nextI < n
                && 0 <= nextJ && nextJ < m
                && grid[i][j] < grid[nextI][nextJ];
            if (isValidPath) {
                nPath = (nPath + dfs(nextI, nextJ)) % MOD;
            }
        }
        return nPaths[i][j] = nPath;
    }
    let nTotalPath = 0;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            nTotalPath = (nTotalPath + dfs(i, j)) % MOD;
        }
    }
    return nTotalPath;
}
