def tau(n: int):
    """
        returns number of divisiors on n
    """
    i = 1
    _tau = 0
    while i*i <= n:
        if n % i == 0:
            _tau += 1
            d = n//i
            if i != d:
                _tau += 1

        i += 1

    return _tau


# nth triangular number
n = 1
n_divisiors = 500

while tau(n*(n + 1)//2) < n_divisiors:
    n += 1

print(n*(n+1)//2)
