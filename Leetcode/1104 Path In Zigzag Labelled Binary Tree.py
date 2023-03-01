class Solution:
    def pathInZigZagTree(self, label):
        path = [label]
        while label != 1:
            label = calculate_parent(label)
            path.append(label)

        i, j = 0, len(path) - 1
        while i < j:
            path[i], path[j] = path[j], path[i]
            i += 1
            j -= 1
            
        return path


def calculate_parent(n):
    p = floor_log_2(n)
    if p & 1:
        d = (1 << (p + 1)) - n
        i = (d >> 1) + (d & 1) - 1
        return (1 << (p - 1)) + i
    to_pow_p = 1 << p
    d = n - to_pow_p + 1
    i = (d >> 1) + (d & 1)
    return to_pow_p - i


def floor_log_2(n):
    n_bit = 31
    p = 1 << n_bit
    while n < p:
        p >>= 1
        n_bit -= 1
    return n_bit
