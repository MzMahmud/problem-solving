class Solution:
    def construct(self, grid):
        return get_quad_tree_root(0, 0, len(grid), grid)


def get_quad_tree_root(row, col, n, grid):
    do_subdivide = False
    for i in range(row, row + n):
        for j in range(col, col + n):
            if grid[i][j] != grid[row][col]:
                do_subdivide = True

    if do_subdivide:
        value, isLeaf = None, False
        half_n = n // 2
        top_left = get_quad_tree_root(row, col, half_n, grid)
        top_right = get_quad_tree_root(row, col + half_n, half_n, grid)
        bottom_left = get_quad_tree_root(row + half_n, col, half_n, grid)
        bottom_right = get_quad_tree_root(row + half_n, col + half_n, half_n, grid)
    else:
        value, isLeaf = grid[row][col] == 1, True
        top_left, top_right, bottom_left, bottom_right = None, None, None, None

    return Node(value, isLeaf, top_left, top_right, bottom_left, bottom_right)
