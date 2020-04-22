/*
    LOJ 1397 - Sudoku Solver
    Author: Moaz Mahmud
    Date  : 22 Apr,2020

    My Solution:
        classical backtracking algorithm
        improvement:
            each position find the spot with least numeber of options

    END :D :D
*/

#include <cstdio>

char board[9][10];

bool is_valid(int i, int j, char val) {
    // checks same row and columns
    for (int k = 0; k < 9; ++k)
        if (board[i][k] == val or board[k][j] == val)
            return false;

    // chack 3x3 box
    // (li,lj) top left corner of the belonging box
    int li = (i / 3) * 3, lj = (j / 3) * 3;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (board[li + i][lj + j] == val)
                return false;
    return true;
}

// finds spot with least number of options
bool find_spot(int &row, int &col) {
    int best = 10; // INF = MAX VALUE = anything greater than 9
    row = col = -1;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == '.') {
                int cur = 0;
                for (char val = '1'; val <= '9'; ++val)
                    if (is_valid(i, j, val))
                        ++cur;
                if (cur < best) {
                    best = cur;
                    row = i, col = j;
                }
            }
        }
    }
    return row >= 0;
}

bool solve_sudoku() {
    int row, col;
    // if no spot found to fill means solved
    if (!find_spot(row, col))
        return true;

    for (char val = '1'; val <= '9'; ++val) {
        if (is_valid(row, col, val)) {

            board[row][col] = val;
            if (solve_sudoku())
                return true;

            // backtrack
            board[row][col] = '.';
        }
    }
    return false;
}

int main() {
    int T, cn = 1;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 9; ++i)
            scanf("%s", &board[i]);

        printf("Case %d:\n", cn++);
        solve_sudoku();
        for (int i = 0; i < 9; ++i)
            printf("%s\n", board[i]);
    }
    return 0;
}