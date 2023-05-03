function regionsBySlashes(grid: string[]): number {
    const n = grid.length;
    const visited = new Array<boolean[][]>(n);
    for (let i = 0; i < n; i++) {
        visited[i] = new Array<boolean[]>(n);
        for (let j = 0; j < n; j++) {
            visited[i][j] = new Array<boolean>(4).fill(false);
        }
    }
    function dfs(i: number, j: number, dir: number) {
        if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j][dir]) {
            return;
        }
        visited[i][j][dir] = true;
        if (dir === 0){ 
            dfs(i - 1, j, 2);
            if (grid[i][j] !== '/') {
                dfs(i, j, 1);
            }
            if (grid[i][j] !== '\\') {
                dfs(i, j, 3);
            }
        } else if (dir === 1) {
            dfs(i, j + 1, 3);
            if (grid[i][j] !== '/') {
                dfs(i, j, 0);
            }
            if (grid[i][j] !== '\\') {
                dfs(i, j, 2);
            }
        } else if (dir === 2) {
            dfs(i + 1, j, 0);
            if (grid[i][j] !== '/') {
                dfs(i, j, 3);
            }
            if (grid[i][j] !== '\\') {
                dfs(i, j, 1);
            }
        } else if (dir === 3) {
            dfs(i, j - 1, 1);
            if (grid[i][j] !== '/') {
                dfs(i, j, 2);
            }
            if (grid[i][j] !== '\\') {
                dfs(i, j, 0);
            }
        }
    }
    let nRegions = 0;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            for (let dir = 0; dir < 4; dir++) {
                if (!visited[i][j][dir]) {
                    dfs(i, j, dir);
                    nRegions++;
                }
            }
        }
    }
    return nRegions;
}
