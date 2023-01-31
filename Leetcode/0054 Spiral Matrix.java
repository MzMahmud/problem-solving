class Solution {
    private static final int[][] DIRS = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0},
    };

    private static final int VISITED = 101;

    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> spiral = new ArrayList<>();
        int n = matrix.length, m = matrix[0].length, number = 1;
        int elements = n * m, dirIndex = 0;
        int i = 0, j = 0;
        while (number <= elements) {
            spiral.add(matrix[i][j]);
            matrix[i][j] = VISITED;
            int nextI = i + DIRS[dirIndex][0], nextJ = j + DIRS[dirIndex][1];
            boolean isInvalid = 
                nextI < 0 || nextI >= n 
                || nextJ < 0 || nextJ >= m 
                || matrix[nextI][nextJ] == VISITED;
            if (isInvalid) {
                dirIndex = (dirIndex + 1) % DIRS.length;
            }
            i += DIRS[dirIndex][0];
            j += DIRS[dirIndex][1];
            ++number;
        }
        return spiral;
    }
}