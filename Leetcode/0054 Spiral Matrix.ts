const DIRS = [[0, 1], [1, 0], [0, -1], [-1, 0]];
const VISITED = -101;

function spiralOrder(matrix: number[][]): number[] {
    const n = matrix.length, m = matrix[0].length, elems = n * m;
    const spiral: number[] = [];
    let i = 0, j = 0, dirIndex = 0;
    while (spiral.length < elems) {
        spiral.push(matrix[i][j]);
        matrix[i][j] = VISITED;
        const nextI = i + DIRS[dirIndex][0], nextJ = j + DIRS[dirIndex][1];
        const isInvalid = nextI < 0 || nextI >= n || nextJ < 0 || nextJ >= m || matrix[nextI][nextJ] === VISITED;
        if (isInvalid) {
            dirIndex = (dirIndex + 1) % DIRS.length;
        }
        i = i + DIRS[dirIndex][0];
        j = j + DIRS[dirIndex][1];
    }
    return spiral;
}
