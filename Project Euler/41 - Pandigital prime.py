'''
sum(1,9) = 45, so pandigital with 9 digit not possible
sum(1,8) = 36, so pandigital with 8 digits not possible
sum(1,7) = 28, possible

'''
from itertools import permutations


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


max_num = -1

for p in permutations("7654321"):
    # converts permutaion touple to string to int
    n = int("".join(p))
    if is_prime(n):
        print("Largest Pandigital Prime ", n)
        break

# ans 7652413
