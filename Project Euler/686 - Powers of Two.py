'''
2^i = 10^{frac + int}
    = 10^frac * 10^int
    = (the leading numbers) * 10^int
'''
import numpy as np


def leading_digit_2(j, d):
    """
    returns d leading digits of 2^j
    """
    # 10^k = 2^j
    # k = j*log(2)
    k = j*np.log10(2.0)
    k_frac = k - int(k)
    leading_digits = np.power(10.0, k_frac)
    d_digits = leading_digits*np.power(10, d-1)
    return int(d_digits)


def p(L, n):
    j = 1
    count = 0
    digits = len(str(L))
    while True:
        if L == leading_digit_2(j, digits):
            count += 1
            if count == n:
                return j
        j += 1

    return None


print(p(123, 678910))
# answer in 193060223
# but took a long time
# google colab took 1190.116s :3
# code have to be fixed!
