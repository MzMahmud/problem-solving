class Solution {
    private static final int[][] DIRS = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0},
    };

    public int[][] spiralMatrix(int m, int n, ListNode head) {
        int[][] matrix = new int[m][n];
        for(int i = 0;i < m; ++i) {
            Arrays.fill(matrix[i], -1);
        }
        
        int elements = m * n, number = 1;
        int i = 0, j = 0, dirIndex = 0;
        while (head != null && number <= elements) {
            matrix[i][j] = head.val;
            int nextI = i + DIRS[dirIndex][0], nextJ = j + DIRS[dirIndex][1];
            boolean isInvalid =
                nextI < 0 || nextI >= m 
                || nextJ < 0 || nextJ >= n 
                || matrix[nextI][nextJ] != -1;
            if (isInvalid) {
                dirIndex = (dirIndex + 1) % DIRS.length;
            }
            i += DIRS[dirIndex][0];
            j += DIRS[dirIndex][1];
            ++number;
            head = head.next;
        }
        return matrix;
    }
}