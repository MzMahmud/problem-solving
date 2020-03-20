/*
    LOJ 1047 - Neighbor House
    Author: Moaz Mahmud
    Date  : 20 Mar,2020

    My Solution:
        Simple DP
    END :D :D
*/

#include <cstdio>

#define MAXN 21
#define NCOL 3
#define INF 2147483647
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int cost[MAXN][NCOL];
int dp[MAXN][NCOL];
int n;

int find_cost(int i, int i_col) {
    if (i == (n - 1))
        return dp[i][i_col] = cost[i][i_col];

    if (dp[i][i_col] < 0) {
        int min_cost = INF;
        for (int col = 0; col < NCOL; col++) {
            if (col == i_col)
                continue;
            min_cost = MIN(min_cost, find_cost(i + 1, col));
        }
        dp[i][i_col] = cost[i][i_col] + min_cost;
    }
    return dp[i][i_col];
}

int main() {
    int T, cn = 1;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            for (int col = 0; col < NCOL; col++) {
                scanf("%d", &cost[i][col]);
                dp[i][col] = -1;
            }
        }
        int ans = INF;
        for (int col = 0; col < NCOL; col++)
            ans = MIN(ans, find_cost(0, col));
        printf("Case %d: %d\n", cn++, ans);
    }
    return 0;
}