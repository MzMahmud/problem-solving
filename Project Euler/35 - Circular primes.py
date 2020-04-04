from collections import deque
from mymath import get_primes_upto


PRIMES = get_primes_upto(1_000_000)


def binary_search(item_list, item):
    first = 0
    last = len(item_list)-1
    found = False
    while(first <= last and not found):
        mid = (first + last)//2
        if item_list[mid] == item:
            found = True
        else:
            if item < item_list[mid]:
                last = mid - 1
            else:
                first = mid + 1
    return found


def is_circular_prime(p):
    n = p
    for _ in range(len(str(p))):
        dq = deque(str(n))
        dq.appendleft(dq.pop())
        n = ""
        for d in dq:
            n = n + d
        n = int(n)
        if not binary_search(PRIMES, n):
            return False

    return True


upto = 1_000_000

count = 0
for p in PRIMES:
    if p > upto:
        break

    if is_circular_prime(p):
        print(p)
        count += 1

print(count)
# ans 55
