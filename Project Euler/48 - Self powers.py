MOD = int(1e10)


def big_mod(a, b, n):
    """
        returns a**b mod n in O(lg n)
    """
    if b == 0:
        return 1 % n

    x = big_mod(a, b//2, n)

    x = (x * x) % n

    if b % 2 == 1:
        x = (x * a) % n

    return x % n


sum = 0
last = 1000
for n in range(1, last + 1):
    sum = (sum + big_mod(n, n, MOD)) % MOD

print(sum % MOD)
