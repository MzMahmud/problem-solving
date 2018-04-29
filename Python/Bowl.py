bowl = []

for i in range(0,2014):
    bowl.append(0)

for i in range(1,2014):
    k = i
    while k <= 2013:
        bowl[k] = bowl[k] + 1
        k = k + i

for i in range(1,2014):
    if bowl[i] % 2 != 0:
        print(i)
