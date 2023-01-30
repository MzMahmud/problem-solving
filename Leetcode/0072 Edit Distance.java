class Solution {
    public int minDistance(String from, String to) {
        int m = from.length(), n = to.length();
        int[][] editDistance = new int[m + 1][n + 1];
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0) {
                    editDistance[i][j] = j;
                } else if (j == 0) {
                    editDistance[i][j] = i;
                } else if (from.charAt(i - 1) == to.charAt(j - 1)) {
                    editDistance[i][j] = editDistance[i - 1][j - 1];
                } else {
                    editDistance[i][j] = 1 + min(
                            editDistance[i][j - 1],
                            editDistance[i - 1][j],
                            editDistance[i - 1][j - 1]
                    );
                }
            }
        }
        return editDistance[m][n];
    }

    private int min(int a, int b, int c) {
        return Math.min(a, Math.min(b, c));
    }
}