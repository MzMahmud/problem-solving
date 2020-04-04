from mymath import Fraction


def digit_sum(n):
    n = str(n)
    summ = 0
    for d in n:
        summ += int(d)
    return summ


def find_approx(cont_frac):
    if len(cont_frac) == 1:
        return Fraction(cont_frac[0])

    return cont_frac[0] + 1/find_approx(cont_frac[1:])


n = 100
cont_frac_e = [1 for _ in range(n)]
cont_frac_e[0] = 2

even = 2
for i in range(2, n, 3):
    cont_frac_e[i] = even
    even += 2

# print(cont_frac_e)

n_th_approx = find_approx(cont_frac_e)
print(digit_sum(n_th_approx.a))
# 272
