from mymath import is_prime


right_append_allowed = ['1', '3', '7', '9']
right_truncatable_primes = []


def generate_right_truncatable_primes(n):
    if not is_prime(int(n)):
        return

    right_truncatable_primes.append(int(n))
    for d in right_append_allowed:
        new_n = n + d
        generate_right_truncatable_primes(new_n)


for d in ['2', '3', '5', '7']:
    generate_right_truncatable_primes(d)

right_truncatable_primes.sort()
# print(len(right_truncatable_primes))
# right_truncatable_primes are fewer (only 83)
# left are large
# so check among rights


def is_left_truncatable_prime(n):
    num = str(n)
    l = len(num)
    for i in range(l):
        if not is_prime(int(num[i:])):
            return False

    return True


both_left_right = [p for p in right_truncatable_primes if p >
                   10 and is_left_truncatable_prime(p)]

print(both_left_right)
print(sum(both_left_right))
# [23, 37, 53, 73, 313, 317, 373, 797, 3137, 3797, 739397]
# 748317
