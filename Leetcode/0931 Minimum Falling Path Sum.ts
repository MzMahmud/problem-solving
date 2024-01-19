function minFallingPathSum(a: number[][]): number {
    const n = a.length;
    for (let i = n - 2; i >= 0; i--) {
        for (let j = 0; j < n; j++) {
            a[i][j] += Math.min(
                a[i + 1][Math.max(0, j - 1)],
                a[i + 1][j],
                a[i + 1][Math.min(n - 1, j + 1)]
            );
        }
    }
    return Math.min(...a[0]);
}
