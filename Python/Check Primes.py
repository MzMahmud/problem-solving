import math

def is_prime(a):
    if a == 2:
        return 1
    elif n % 2 == 0:
        return 2
    root = math.sqrt(a)
    i = 3
    while i <= root:
        if a % i == 0:
            return i
        i += 2
    return 1
while 1:
    
    n = int(input('Enter any integer >= 2(0 to Exit) ::'))
    if n == 0:
        break
    a = is_prime(n)
    
    if a == 1:
        print('%s is a prime' %n)
    else:
        print('%s is composite.' %n)
        print('Smallest prime factor of %s is %s' %(n,a))

