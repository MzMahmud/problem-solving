function surfaceArea(grid: number[][]): number {
    const n = grid.length;
    let area = 0;
    for (let i = 0; i < n; i++) {
        area += grid[i][n - 1] + grid[n - 1][i];
        for (let j = 0; j < n; j++) {
            area += Math.abs(grid[i][j] - (j == 0 ? 0 : grid[i][j - 1]));
            area += Math.abs(grid[i][j] - (i == 0 ? 0 : grid[i - 1][j]));
            if (grid[i][j]) area += 2;
        }
    }
    return area;
}
