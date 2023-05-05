VOWELS = 'aeiou'

class Solution:
    def maxVowels(self, s, k):
        vowels, max_vowels = 0, 0
        for i, c in enumerate(s):
            if c in VOWELS:
                vowels += 1
            if i >= k and s[i - k] in VOWELS:
                vowels -= 1
            max_vowels = max(max_vowels, vowels)
        return max_vowels
