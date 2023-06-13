function equalPairs(grid: number[][]): number {
    const rowCount = new Map<string, number>();
    for (const row of grid) {
        const key = `${row}`;
        rowCount.set(key, (rowCount.get(key) ?? 0) + 1);
    }
    const n = grid.length;
    let pairs = 0;
    for (let j = 0; j < n; j++) {
        const column = new Array<number>(n);
        for (let i = 0; i < n; i++) {
            column[i] = grid[i][j];
        }
        pairs += (rowCount.get(`${column}`) ?? 0);
    }
    return pairs;
}
