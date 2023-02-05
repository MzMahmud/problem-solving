class Solution:
    def findAnagrams(self, s, p):
        len_s, len_p = len(s), len(p)
        if len_s < len_p:
            return []

        p_counts = {}
        s_window_counts = {}
        for char_p, char_s in zip(p, s):
            p_counts[char_p] = p_counts.get(char_p, 0) + 1
            s_window_counts[char_s] = s_window_counts.get(char_s, 0) + 1

        matches = 0
        for char_p in p_counts:
            matches = get_updated_matches(char_p, p_counts, s_window_counts, matches, 1)

        len_p_counts = len(p_counts)
        anagram_indices = []
        if matches == len_p_counts:
            anagram_indices.append(0)

        for i in range(len_p, len_s):
            enter_char, exit_char = s[i], s[i - len_p]

            if enter_char != exit_char:
                matches = get_updated_matches(enter_char, p_counts, s_window_counts, matches, -1)
                matches = get_updated_matches(exit_char, p_counts, s_window_counts, matches, -1)

                s_window_counts[enter_char] = s_window_counts.get(enter_char, 0) + 1
                s_window_counts[exit_char] -= 1

                matches = get_updated_matches(enter_char, p_counts, s_window_counts, matches, 1)
                matches = get_updated_matches(exit_char, p_counts, s_window_counts, matches, 1)

            if matches == len_p_counts:
                anagram_indices.append(i - len_p + 1)

        return anagram_indices


def get_updated_matches(char, counts_1, counts_2, matches, increment):
    char_count_mathced = (
        char in counts_1
        and char in counts_2
        and counts_1[char] == counts_2[char]
    )
    return matches + increment if char_count_mathced else matches
