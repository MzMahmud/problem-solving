class Solution:
    def mergeAlternately(self, a, b):
        return "".join(map("".join, zip_longest(a, b, fillvalue ='')))
      
