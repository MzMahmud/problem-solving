def get_repdigit_cycle_len(b, a, prev_b):
    """
        decimal division of b/a
        returns the redigits cycle length
        0.12654654654....
        returns 3 because 654 repeats 
        and cycle length = 3
    """
    if b in prev_b:
        return len(prev_b) - prev_b.index(b)

    prev_b.append(b)

    b = (b * 10) if (a > b) else b
    b = b % a

    return get_repdigit_cycle_len(b, a, prev_b)


LIMITS = 1000
max_cycle = -1
max_d = -1
for d in range(2, LIMITS + 1):
    cycle = get_repdigit_cycle_len(1, d, [])
    if cycle > max_cycle:
        max_cycle = cycle
        max_d = d

print(f'1/{max_d} has cycle len {max_cycle}')
# 1/983 has cycle len 982
