class Solution:
    def islandPerimeter(self, grid):
        n, m = len(grid), len(grid[0])
        for i in range(n):
            for j in range(m):
                if grid[i][j] == LAND:
                    return island_perimeter(i, j, grid)
        return 0


LAND = 1
WATER = 0
VISITED_LAND = -1
DIRS = ((-1, 0), (0, 1), (1, 0), (0, -1))


def island_perimeter(i, j, grid):
    n, m = len(grid), len(grid[0])
    if i < 0 or i >= n or j < 0 or j >= m:
        return 1
    if grid[i][j] == WATER:
        return 1
    if grid[i][j] == VISITED_LAND:
        return 0

    grid[i][j] = VISITED_LAND

    total_perimeter = 0
    for di, dj in DIRS:
        total_perimeter += island_perimeter(i + di, j + dj, grid)

    return total_perimeter
