def score(s):
    score = 0
    for c in s:
        score += (ord(c) - ord('A') + 1)

    return score


with open('in.txt') as file:
    names = file.readline().split(sep=",")
    names = [name.strip("\"") for name in names]
    names.sort()

    total_score = 0
    for i in range(len(names)):
        total_score += ((i + 1)*score(names[i]))

    print(total_score)
