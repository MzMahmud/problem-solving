class Solution:
    VISITED = -1

    def shortestPathBinaryMatrix(self, grid):
        n = len(grid)
        queue = deque([(-1, -1)])
        path_length, target = 0, (n-1, n-1)

        while queue:
            for _ in range(len(queue)):
                node = queue.popleft()
                if node == target:
                    return path_length
                Solution.add_neghbours(node[0], node[1], grid, queue)

            path_length += 1

        return -1

    @staticmethod
    def add_neghbours(i, j, grid, queue):
        n = len(grid)
        for di in range(-1, 2):
            for dj in range(-1, 2):
                n_i, n_j = i + di, j + dj
                is_valid_neighbour = (
                    (0 <= n_i < n) and (0 <= n_j < n)
                    and (n_i != i or n_j != j)
                    and grid[n_i][n_j] == 0
                )
                if is_valid_neighbour:
                    grid[n_i][n_j] = Solution.VISITED
                    queue.append((n_i, n_j))
