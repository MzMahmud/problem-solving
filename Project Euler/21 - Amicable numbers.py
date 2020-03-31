def sum_proper_divison(n):
    i = 1
    sod = 0
    while i*i <= n:
        if n % i == 0:
            sod += i
            if i != 1 and i != (n/i):
                sod += (n//i)

        i += 1

    return sod


upto = 10000

sopd = [0 for _ in range(upto + 1)]

for n in range(2, upto + 1):
    sopd[n] = sum_proper_divison(n)

amicable_sum = 0
for i in range(2, upto + 1):
    for j in range(i + 1, upto + 1):
        if sopd[i] == j and sopd[j] == i:
            amicable_sum += (i + j)
            print(i, j)

print(f'amicable_sum = {amicable_sum}')
