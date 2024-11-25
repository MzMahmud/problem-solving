type Board = number[][];
const DONE_STATE = JSON.stringify([[1, 2, 3], [4, 5, 0]]);

function slidingPuzzle(board: Board): number {
    let q: Board[] = [board];
    const visited = new Set<string>();
    let nMoves = 0;
    while (q.length > 0) {
        const newQ: Board[] = [];
        for (const state of q) {
            const stateKey = JSON.stringify(state);
            if (stateKey === DONE_STATE) return nMoves;
            visited.add(stateKey);
            const { zero, swaps } = getValidMoves(state);
            for (const move of swaps) {
                const newBoard = JSON.parse(stateKey) as Board;
                const temp = newBoard[zero[0]][zero[1]];
                newBoard[zero[0]][zero[1]] = newBoard[move[0]][move[1]];
                newBoard[move[0]][move[1]] = temp;
                const newBoardKey = JSON.stringify(newBoard);
                if (visited.has(newBoardKey)) continue;
                newQ.push(newBoard);
            }
        }
        q = newQ;
        nMoves++;
    }
    return -1;
}

type Moves = { zero: [number, number], swaps: [number, number][] };

function getValidMoves(board: number[][]): Moves {
    let zi = -1, zj = -1;
    const n = board.length, m = board[0].length;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (board[i][j] === 0) {
                zi = i;
                zj = j;
                break;
            }
        }
    }
    const moves: Moves = { zero: [zi, zj], swaps: [] };
    if (zi === -1 || zj === -1) return moves;
    const del = [[-1, 0], [0, 1], [1, 0], [0, -1]];
    for (const [di, dj] of del) {
        const ni = zi + di, nj = zj + dj;
        if (0 <= ni && ni < n && 0 <= nj && nj < m) {
            moves.swaps.push([ni, nj]);
        }
    }
    return moves;
}
