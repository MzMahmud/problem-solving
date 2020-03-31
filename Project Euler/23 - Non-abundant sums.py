# it can be shown that all integers greater than
# 28123 can be written as the sum of two abundant numbers.

LIMIT = 28123


def proper_divisor_sum(n):
    i = 1
    sod = 0
    while i*i <= n:
        if n % i == 0:
            sod += i
            if i != 1 and i != (n//i):
                sod += (n//i)

        i += 1

    return sod


abundant_num = []

for n in range(1, LIMIT + 1):
    sod = proper_divisor_sum(n)
    if sod > n:
        abundant_num.append(n)


all_pair_abundant_sum = set()
for i in range(len(abundant_num)):
    for j in range(i, len(abundant_num)):
        all_pair_abundant_sum.add(abundant_num[i] + abundant_num[j])


non_abundant_sum = 0
for num in range(1, LIMIT + 1):
    if num not in all_pair_abundant_sum:
        non_abundant_sum += num

print(non_abundant_sum)
