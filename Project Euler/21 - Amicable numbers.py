from mymath import sum_of_divisons

upto = 10000

sopd = [0 for _ in range(upto + 1)]

for n in range(2, upto + 1):
    sopd[n] = sum_of_divisons(n) - n

amicable_sum = 0
for i in range(2, upto + 1):
    for j in range(i + 1, upto + 1):
        if sopd[i] == j and sopd[j] == i:
            amicable_sum += (i + j)
            print(i, j)

print(f'amicable_sum = {amicable_sum}')

# 220 284
# 1184 1210
# 2620 2924
# 5020 5564
# 6232 6368
# amicable_sum = 31626
