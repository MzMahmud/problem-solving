def n_th_digit(n):
    """
    C = 1234567891011121314151617181920....
    returns n-th digit of C
    """
    ten_pow = 1
    i = 1
    while True:
        limit = i * 9 * ten_pow
        if n <= limit:
            n -= 1
            num = ten_pow + (n // i)
            return int(str(num)[n % i])
        ten_pow *= 10
        n -= limit
        i += 1


ns = [1, 10, 100, 1000, 10000, 100000, 1000000]
ds = [n_th_digit(n) for n in ns]

prod = 1
for d in ds:
    prod *= d

print("ans", prod)
