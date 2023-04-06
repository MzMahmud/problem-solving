const ON_EDGE = -1, NOT_ON_EDGE = 1, LAND = 0, VISITED_LAND = 2;

function closedIsland(grid: number[][]): number {
    const n = grid.length, m = grid[0].length;
    let nClosedIslands = 0;
    for(let i = 1; i < (n-1); i++) {
        for(let j = 1; j < (m-1); j++) {
            if(grid[i][j] !== LAND) {
                continue;
            }
            if(dfs(i, j, grid) === NOT_ON_EDGE) {
                nClosedIslands++;
            }
        }
    }
    return nClosedIslands;
}

function dfs(i: number, j: number, grid: number[][]) {
    const n = grid.length, m = grid[0].length;
    if(i < 0 || i >= n || j < 0 || j >= m) {
        return ON_EDGE;
    }
    if(grid[i][j] !== 0) {
        return NOT_ON_EDGE;
    }
    grid[i][j] = VISITED_LAND;
    const neighbourStates = [
        dfs(i - 1, j, grid), 
        dfs(i ,j + 1, grid), 
        dfs(i + 1, j, grid), 
        dfs(i, j - 1, grid)
    ];
    return neighbourStates.some(state => state === ON_EDGE) ? ON_EDGE : NOT_ON_EDGE;
}
