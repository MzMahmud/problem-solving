n = int(input())
for i in range(0, n):
    k, x = input().split()
    k = int(k)
    x = int(x)

    print(f"{x + (k-1)*9}")