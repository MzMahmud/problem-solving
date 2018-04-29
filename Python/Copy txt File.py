file = open('aa.txt')

file1 = open('Copy of aa.txt','w')

file1.write(file.read())

file.close()
file1.close()

print('Done.')
print('Press Any key to Break.')
input()