from mymath import is_square
from math import sqrt


def is_pentagonal(n: int) -> bool:
    D = 1 + 24*n
    if not is_square(D):
        return False
    D = 1 + int(sqrt(D))
    return D % 6 == 0


def P(n): return n*(3*n - 1)//2

# Pj + Pk = Ps,Pj - Pk = Pd, Pj > Pk
# Pj = (Ps + Pd)/2 and Pk = (Ps - Pd)/2
# for every pair Pd,Ps if (Ps + Pd)/2 and (Ps - Pd)/2
# exists in P we found Pd. To minimize lets look


L_LIMIT = 1000
U_LIMIT = 10000

for d in range(L_LIMIT, U_LIMIT + 1):
    for s in range(d + 1, U_LIMIT + 1):
        ps = P(s)
        pd = P(d)

        summ = ps + pd
        if summ % 2 == 1:
            continue
        summ //= 2

        diff = ps - pd
        if diff % 2 == 1:
            continue
        diff //= 2

        if is_pentagonal(summ) and is_pentagonal(diff):
            print('min diff', pd)
            exit(0)

# min diff 5482660
