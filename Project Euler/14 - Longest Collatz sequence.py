def get_collatz_chain_len(n):
    chain_len = 0

    while n != 1:
        if n % 2 == 0:
            chain_len += 1
            n = n//2
        else:
            chain_len += 2
            n = (3*n + 1)//2

    return chain_len


def brutforce():
    mill = 1_000_000
    max_len = -1
    max_n = -1
    for n in range(1, mill + 1):
        chain_len = get_collatz_chain_len(n)
        if chain_len > max_len:
            max_len = chain_len
            max_n = n

    print(max_len, max_n)


# dp for chain len
collatz_chain_len = {1: 1}


def cal_chain_len(n):
    if n in collatz_chain_len:
        return collatz_chain_len[n]

    chan_len = 0
    if n % 2 == 0:
        chan_len = 1 + cal_chain_len(n//2)
    else:
        chan_len = 2 + cal_chain_len((3*n + 1)//2)

    collatz_chain_len[n] = chan_len

    return collatz_chain_len[n]


mill = 1_000_000
for n in range(1, mill + 1):
    cal_chain_len(n)

# key with max value
max_n = max(collatz_chain_len, key=collatz_chain_len.get)
print(max_n)
