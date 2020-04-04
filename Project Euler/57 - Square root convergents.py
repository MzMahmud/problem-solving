from mymath import Fraction


ONE = Fraction(1)
LIMIT = 1000
ans = 0

stir_case_2 = Fraction(2)
for _ in range(1, LIMIT + 1):
    frac = ONE + ONE/stir_case_2
    n, d = str(frac).split('/')

    if len(n) > len(d):
        ans += 1

    stir_case_2 = Fraction(2) + ONE/stir_case_2

print(ans)
# 153
