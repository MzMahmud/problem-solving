class Solution {
    private static final int[][] dirs = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0},
    };

    public int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];
        int number = 1, elements = n * n, dirIndex = 0;
        int i = 0, j = 0;
        while (number <= elements) {
            matrix[i][j] = number;
            int nextI = i + dirs[dirIndex][0], nextJ = j + dirs[dirIndex][1];
            boolean isInvalid = 
                nextI < 0 || nextI >= n 
                || nextJ < 0 || nextJ >= n 
                || (matrix[nextI][nextJ] != 0 && matrix[nextI][nextJ] < number);
            if (isInvalid) {
                dirIndex = (dirIndex + 1) % dirs.length;
            }
            i += dirs[dirIndex][0];
            j += dirs[dirIndex][1];
            ++number;
        }
        return matrix;
    }
}