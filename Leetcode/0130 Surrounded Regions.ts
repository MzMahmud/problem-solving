function solve(board: string[][]): void {
    const n = board.length, m = board[0].length;
    for (let i = 0; i < n; i++) {
        if(board[i][0] === 'O') {
            dfs(i, 0, board);
        }
        if(board[i][m - 1] === 'O') {
            dfs(i, m - 1, board);
        }
    }
    for (let j = 0; j < m; j++) {
        if(board[0][j] === 'O') {
            dfs(0, j, board);
        }
        if(board[n - 1][j] === 'O') {
            dfs(n - 1, j, board);
        }
    }
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (board[i][j] === '.') {
                board[i][j] = 'O';
            } else if (board[i][j] === 'O') {
                board[i][j] = 'X';
            }
        }
    }
}

function dfs(i: number, j: number, board: string[][]) {
    const n = board.length, m = board[0].length;
    if (i < 0 || i === n || j < 0 || j === m || board[i][j] !== 'O') {
        return;
    }
    board[i][j] = '.';
    dfs(i - 1, j, board);
    dfs(i, j + 1, board);
    dfs(i + 1, j, board);
    dfs(i, j - 1, board);
}  
