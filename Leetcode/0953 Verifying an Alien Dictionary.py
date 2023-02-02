class Solution:
    def isAlienSorted(self, words, order):
        char_comparator = get_char_comparator(order)

        for i in range(1, len(words)):
            compared = string_comparator(words[i-1], words[i], char_comparator)
            if compared > 0:
                return False

        return True


def get_char_comparator(order):
    char_index_to_order = [0 for _ in order]
    for i, char in enumerate(order):
        char_index = ord(char) - ord('a')
        char_index_to_order[char_index] = i

    def compare(a, b):
        if a == b:
            return 0
        
        a_index = ord(a) - ord('a')
        b_index = ord(b) - ord('a')
        diff = char_index_to_order[a_index] - char_index_to_order[b_index]
        
        return -1 if diff < 0 else 1

    return compare


def string_comparator(a, b, char_comparator):
    for ai, bi in zip(a, b):
        compared = char_comparator(ai, bi)
        if compared != 0:
            return compared

    len_diff = len(a) - len(b)
    return 0 if len_diff == 0 else (-1 if len_diff < 0 else 1)
