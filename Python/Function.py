import time

t1 = time.time()

dp = []
for i in range(0,1001):
    dp.append(-1)

def fib(n):
    if n == 0:
        dp[n] = 0
        return dp[n]
    elif n == 1:
        dp[n] = 1
        return dp[n]
    elif dp[n] == -1 :
        dp[n] = dp[n-1] + dp[n-2]
        return dp[n]
    else:
        return dp[n]

for i in range(0,1001):
    print(i,'.',fib(i))

t2 = time.time()
print('Took %s Sec' %(t2-t1))

input()

