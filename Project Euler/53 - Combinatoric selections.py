dp = {}


def C(n, r):
    if r == 0:
        return 1
    if n < 0:
        return 0

    if r > n//2:
        r = n - r

    if (n, r) not in dp:
        dp[(n, r)] = C(n - 1, r) + C(n - 1, r - 1)

    return dp[(n, r)]


n_range = [1, 100]
mill = 1_000_000
count = 0
for n in range(n_range[0], n_range[1] + 1):
    for r in range(0, n + 1):
        if C(n, r) >= mill:
            count += 1

print(count)
