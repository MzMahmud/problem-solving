grid = []

with open('in.txt') as file:
    for line in file:
        row = [int(n) for n in line.split()]
        grid.append(row)

n = len(grid)

# i know it is overlapping,this test case is small
# used dp for the bigger input :3


def max_path_sum(i=0, j=0):
    # passed last row,negative index,i th rows index > i
    if i == n or i < 0 or j < 0 or j > i:
        return 0

    left = max_path_sum(i + 1, j)
    right = max_path_sum(i + 1, j + 1)

    return grid[i][j] + max(left, right)


print(max_path_sum())
