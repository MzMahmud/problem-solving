VISITED_LAND = -1

class Solution:
    def closedIsland(self, grid):
        n, m = len(grid), len(grid[0])
        def dfs(i, j):
            if i < 0 or i == n or j < 0 or j == m:
                return 0
            if grid[i][j] != 0:
                return 1
            grid[i][j] = VISITED_LAND
            return min(dfs(i-1, j), dfs(i, j+1), dfs(i+1, j), dfs(i, j-1))
        
        n_closed = 0
        for i in range(1, n-1):
            for j in range(1, m-1):
                if grid[i][j] == 0:
                    n_closed += dfs(i, j)
        return n_closed
