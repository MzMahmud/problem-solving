import sys

caseno = 1

t = int(sys.stdin.readline())

while t != 0:
    a = int(sys.stdin.readline())
    b = int(sys.stdin.readline())
    print('Case %s:'%caseno,a+b)
    caseno = caseno + 1
    t = t - 1
