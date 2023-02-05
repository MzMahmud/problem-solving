ALPHABET_SIZE = 26


class Solution:
    def findAnagrams(self, s, p):
        len_s, len_p = len(s), len(p)
        if len_s < len_p:
            return []

        p_counts = [0 for _ in range(ALPHABET_SIZE)]
        s_window_counts = [0 for _ in range(ALPHABET_SIZE)]
        for char_p, char_s in zip(p, s):
            p_counts[char_index(char_p)] += 1
            s_window_counts[char_index(char_s)] += 1

        matches = 0
        for p_count, s_window_count in zip(p_counts, s_window_counts):
            if p_count == s_window_count:
                matches += 1

        anagram_indices = []
        if matches == ALPHABET_SIZE:
            anagram_indices.append(0)

        for i in range(len_p, len_s):
            enter_char_index = char_index(s[i])
            exit_char_index = char_index(s[i - len_p])

            if enter_char_index != exit_char_index:
                if p_counts[enter_char_index] == s_window_counts[enter_char_index]:
                    matches -= 1
                if p_counts[exit_char_index] == s_window_counts[exit_char_index]:
                    matches -= 1

                s_window_counts[enter_char_index] += 1
                s_window_counts[exit_char_index] -= 1

                if p_counts[enter_char_index] == s_window_counts[enter_char_index]:
                    matches += 1
                if p_counts[exit_char_index] == s_window_counts[exit_char_index]:
                    matches += 1

            if matches == ALPHABET_SIZE:
                anagram_indices.append(i - len_p + 1)

        return anagram_indices


def char_index(char):
    return ord(char) - ord('a')
