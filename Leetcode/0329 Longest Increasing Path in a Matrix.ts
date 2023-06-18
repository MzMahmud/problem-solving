const DIRS = [[0, -1], [0, 1], [1, 0], [-1, 0]];

function longestIncreasingPath(matrix: number[][]): number {
    const n = matrix.length, m = matrix[0].length;
    const longestPathLens = new Array<number[]>(n);
    for (let i = 0; i < n; i++) {
        longestPathLens[i] = new Array<number>(m).fill(0);
    }
    function dfs(i: number, j: number): number {
        if (longestPathLens[i][j] !== 0) {
            return longestPathLens[i][j];
        }
        let longestPathLen = 1;
        for (const [di, dj] of DIRS) {
            const nextI = i + di, nextJ = j + dj;
            const isValidPath =
                0 <= nextI && nextI < n
                && 0 <= nextJ && nextJ < m
                && matrix[i][j] < matrix[nextI][nextJ];
            if (isValidPath) {
                longestPathLen = Math.max(longestPathLen, 1 + dfs(nextI, nextJ));
            }
        }
        return longestPathLens[i][j] = longestPathLen;
    }
    let maxLen = 0;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            maxLen = Math.max(maxLen, dfs(i, j));
        }
    }
    return maxLen;
}
