/* Used bit mask dp to solve
 * https://projecteuler.net/problem=345
 */

#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> matrix2d;

inline bool check_bit(int mask, int i) { return mask & (1 << i);}

inline int set_bit(int mask, int i)    { return mask | (1 << i); }

inline bool clear_bit(int mask, int i) { return mask & (~(1 << i)); }


unordered_map<int, int> dp;
int matrix_sum(const matrix2d &mat, int row = 0,int mask = 0) {
    int n_row = mat.size();
    if (mask == ((1 << n_row) - 1) || row == n_row)
        return 0;

    if (dp.find(mask) == dp.end()) {
        int ans  = INT_MIN;
        int elem = -1;
        for (int j = 0; j < mat[row].size(); j++) {
            if (check_bit(mask, j))
                continue;
            int take = mat[row][j]
                       + matrix_sum(mat, row + 1,
                                    set_bit(mask, j));

            ans = max(ans, take);
        }
        dp[mask] = ans;
    }
    return dp[mask];
}

int main() {
    int n;
    cin >> n;
    matrix2d matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    cout << matrix_sum(matrix);
	// Answer: 13938

    return 0;
}

