from pprint import pprint

grid = []

with open('in.txt') as file:
    for line in file:
        row = [int(n) for n in line.split(',')]
        grid.append(row)

# print(grid)


def min_path_sum(grid):
    # bottom up dp
    n = len(grid)

    for i in range(n - 1, -1, -1):
        for j in range(n - 1, -1, -1):
            best_choise = 0

            # right most corner: no option
            if i == (n - 1) and j == (n - 1):
                best_choise = 0

            # bottom row: only go right
            elif i == (n - 1):
                best_choise = grid[i][j + 1]

            # rightmost column: only go down
            elif j == (n - 1):
                best_choise = grid[i + 1][j]

            # max between right and dwon
            else:
                best_choise = min(grid[i][j + 1], grid[i + 1][j])

            grid[i][j] += best_choise

    return grid[0][0]


print(min_path_sum(grid))
# 427337
