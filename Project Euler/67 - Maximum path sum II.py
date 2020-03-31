grid = []

with open('in.txt') as file:
    for line in file:
        row = [int(n) for n in line.split()]
        grid.append(row)

n = len(grid)
dp = {}


def max_path_sum(i=0, j=0):
    # passed last row,negative index,i th rows index > i
    if i == n or i < 0 or j < 0 or j > i:
        return 0

    if (i, j) not in dp:
        left = max_path_sum(i + 1, j)
        right = max_path_sum(i + 1, j + 1)
        dp[(i, j)] = grid[i][j] + max(left, right)

    return dp[(i, j)]


print(max_path_sum())
