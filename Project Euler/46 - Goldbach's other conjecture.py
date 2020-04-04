from mymath import get_primes_upto, is_prime, is_square


primes = get_primes_upto(1000000)

MAX_N = 1000000

for n in range(3, MAX_N+1, 2):
    if is_prime(n):
        continue

    found = False
    for p in primes[1:]:
        if p > n:
            break

        # n = p + 2*a^2
        a = (n - p)//2
        if is_square(a):
            found = True
            break

    if not found:
        print(f'Counter Example {n}')
        break

# Counter Example 5777
