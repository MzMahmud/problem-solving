function diagonalSum(mat: number[][]): number {
    const n = mat.length;
    let diagSum = 0;
    for (let i = 0; i < n; i++) {
        diagSum += mat[i][i] + mat[i][n - 1 - i];
    }
    const halfN = Math.floor(n / 2);
    if (n % 2 != 0) {
        diagSum -= mat[halfN][halfN];
    }
    return diagSum;
}
