/*
    LOJ 1151 - Snakes and Ladders
    Author: Moaz Mahmud
    Date  : 29 Dec,2019

    My Solution:
        E[i]   = Expected number of move to 100.
        E[100] = 0.

        Now,E[1]  = (1+E[2])/6 + (1+E[3])/6 + ... + (1+E[7])/6
        So, 6E[1] = 6+E[2]+E[3]+...+E[7].
        Also consider case for E[95] to E[99].
        A 3 is 98 would loop back to 98.
        For 98,2E[98] - E[99] - E[100] = 6

        This could have been solved easily with dp
        But the problem arises when Snakes and Ladders arrives.
        Suppose there is a ladder from 2 to 8.
        Then being in 2 is same as in 8.
        Similarly a snake from 9 to 3 being E[9] = E[3].

        Now this can't be solved by simple dp.
        Here comes Gauss-Jordan.
        Consider 100 variables for E[0],E[1],...,E[100].

        In normal case,
        6*E[i] - E[i+1] - E[i+2] - ... - E[i+6] = 6

        For a snake or ladder from a to b
        E[a] - E[b] = 0

        now solve with Gauss-Jordan.
        I must admit I did not write the Gauss() function.
        Rest of the solution is mine!

    END :D :D
*/

#include <cstdio>
#include <cmath>

using namespace std;

#define N 100 // Number of unknowns
#define EPS 1e-8

double Gauss(double mat[N][N + 1], int n, int m){
    int col, row, mxr;
    for (col = row = 1; row <= n && col <= m; row++, col++) {
        mxr = row;
        for (int i = row + 1; i <= n; i++)
            if (fabs(mat[i - 1][col - 1]) > fabs(mat[mxr - 1][col - 1]))
                mxr = i;
        if (fabs(mat[row - 1][col - 1]) < EPS) {
            row--;
            continue;
        }
        for (int i = 1; i <= n; i++) {
            if (i != row && fabs(mat[i - 1][col - 1]) > EPS) {
                for (int j = m; j >= col; j--)
                    mat[i - 1][j - 1] -= mat[row - 1][j - 1] / mat[row - 1][col - 1] * mat[i - 1][col - 1];
            }
        }
    }
    row--;
    for (int i = row; i >= 1; i--) {
        for (int j = i + 1; j <= row; j++)
            mat[i - 1][m - 1] -= mat[j - 1][m - 1] * mat[i - 1][j - 1];
        mat[i - 1][m - 1] /= mat[i - 1][i - 1];
    }
    return mat[0][m - 1];
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int T, cn = 1;
    scanf("%d", &T);
    while (T--) {
        int n; //number of snakes and ladders
        scanf("%d", &n);

        double mat[N][N + 1] = {}; // N = total cells = 100

        //E[100] = 0
        mat[N - 1][N - 1] = 1.0;
        mat[N - 1][N] = 0.0;

        // Forms the matrix
        for (int i = 1; i < N; i++) {
            int diff = N - i;
            mat[i - 1][i - 1] = (diff < 6) ? diff : 6;

            for (int j = i + 1; (j <= (i + 6)) && (j <= N); j++) {
                mat[i - 1][j - 1] = -1.0;
            }

            mat[i - 1][N] = 6.0;
        }

        for (int i = 0; i < n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            for (int i = 1; i <= (N + 1); i++) {
                mat[a - 1][i - 1] = .0;
            }
            mat[a - 1][a - 1] = 1.0; //
            mat[a - 1][b - 1] = -1.0;
        }

        double ans = Gauss(mat, N, N + 1);
        printf("Case %d: %.10lf\n", cn++, ans);
    }
    return 0;
}
