class Solution:
    # O(nk) time O(k) space
    # n = length of b, k = alphabet size
    # in this problem k = 26
    # so the solution is O(n) time and O(1) space 
    def checkInclusion(self, a, b):
        m, n = len(a), len(b)
        if m > n:
            return False

        a_chars = [0 for _ in range(26)]
        for char_a in a:
            a_chars[char_index(char_a)] += 1

        b_window_chars = [0 for _ in range(26)]
        for i in range(n):
            b_window_chars[char_index(b[i])] += 1
            
            if m <= i:
                b_window_chars[char_index(b[i - m])] -= 1

            if (m - 1) <= i and a_chars == b_window_chars:
                return True

        return False


def char_index(char):
    return ord(char) - ord('a')
