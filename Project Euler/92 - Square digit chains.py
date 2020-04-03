def digit_square_sum(n):
    summ = 0
    while n != 0:
        d = (n % 10)
        summ += (d*d)
        n //= 10

    return summ


ends_in_89 = set()
ends_in_1 = set()

LIMIT = 10_000_000
UPPER_BOUND = 600
# Upper Bound is there because maximum value of square
# sum of digit sum un der 10 million is 7*9^2 = 567
# so manually calculate all utpo 567
# then just go throung all the digit sums upto LIMIT
for n in range(1, UPPER_BOUND + 1):
    num = n
    num_set = set()
    in_1, in_89 = False, False
    while True:
        num_set.add(num)
        if num == 1 or num in ends_in_1:
            in_1 = True
            break
        if num == 89 or num in ends_in_89:
            in_89 = True
            break
        num = digit_square_sum(num)

    if in_1:
        ends_in_1 = ends_in_1.union(num_set)
    elif in_89:
        ends_in_89 = ends_in_89.union(num_set)

# print(ends_in_1)
# print(ends_in_89)
count = 0
for n in range(1, LIMIT + 1):
    summ = digit_square_sum(n)
    if summ in ends_in_89:
        count += 1

print(count)
# 8581146
