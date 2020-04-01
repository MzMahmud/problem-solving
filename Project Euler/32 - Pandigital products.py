def get_digit_count(n: int) -> list:
    digit_count = [0 for _ in range(10)]
    for d in str(n):
        digit_count[int(d)] += 1

    return digit_count


def is_pandigital(digit_count: list):
    if digit_count[0] != 0:
        return False

    for i in range(1, 10):
        if digit_count[i] != 1:
            return False

    return True


def is_valid(n):
    """
    if n contains 0 or has repeated digit its not valid
    """
    digit_count = get_digit_count(n)

    if digit_count[0] != 0:
        return False

    for i in range(1, 10):
        if digit_count[i] > 1:
            return False

    return True


unique_pandigital_prod = set()

LIMIT = int(1e4)
n_try = 0

for a in range(1, LIMIT):
    if not is_valid(a):
        continue

    for b in range(a + 1, LIMIT):
        if not is_valid(b):
            continue

        c = a * b
        if not is_valid(c):
            continue

        # if already found dont bother
        if c in unique_pandigital_prod:
            continue

        n_try += 1

        digits_a = get_digit_count(a)
        digits_b = get_digit_count(b)
        digits_c = get_digit_count(c)
        digit_count = [
            digits_a[i] + digits_b[i] + digits_c[i]
            for i in range(10)
        ]

        if is_pandigital(digit_count):
            print(a, b, c)
            unique_pandigital_prod.add(c)


print(unique_pandigital_prod)
print('answer', sum(unique_pandigital_prod))
print(f'#Tries{n_try}')

# 4 1738 6952
# 4 1963 7852
# 12 483 5796
# 18 297 5346
# 28 157 4396
# 39 186 7254
# 48 159 7632
# {5346, 5796, 6952, 7852, 4396, 7632, 7254}
# answer 45228
# #Tries 118371
