TEN_TO_THE_POWER_TEN = int(1e10)


def mod_exp(a, n, m):
    if n == 0:
        return 1 % m
    half = mod_exp(a, n // 2, m) % m
    full = (half * half) % m
    return (full * a if n % 2 == 1 else full) % m


a = 28433
n = 7830457

two_power_n = mod_exp(2, n, TEN_TO_THE_POWER_TEN)
last_10_digits = (two_power_n * a + 1) % TEN_TO_THE_POWER_TEN
print(last_10_digits)
