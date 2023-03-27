class Solution:
    def minPathSum(self, grid):
        m, n = len(grid), len(grid[0])

        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                no_right = j == (n - 1)
                no_down = i == (m - 1)
                if no_right and no_down:
                    continue
                elif no_right:
                    grid[i][j] += grid[i + 1][j]
                elif no_down:
                    grid[i][j] += grid[i][j + 1]
                else:
                    grid[i][j] += min(grid[i][j + 1], grid[i + 1][j])
        
        return grid[0][0]
      
