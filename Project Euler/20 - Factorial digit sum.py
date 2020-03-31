def fact(n: int):
    if n == 0:
        return 1

    return n*fact(n - 1)


def digit_sum(n):
    n = str(n)
    digit_sum = 0
    for digit in n:
        digit_sum += int(digit)

    return digit_sum


print(digit_sum(fact(100)))
