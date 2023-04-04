class Solution:
    def partitionString(self, s):
        last_index = [-1] * 26
        start_index, n_partions = -1, 0
        for i, char in enumerate(s):
            char_index = get_char_index(char)
            if last_index[char_index] >= start_index:
                n_partions += 1
                start_index = i
            last_index[char_index] = i
        return n_partions


def get_char_index(char):
    return ord(char) - ord('a')
