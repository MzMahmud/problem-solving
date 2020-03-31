a = 2
b = 1000
num = str(a**b)

digit_sum = 0
for digit in num:
    digit_sum += int(digit)

print(digit_sum)
