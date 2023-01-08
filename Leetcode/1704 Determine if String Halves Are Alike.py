class Solution:
    VOWELS = set('aeiouAEIOU')

    @staticmethod
    def sign(index, limit):
        return -1 if index < limit else 1

    def halvesAreAlike(self, string: str) -> bool:
        mid, vowel_count = len(string) // 2, 0

        for i, char in enumerate(string):
            if char in Solution.VOWELS:
                vowel_count += Solution.sign(i, mid)

        return vowel_count == 0
