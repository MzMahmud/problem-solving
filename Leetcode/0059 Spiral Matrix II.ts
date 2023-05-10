const DIRS = [[0, 1], [1, 0], [0, -1], [-1, 0]];
const EMPTY = -1;

function generateMatrix(n: number): number[][] {
    const matrix = new Array<number[]>(n);
    for (let i = 0; i < n; i++) {
        matrix[i] = new Array<number>(n).fill(EMPTY);
    }
    const nSquare = n * n;
    let i = 0, j = 0, dirIndex = 0, num = 1;
    while (num <= nSquare) {
        matrix[i][j] = num++;
        const nextI = i + DIRS[dirIndex][0], nextJ = j + DIRS[dirIndex][1];
        const changeDir = nextI < 0 || nextI >= n || nextJ < 0 || nextJ >= n || matrix[nextI][nextJ] !== EMPTY;
        if (changeDir) {
            dirIndex = (dirIndex + 1) % DIRS.length;
        }
        i += DIRS[dirIndex][0];
        j += DIRS[dirIndex][1];
    }
    return matrix;
}
