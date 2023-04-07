class Solution:
    def numEnclaves(self, grid):
        n, m = len(grid), len(grid[0])
        for i in range(n):
            if grid[i][0] == 1:
                dfs(i, 0, grid)
            if grid[i][m-1] == 1:
                dfs(i, m-1, grid)
        for j in range(m):
            if grid[0][j] == 1:
                dfs(0, j, grid)
            if grid[n-1][j] == 1:
                dfs(n-1, j, grid)
        enclaves = 0
        for row in grid:
            for cell in row:
                if cell == 1:
                    enclaves += 1
        return enclaves


def dfs(i, j, grid):
    n, m = len(grid), len(grid[0])
    if i < 0 or i == n or j < 0 or j == m or grid[i][j] != 1:
        return
    grid[i][j] = -1
    dfs(i - 1, j, grid)
    dfs(i, j + 1, grid)
    dfs(i + 1, j, grid)
    dfs(i, j - 1, grid)
