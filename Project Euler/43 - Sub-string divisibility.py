from itertools import permutations

sum_all = 0


def push_valid_back(t: tuple, a: list, d: list):
    global sum_all

    if len(a) == 0:
        num = int("".join(t))
        print(num)
        sum_all += num
        return

    for digit in a:
        # number formed by last three digits
        num = int(t[-2] + t[-1] + digit)
        if num % d[0] == 0:
            new_t = t + tuple([digit])
            new_a = [x for x in a if x != digit]
            new_d = d[1:]
            push_valid_back(new_t, new_a, new_d)


all = "0123456789"
div = [2, 3, 5, 7, 11, 13, 17]

for p in permutations(all, 3):
    if p[0] != '0':
        a = [x for x in all if x not in p]
        push_valid_back(p, a, div)


print("Sum", sum_all)
