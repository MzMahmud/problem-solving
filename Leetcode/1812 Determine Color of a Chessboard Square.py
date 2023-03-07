class Solution:
    def squareIsWhite(self, coordinate):
        row = ord(coordinate[1]) - ord('1')
        col = ord(coordinate[0]) - ord('a')
        # row + col is even -> black else white
        return bool((row ^ col) & 1)