class Solution:
    def init(self):
        self.max_length = 0
        self.start = 0
        self.end = 0

    def __init__(self):
        self.init()

    def longestPalindrome(self, string: str) -> str:
        self.init()
        for i in range(len(string)):
            self.expand_palindrome_update_max(i, i, string)
            self.expand_palindrome_update_max(i, i + 1, string)
        return string[self.start: self.end]

    def expand_palindrome_update_max(self, start: int, end: int, string: str) -> None:
        while 0 <= start and end < len(string) and string[start] == string[end]:
            start -= 1
            end += 1
        current_length = end - start - 1
        if current_length > self.max_length:
            self.max_length = current_length
            self.start = start + 1
            self.end = end
