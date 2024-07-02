function projectionArea(grid: number[][]): number {
    const n = grid.length;
    let area = 0;
    for (let row = 0; row < n; row++) {
        let yzMax = 0, zxMax = 0;
        for (let col = 0; col < n; col++) {
            yzMax = Math.max(yzMax, grid[row][col]);
            zxMax = Math.max(zxMax, grid[col][row]);
            if (grid[row][col]) area++;
        }
        area += yzMax + zxMax;
    }
    return area;
}
