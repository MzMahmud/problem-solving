T = int(input())
for t in range(T):
    n = int(input())
    a = map(int, input().split())
    seen = dict()
    for ai in a:
        abs_ai = ai if ai > 0 else -ai
        seen[abs_ai] = ai
    print(f'Case {t + 1}: {sum(seen.values())}')
