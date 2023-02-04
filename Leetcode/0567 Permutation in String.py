class Solution:
    # O(m + k(n-m)) time, O(k) space
    # m = length of a, n = length of b, k = alphabet size
    # in this problem k = 26
    # so the solution is O(m + n) time and O(1) space
    # but in this implementation if m > n an early return is done
    # so if m > n it takes O(1) time. this means n is the dominating term
    # this omits m from time complexity
    # O(n) time, O(1) space
    def checkInclusion(self, a, b):
        m, n = len(a), len(b)
        if m > n:
            return False

        a_chars = [0 for _ in range(26)]
        # runs in O(m) time
        for char_a in a:
            a_chars[char_index(char_a)] += 1

        b_window_chars = [0 for _ in range(26)]
        for i in range(n):
            b_window_chars[char_index(b[i])] += 1

            if m <= i:
                b_window_chars[char_index(b[i - m])] -= 1
            # runs n-m times and for eac time takes k
            if (m - 1) <= i and a_chars == b_window_chars:
                return True
        # this loop runs in O(k(n-m)) time
        return False

    # removed k factor
    # O(m + k + m + k n - m) = O(m + n + k) = O(n + k) time as n > m
    def checkInclusionOptimizedSlidingWindow(self, a, b):
        m, n = len(a), len(b)
        if m > n:
            return False
        
        alphabet_size = 26
        
        # O(m) time
        a_chars = [0 for _ in range(alphabet_size)]
        for char_a in a:
            a_chars[char_index(char_a)] += 1

        # O(k) time
        b_window_chars = [0 for _ in range(alphabet_size)]
        # O(m) time
        for i in range(m):
            b_window_chars[char_index(b[i])] += 1

        char_count_match = 0
        # O(k) time
        for i in range(alphabet_size):
            char_count_match += 1 if a_chars[i] == b_window_chars[i] else 0

        if char_count_match == alphabet_size:
            return True

        # O(n - m) time
        for i in range(m, n):
            exit_char_index = char_index(b[i - m])
            enter_char_index = char_index(b[i])

            if exit_char_index != enter_char_index:
                if a_chars[exit_char_index] == b_window_chars[exit_char_index]:
                    char_count_match -= 1
                if a_chars[enter_char_index] == b_window_chars[enter_char_index]:
                    char_count_match -= 1

                b_window_chars[exit_char_index] -= 1
                b_window_chars[enter_char_index] += 1

                if a_chars[exit_char_index] == b_window_chars[exit_char_index]:
                    char_count_match += 1
                if a_chars[enter_char_index] == b_window_chars[enter_char_index]:
                    char_count_match += 1

            if char_count_match == alphabet_size:
                return True

        return False


def char_index(char):
    return ord(char) - ord('a')
