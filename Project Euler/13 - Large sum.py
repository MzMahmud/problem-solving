with open('in.txt') as file:
    sum = 0
    for line in file:
        num = int(line.strip())
        sum += num
    print(str(sum)[:10])
