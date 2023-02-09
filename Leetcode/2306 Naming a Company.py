class Solution:
    ALPHABET_SIZE = 26

    # n = ideas length, m = average string size, a = alphabet size
    def distinctNames(self, ideas):
        # O(m) time O(nm) space
        suffixes_by_start = [set() for _ in range(Solution.ALPHABET_SIZE)]
        # O(n) time iteration
        for idea in ideas:
            # O(m) time  to find substring
            start, suffix = idea[0], idea[1:]
            # average O(1) time to insert
            suffixes_by_start[char_index(start)].add(suffix)
        # loop runs in O(nm) time

        distinct_names = 0
        # O(a) time iteration
        for i in range(Solution.ALPHABET_SIZE):
            # O(a) time iteration
            for j in range(i + 1, Solution.ALPHABET_SIZE):
                size_i = len(suffixes_by_start[i])
                size_j = len(suffixes_by_start[j])
                # O(n) time to find intersection
                common_suffixes = suffixes_by_start[i].intersection(suffixes_by_start[j])
                size_common = len(common_suffixes)

                distinct_name = 2 * (size_i - size_common) * (size_j - size_common)
                distinct_names += distinct_name
        # O(n*a^2) time 

        # overall O(nm + n*a^2) time O(nm) space
        return distinct_names


def char_index(char):
    return ord(char) - ord('a')