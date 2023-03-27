function minPathSum(grid: number[][]): number {
    const m = grid.length, n = grid[0].length;
    for (let i = m - 1; i >= 0; i--) {
        for (let j = n - 1; j >= 0; j--) {
            const noRight = j == (n - 1), noDown = i == (m - 1);
            if (noRight && noDown) {
                continue;
            }
            if (noRight) {
                grid[i][j] += grid[i + 1][j];
            } else if (noDown) {
                grid[i][j] += grid[i][j + 1];
            } else {
                grid[i][j] += Math.min(grid[i][j + 1], grid[i + 1][j]);
            }
        }
    }
    return grid[0][0];
}
