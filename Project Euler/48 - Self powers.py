from mymath import big_mod


MOD = int(1e10)
sum = 0
last = 1000
for n in range(1, last + 1):
    sum = (sum + big_mod(n, n, MOD)) % MOD

print(sum % MOD)
