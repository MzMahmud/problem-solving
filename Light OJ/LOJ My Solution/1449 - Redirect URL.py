T = int(input())
for t in range(1, T + 1):
    s = input()
    print(f'Case {t}: {s.replace("http:", "https:")}')
