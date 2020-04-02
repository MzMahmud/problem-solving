def get_digit_count(n) -> list:
    digit_count = [0 for _ in range(10)]
    for d in str(n):
        digit_count[int(d)] += 1

    return digit_count


def is_pandigital(n):
    digit_count = get_digit_count(n)

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

max_concat = -1

for n in range(LIMIT):
    concat = ""
    for i in range(1, 10):
        n_i = n*i
        if not is_valid(n_i):
            break

        concat += str(n_i)

        if len(concat) > 9 or not is_valid(concat):
            break

        if len(concat) == 9:
            if is_pandigital(concat):
                print(f"{n}*{list(range(1,i+1))} = {concat}")
                max_concat = max(max_concat, int(concat))

            break


print(f"Max Pandigital concat {max_concat}")
# Max Pandigital concat 932718654
