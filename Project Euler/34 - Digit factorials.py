fact = [1]
for i in range(1, 10):
    fact.append(i * fact[-1])


def digit_factorial_sum(n):
    fact_sum = 0
    for d in str(n):
        fact_sum += fact[int(d)]
    return fact_sum


ans_sum = 0
LIMIT = 1000000
for n in range(10, LIMIT + 1):
    if n == digit_factorial_sum(n):
        ans_sum += n

print(ans_sum)
