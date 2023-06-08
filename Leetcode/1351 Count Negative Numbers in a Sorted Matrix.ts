function countNegatives(grid: number[][]): number {
    const n = grid[0].length;
    let negatives = 0, lastRowNegIndex = n - 1;
    for (const row of grid) {
        while (lastRowNegIndex >= 0 && row[lastRowNegIndex] < 0) {
            lastRowNegIndex--;
        }
        negatives += n - (lastRowNegIndex + 1);
    }
    return negatives;
}
