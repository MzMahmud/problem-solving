function numEnclaves(grid: number[][]): number {
    const n = grid.length, m = grid[0].length;
    let enclaves = 0
    for(let i = 1; i < n - 1; i++) {
        for(let j = 1; j < m - 1;j++) {
            if(grid[i][j] == 1) {
                enclaves += Math.max(0, dfs(i, j, grid))
            }
        }
    }
    return enclaves;
}

function dfs(i: number,j: number, grid: number[][]) {
    const n = grid.length, m = grid[0].length;
    // touched edge so this whole land mass is not valid
    if(i < 0 || i == n || j < 0 || j == m) {
        return -1; 
    }
    if(grid[i][j] != 1) {
        return 0;
    }
    grid[i][j] = -1;
    const neighbourCounts = [
        dfs(i - 1, j, grid), 
        dfs(i, j + 1, grid), 
        dfs(i + 1, j, grid), 
        dfs(i, j - 1, grid)
    ];
    let totalCount = 1;
    for(const neighbourCount of neighbourCounts) {
        // any neighbout is invalid the whole lang mass is invalid
        if(neighbourCount < 0) {
            return -1;
        }
        totalCount += neighbourCount;
    }
    return totalCount;
}
