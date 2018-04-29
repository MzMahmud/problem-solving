SIZE = 1000000
isPrime = ['1']*(SIZE+3)
def primeSieve(n):
    i = 3
    while i*i <= SIZE:
        if isPrime[i] == '1':
            j = i*i
            while j < SIZE:
                isPrime[j] = '0'
                j += (2*i)
        i += 2

primeSieve(SIZE)

while 1:
    n = int(input())
    if n == 0:
        break
    i = 3
    while (2*i) <= n:
        if isPrime[i] == '1' and isPrime[n-i] == '1':
            print("%d = %d + %d" %(n,i,n-i))
            break
        i += 2

