def is_palindrome(n):
    n = str(n)
    i = 0
    j = len(n) - 1
    while i <= j:
        if n[i] != n[j]:
            return False
        i += 1
        j -= 1

    return True


def to_binary(n):
    if n == 0:
        return "0"

    binary = ""
    while n != 0:
        if n % 2 == 0:
            binary = "0" + binary
        else:
            binary = "1" + binary

        n = n//2

    return binary


mill = 1_000_000

Sum = 0
for n in range(1, mill + 1):
    if is_palindrome(n) and is_palindrome(to_binary(n)):
        Sum += n

print(Sum)
