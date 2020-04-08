from sys import stdin


def group_anagrams(strs):
    seen = {}
    for s in strs:
        sorted_s = tuple(sorted(s.lower()))

        if sorted_s not in seen:
            seen[sorted_s] = []

        seen[sorted_s].append(s)

    return [seen[s] for s in seen]


strs = []
for line in stdin:
    line = line.strip()
    if line == '#':
        break

    words = [word.strip() for word in line.split()]
    strs += words

ans = []
for ana in group_anagrams(strs):
    if len(ana) == 1:
        ans.append(ana[0])

for a in sorted(ans):
    print(a)
