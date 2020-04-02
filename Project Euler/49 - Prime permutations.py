from itertools import combinations, permutations


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


def prime_perm_arithmetic_seq(comb: tuple):
    prime_perm = set()
    for perm in permutations(comb):
        if perm[0] == '0':
            continue

        nump = int("".join(perm))
        if is_prime(nump):
            prime_perm.add(nump)

    length = len(prime_perm)
    if length < 3:
        return

    prime_perm = list(prime_perm)
    for i in range(length):
        for j in range(i + 1, length):
            avg = (prime_perm[i] + prime_perm[j])
            if avg % 2 == 1:
                continue
            avg //= 2
            if avg in prime_perm:
                print(prime_perm[i], avg, prime_perm[j])


def generate_comb(all, distinct, same):
    if same < 2:
        distinct += same
        same = 0

    for comb in combinations(all, distinct):
        if same > 0:
            for a in all:
                if a not in comb:
                    tup = tuple([a for _ in range(same)])
                    ret = comb + tup
                    yield ret
        else:
            yield comb


for i in range(1, 4):
    for comb in generate_comb("0123456789", 4-i, i):
        prime_perm_arithmetic_seq(comb)

# Only These Two!
# 1487 4817 8147
# 2969 6299 9629
