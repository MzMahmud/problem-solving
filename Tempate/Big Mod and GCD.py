def bigMod(a,b,m):
    if b == 0:
        return 1%m

    x = bigMod(a,int(b/2),m)
    x = (x*x) % m

    if b % 2 == 1:
        x = (a*x) % m

    return x
def gcd(a,b):
    if b == 0:
        return a
    return gcd(b,a%b)

print(bigMod(2,34,341))
print(gcd(1035,10300))
