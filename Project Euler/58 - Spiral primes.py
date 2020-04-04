from mymath import is_prime


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
