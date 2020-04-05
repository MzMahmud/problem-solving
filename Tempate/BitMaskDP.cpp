/* Used bit mask dp to solve
 * https://projecteuler.net/problem=345
 */

#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> matrix2d;

inline bool check_bit(int mask, int i) { return mask & (1 << i); }

inline int set_bit(int mask, int i) { return mask | (1 << i); }

inline bool clear_bit(int mask, int i) { return mask & (~(1 << i)); }

void print(const matrix2d &mat) {
    for (auto row : mat)
        for (auto elem : row)
            cout << elem << " ";
    cout << "\n";
}

void show_bit(int mask) {
    for (int i = 31; i >= 0; i--)
        cout << (check_bit(mask, i) ? '1' : '0') << (i % 4 == 0 ? " " : "");
    cout << endl;
}

unordered_map<int, int> dp;
int matrix_sum(const matrix2d &mat, int row = 0, int mask = 0) {

    int n_row = mat.size();
    if (mask == ((1 << n_row) - 1) || row == n_row)
        return 0;

    if (dp.find(mask) == dp.end()) {
        int ans  = INT_MIN;
        int elem = -1;
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
    int n;
    scanf("%d", &n);
    matrix2d matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    dp.clear();

    printf("Case %d: %d\n", matrix_sum(matrix));
    return 0;
}

/*
Some Input:

15
  7  53 183 439 863 497 383 563  79 973 287  63 343 169 583
627 343 773 959 943 767 473 103 699 303 957 703 583 639 913
447 283 463  29  23 487 463 993 119 883 327 493 423 159 743
217 623   3 399 853 407 103 983  89 463 290 516 212 462 350
960 376 682 962 300 780 486 502 912 800 250 346 172 812 350
870 456 192 162 593 473 915  45 989 873 823 965 425 329 803
973 965 905 919 133 673 665 235 509 613 673 815 165 992 326
322 148 972 962 286 255 941 541 265 323 925 281 601  95 973
445 721  11 525 473  65 511 164 138 672  18 428 154 448 848
414 456 310 312 798 104 566 520 302 248 694 976 430 392 198
184 829 373 181 631 101 969 613 840 740 778 458 284 760 390
821 461 843 513  17 901 711 993 293 157 274  94 192 156 574
 34 124   4 878 450 476 712 914 838 669 875 299 823 329 699
815 559 813 459 522 788 168 586 966 232 308 833 251 631 107
813 883 451 509 615  77 281 613 459 205 380 274 302  35 805
Answer: 13938


5
  7  53 183 439 863
497 383 563  79 973
287  63 343 169 583
627 343 773 959 943
767 473 103 699 303
Answer: 3315

*/