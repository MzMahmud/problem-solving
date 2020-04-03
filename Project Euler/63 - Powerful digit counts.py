from math import log10, floor

n = 1
count = 0
while True:
    diff = n - floor(n*log10(9))
    if diff > 1:
        break

    for a in range(1, 10):
        # #digits(a^n)
        n_digit = floor(n*log10(a)) + 1
        if n_digit == n:
            count += 1
            # print(a, n)

    n += 1

print(count)
# 49
