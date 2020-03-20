# UVa 543 Goldbach's Conjecture with Python
# MoaZ
def isPrime(n):
    if n < 2:
        return 0
    if n == 2:
        return 1
    if n % 2 == 0:
        return 0
    i = 3
    while(i*i <= n):
        if n % i == 0:
            return 0
        i += 2
    return -1

while 1:
    n = int(input())
    if n == 0:
        break
    i = 3
    while (2*i) <= n:
        if (isPrime(i) and isPrime(n-i)):
            print("%d = %d + %d" %(n,i,n-i))
            break
        i += 2
