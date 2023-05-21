WATER, LAND, VISITED = 0, 1, 2
DIRS = [(-1, 0), (0, 1), (1, 0), (0, -1)]

class Solution:
    def shortestBridge(self, grid):
        n = len(grid)
        q = deque()
        
        def dfs(i, j):
            if not (0 <= i < n) or not (0 <= j < n) or grid[i][j] != LAND:
                return
            grid[i][j] = VISITED
            q.append((i, j))
            for di, dj in DIRS:
                dfs(i + di, j + dj)
        
        def first_land_pos():
            for i in range(n):
                for j in range(n):
                    if grid[i][j] == LAND:
                        return i, j
                      
        dfs(*first_land_pos())
        dist = 0
        while q:
            for _ in range(len(q)):
                i, j = q.popleft()
                for di, dj in DIRS:
                    n_i, n_j = i + di, j + dj
                    if 0 <= n_i < n and 0 <= n_j < n:
                        if grid[n_i][n_j] == LAND:
                            return dist
                        if grid[n_i][n_j] == WATER:
                            grid[n_i][n_j] = VISITED
                            q.append((n_i, n_j))
            dist += 1
        return dist
