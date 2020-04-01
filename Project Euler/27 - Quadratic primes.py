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


def quadratic(a, b, n):
    return n**2 + a*n + b


def prime_run(a, b):
    n = 0
    while is_prime(quadratic(a, b, n)):
        n += 1

    return n


LIMIT = 1000
max_run = -1
max_a = 0
max_b = 0
for a in range(-LIMIT + 1, LIMIT):
    for b in range(-LIMIT, LIMIT + 1):
        run = prime_run(a, b)
        if run > max_run:
            max_run = run
            max_a = a
            max_b = b

print(f'max run {max_run},max a {max_a},max b {max_b}')
print(max_a*max_b)
