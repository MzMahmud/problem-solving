def score(s):
    score = 0
    for c in s:
        score += (ord(c) - ord('A') + 1)
    return score


words = []
with open("in.txt") as f:
    words = [w.strip('"') for w in f.readline().split(',')]


longest_word = max(words, key=lambda w: len(w))
print("longest word len", len(longest_word))
# so max sum of code = 14*26 = 364
# generate all the triangle num < 364

# set because set searching is fast
tn = set()

n = 1
t_n = n*(n + 1)//2
while t_n < (len(longest_word)*26):
    tn.add(t_n)
    n += 1
    t_n = n*(n + 1)//2

count = 0
for word in words:
    if score(word) in tn:
        count += 1

print(count)
