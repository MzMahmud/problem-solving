LIMIT = 1_000_000

phi = [1 for _ in range(LIMIT + 1)]

for n in range(2, LIMIT + 1):
    if phi[n] == 1:
        for j in range(n, LIMIT + 1, n):
            phi[j] = phi[j]/n*(n - 1)

min_ratio = float('inf')
ans = -1
for n in range(2, LIMIT + 1):
    if phi[n] < min_ratio:
        min_ratio = phi[n]
        ans = n

print(ans)
# 510510
# https://projecteuler.net/overview=069 this solution is amazing!
