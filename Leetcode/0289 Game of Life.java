class Solution {
    // use 0-th bit to store previous value
    //     1-st bit to store next value
    public void gameOfLife(int[][] board) {
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                int neighbourCount = getNeighbourCount(i, j, board);
                int newValue = board[i][j];
                if (board[i][j] == 1 && (neighbourCount < 2 || neighbourCount > 3)) {
                    newValue = 0;
                } else if (board[i][j] == 0 && neighbourCount == 3) {
                    newValue = 1;
                }
                recordNewValue(newValue, i, j, board);
            }
        }
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                board[i][j] = getNextValue(board[i][j]);
            }
        }
    }

    private void recordNewValue(int newValue, int i, int j, int[][] board) {
        board[i][j] = (newValue << 1) | board[i][j];
    }

    private int getNeighbourCount(int i, int j, int[][] board) {
        int count = 0;
        for (int di = -1; di <= 1; ++di) {
            for (int dj = -1; dj <= 1; ++dj) {
                int neighbourI = i + di, neighbourJ = j + dj;
                boolean isIndexInvalid =
                        neighbourI < 0 || neighbourJ < 0
                        || neighbourI >= board.length || neighbourJ >= board[0].length
                        || (neighbourI == i && neighbourJ == j);
                if (isIndexInvalid) {
                    continue;
                }
                count += getPrevValue(board[neighbourI][neighbourJ]);
            }
        }
        return count;
    }

    private int getPrevValue(int prevNext) {
        return prevNext & 1;
    }

    private int getNextValue(int prevNext) {
        return (prevNext >>> 1) & 1;
    }
}