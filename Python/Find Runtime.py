import time

t1 = time.time()

for i in range (1,1001):
    print(i)
    t2 = time.time()
print('It took %s s' %(t2 -t1))


print('Done.')
print('Press Any key to Break.')
input()
