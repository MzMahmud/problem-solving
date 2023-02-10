DIRS = ((-1, 0), (0, 1), (1, 0), (0, -1))
VISITED = -1
LAND = 1
WATER = 0

class Solution:
    def maxDistance(self, grid):
        n = len(grid)
        queue = deque()
        for i in range(n):
            for j in range(n):
                if grid[i][j] == LAND:
                    grid[i][j] = VISITED
                    queue.append((i, j))

        distance = -1
        while queue:
            nodes_in_level = len(queue)
            for _ in range(nodes_in_level):
                i, j = queue.popleft()
                for di, dj in DIRS:
                    n_i, n_j = i + di, j + dj
                    if 0 <= n_i < n and 0 <= n_j < n and grid[n_i][n_j] == WATER:
                        grid[n_i][n_j] = VISITED
                        queue.append((n_i, n_j))
            
            distance += 1
        
        return -1 if distance == 0 else distance 
