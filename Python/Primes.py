import math

def is_prime(a):
    root = math.sqrt(a)
    if a <= 1:
        return 0
    elif a == 2:
        return 1
    elif a % 2 == 0:
        return 0

    i = 3
    while i <= root:
        if a % i == 0:
            return 0
        i = i + 2
        
    return 1

count = 0
for j in range(1,1000):
    if(is_prime(j) == 1):
        print(j)
        count = count + 1

print('total ::',count)
input()
