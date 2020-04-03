def is_prime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False

    i = 3
    while i*i <= n:
        if n % i == 0:
            return False
        i += 2

    return True


n = 1
primes = 0
while True:
    diag = [(2*n - 1)**2 + 2*n,
            (2*n - 1)**2 + 4*n,
            (2*n + 1)**2 - 2*n]
    for num in diag:
        if is_prime(num):
            primes += 1

    proportion = primes/(4*n + 1)*100
    if proportion < 10:
        print(n)
        break
    n += 1

print("Side length", 2*n + 1)
