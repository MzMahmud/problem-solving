class Solution:
    def numRookCaptures(self, board):
        rook_i, rook_j = get_rook_pos(board)
        captures = map(
            lambda direction: find_capture(rook_i, rook_j, board, direction),
            DIRECTIONS
        )
        return sum(captures)


DIRECTIONS = ((0, 1), (0, -1), (1, 0), (-1, 0))


def find_capture(i, j, board, direction):
    n = len(board)
    i, j = i + direction[0], j + direction[1]
    while 0 <= i < n and 0 <= j < n:
        if board[i][j] != '.':
            return 1 if board[i][j] == 'p' else 0
        i, j = i + direction[0], j + direction[1]
    return 0


def get_rook_pos(board):
    for i, row in enumerate(board):
        for j, cell in enumerate(row):
            if cell == 'R':
                return i, j
