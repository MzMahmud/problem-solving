def cancel_ith_digit(a: int, i: int) -> int:
    s = str(a)
    return int(s[:i] + s[i+1:])


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


def is_digit_cancelling(a, b):
    """
    for a two digit numerator a and denominator b 
    """
    s_a = str(a)
    s_b = str(b)
    if s_a[-1] == '0' and s_b[-1] == '0':
        # Trivial
        return False

    g = gcd(a, b)
    r_a = a//g
    r_b = b//g
    for i in range(2):
        for j in range(2):
            if s_a[i] == s_b[j]:
                c_a = cancel_ith_digit(a, i)
                c_b = cancel_ith_digit(b, j)
                g = gcd(c_a, c_b)
                c_a //= g
                c_b //= g
                if r_a == c_a and r_b == c_b:
                    return True

    return False


mul_a = 1
mul_b = 1
for a in range(10, 100):
    for b in range(a + 1, 100):
        if is_digit_cancelling(a, b):
            mul_a *= a
            mul_b *= b
            print(f'{a}/{b}')


g = gcd(mul_a, mul_b)
mul_a //= g
mul_b //= g
print(f'{mul_a}/{mul_b}')
# 1/100
# answer 100
