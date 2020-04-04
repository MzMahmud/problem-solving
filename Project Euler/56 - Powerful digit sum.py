def digit_sum(n):
    n = str(n)
    summ = 0
    for d in n:
        summ += int(d)
    return summ 


max_sum = -1
for a in range(1,101):
    for b in range(1,101):
        max_sum = max(max_sum,digit_sum(a**b))
        
print(max_sum)
# 972
        