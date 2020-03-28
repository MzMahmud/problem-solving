l, r = input().split()
l = int(l)
r = int(r)

print("YES")

i = l
while i < r:
    print(f"{i} {i+1}")
    i += 2