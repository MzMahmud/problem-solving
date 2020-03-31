grid = []
with open('in.txt') as f:
    for line in f:
        grid.append([int(x) for x in line.split()])


n = len(grid)

max_prod = -1
for i in range(n):
    for j in range(n):
        if (j - 3) >= 0:
            left = 1
            for k in range(4):
                left *= grid[i][j - k]
            if left > max_prod:
                max_prod = left

        if (j + 3) < n:
            right = 1
            for k in range(4):
                right *= grid[i][j + k]
            if right > max_prod:
                max_prod = right

        if (i - 3) >= 0:
            up = 1
            for k in range(4):
                up *= grid[i - k][j]
            if up > max_prod:
                max_prod = up

        if (i + 3) < n:
            down = 1
            for k in range(4):
                down *= grid[i + k][j]
            if down > max_prod:
                max_prod = down

        if (i + 3) < n and (j + 3) < n:
            diag = 1
            for k in range(4):
                diag *= grid[i + k][j + k]
            if diag > max_prod:
                max_prod = diag


print('Max Product', max_prod)
