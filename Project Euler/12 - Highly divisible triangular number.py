from mymath import number_of_divisors
# nth triangular number
n = 1
n_divisiors = 500

while number_of_divisors(n*(n + 1)//2) < n_divisiors:
    n += 1

print(n*(n+1)//2)
# 76576500
