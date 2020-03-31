a = [2, 100]
b = [2, 100]
unique = set()
for base in range(a[0], a[1] + 1):
    for power in range(b[0], b[1] + 1):
        ab = base**power
        if ab not in unique:
            unique.add(ab)

print(len(unique))
