class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean[][] rows = new boolean[9][9];
        boolean[][] cols = new boolean[9][9];
        boolean[][][] blocks = new boolean[3][3][9];

        for(int i = 0;i < board.length;++i) {
            for(int j = 0;j < board.length;++j) {    
                char ch = board[i][j];
                boolean isNotDigit = !('0' <= ch && ch <= '9');
                if(isNotDigit) {
                    continue;
                }
                int chatIndex = ch - '0' - 1, blockRow = i / 3, blockCol = j / 3;
                boolean hasDuplicate = rows[i][chatIndex] 
                                       || cols[j][chatIndex] 
                                       || blocks[blockRow][blockCol][chatIndex];
                if(hasDuplicate) {
                    return false;
                }
                rows[i][chatIndex] = true;
                cols[j][chatIndex] = true;
                blocks[blockRow][blockCol][chatIndex] = true;
            }
        }
        return true;
    }
}
