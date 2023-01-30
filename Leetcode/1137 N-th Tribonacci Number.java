class Solution {
    // sliding window O(n) time, O(1) space
    public int tribonacci(int n) {
        if(n == 0) {
            return 0;
        }
        if(n < 3) {
            return 1;
        }
        int a = 0, b = 1, c = 1, d = 0;
        for(int k = 2;k < n; ++k) {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return d;
    }

    private static final int[][] baseCaseVector = {{1}, {1}, {0}};
    private static final int[][] transformationMatrix = {
            {1, 1, 1},
            {1, 0, 0},
            {0, 1, 0},
    };

    // matrix exponentiation O(m^3*log n) time, O(m) space where m = dimention of the matrix
    // in this problem m = 3
    public int tribonacciMatrixExponentiation(int n) {
        if (n < baseCaseVector.length) {
            return baseCaseVector[baseCaseVector.length - n - 1][0];
        }
        var matrix = fastPower(transformationMatrix, n - 2);
        var nThVector = multiply(matrix, baseCaseVector);
        return nThVector[0][0];
    }

    private int[][] identity(int n) {
        int[][] I = new int[n][n];
        for (int i = 0; i < n; ++i) {
            I[i][i] = 1;
        }
        return I;
    }

    private int[][] fastPower(int[][] a, int n) {
        if (n == 0) {
            return identity(a.length);
        }
        var half = fastPower(a, n / 2);
        var full = multiply(half, half);
        if (n % 2 == 1) {
            full = multiply(full, a);
        }
        return full;
    }

    private int[][] multiply(int[][] a, int[][] b) {
        if (a[0].length != b.length) {
            throw new IllegalArgumentException("can not multiply matrix with wrong dimension");
        }
        int m = a.length, n = b[0].length;
        int[][] res = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < b.length; ++k) {
                    res[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return res;
    }
}