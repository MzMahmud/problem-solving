from itertools import permutations

mill = 1_000_000
count = 0
for p in permutations("0123456789"):
    count += 1
    if count == mill:
        print(p)
        break

# 2783915460
