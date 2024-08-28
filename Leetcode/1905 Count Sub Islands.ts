function countSubIslands(grid1: number[][], grid2: number[][]) {
    const m = grid1.length, n = grid1[0].length;
    function dfs(i: number, j: number): number {
        if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] != 1) {
            return 1;
        }
        grid2[i][j] = 0;
        return dfs(i - 1, j)
            & dfs(i, j + 1)
            & dfs(i + 1, j)
            & dfs(i, j - 1)
            & grid1[i][j];
    }
    let subIslands = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid2[i][j] == 1) {
                subIslands += dfs(i, j);
            }
        }
    }
    return subIslands;
}
