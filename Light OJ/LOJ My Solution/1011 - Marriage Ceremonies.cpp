/*
    LOJ 1011 - Marriage Ceremonies
    Author: Moaz Mahmud
    Date  : 05 Apr,2020

    My Solution:
        Bitmask DP
    END :D :D
*/

#include <climits>
#include <cstdio>
#include <unordered_map>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix2d;

inline bool check_bit(int mask, int i) { return mask & (1 << i); }

inline int set_bit(int mask, int i) { return mask | (1 << i); }

inline int clear_bit(int mask, int i) { return mask & (~(1 << i)); }

unordered_map<int, int> dp;
int matrix_sum(const matrix2d &mat, int row = 0, int mask = 0) {

    int n_row = mat.size();
    if (mask == ((1 << n_row) - 1) || row == n_row)
        return 0;

    if (dp.find(mask) == dp.end()) {
        int ans = INT_MIN;
        for (int j = 0; j < mat[row].size(); j++) {
            if (check_bit(mask, j))
                continue;
            int take = mat[row][j] + matrix_sum(mat, row + 1, set_bit(mask, j));

            ans = max(ans, take);
        }
        dp[mask] = ans;
    }
    return dp[mask];
}

int main() {
    int T, cn = 1;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        matrix2d matrix(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &matrix[i][j]);
        dp.clear();
        printf("Case %d: %d\n", cn++, matrix_sum(matrix));
    }
    return 0;
}